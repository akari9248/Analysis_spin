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
import numpy as np
import dnn
from tensorflow.keras.models import load_model # type: ignore
def main(args):
    sample_path0 = args.sample_path0
    model_path = args.model_path
    select_opt = args.select_opt
    suffix = args.suffix
    sample_filename = "kto4"
    entries=args.entries
    X_data, branch_to_index, index_to_branch,branch_names = dnn.LoadROOTFile(sample_paths=[sample_path0],entries=args.entries,branches_name=["Nparticles_2","Ntracks_2","pTD_2","sigma1_2","sigma2_2","sigma_2","Nparticles_3","Ntracks_3","pTD_3","sigma1_3","sigma2_3","sigma_3","pt_3","eta_3","phi_3","e_3","Nparticles_4","Ntracks_4","pTD_4","sigma1_4","sigma2_4","sigma_4","pt_4","eta_4","phi_4","e_4","z1","z2","DeltaR","kt","Phi","kt0","GeneratorWeight","PassPileUpRm","NextPassedNumber"])
    select_item = [
        ["Nparticles_2","Ntracks_2","pTD_2","sigma1_2","sigma2_2","sigma_2","Nparticles_3","Ntracks_3","pTD_3","sigma1_3","sigma2_3","sigma_3","Nparticles_4","Ntracks_4","pTD_4","sigma1_4","sigma2_4","sigma_4","z1","z2","DeltaR","kt"]
    ]
    #opt 1 full 2: veto kt 3: veto kt deltaR  3: veto kt theta
    for i in range(len(select_item)):
        if select_opt!=-1:
            i = select_opt

        #1.select the coloum for train features
        select_index_feature = [branch_to_index[name] for name in select_item[i]]
        model = load_model(model_path)
        folder_name = suffix
        if not os.path.exists(folder_name):
            os.makedirs(folder_name)
        ##########################  Saving root file ############################################################################################
        root_filename = folder_name+f"/"
        X_data_predict=X_data[:, select_index_feature]
        full_predictions = model.predict(X_data_predict,batch_size=1024)
        dnn.save_multiclass_predictions_to_root(X_data,np.ones(len(X_data)),full_predictions,root_filename=root_filename,branch_name=branch_names)

        if select_opt!=-1:
            break

if __name__ == "__main__":
    # 创建 ArgumentParser 对象
    parser = argparse.ArgumentParser(description="Run the binary classification model.")
    parser.add_argument('--sample_path0', type=str, default='', help='Path to the sample root file.')
    parser.add_argument('--model_path', type=str, default='ML/model/fourLabels_j2pt80_120', help='Path to the trained model.')

    parser.add_argument('--select_opt', type=int, default=-1, help='Option for selecting features.')
    parser.add_argument('--entries', type=int, default=-1, help='Option for training entries.')
    parser.add_argument('--suffix', type=str, default="", help='Suffix string for the folder saved model and root file')
    # 解析参数
    args = parser.parse_args()
    main(args)