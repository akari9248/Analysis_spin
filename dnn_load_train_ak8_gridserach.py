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
    
    dir_path = os.path.dirname(sample_path0)
    basefolder_name = os.path.basename(dir_path)+"_FourLabel1/"    
    select_item = ["nparticles2","ntracks2","pTD2","sigma12","sigma22","sigma2","nparticles3","ntracks3","pTD3","sigma13","sigma23","sigma3","nparticles4","ntracks4","pTD4","sigma14","sigma24","sigma4","z1","z2","deltaR2","kt2"]
    
    entrynum_iter=100000
    #entrynum_iter=10
    tree,nentries =  dnn.LoadTree(sample_paths=[sample_path0])
    if nentries>args.entries and args.entries!=-1:
        nentries = args.entries
    iter_num = math.ceil(nentries / entrynum_iter)
    model = tf.keras.Sequential()
    X_data1_train_full=np.empty((0, 0))
    X_data1_val_full=np.empty((0, 0))
    Y_data1_train_full=np.empty((0, 0))
    Y_data1_val_full=np.empty((0, 0))
    train_val_index_full=np.empty((0, 0))
    for iter in range(iter_num):
        X_data, branch_to_index, index_to_branch, branch_names, branch_types = dnn.LoadROOTFile(sample_paths=[sample_path0],entries=entrynum_iter,entry_begin=iter*entrynum_iter)
        if mode == "Train":
            folder_name = '/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets/Train/'+basefolder_name
            if not os.path.exists(folder_name):
                os.makedirs(folder_name)
            
            # input setting
            match_index=["match2"]
            Y_data_index=["type2"]
            final_descri3_index=["final_descri3"]
            final_descri4_index=["final_descri4"]
            level_prefix="Reco"
            level_suffix=""
            
            # input features/flavours
            X_data0, X_data_shape =  dnn.Extract_flat_features(X_data, branch_to_index, select_item, level_prefix, level_suffix, return_shape=True)
            Y_data, *_ = dnn.Extract_flat_features(X_data, branch_to_index, Y_data_index, level_prefix, level_suffix, return_shape=True)
            match_data, *_ = dnn.Extract_flat_features(X_data, branch_to_index, match_index, prefix="", suffix="", return_shape=True)
            final_descri3_data, *_ = dnn.Extract_flat_features(X_data, branch_to_index, final_descri3_index, level_prefix, level_suffix, return_shape=True)
            final_descri4_data, *_ = dnn.Extract_flat_features(X_data, branch_to_index, final_descri4_index, level_prefix, level_suffix, return_shape=True)
            match_data = match_data[:,0]
            final_descri3_data = final_descri3_data[:,0]
            final_descri4_data = final_descri4_data[:,0]
            
            # hot label and balance data
            Y_data0 = dnn.convert_to_one_hot_fourlabel3(Y_data,match_data,final_descri3_data,final_descri4_data)
            indices_type = dnn.balance_data_multiLabel(Y_data0)
            
            # get X, Y
            X_data1 = X_data0[indices_type]
            Y_data1 = Y_data0[indices_type]
            final_nan_mask = np.isnan(X_data1).any(axis=1)
            X_data1 = X_data1[~final_nan_mask]
            Y_data1 = Y_data1[~final_nan_mask]
            
            # split into training, validation and testing
            select_index_train, select_index_val, select_index_test = dnn.custom_train_val_test_split_indices(len(X_data1), val_size=0.2, test_size=0.2, random_state=42)
            X_data1_train = X_data1[select_index_train]
            X_data1_val = X_data1[select_index_val]
            X_data1_test = X_data1[select_index_test]
            Y_data1_train = Y_data1[select_index_train]
            Y_data1_val = Y_data1[select_index_val]
            Y_data1_test = Y_data1[select_index_test]
            
            if iter == 0:
                X_data1_train_full=X_data1_train 
                X_data1_val_full=X_data1_val
                X_data1_test_full=X_data1_test
                Y_data1_train_full=Y_data1_train
                Y_data1_val_full=Y_data1_val
                Y_data1_test_full=Y_data1_test
            else:
                X_data1_train_full = np.concatenate((X_data1_train_full, X_data1_train), axis=0)
                X_data1_val_full = np.concatenate((X_data1_val_full, X_data1_val), axis=0)
                X_data1_test_full = np.concatenate((X_data1_test_full, X_data1_test), axis=0)
                Y_data1_train_full = np.concatenate((Y_data1_train_full, Y_data1_train), axis=0)
                Y_data1_val_full = np.concatenate((Y_data1_val_full, Y_data1_val), axis=0)
                Y_data1_test_full = np.concatenate((Y_data1_test_full, Y_data1_test), axis=0)
                
            assert not np.isnan(X_data1_train).any(), "NaN for training set!"
            assert not np.isnan(X_data1_val).any(), "NaN for validation set!"
            
            ###### Add validation branch ##########
            train_val_index0 = dnn.modify_array_advanced(indices_type, select_index_train, select_index_val)
            train_val_index = dnn.ShapeAlign(train_val_index0, X_data_shape) 
            train_val_index_full = train_val_index_full + train_val_index if len(train_val_index_full) != 0 else train_val_index       
            
            del X_data, X_data0, X_data1 
            del Y_data, Y_data0, Y_data1
            del match_data, select_index_train, select_index_val 
            del X_data1_train, X_data1_val, Y_data1_train, Y_data1_val, train_val_index0, train_val_index
        if mode == "Prediction":
            folder_name = '/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets_newflavour/Prediction_ak8_730_gridsearch/'+basefolder_name
            if not os.path.exists(folder_name):
                os.makedirs(folder_name)
            model = load_model(model_path)
            Xdata_full = X_data
            level_prefixs = set()
            level_suffixs = set()
            for name in branch_names:
                if "Gen" in name and name !='GeneratorWeight':
                    level_prefixs.add("Gen")
                elif "Parton" in name and "_Parton" not in name:
                    level_prefixs.add("Parton")
                elif "Reco" in name and name !='RecoBtag_value':
                    level_prefixs.add("Reco")
                if "_Hadron" in name:
                    level_suffixs.add("_Hadron")
            level_prefixs = list(level_prefixs)
            level_suffixs = list(level_suffixs)
            if len(level_prefixs) == 0:
                level_prefixs=[""]
            if len(level_suffixs) == 0:
                level_suffixs=[""]   
            for level_prefix in level_prefixs:
                for level_suffix in level_suffixs:
                    
                    X_data_predict,X_data_shape =  dnn.Extract_flat_features(Xdata_full,branch_to_index,select_item,level_prefix,level_suffix,return_shape=True)
                    full_predictions = model.predict(X_data_predict,batch_size=1024)
                    n_classes = full_predictions.shape[1]
                    full_predictions =  dnn.ShapeAlign(full_predictions.T,X_data_shape)
                    for i in range(n_classes):
                        branch_names.append(level_prefix+f'score{i}'+level_suffix) 
                        branch_types.append('vector<double>') 
                        Xdata_full = [row + [new_value] for row, new_value in zip(Xdata_full, full_predictions[i])]
            if len(args.train_val_index_full)>0:
                entry_end = (iter+1)*entrynum_iter if len(args.train_val_index_full) > (iter+1)*entrynum_iter else len(args.train_val_index_full)
                train_val_index = args.train_val_index_full[iter*entrynum_iter:entry_end]
                branch_names.append('validate'+level_suffix) 
                branch_types.append('vector<int>') 
                Xdata_full = [row + [new_value] for row, new_value in zip(Xdata_full, train_val_index)]
            print("Save to root file")
            ###### Save to root file ###############
            dnn.save_multiclass_predictions_to_root(Xdata_full,root_filename=folder_name+f"Chunk{iter}",branch_names=branch_names,branch_types=branch_types)
            del X_data, Xdata_full, X_data_predict, full_predictions
    if mode == "Train":
        param_grid = {
            'model__hidden_units': [[256, 128, 128], [256, 128, 32], [64, 32, 32]],
            'model__learning_rate': [0.001, 0.0005],
            'model__l2_reg': [0, 0.0001],
            'model__batch_size': [128, 256, 512],
            'model__dropout_rate': [0.0, 0.1, 0.3, 0.5]
        }
        best_model, all_metrics = dnn.grid_search(X_train=X_data1_train_full,X_val=X_data1_val_full,Y_train=Y_data1_train_full,Y_val=Y_data1_val_full, param_grid=param_grid,sample_path1=sample_path1)
        
        test_dir = os.path.join(sample_path1, 'test_results')
        if not os.path.exists(test_dir):
            os.makedirs(test_dir)
        
        test_loss, test_accuracy = best_model.evaluate(
            X_data1_test_full, 
            Y_data1_test_full, 
            verbose=1
        )
        print(f"Test loss: {test_loss:.4f}")
        print(f"Test accuracy: {test_accuracy:.4f}")
        
        y_pred_test = best_model.predict(X_data1_test_full)
        y_true_test = Y_data1_test_full
        
        y_pred_classes = np.argmax(y_pred_test, axis=1)
        y_true_classes = np.argmax(y_true_test, axis=1)
        
        from sklearn.metrics import f1_score, precision_score, recall_score, roc_curve, auc
        test_f1 = f1_score(y_true_classes, y_pred_classes, average='micro')
        test_precision = precision_score(y_true_classes, y_pred_classes, average='macro')
        test_recall = recall_score(y_true_classes, y_pred_classes, average='macro')
        
        test_metrics = {
            'test_loss': test_loss,
            'test_accuracy': test_accuracy,
            'test_f1': test_f1,
            'test_precision': test_precision,
            'test_recall': test_recall
        }
        
        import json
        with open(os.path.join(test_dir, 'test_metrics.json'), 'w') as f:
            json.dump(test_metrics, f, indent=2)
        
        # 5. 可视化结果
        # ROC曲线
        plt.figure(figsize=(10, 8))
        for i in range(y_true_test.shape[1]):
            fpr_test, tpr_test, _ = roc_curve(y_true_test[:, i], y_pred_test[:, i])
            roc_auc_test = auc(fpr_test, tpr_test)
            plt.plot(fpr_test, tpr_test, label=f'Test ROC Curve - Label {i} (AUC = {roc_auc_test:.4f})')
        plt.plot([0, 1], [0, 1], linestyle='--', color='grey')
        plt.title('ROC Curves for Test Set', fontsize=18)
        plt.xlabel('False Positive Rate', fontsize=18)
        plt.ylabel('True Positive Rate', fontsize=18)
        plt.legend(loc='lower right', fontsize=12)
        plt.savefig(os.path.join(test_dir, 'roc_curves_test.pdf'), format='pdf')
        plt.close()
        
        # 混淆矩阵
        confusion_matrix_dir = os.path.join(test_dir, 'confusion_matrix')
        if not os.path.exists(confusion_matrix_dir):
            os.makedirs(confusion_matrix_dir)
        
        dnn.plot_confusion_matrix(
            y_true_test, 
            y_pred_test, 
            title='Confusion Matrix - Test Set (Unnormalized)',
            filename=os.path.join(confusion_matrix_dir, 'confusion_matrix_test_unnormalized.pdf')
        )
        dnn.plot_confusion_matrix(
            y_true_test, 
            y_pred_test, 
            title='Confusion Matrix - Test Set (X-axis Normalized)',
            filename=os.path.join(confusion_matrix_dir, 'confusion_matrix_test_x_normalized.pdf'),
            normalize='pred',
        )
        dnn.plot_confusion_matrix(
            y_true_test, 
            y_pred_test, 
            title='Confusion Matrix - Test Set (Y-axis Normalized)',
            filename=os.path.join(confusion_matrix_dir, 'confusion_matrix_test_y_normalized.pdf'),
            normalize='true',
        )
    
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Run the binary classification model.")
    parser.add_argument('--sample_path0', type=str, default='', help='Path to the root file for training or prediction (typically spin-off samples).')
    parser.add_argument('--sample_path1', type=str, default='', help='Path to the root file for validation (typically spin-on samples).')

    parser.add_argument('--mode', type=str, default="Prediction", help='Mode of operation: "Train" for model training, "Prediction" for model prediction.')
    parser.add_argument('--model_path', type=str, default="", help='Path to the model for prediction (required if mode is "Prediction").')
    parser.add_argument('--entries', type=int, default=-1, help='Number of entries for training or prediction.')
    parser.add_argument('--suffix', type=str, default="", help='Suffix for the name of saved model and roc curve.')
    
    args = parser.parse_args()
    args.train_val_index_full =[]
    main(args)