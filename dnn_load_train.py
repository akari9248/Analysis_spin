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
import dnn
from tensorflow.keras.models import load_model # type: ignore
    

def main(args):
    sample_path0 = args.sample_path0
    sample_path1 = args.sample_path1
    model_path = args.model_path
    suffix =args.suffix
    mode= args.mode
    
    folder_name = "ML/train_out/threelabel"+suffix
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
    root_filename = folder_name+"/"
    
    select_item = ["nparticles2","ntracks2","pTD2","sigma12","sigma22","sigma2","nparticles3","ntracks3","pTD3","sigma13","sigma23","sigma3","nparticles4","ntracks4","pTD4","sigma14","sigma24","sigma4","z1","z2","deltaR2","kt2"]
    if mode == "Train":
        match_index=["match2"]
        Y_data_index=["type2"]
        level_prefix=""
        level_suffix="_Hadron"
        X_data, branch_to_index, index_to_branch,branch_names,branch_types = dnn.LoadROOTFile(sample_paths=[sample_path0],entries=args.entries)
        X_data_supp, *_ = dnn.LoadROOTFile(sample_paths=[sample_path1],entries=args.entries)
        
        X_data0,X_data_shape =  dnn.Extract_flat_features(X_data,branch_to_index,select_item,level_prefix,level_suffix,return_shape=True)
        X_data_supp0,X_data_supp_shape =  dnn.Extract_flat_features(X_data_supp,branch_to_index,select_item,level_prefix,level_suffix,return_shape=True)
        Y_data,*_ = dnn.Extract_flat_features(X_data,branch_to_index,Y_data_index,level_prefix,level_suffix,return_shape=True)
        match_data,*_ = dnn.Extract_flat_features(X_data,branch_to_index,match_index,prefix="",suffix="",return_shape=True)
        match_data=match_data[:,0]
        Y_data0 = dnn.convert_to_one_hot_threeLabel(Y_data,match_data)
        indices_type = dnn.balance_data_multiLabel(Y_data0)
        X_data1 = X_data0[indices_type]
        Y_data1 = Y_data0[indices_type]
        select_index_train,select_index_val = dnn.custom_train_test_split_indices(len(X_data1),test_size=0.2,random_state=42)
        X_data1_train = X_data1[select_index_train]
        X_data1_val = X_data1[select_index_val]
        Y_data1_train = Y_data1[select_index_train]
        Y_data1_val = Y_data1[select_index_val]
        ######################### model train : X_data3_train , X_data3_val , Y_data1_train , Y_data1_val #####################################
        hidden_units=[128,128,32]
        learning_rate=0.001
        l2_reg=0
        model = dnn.train_and_save_model_MultiLabel(X_train=X_data1_train,X_val=X_data1_val,Y_train=Y_data1_train,Y_val=Y_data1_val,hidden_units=hidden_units,learning_rate=learning_rate,l2_reg=l2_reg)
        model.save("ML/model/threelabel"+suffix)
        ######################## roc curve ##############################
        predictions_train = model.predict(X_data1_train,batch_size=1024)
        predictions_val = model.predict(X_data1_val,batch_size=1024)
        dnn.plot_roc_curve_threeLabel(Y_data1_train,predictions_train,root_filename+"train"+suffix)
        dnn.plot_roc_curve_threeLabel(Y_data1_val,predictions_val,root_filename+"val"+suffix)
        ##########################  Saving root file ############################################################################################
        ###### X data full
        Xdata_full = X_data + X_data_supp
        ###### Add validation branch ##########
        train_val_index0 = dnn.modify_array_advanced(indices_type,select_index_train,select_index_val)
        train_val_index = dnn.ShapeAlign(train_val_index0,X_data_shape) +dnn.CreateAlignedShapeArr(X_data_supp_shape, -1)
        branch_names.append('validate'+level_suffix) 
        branch_types.append('vector<int>') 
        Xdata_full = [row + [new_value] for row, new_value in zip(Xdata_full, train_val_index)]
        ###### Add spin branch ##########
        spin_full = dnn.CreateAlignedShapeArr(X_data_shape, 0) + dnn.CreateAlignedShapeArr(X_data_supp_shape, 1)
        Xdata_full = [row + [new_value] for row, new_value in zip(Xdata_full, spin_full)]
        branch_names.append("spin")
        branch_types.append("vector<int>")
        ###### Add inputs for prediction ##########
        X_data_predict = np.concatenate((X_data0, X_data_supp0), axis=0)
        X_data_full_shape = X_data_shape + X_data_supp_shape
        full_predictions = model.predict(X_data_predict,batch_size=1024)
        full_predictions =  dnn.ShapeAlign(full_predictions.T,X_data_full_shape)
        n_classes = len(full_predictions)
        for i in range(n_classes):
            branch_names.append(level_prefix+f'score{i}'+level_suffix) 
            branch_types.append('vector<double>') 
            Xdata_full = [row + [new_value] for row, new_value in zip(Xdata_full, full_predictions[i])]
    if mode == "Prediction":
        model = load_model(model_path)
        Xdata_full, branch_to_index, index_to_branch,branch_names,branch_types = dnn.LoadROOTFile(sample_paths=[sample_path0],entries=args.entries)
        level_prefixs=[]
        level_suffixs=[]
        for name in branch_names:
            if "Gen" in name:
                level_prefixs.append("Gen_")
            elif "Reco" in name:
                level_prefixs.append("Reco_")
            if "Hadron" in name:
                level_suffixs.append("_Hadron")
        if len(level_prefixs) == 0:
            level_prefixs=[""]
        if len(level_suffixs) == 0:
            level_suffixs=[""]   
        for level_prefix in level_prefixs:
            for level_suffix in level_prefixs:
                X_data_predict,X_data_shape =  dnn.Extract_flat_features(Xdata_full,branch_to_index,select_item,level_prefix,level_suffix,return_shape=True)
                full_predictions = model.predict(X_data_predict,batch_size=1024)
                full_predictions =  dnn.ShapeAlign(full_predictions.T,X_data_shape)
                n_classes = len(full_predictions)
                for i in range(n_classes):
                    branch_names.append(level_prefix+f'score{i}'+level_suffix) 
                    branch_types.append('vector<double>') 
                    Xdata_full = [row + [new_value] for row, new_value in zip(Xdata_full, full_predictions[i])]
    ###### Save to root file ###############
    dnn.save_multiclass_predictions_to_root(Xdata_full,root_filename=root_filename,branch_names=branch_names,branch_types=branch_types)
    
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Run the binary classification model.")
    parser.add_argument('--sample_path0', type=str, default='', help='Path to the root file for training or prediction (typically spin-off samples).')
    parser.add_argument('--sample_path1', type=str, default='', help='Path to the root file for validation (typically spin-on samples).')

    parser.add_argument('--mode', type=str, default="Prediction", help='Mode of operation: "Train" for model training, "Prediction" for model prediction.')
    parser.add_argument('--model_path', type=str, default="", help='Path to the model for prediction (required if mode is "Prediction").')
    parser.add_argument('--entries', type=int, default=-1, help='Number of entries for training.')
    parser.add_argument('--suffix', type=str, default="", help='Suffix for the folder where the model and root file are saved.')

    args = parser.parse_args()
    main(args)