
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
from array import array
import ROOT


def LoadData(sample_path, entries):
    tqdm.pandas(desc="Reading CSV")
    file_size = os.path.getsize(sample_path)
    sample_df = pd.read_csv(sample_path, nrows=10000)
    sample_size = sample_df.memory_usage(deep=True).sum()
    size_per_row = sample_size / len(sample_df)
    estimated_total_rows = max(int(file_size // size_per_row) - 1, 0)
    if entries == -1:
        # 如果entries为-1，则计划读取整个文件
        total_rows = estimated_total_rows
    else:
        # 否则，使用min函数取entries和估计总行数中较小的一个
        total_rows = min(entries, estimated_total_rows)

    chunks = []
    chunksize = 10000
    
    with tqdm(total=total_rows, desc='Loading', unit='row') as progress_bar:
        # 读取文件
        reader = pd.read_csv(sample_path, chunksize=chunksize, header=0)
        for chunk in reader:
            chunks.append(chunk)
            progress_bar.update(chunk.shape[0])
            
            if entries != -1:
                # 计算已经读取的行数
                if sum(map(len, chunks)) >= entries:
                    # 如果读取的行数达到指定的entries，则停止读取
                    break

        # 合并chunks中的所有DataFrame
        data = pd.concat(chunks, ignore_index=True)
        
        # 如果行数超过了entries，我们只保留前entries行
        if entries != -1 and len(data) > entries:
            data = data.head(entries)

    print("Complete loading data.")
    
    # 获取DataFrame的列名
    column_names = data.columns.tolist()

    return data, column_names
def LoadROOTFile(sample_path, entries,branches_name=[],select_opt=""):
    file = ROOT.TFile(sample_path)
    tree = file.Get("DataInfo")
    nentries = min(tree.GetEntries(), entries)
    if entries == -1:
        nentries=tree.GetEntries()
    branches = {}
    branch_buffers = {}
    branch_names=[]
    # Set up branch reading
    for branch_name0 in branches_name:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            if branch_name0!=branch_name:
                continue
            branch_names.append(branch_name)
            leaf = branch.GetLeaf(branch_name)
            leaf_type = leaf.GetTypeName()
            if 'Double' in leaf_type:
                branch_buffers[branch_name] = array('d', [0])
            elif 'Float' in leaf_type:
                branch_buffers[branch_name] = array('f', [0])
            elif 'Int' in leaf_type:
                branch_buffers[branch_name] = array('i', [0])
            else:
                continue  # Add other types as necessary
            tree.SetBranchAddress(branch_name, branch_buffers[branch_name])
            branches[branch_name] = []
    if len(branches_name)==0:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            branch_names.append(branch_name)
            leaf = branch.GetLeaf(branch_name)
            leaf_type = leaf.GetTypeName()
            if 'Double' in leaf_type:
                branch_buffers[branch_name] = array('d', [0])
            elif 'Float' in leaf_type:
                branch_buffers[branch_name] = array('f', [0])
            elif 'Int' in leaf_type:
                branch_buffers[branch_name] = array('i', [0])
            else:
                continue  # Add other types as necessary
            tree.SetBranchAddress(branch_name, branch_buffers[branch_name])
            branches[branch_name] = []

    # Read data and fill arrays
    variable_name,number=split_and_format(select_opt)
    entries=0
    for i in tqdm(range(nentries)):
        tree.GetEntry(i)
        if select_opt!="":
            if branch_buffers[variable_name][0]<=number:
                continue
        for name, buffer in branch_buffers.items():
                branches[name].append(buffer[0])
        entries=entries+1
    file.Close()

    # Convert to numpy array
    feature_names = list(branches.keys())
    if len(branches_name)==0:
        feature_names = branches_name
    print(len(feature_names))
    num_features = len(feature_names)
    data_array = np.zeros((entries, num_features), dtype=float)
    
    for i, name in enumerate(feature_names):
        data_array[:, i] = branches[name]

    # Create mappings
    branch_to_index = {name: i for i, name in enumerate(feature_names)}
    index_to_branch = {i: name for i, name in enumerate(feature_names)}
    print(index_to_branch)
    return data_array, branch_to_index, index_to_branch ,branch_names
def split_and_format(expression):
    # 假设表达式格式为 "变量名>数字"
    parts = expression.split('>')  # 使用 > 符号进行分割
    variable_name = parts[0].strip()  # 获取变量名并去除两边可能的空格
    number = parts[1].strip()  # 获取数字并去除两边可能的空格
    number=float(number)
    return variable_name,number

def convert_to_one_hot(labels):
    one_hot_labels = np.zeros((labels.shape[0], 3))
    for i, label in enumerate(labels):
        if np.array_equal(label, [1, 0]):
            one_hot_labels[i, 0] = 1  # 类别0
        elif np.array_equal(label, [0, 1]):
            one_hot_labels[i, 1] = 1  # 类别1
        elif np.array_equal(label, [0, 0]):
            one_hot_labels[i, 2] = 1  # 类别2
def convert_to_binary(labels):
    binary_labels = np.zeros(labels.shape[0])
    for i, label in enumerate(labels):
        if np.array_equal(label, [1, 0]):
            binary_labels[i] = 0  # 类别0
        elif np.array_equal(label, [0, 1]):
            binary_labels[i] = 1  # 类别1
        else:
            binary_labels[i] = -1
    return binary_labels
def prepare_data_for_dnn(data_dict, features):
    feature_data = []
    num_entries = len(data_dict[features[0]]) 
    for i in range(num_entries):
        event_features = [data_dict[feature][i] for feature in features]
        feature_data.append(event_features)
    return np.array(feature_data)
