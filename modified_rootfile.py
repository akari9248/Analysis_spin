import sys, os
path = "python" 
sys.path.append(path)

import numpy as np
import argparse
import dnn
import os
import math
import matplotlib.pyplot as plt

import ROOT

def main(args):
    sample_path = args.sample_path
    select_opt = args.select_opt
    suffix = args.suffix
    sample_filename = sample_path.split("/")[-1].split(".")[0]
    entries=args.entries
    parton_types=["Parton","Hadron"]
    spins=["spin_off","spin_on"]
    
    for parton_type in parton_types:
        X_data, branch_to_index, index_to_branch,branch_names = dnn.LoadROOTFile(sample_path=sample_path,entries=args.entries,branches_name=["pt1_"+parton_type,"eta1_"+parton_type, "phi1_"+parton_type, "e1_"+parton_type,"pt3_"+parton_type,"eta3_"+parton_type, "phi3_"+parton_type, "e3_"+parton_type,"pt4_"+parton_type,"eta4_"+parton_type, "phi4_"+parton_type, "e4_"+parton_type,"phi_"+parton_type,"isqq_"+parton_type,"isgg_"+parton_type,"spin","kt2_"+parton_type],select_opt="kt2_"+parton_type+">4")
        for spintype in spins:
            branch_names_root=["pt1","eta1","phi1","e1","pt2","eta2","phi2","e2","pt3","eta3","phi3","e3","phi","type"]
            if spintype == "spin_off":
                X_data0 = X_data[X_data[:, 15] == 0]
            else:
                X_data0 = X_data[X_data[:, 15] == 1]
            X_data1 = X_data0[:,0:13]
            new_column = X_data0[:, 13] * 2 + X_data0[:, 14]
            new_column = new_column.reshape(-1, 1)
            X_data2 = np.append(X_data1, new_column, axis=1)
            f = ROOT.TFile(parton_type+spintype+".root", "RECREATE")
            tree = ROOT.TTree("DataInfo", "DataInfo")
            branch_vars = {name: np.zeros(1, dtype=float) for name in branch_names_root}
            branch_var_int = {name: np.zeros(1, dtype=int) for name in branch_names_root}
            for name in branch_names_root:
                if name!="type":
                    tree.Branch(name, branch_vars[name], name + "/D")
                else:
                    tree.Branch(name, branch_var_int[name], name + "/I")
            for i in range(X_data2.shape[0]):
                for j, name in enumerate(branch_names_root):
                    if name!="type":
                        branch_vars[name][0] = X_data2[i, j]
                    else:
                        type_value = X_data2[i, j].astype(int)
                        branch_var_int[name][0] = type_value
                tree.Fill()
            f.Write()
            f.Close()


    
if __name__ == "__main__":
    # 创建 ArgumentParser 对象
    parser = argparse.ArgumentParser(description="Run the binary classification model.")
    parser.add_argument('--sample_path', type=str, default='X:/home/zlin/Machine_learning/test/validation_data_CA.csv', help='Path to the sample CSV file.')
    parser.add_argument('--select_opt', type=int, default=-1, help='Option for selecting features.')
    parser.add_argument('--entries', type=int, default=-1, help='Option for training entries.')
    parser.add_argument('--suffix', type=str, default="", help='Suffix string for the folder saved model and root file')
    # 解析参数
    args = parser.parse_args()
    main(args)
