import sys, os
path = "X:/storage/ylye/QCDAnalysis/OfflineExamples/python" 
path = "python" 
sys.path.append(path)
from keras.optimizers import Adam
import tensorflow as tf
import pandas as pd
import uproot
import numpy as np
import argparse
from sklearn.model_selection import train_test_split
from tqdm import tqdm
import os
import math
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, auc
from sklearn.metrics import roc_auc_score
from sklearn.preprocessing import StandardScaler, MinMaxScaler
import time

def log_time(start, end, step_name):
    print(f"{step_name} took {end - start:.2f} seconds")
import dnn
def select_and_convert(X_data, select_index):
    Y_data = [[row[i] for i in select_index] for row in X_data]
    flattened_data = []
    for row in Y_data:
        concatenated = np.array(row).T
        flattened_data.extend(concatenated)
    flattened_data = np.array(flattened_data)
    print(flattened_data.shape)
    return flattened_data
def extract_shape(X_data, select_index):
    Y_data = X_data[select_index[0]]
    return Y_data
    
def add_suffix(strings, suffix):
    return [s + suffix for s in strings]
def add_suffix_2d(strings_2d, suffix):
    return [[s + suffix for s in row] for row in strings_2d]
def main(args):
    sample_path0 = args.sample_path0
    sample_path1 = args.sample_path1
    select_opt = args.select_opt
    suffix = args.suffix
    sample_filename = "kto4"
    entries=args.entries
    branches_name=[]
    X_data, branch_to_index, index_to_branch,branch_names,branch_types = dnn.LoadROOTFile(sample_paths=[sample_path0],entries=args.entries)
    X_data_supp, *_ = dnn.LoadROOTFile(sample_paths=[sample_path1],entries=args.entries)

    match_index=["match2"]
    level_suffix="_Hadron"
    Y_data_index=["type2"]
    select_item = ["nparticles2","ntracks2","pTD2","sigma12","sigma22","sigma2","nparticles3","ntracks3","pTD3","sigma13","sigma23","sigma3","nparticles4","ntracks4","pTD4","sigma14","sigma24","sigma4","z1","z2","deltaR2","kt2"]
    
    Y_data_index = add_suffix(Y_data_index,level_suffix)
    select_item = add_suffix(select_item,level_suffix)
    select_index = [branch_to_index[name] for name in Y_data_index]
    Y_data = select_and_convert(X_data,select_index)

   
    X_data_shape = [row[select_index[0]] for row in X_data]
    X_data_supp_shape =  [row[select_index[0]] for row in X_data_supp]
    select_index = [branch_to_index[name] for name in match_index]
    match_data = select_and_convert(X_data,select_index)
    
    match_data=match_data[:,0]
    #Y_data = dnn.convert_to_one_hot_threeLabel(Y_data,match_data)
    Y_data = dnn.convert_to_one_hot_threeLabel(Y_data,match_data)
    
    ############################# Model trainning ########################################     
    #1.select the coloum for train features
    select_index_feature = [branch_to_index[name] for name in select_item]
    X_data0 = select_and_convert( X_data,select_index_feature)
    #2.select row for qq and gg plane type and the number for gg and qq remain the        
    indices_type = dnn.balance_data_multiLabel(Y_data)
    X_data1 = X_data0[indices_type]
    Y_data0 = Y_data[indices_type]
    #3.select the raw for test and validate
    select_index_train,select_index_val = dnn.custom_train_test_split_indices(len(X_data1),test_size=0.2,random_state=42)
    X_data2_train = X_data1[select_index_train]
    X_data2_val = X_data1[select_index_val]
    Y_data1_train = Y_data0[select_index_train]
    Y_data1_val = Y_data0[select_index_val]
    #4. define scaler for train input
    scaler = dnn.ConditionalScaler(use_scaling=False)
    X_data3_train = scaler.fit_transform(X_data2_train)
    X_data3_val = scaler.transform(X_data2_val)
    ######################### model train : X_data3_train , X_data3_val , Y_data1_train , Y_data1_val #####################################
    hidden_units=[128,128,32]
    learning_rate=0.001
    l2_reg=0
    model = dnn.train_and_save_model_MultiLabel(X_train=X_data3_train,X_val=X_data3_val,Y_train=Y_data1_train,Y_val=Y_data1_val,hidden_units=hidden_units,learning_rate=learning_rate,l2_reg=l2_reg)
    folder_name = "ML/train_out/"+suffix+"threelabel"
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
    model.save("ML/model/"+suffix+"threelabel")
    
    
    ##########################  Saving root file ############################################################################################
    root_filename = folder_name+"/"
    train_val_index0 = dnn.modify_array_advanced(indices_type,select_index_train,select_index_val)
    Xdata_full = X_data + X_data_supp
    train_val_index = dnn.ShapeAlign(train_val_index0,X_data_shape) +dnn.CreateAlignedShapeArr(X_data_supp_shape, -1)
    spin_full = dnn.CreateAlignedShapeArr(X_data_shape, 0) + dnn.CreateAlignedShapeArr(X_data_supp_shape, 1)
    Xdata_full_with_spin = [row + [new_value] for row, new_value in zip(Xdata_full, spin_full)]
    branch_names.append("spin")
    branch_types.append("vector<int>")
    
    ## X data select feature for prediction
    X_data_full_shape = X_data_shape + X_data_supp_shape
    Xdata_full_with_spin_selcolumn = select_and_convert( Xdata_full_with_spin,select_index_feature)
    X_data_predict = scaler.transform(Xdata_full_with_spin_selcolumn)
    full_predictions = model.predict(X_data_predict,batch_size=1024)
    full_predictions =  dnn.ShapeAlign(full_predictions.T,X_data_full_shape)
    ## expand prediction and validation index
    n_classes = len(full_predictions)
    for i in range(n_classes):
        branch_names.append(f'score{i}'+level_suffix) 
        branch_types.append('vector<double>') 
        Xdata_full_with_spin = [row + [new_value] for row, new_value in zip(Xdata_full_with_spin, full_predictions[i])]

    branch_names.append('validate'+level_suffix) 
    branch_types.append('vector<int>') 
    Xdata_full_with_spin = [row + [new_value] for row, new_value in zip(Xdata_full_with_spin, train_val_index)]
    ###### Save to root file ###############
    dnn.save_multiclass_predictions_to_root(Xdata_full_with_spin,root_filename=root_filename,branch_names=branch_names,branch_types=branch_types)
    ######################## roc curve ##############################
    train_val_index = dnn.modify_array_advanced(indices_type,select_index_train,select_index_val)
    X_data_train = X_data0[train_val_index0==0]
    X_data_val = X_data0[train_val_index0==1]
    X_data_train = scaler.transform(X_data_train)
    X_data_val = scaler.transform(X_data_val)
    Y_data_train = Y_data[train_val_index==0]
    Y_data_val = Y_data[train_val_index==1]

    predictions_train = model.predict(X_data_train,batch_size=1024)
    predictions_val = model.predict(X_data_val,batch_size=1024)
    dnn.plot_roc_curve_threeLabel(Y_data_train,predictions_train,root_filename+"_train")
    dnn.plot_roc_curve_threeLabel(Y_data_val,predictions_val,root_filename+"_val")

    
if __name__ == "__main__":
    # 创建 ArgumentParser 对象
    parser = argparse.ArgumentParser(description="Run the binary classification model.")
    parser.add_argument('--sample_path0', type=str, default='X:/home/zlin/Machine_learning/test/validation_data_CA.csv', help='Path to the sample root file.')
    parser.add_argument('--sample_path1', type=str, default='X:/home/zlin/Machine_learning/test/validation_data_CA.csv', help='Path to the sample root file.')

    parser.add_argument('--select_opt', type=int, default=-1, help='Option for selecting features.')
    parser.add_argument('--entries', type=int, default=-1, help='Option for training entries.')
    parser.add_argument('--suffix', type=str, default="", help='Suffix string for the folder saved model and root file')
    # 解析参数
    args = parser.parse_args()
    main(args)