import xgboost as xgb
from sklearn.metrics import accuracy_score
from keras.optimizers import Adam
import tensorflow as tf
from tensorflow.keras import layers,models,regularizers # type: ignore
import pandas as pd
import uproot
import numpy as np
import argparse
from sklearn.model_selection import train_test_split, GridSearchCV, ParameterGrid
from tqdm import tqdm
import os
import math
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, auc
from sklearn.metrics import roc_auc_score
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from array import array
import ROOT
from sklearn.utils import class_weight
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import accuracy_score
from tqdm import tqdm
import joblib
import awkward as ak
def handleXdata(X_data1):
    return X_data1
    ntracks2_pt = X_data1[:, 3] / X_data1[:, 7]
    ntracks3_pt = X_data1[:, 4] / X_data1[:, 8]
    nparticles2_pt = X_data1[:, 5] / X_data1[:, 7]
    nparticles3_pt = X_data1[:, 6] / X_data1[:, 8]

    ntracks2_pt = ntracks2_pt[:, np.newaxis]
    ntracks3_pt = ntracks3_pt[:, np.newaxis]
    nparticles2_pt = nparticles2_pt[:, np.newaxis]
    nparticles3_pt = nparticles3_pt[:, np.newaxis]
    #return X_data1
    X_data1 = np.column_stack((X_data1[:,0:3], nparticles2_pt, nparticles3_pt))
    return X_data1

class ConditionalScaler:
    def __init__(self, use_scaling=True):
        self.use_scaling = use_scaling
        self.mean_ = None
        self.scale_ = None

    def fit(self, X):
        if self.use_scaling:
            self.mean_ = np.mean(X, axis=0)
            self.scale_ = np.std(X, axis=0)
        return self

    def transform(self, X):
        if self.use_scaling:
            if self.mean_ is not None and self.scale_ is not None:
                X_scaled = (X - self.mean_) / self.scale_
                return X_scaled
        return X

    def fit_transform(self, X):
        self.fit(X)
        return self.transform(X)
def balance_data(Y_data,seed=None):
    if seed is not None:
        np.random.seed(seed)
    
    not_minus_one_indices = np.where(Y_data != -1)[0]
    filtered_data = Y_data[not_minus_one_indices]
    
    count_0 = np.sum(filtered_data == 0)
    count_1 = np.sum(filtered_data == 1)
    
    min_count = min(count_0, count_1)

    indices_0 = np.random.choice(np.where(filtered_data == 0)[0], min_count, replace=False)
    indices_1 = np.random.choice(np.where(filtered_data == 1)[0], min_count, replace=False)
    
    balanced_indices = np.sort(np.concatenate((not_minus_one_indices[indices_0], not_minus_one_indices[indices_1])))
    
    # 创建一个布尔数组，长度与 Y_data 相同，初始值为 False
    balanced_mask = np.zeros_like(Y_data, dtype=bool)
    # 将平衡索引位置的值设置为 True
    balanced_mask[balanced_indices] = True
    
    return balanced_mask

def balance_data_threeLabel(Y_data,match_data, seed=None):
    if seed is not None:
        np.random.seed(seed)
    
    indices_per_class = []
    for i in range(Y_data.shape[1]):
        indices = np.where((Y_data[:, i] == 1) & (match_data >= 0))[0]
        indices_per_class.append(indices)
    
    min_count = min(len(indices) for indices in indices_per_class)
    
    balanced_indices = []
    for indices in indices_per_class:
        balanced_indices.append(np.random.choice(indices, min_count, replace=False))
    
    balanced_indices = np.sort(np.concatenate(balanced_indices))
    balanced_mask = np.zeros(Y_data.shape[0], dtype=bool)
    balanced_mask[balanced_indices] = True
    
    return balanced_mask
def balance_data_multiLabel(Y_data, seed=None):
    if seed is not None:
        np.random.seed(seed)
    
    indices_per_class = []
    for i in range(Y_data.shape[1]):
        indices = np.where((Y_data[:, i] == 1))[0]
        indices_per_class.append(indices)
    
    min_count = min(len(indices) for indices in indices_per_class)
    
    balanced_indices = []
    for indices in indices_per_class:
        balanced_indices.append(np.random.choice(indices, min_count, replace=False))
    
    balanced_indices = np.sort(np.concatenate(balanced_indices))
    balanced_mask = np.zeros(Y_data.shape[0], dtype=bool)
    balanced_mask[balanced_indices] = True
    
    return balanced_mask
def Selection(X_data,balanced_mask0):
    balanced_mask = X_data[:, 0] > 2
    combined_mask = balanced_mask0 & balanced_mask
    return combined_mask
def modify_array_advanced(data, zero_indices, one_indices):
    modified_array = np.where(data == 0, -1, data)
    non_zero_indices = np.where(data != 0)[0]
    modified_array[non_zero_indices[zero_indices]] = 0
    modified_array[non_zero_indices[one_indices]] = 1
    
    return modified_array
def ShapeAlign(arr_src, arr_dst):
    aligned = []
    if arr_src.ndim == 1:
        index = 0
        for obj in arr_dst:
            length = len(obj)
            aligned.append(arr_src[index:index + length])
            index += length
    
    elif arr_src.ndim == 2:
        for row in arr_src:
            index = 0
            aligned_row = []
            for obj in arr_dst:
                length = np.shape(obj)[0]
                aligned_row.append(row[index:index + length])
                index += length
            aligned.append(aligned_row)
    
    return aligned

def CreateAlignedShapeArr(arr_dst,value=-1):
    result = []
    for obj in arr_dst:
        if len(obj) > 0:
            result.append([value] * len(obj))
        else:
            result.append([])
    return result
def custom_train_test_split_indices(n_samples, test_size=0.2, random_state=None):
    if random_state is not None:
        np.random.seed(random_state)

    # 创建所有样本的索引数组
    indices = np.arange(n_samples)
    
    # 打乱索引
    np.random.shuffle(indices)
    
    # 计算测试集的大小
    test_set_size = int(n_samples * test_size)
    
    # 分割索引为测试集和训练集
    test_idx = indices[:test_set_size]
    train_idx = indices[test_set_size:]
    
    return train_idx, test_idx
def build_binary_classification_model(input_dim,  hidden_units, l2_reg=0.0, dropout_rate=0):
    # 使用Keras的序列模型API
    model = tf.keras.Sequential()
    hidden_layers=len(hidden_units)
    # 添加输入层（输入维度）
    model.add(layers.InputLayer(input_shape=(input_dim,)))

    # 添加隐藏层
    for i in range(hidden_layers):
        model.add(layers.Dense(hidden_units[i], activation='relu', kernel_regularizer=regularizers.l2(l2_reg)))
        model.add(layers.BatchNormalization())
        # Add Dropout here
        model.add(layers.Dropout(dropout_rate))
    # 添加输出层（1个神经元，二分类）
    model.add(layers.Dense(1, activation='sigmoid'))

    return model
def build_ThreeLabel_classification_model(input_dim, hidden_units, l2_reg=0.0, dropout_rate=0):
    # 使用Keras的序列模型API
    model = tf.keras.Sequential()
    hidden_layers = len(hidden_units)
    # 添加输入层（输入维度）
    model.add(layers.InputLayer(input_shape=(input_dim,)))

    # 添加隐藏层
    for i in range(hidden_layers):
        model.add(layers.Dense(hidden_units[i], activation='relu', kernel_regularizer=regularizers.l2(l2_reg)))
        model.add(layers.BatchNormalization())
        # 添加 Dropout
        model.add(layers.Dropout(dropout_rate))

    # 修改输出层：2个输出神经元，使用softmax激活函数
    model.add(layers.Dense(3, activation='softmax'))

    return model
def build_multiLabel_classification_model(input_dim,output_dim, hidden_units, l2_reg=0.0, dropout_rate=0):
    model = tf.keras.Sequential()
    hidden_layers = len(hidden_units)
    model.add(layers.InputLayer(input_shape=(input_dim,)))

    for i in range(hidden_layers):
        model.add(layers.Dense(hidden_units[i], activation='relu', kernel_regularizer=regularizers.l2(l2_reg)))
        model.add(layers.BatchNormalization())
        model.add(layers.Dropout(dropout_rate))

    model.add(layers.Dense(output_dim, activation='softmax'))

    return model
def build_conv1d_classification_model(input_length, num_features, l2_reg=0.0, dropout_rate=0):
    model = tf.keras.Sequential()
    
    # 一维卷积层
    model.add(layers.Conv1D(filters=32, kernel_size=3, activation='relu', input_shape=(input_length, num_features),
                            kernel_regularizer=regularizers.l2(l2_reg)))
    model.add(layers.BatchNormalization())
    model.add(layers.MaxPooling1D(2))
    model.add(layers.Dropout(dropout_rate))
    
    model.add(layers.Conv1D(filters=64, kernel_size=3, activation='relu',
                            kernel_regularizer=regularizers.l2(l2_reg)))
    model.add(layers.BatchNormalization())
    model.add(layers.MaxPooling1D(2))
    model.add(layers.Dropout(dropout_rate))

    # 展平层
    model.add(layers.Flatten())

    # 全连接层
    model.add(layers.Dense(128, activation='relu', kernel_regularizer=regularizers.l2(l2_reg)))
    model.add(layers.Dropout(dropout_rate))

    # 输出层
    model.add(layers.Dense(1, activation='sigmoid'))

    return model
class RocAucCallback(tf.keras.callbacks.Callback):
    def on_train_begin(self, logs={}):
        self.train_roc_auc = []
        self.val_roc_auc = []

    def on_epoch_end(self, epoch, logs={}):
        train_y_pred = self.model.predict(self.training_data[0])
        train_roc_auc = roc_auc_score(self.training_data[1], train_y_pred)
        self.train_roc_auc.append(train_roc_auc)
        
        val_y_pred = self.model.predict(self.validation_data[0])
        val_roc_auc = roc_auc_score(self.validation_data[1], val_y_pred)
        self.val_roc_auc.append(val_roc_auc)

        print(f'\nEpoch {epoch+1}: train ROC AUC: {train_roc_auc:.4f}, val ROC AUC: {val_roc_auc:.4f}')
        return
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

from multiprocessing import Pool, Manager
import time
def read_entries(args):
    tree, branch_buffers, start, end, q, batch_size = args
    branches_name=branch_buffers.keys()
    for branch_name0 in branches_name:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            if branch_name0 != branch_name:
                continue
            leaf = branch.GetLeaf(branch_name)
            leaf_type = leaf.GetTypeName()
            if leaf_type.startswith('vector<double>'):
                branch_buffers[branch_name] = ROOT.std.vector('double')()
            elif leaf_type.startswith('vector<float>'):
                branch_buffers[branch_name] = ROOT.std.vector('float')()
            elif leaf_type.startswith('vector<int>'):
                branch_buffers[branch_name] = ROOT.std.vector('int')()
            elif 'Double' in leaf_type:
                branch_buffers[branch_name] = array('d', [0.0])
            elif 'Float' in leaf_type:
                branch_buffers[branch_name] = array('f', [0.0])
            elif 'Int' in leaf_type:
                branch_buffers[branch_name] = array('i', [0])
            else:
                print(f"Unsupported type for branch {branch_name}: {leaf_type}")
                continue
            tree.SetBranchAddress(branch_name, branch_buffers[branch_name])
    branches = {name: [] for name in branch_buffers.keys()}
    count = 0 
    for i in range(start, end):
        tree.GetEntry(i)
        for name, buffer in branch_buffers.items():
            branches[name].append(list(buffer))
        count += 1
        if count % batch_size == 0:  
            q.put(batch_size)
    if count % batch_size != 0:
        q.put(count % batch_size)
    return branches
def LoadTree(sample_paths):
    tree = ROOT.TChain()
    for sample_path in sample_paths:
        tree.Add(sample_path + "/DataInfo")
    return tree,tree.GetEntries()
def LoadTree2(sample_paths):
    tree = ROOT.TChain()
    for sample_path in sample_paths:
        tree.Add(sample_path + "/DNNTrainTree")
    return tree,tree.GetEntries()
def LoadROOTFile(sample_paths, entries, branches_name=[], select_opt="", num_processes=40,batch_size=1000,entry_begin=0):
    tree = ROOT.TChain()
    for sample_path in sample_paths:
        tree.Add(sample_path + "/DataInfo")
        
    nentries = tree.GetEntries()
    full_entries = nentries
    nentries = min(nentries-entry_begin, entries)
    
    branches = {}
    branch_buffers = {}
    branch_names = []
    branch_types = []
    
    # Set up branch reading
    if len(branches_name) == 0:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            branches_name.append(branch_name)
    
    for branch_name0 in branches_name:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            if branch_name0 != branch_name:
                continue
            branch_names.append(branch_name)
            leaf = branch.GetLeaf(branch_name)
            leaf_type = leaf.GetTypeName()
            branch_types.append(leaf_type)
            if leaf_type.startswith('vector<double>'):
                branch_buffers[branch_name] = ROOT.std.vector('double')()
            elif leaf_type.startswith('vector<float>'):
                branch_buffers[branch_name] = ROOT.std.vector('float')()
            elif leaf_type.startswith('vector<int>'):
                branch_buffers[branch_name] = ROOT.std.vector('int')()
            elif 'Double' in leaf_type:
                branch_buffers[branch_name] = array('d', [0.0])
            elif 'Float' in leaf_type:
                branch_buffers[branch_name] = array('f', [0.0])
            elif 'Int' in leaf_type:
                branch_buffers[branch_name] = array('i', [0])
            else:
                print(f"Unsupported type for branch {branch_name}: {leaf_type}")
                continue
            tree.SetBranchAddress(branch_name, branch_buffers[branch_name])
            branches[branch_name] = []

    # Split the entries into chunks for each process
    chunk_size = nentries // num_processes
    manager = Manager()
    q = manager.Queue()  # Queue for progress bar updates

    # Prepare arguments for each process
    args = []
    for i in range(num_processes):
        start = i * chunk_size + entry_begin
        end = (i + 1) * chunk_size + entry_begin if i < num_processes - 1 else nentries+ entry_begin
        args.append((tree, branch_buffers, start, end, q, batch_size))

    # Start processes with a pool and monitor progress
    with Pool(processes=num_processes) as pool:
        result_async = pool.map_async(read_entries, args)
        pbar = tqdm(total=nentries, desc=f"Overall Progress, full entries : {full_entries}, target entries : {nentries+ entry_begin}, entry: {entry_begin} => {nentries+ entry_begin}")
        while not result_async.ready() or not q.empty():
            while not q.empty():
                pbar.update(q.get())
            time.sleep(0.1)
        results = result_async.get()
        pbar.close()
    combined_branches = {name: [] for name in branch_buffers.keys()}
    for result in results:
        for name, data in result.items():
            combined_branches[name].extend(data)

    # Convert to numpy array
    feature_names = list(combined_branches.keys())
    data_array = list(map(list, zip(*[combined_branches[name] for name in feature_names])))

    num_rows = len(data_array)
    num_cols = len(data_array[0]) if num_rows > 0 else 0
    print(f"Shape: ({num_rows}, {num_cols})")
    
    # Create mappings
    branch_to_index = {name: i for i, name in enumerate(feature_names)}
    index_to_branch = {i: name for i, name in enumerate(feature_names)}

    return data_array, branch_to_index, index_to_branch, branch_names, branch_types
def LoadROOTFile2(sample_paths, entries, branches_name=[], select_opt="", num_processes=40,batch_size=1000,entry_begin=0):
    tree = ROOT.TChain()
    for sample_path in sample_paths:
        tree.Add(sample_path + "/DNNTrainTree")
        
    nentries = tree.GetEntries()
    full_entries = nentries
    nentries = min(nentries-entry_begin, entries)
    print(nentries)
    branches = {}
    branch_buffers = {}
    branch_names = []
    branch_types = []
    
    # Set up branch reading
    if len(branches_name) == 0:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            branches_name.append(branch_name)
    
    for branch_name0 in branches_name:
        for branch in tree.GetListOfBranches():
            branch_name = branch.GetName()
            if branch_name0 != branch_name:
                continue
            branch_names.append(branch_name)
            leaf = branch.GetLeaf(branch_name)
            leaf_type = leaf.GetTypeName()
            branch_types.append(leaf_type)
            if leaf_type.startswith('vector<double>'):
                branch_buffers[branch_name] = ROOT.std.vector('double')()
            elif leaf_type.startswith('vector<float>'):
                branch_buffers[branch_name] = ROOT.std.vector('float')()
            elif leaf_type.startswith('vector<int>'):
                branch_buffers[branch_name] = ROOT.std.vector('int')()
            elif 'Double' in leaf_type:
                branch_buffers[branch_name] = array('d', [0.0])
            elif 'Float' in leaf_type:
                branch_buffers[branch_name] = array('f', [0.0])
            elif 'Int' in leaf_type:
                branch_buffers[branch_name] = array('i', [0])
            else:
                print(f"Unsupported type for branch {branch_name}: {leaf_type}")
                continue
            tree.SetBranchAddress(branch_name, branch_buffers[branch_name])
            branches[branch_name] = []

    # Split the entries into chunks for each process
    chunk_size = nentries // num_processes
    manager = Manager()
    q = manager.Queue()  # Queue for progress bar updates

    # Prepare arguments for each process
    args = []
    for i in range(num_processes):
        start = i * chunk_size + entry_begin
        end = (i + 1) * chunk_size + entry_begin if i < num_processes - 1 else nentries+ entry_begin
        args.append((tree, branch_buffers, start, end, q, batch_size))

    # Start processes with a pool and monitor progress
    with Pool(processes=num_processes) as pool:
        result_async = pool.map_async(read_entries, args)
        pbar = tqdm(total=nentries, desc=f"Overall Progress, full entries : {full_entries}, target entries : {nentries+ entry_begin}, entry: {entry_begin} => {nentries+ entry_begin}")
        while not result_async.ready() or not q.empty():
            while not q.empty():
                pbar.update(q.get())
            time.sleep(0.1)
        results = result_async.get()
        pbar.close()
    combined_branches = {name: [] for name in branch_buffers.keys()}
    for result in results:
        for name, data in result.items():
            combined_branches[name].extend(data)

    # Convert to numpy array
    feature_names = list(combined_branches.keys())
    data_array = list(map(list, zip(*[combined_branches[name] for name in feature_names])))
    num_rows = len(data_array)
    num_cols = len(data_array[0]) if num_rows > 0 else 0
    print(f"Shape: ({num_rows}, {num_cols})")
    
    # Create mappings
    branch_to_index = {name: i for i, name in enumerate(feature_names)}
    index_to_branch = {i: name for i, name in enumerate(feature_names)}

    return data_array, branch_to_index, index_to_branch, branch_names, branch_types
def split_and_format(expression):
    parts = expression.split('>')  
    variable_name = parts[0].strip()
    number = parts[1].strip() 
    number=float(number)
    return variable_name,number

def convert_to_one_hot(labels):
    one_hot_labels = np.zeros((labels.shape[0], 3))
    for i, label in enumerate(labels):
        if np.array_equal(label, [0]):
            one_hot_labels[i, 0] = 1  
        elif np.array_equal(label, [1]):
            one_hot_labels[i, 1] = 1  
        elif np.array_equal(label, [2]):
            one_hot_labels[i, 2] = 1 
    return one_hot_labels
def convert_to_one_hot_fourlabel(labels,match):
    one_hot_labels = np.zeros((labels.shape[0], 4))
    for i, label in enumerate(labels):
        if np.array_equal(label, [0]) and (match[i] >=0):
            one_hot_labels[i, 0] = 1  
        elif np.array_equal(label, [1]):
            one_hot_labels[i, 1] = 1  
        elif np.array_equal(label, [2]):
            one_hot_labels[i, 2] = 1  
        elif np.array_equal(label, [0]) and (match[i] < 0):
            one_hot_labels[i, 3] = 1  
    return one_hot_labels
def convert_to_one_hot_fourlabel2(labels,match):
    one_hot_labels = np.zeros((labels.shape[0], 4))
    for i, label in enumerate(labels):
        if np.array_equal(label, [3]) and (match[i] >= 0):
            one_hot_labels[i, 3] = 1  
        elif np.array_equal(label, [1]) and (match[i] >= 0):
            one_hot_labels[i, 1] = 1  
        elif (np.array_equal(label, [2]) or np.array_equal(label, [4]) and (match[i] >= 0)):
            one_hot_labels[i, 2] = 1  
        elif np.array_equal(label, [0]) and (match[i] < 0):
            one_hot_labels[i, 0] = 1  
    return one_hot_labels
def convert_to_one_hot_fourlabel3(labels,match,final_descri3,final_descri4):
    one_hot_labels = np.zeros((labels.shape[0], 4))
    for i, label in enumerate(labels):
        if (((abs(final_descri3[i]) > 0 and abs(final_descri3[i]) <= 5) and final_descri4[i] == 21) or ((abs(final_descri4[i]) > 0 and abs(final_descri4[i]) <= 5) and final_descri3[i] == 21)) and (match[i] >= 0):
            one_hot_labels[i, 3] = 1  
        elif (final_descri3[i] == 21) and (final_descri4[i] == 21) and (match[i] >= 0):
            one_hot_labels[i, 1] = 1  
        elif (abs(final_descri3[i]) > 0 and abs(final_descri3[i]) <= 5) and (final_descri3[i] + final_descri4[i] == 0) and (match[i] >= 0):
            one_hot_labels[i, 2] = 1  
        elif (final_descri3[i] == 0) and (final_descri4[i] == 0) and (match[i] < 0):
            one_hot_labels[i, 0] = 1  
    return one_hot_labels
def convert_to_one_hot_sevenlabel(labels,match):
    one_hot_labels = np.zeros((labels.shape[0], 7))
    for i, label in enumerate(labels):      
        if np.array_equal(label, [1]) and (match[i] >= 0): # gg
            one_hot_labels[i, 1] = 1  
        elif np.array_equal(label, [2]) and (match[i] >= 0): # qq
            one_hot_labels[i, 2] = 1  
        elif np.array_equal(label, [3]) and (match[i] >= 0): # qg
            one_hot_labels[i, 3] = 1  
        elif np.array_equal(label, [4]) and (match[i] >= 0): # qr
            one_hot_labels[i, 4] = 1  
        elif np.array_equal(label, [5]) and (match[i] >= 0): # gr
            one_hot_labels[i, 5] = 1  
        elif np.array_equal(label, [0]) and (match[i] >= 0): # rr
            one_hot_labels[i, 6] = 1  
        elif np.array_equal(label, [0]) and (match[i] < 0): #unmatched
            one_hot_labels[i, 0] = 1  
    return one_hot_labels
def convert_to_one_hot_fourlabel_kt(labels,match,kt):
    one_hot_labels = np.zeros((labels.shape[0], 4))
    for i, label in enumerate(labels):
        if np.array_equal(label, [3]) and (match[i] >= 0) and (kt[i] > 2):
            one_hot_labels[i, 3] = 1  
        elif np.array_equal(label, [1]) and (match[i] >= 0) and (kt[i] > 2):
            one_hot_labels[i, 1] = 1  
        elif (np.array_equal(label, [2]) or np.array_equal(label, [4]) and (match[i] >= 0)) and (kt[i] > 2):
            one_hot_labels[i, 2] = 1  
        elif np.array_equal(label, [0]) and (match[i] < 0) and (kt[i] > 2):
            one_hot_labels[i, 0] = 1  
    return one_hot_labels
def convert_to_one_hot_twolabel_spin(labels, match, kt, spin):
    one_hot_labels = np.zeros((labels.shape[0], 2))
    for i, label in enumerate(labels):
        if np.array_equal(label, [2]) and (match[i] >= 0) and (kt[i] > 2) and spin[i] == 0:
            one_hot_labels[i, 0] = 1  
        elif np.array_equal(label, [2]) and (match[i] >= 0) and (kt[i] > 2) and spin[i] == 1:
            one_hot_labels[i, 1] = 1   
    return one_hot_labels
def convert_to_one_hot_threeLabel(labels,match):
    one_hot_labels = np.zeros((labels.shape[0], 3))
    for i, label in enumerate(labels):
        if np.array_equal(label, [3]) :
            one_hot_labels[i, 0] = 1  
        elif np.array_equal(label, [1]):
            one_hot_labels[i, 1] = 1  
        elif np.array_equal(label, [2]) or np.array_equal(label, [4]):
            one_hot_labels[i, 2] = 1  
    return one_hot_labels
def convert_to_binary(labels):
    binary_labels = np.zeros(labels.shape[0])
    for i, label in enumerate(labels):
        if np.array_equal(label, [1, 0]):
            binary_labels[i] = 0  
        elif np.array_equal(label, [0, 1]):
            binary_labels[i] = 1 
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

def train_and_save_conv1dmodel(X_train, Y_train, X_val, Y_val, input_length, num_features, l2_reg=0.0, dropout_rate=0.0, learning_rate=0.0001):
    model = build_conv1d_classification_model(input_length, num_features, l2_reg=l2_reg, dropout_rate=dropout_rate)
    adam_optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)
    model.compile(optimizer=adam_optimizer, loss='binary_crossentropy', metrics=['accuracy'])
    history = model.fit(
        X_train, Y_train,
        epochs=50,
        batch_size=16,  
        validation_data=(X_val, Y_val)
    )  
    return model
def train_and_save_model(X_train, Y_train, X_val, Y_val,hidden_units=[16],learning_rate=0.0001,l2_reg=0,batch_size=16):
    #hidden_units=math.ceil((X_train.shape[1]+1)/2)
    #hidden_units=math.ceil((X_train.shape[1]+1)*2.0/3)
    #model = build_binary_classification_model(X_train.shape[1], hidden_layers=2, hidden_units=16)
    # weights = class_weight.compute_class_weight('balanced', classes=np.unique(Y_train), y=Y_train)
    # class_weights = dict(enumerate(weights))

    model = build_binary_classification_model(X_train.shape[1], hidden_units=hidden_units,l2_reg=l2_reg)
    adam_optimizer = Adam(learning_rate=learning_rate)
    model.compile(optimizer=adam_optimizer, loss='binary_crossentropy', metrics=['accuracy'])
    # roc_auc_callback = RocAucCallback()
    # roc_auc_callback.training_data = (X_train, Y_train)
    # roc_auc_callback.validation_data = (X_val, Y_val)
    history = model.fit(
        X_train, Y_train,
        epochs=200,
        batch_size=batch_size,
        validation_data=(X_val, Y_val),
        #class_weight=class_weights,
        #callbacks=[roc_auc_callback]
    )  
    return model

def train_and_save_model_bdt_params(X_train, Y_train, X_val, Y_val, best_params):
    num_classes = len(np.unique(Y_train))
    
    if num_classes == 2:
        objective = 'binary:logistic'
        eval_metric = 'logloss'
    else:
        objective = 'multi:softmax'
        eval_metric = 'mlogloss'
    
    best_params.update({
        'objective': objective,
        'eval_metric': eval_metric,
    })

    if num_classes > 2:
        best_params['num_class'] = num_classes
    
    dtrain = xgb.DMatrix(X_train, label=Y_train)
    dval = xgb.DMatrix(X_val, label=Y_val)

    evals = [(dtrain, 'train'), (dval, 'eval')]

    model = xgb.train(best_params, dtrain, num_boost_round=1000, evals=evals, early_stopping_rounds=10)

    y_pred = model.predict(dval)
    
    if num_classes == 2:
        y_pred_binary = [1 if pred > 0.5 else 0 for pred in y_pred]
        accuracy = accuracy_score(Y_val, y_pred_binary)
    else:
        accuracy = accuracy_score(Y_val, y_pred)
    
    print(f"Validation Accuracy: {accuracy:.4f}")


    return model

def train_and_save_model_bdt2(X_train, Y_train, X_val, Y_val, hidden_units=[16], learning_rate=0.0001, l2_reg=0):
    # Determine the number of classes by checking the unique values in Y_train
    
    Y_train = np.argmax(Y_train, axis=1)  # 转换为整数类别
    Y_val = np.argmax(Y_val, axis=1)

    num_classes = len(np.unique(Y_train))
    # Set the objective based on the number of classes
    if num_classes == 2:
        objective = 'binary:logistic'
        eval_metric = 'logloss'
    else:
        objective = 'multi:softmax'
        eval_metric = 'mlogloss'
    
    # XGBoost parameters
    params = {
        'objective': objective,
        'learning_rate': 0.01,
        'max_depth': 8,
        'min_child_weight': 1,
        'gamma': 0.1,
        'lambda': 1.0,
        'alpha': 0.5,
        'subsample': 0.8,
        'colsample_bytree': 0.8,
        'eval_metric': eval_metric,
        'nthread': 1  # 使用单核
    }
    
    if num_classes > 2:
        params['num_class'] = num_classes
    # Create DMatrix for XGBoost
    global dtrain, dval, evals
    dtrain = xgb.DMatrix(X_train, label=Y_train)
    dval = xgb.DMatrix(X_val, label=Y_val)
    evals = [(dtrain, 'train'), (dval, 'eval')]
    # Train the model
    model = xgb.train(params, dtrain, num_boost_round=1000, evals=evals, early_stopping_rounds=10)
    
    # Predict on validation set
    y_pred = model.predict(dval)
    
    if num_classes == 2:
        y_pred_binary = [1 if pred > 0.5 else 0 for pred in y_pred]
        accuracy = accuracy_score(Y_val, y_pred_binary)
    else:
        accuracy = accuracy_score(Y_val, y_pred)
    
    print(f"Validation Accuracy: {accuracy}")

    return model
import logging
class TqdmLoggingHandler(logging.StreamHandler):
    def __init__(self, tqdm_instance):
        super().__init__()
        self.tqdm_instance = tqdm_instance

    def emit(self, record):
        try:
            msg = self.format(record)
            self.tqdm_instance.write(msg)
            self.flush()
        except Exception:
            self.handleError(record)
from sklearn.model_selection import train_test_split, ParameterGrid, cross_val_score

def grid_search_best_params(X_train, Y_train):
    num_classes = len(np.unique(Y_train))
    
    if num_classes == 2:
        objective = 'binary:logistic'
        eval_metric = 'logloss'
    else:
        objective = 'multi:softmax'
        eval_metric = 'mlogloss'
    
    xgb_model = xgb.XGBClassifier(objective=objective, eval_metric=eval_metric, use_label_encoder=False)
    
    # param_grid = {
    #     'learning_rate': [0.01, 0.1, 0.2],
    #     'max_depth': [3, 4, 5, 6],
    #     'min_child_weight': [1, 5, 10],
    #     'gamma': [0, 0.5, 1, 1.5, 2],
    #     'subsample': [0.6, 0.8, 1.0],
    #     'colsample_bytree': [0.6, 0.8, 1.0],
    #     'reg_lambda': [1, 5, 10],
    #     'reg_alpha': [0.5, 1, 1.5]
    # }
    param_grid = {
        'learning_rate': [0.01, 0.1],
        'max_depth': [2 , 3, 4 , 5 , 6 ,7],
        'min_child_weight': [1, 5],
        'gamma': [0, 1],
        'subsample': [0.8, 1.0],
        'colsample_bytree': [0.8, 1.0],
        'reg_lambda': [1, 5],
        'reg_alpha': [0.5, 1]
    }
    
    # 计算总的迭代次数
    total_iterations = len(ParameterGrid(param_grid))
    
    # 初始化进度条
    tqdm_bar = tqdm(total=total_iterations, desc="Grid Search")

    best_score = 0
    best_params = None
    
    for params in ParameterGrid(param_grid):
        xgb_model.set_params(**params)
        
        # 使用交叉验证评估模型
        scores = cross_val_score(xgb_model, X_train, Y_train, scoring='accuracy', cv=5, n_jobs=-1)
        mean_score = np.mean(scores)
        
        if mean_score > best_score:
            best_score = mean_score
            best_params = params

        tqdm_bar.update(1)
    
    tqdm_bar.close()
    

    print("Best parameters found: ", best_params)
    print("Best accuracy found: ", best_score)


    return best_params
def build_multiclass_classification_model(input_dim, hidden_units=[16], l2_reg=0):
    model =  tf.keras.Sequential()
    for units in hidden_units:
        model.add( layers.Dense(units, activation='relu', kernel_regularizer=l2(l2_reg), input_dim=input_dim))
        input_dim = units
    model.add( layers.Dense(3, activation='softmax'))  # 输出层，3个类别
    return model

def train_and_save_threeclass_model(X_train, Y_train, X_val, Y_val, hidden_units=[16], learning_rate=0.0001, l2_reg=0):
    # 标签转换为one-hot编码
    
    model = build_multiclass_classification_model(X_train.shape[1], hidden_units=hidden_units, l2_reg=l2_reg)
    adam_optimizer = Adam(learning_rate=learning_rate)
    model.compile(optimizer=adam_optimizer, loss='categorical_crossentropy', metrics=['accuracy'])
    
    # 训练模型
    history = model.fit(
        X_train, Y_train,
        epochs=200,
        batch_size=16,
        validation_data=(X_val, Y_val)
    )
    
    return model
def train_and_save_model_ThreeLabel(X_train, Y_train, X_val, Y_val,hidden_units=[16],learning_rate=0.0001,l2_reg=0):
    #hidden_units=math.ceil((X_train.shape[1]+1)/2)
    #hidden_units=math.ceil((X_train.shape[1]+1)*2.0/3)
    #model = build_binary_classification_model(X_train.shape[1], hidden_layers=2, hidden_units=16)
    model = build_ThreeLabel_classification_model(X_train.shape[1], hidden_units=hidden_units,l2_reg=l2_reg)
    adam_optimizer = Adam(learning_rate=learning_rate)
    model.compile(optimizer=adam_optimizer, loss='categorical_crossentropy', metrics=['accuracy'])
    # roc_auc_callback = RocAucCallback()
    # roc_auc_callback.training_data = (X_train, Y_train)
    # roc_auc_callback.validation_data = (X_val, Y_val)
    history = model.fit(
        X_train, Y_train,
        epochs=50,
        batch_size=16,
        validation_data=(X_val, Y_val),
        #callbacks=[roc_auc_callback]
    )  
    return model
from tensorflow.keras.callbacks import EarlyStopping
def train_and_save_model_MultiLabel(X_train, Y_train, X_val, Y_val,hidden_units=[16],learning_rate=0.0001,l2_reg=0,model = tf.keras.Sequential(), file_suffix=''):
    #hidden_units=math.ceil((X_train.shape[1]+1)/2)
    #hidden_units=math.ceil((X_train.shape[1]+1)*2.0/3)
    #model = build_binary_classification_model(X_train.shape[1], hidden_layers=2, hidden_units=16)
    if isinstance(model, tf.keras.Sequential) and len(model.layers) == 0:
        model = build_multiLabel_classification_model(X_train.shape[1],Y_train.shape[1], hidden_units=hidden_units,l2_reg=l2_reg, dropout_rate=0.5)
        adam_optimizer = Adam(learning_rate=learning_rate)
        model.compile(optimizer=adam_optimizer, loss='categorical_crossentropy', metrics=['accuracy'])
    # roc_auc_callback = RocAucCallback()
    # roc_auc_callback.training_data = (X_train, Y_train)
    # roc_auc_callback.validation_data = (X_val, Y_val)
    early_stopping = EarlyStopping(monitor='val_loss', patience=5, restore_best_weights=True)
    history = model.fit(
        X_train, Y_train,
        epochs=100,
        batch_size=256,
        validation_data=(X_val, Y_val),
        # callbacks=[early_stopping]
        callbacks=[]
    ) 
    
    plt.figure(figsize=(8, 6))
    plt.plot(history.history['loss'], label='Training Loss')
    plt.plot(history.history['val_loss'], label='Validation Loss')
    plt.title('Loss vs. Epoch')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend()
    plt.grid(True)
    if file_suffix:
        plot_file_name = f'loss_vs_epoch_{file_suffix}.pdf'
    else:
        plot_file_name = 'loss_vs_epoch.pdf'
    plot_file_path = os.path.join('/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/loss_epoch/', plot_file_name)
    plt.savefig(plot_file_path, format='pdf')
    plt.show() 
    
    return model
def save_predictions_to_root(X_data,train_val_index,full_predictions,root_filename,branch_name):
    data_dict = {name: X_data[:, i] for i, name in enumerate(branch_name)}
    data_dict['score'] = full_predictions
    data_dict['validate'] = train_val_index
    n_entries = len(next(iter(data_dict.values())))
    max_entries_per_chunk = 1000000
    n_chunks = n_entries // max_entries_per_chunk + (n_entries % max_entries_per_chunk > 0)
    for i in range(n_chunks):
        start = i * max_entries_per_chunk
        end = min((i + 1) * max_entries_per_chunk, n_entries)
        chunk_filename = f"{root_filename}_Chunk{i}.root"
        chunk_data_dict = {k: v[start:end] for k, v in data_dict.items()}
        with uproot.recreate(chunk_filename) as f:
            f['DNNTrainTree'] = chunk_data_dict
def save_predictions_to_root(X_data,train_val_index1,full_predictions1,train_val_index2,full_predictions2,root_filename,branch_name):
    data_dict = {name: X_data[:, i] for i, name in enumerate(branch_name)}
    data_dict['score1'] = full_predictions1
    data_dict['validate1'] = train_val_index1
    data_dict['score2'] = full_predictions2
    data_dict['validate2'] = train_val_index2
    n_entries = len(next(iter(data_dict.values())))
    max_entries_per_chunk = 1000000
    n_chunks = n_entries // max_entries_per_chunk + (n_entries % max_entries_per_chunk > 0)
    for i in range(n_chunks):
        start = i * max_entries_per_chunk
        end = min((i + 1) * max_entries_per_chunk, n_entries)
        chunk_filename = f"{root_filename}_Chunk{i}.root"
        chunk_data_dict = {k: v[start:end] for k, v in data_dict.items()}
        with uproot.recreate(chunk_filename) as f:
            f['DNNTrainTree'] = chunk_data_dict
def save_threeclass_predictions_to_root(X_data,train_val_index,full_predictions,root_filename,branch_name):
    data_dict = {name: X_data[:, i] for i, name in enumerate(branch_name)}
    data_dict['score0'] = full_predictions[:,0]
    data_dict['score1'] = full_predictions[:,1]
    data_dict['score2'] = full_predictions[:,2]
    data_dict['validate'] = train_val_index
    n_entries = len(next(iter(data_dict.values())))
    max_entries_per_chunk = 1000000
    n_chunks = n_entries // max_entries_per_chunk + (n_entries % max_entries_per_chunk > 0)
    for i in range(n_chunks):
        start = i * max_entries_per_chunk
        end = min((i + 1) * max_entries_per_chunk, n_entries)
        chunk_filename = f"{root_filename}_Chunk{i}.root"
        chunk_data_dict = {k: v[start:end] for k, v in data_dict.items()}
        with uproot.recreate(chunk_filename) as f:
            f['DNNTrainTree'] = chunk_data_dict
def save_multiclass_predictions_to_root(X_data, root_filename, branch_names, branch_types):
    # Create a dictionary for the data
    data_dict = {name: [row[i] for row in X_data] for i, name in enumerate(branch_names)}
    # Determine number of entries
    n_entries = len(next(iter(data_dict.values())))
    max_entries_per_chunk = 1000000
    n_chunks = n_entries // max_entries_per_chunk + (n_entries % max_entries_per_chunk > 0)
    print(len(X_data))
    print(n_chunks)
    for i in range(n_chunks):
        start = i * max_entries_per_chunk
        end = min((i + 1) * max_entries_per_chunk, n_entries)
        chunk_filename = f"{root_filename}_Part{i}.root"
        chunk_data_dict = {k: v[start:end] for k, v in data_dict.items()}

        file = ROOT.TFile(chunk_filename, "recreate")
        tree = ROOT.TTree("DNNTrainTree", "DNN Train Tree")

        branches = {}
        for name,type in zip(branch_names,branch_types):
            if  type == 'vector<double>' :
                branches[name] = ROOT.std.vector('double')()
                tree.Branch(name, branches[name])
            elif type == 'vector<int>' :
                branches[name] = ROOT.std.vector('int')()
                tree.Branch(name, branches[name])
            elif type == 'Double_t':
                branches[name] = array('d', [0.0])
                tree.Branch(name, branches[name], f"{name}/D")
            elif type == 'Int_t':
                branches[name] = array('i', [0])
                tree.Branch(name, branches[name], f"{name}/I")

        for i in tqdm(range(len(chunk_data_dict[branch_names[0]]))):
            for (name, data),type in zip(chunk_data_dict.items(),branch_types):
                if type == 'vector<double>' :
                    branches[name].clear()
                    for value in data[i]:
                        branches[name].push_back(float(value))
                elif type == 'vector<int>' :
                    branches[name].clear()
                    for value in data[i]:
                        branches[name].push_back(int(value))
                elif type == 'Double_t':
                    branches[name][0] = data[i][0]
                elif type == 'Int_t':
                    branches[name][0] = data[i][0]
            tree.Fill()

        file.Write()
        file.Close()
            
# def save_predictions_to_root(X_data, train_val_index, full_predictions, root_filename, branch_name):
#     # 生成随机排列的索引
#     n_entries = X_data.shape[0]
#     random_indices = np.random.permutation(n_entries)
    
#     # 使用随机索引重排数据
#     X_data = X_data[random_indices]
#     full_predictions = full_predictions[random_indices]
#     train_val_index = train_val_index[random_indices]
    
#     # 创建数据字典
#     data_dict = {name: X_data[:, i] for i, name in enumerate(branch_name)}
#     data_dict['score'] = full_predictions
#     data_dict['validate'] = train_val_index
    
#     max_entries_per_chunk = 1000000
#     n_chunks = n_entries // max_entries_per_chunk + (n_entries % max_entries_per_chunk > 0)
    
#     for i in range(n_chunks):
#         start = i * max_entries_per_chunk
#         end = min((i + 1) * max_entries_per_chunk, n_entries)
#         chunk_filename = f"{root_filename}_Chunk{i}.root"
#         chunk_data_dict = {k: v[start:end] for k, v in data_dict.items()}
        
#         with uproot.recreate(chunk_filename) as f:
#             f['DNNTrainTree'] = chunk_data_dict
def save_predictions_to_root_ThreeLabel(model, X_train, X_val, Y_train, Y_val, X_train0, X_val0, root_filename, branch_name):
    predictions_train = model.predict(X_train, batch_size=1024)
    predictions_val = model.predict(X_val, batch_size=1024)
    
    # 绘制 ROC 曲线
    plot_roc_curve_threelabel(Y_train, predictions_train, root_filename + "_train")
    plot_roc_curve_threelabel(Y_val, predictions_val, root_filename + "_val")
    
    # 合并训练和验证集的预测结果
    predictions = np.concatenate((predictions_train, predictions_val), axis=0)

    # 创建索引数组来区分训练集和验证集
    train_indices = np.zeros(X_train.shape[0], dtype=int)
    val_indices = np.ones(X_val.shape[0], dtype=int)
    indices = np.concatenate((train_indices, val_indices), axis=0)
    
    # 合并原始特征数据
    X_data = np.concatenate((X_train0, X_val0), axis=0)
    
    # 合并真实标签数据
    Y_data = np.concatenate((Y_train, Y_val), axis=0)
    
    # 构建数据字典
    data_dict = {name: X_data[:, i] for i, name in enumerate(branch_name[:])}
    data_dict['score0'] = predictions[:, 0]
    data_dict['score1'] = predictions[:, 1]
    data_dict['score2'] = predictions[:, 2]
    data_dict['onehot0'] = Y_data[:, 0]
    data_dict['onehot1'] = Y_data[:, 1]
    data_dict['onehot2'] = Y_data[:, 2]
    data_dict['validate'] = indices

    # 分块写入 ROOT 文件
    n_entries = len(indices)
    max_entries_per_chunk = 1000000
    n_chunks = n_entries // max_entries_per_chunk + (n_entries % max_entries_per_chunk > 0)
    for i in range(n_chunks):
        start = i * max_entries_per_chunk
        end = min((i + 1) * max_entries_per_chunk, n_entries)
        chunk_filename = f"{root_filename}_Chunk{i}.root"
        chunk_data_dict = {k: v[start:end] for k, v in data_dict.items()}
        with uproot.recreate(chunk_filename) as f:
            f['DNNTrainTree'] = chunk_data_dict
def plot_roc_curve(Y_val, y_scores,filename):
    fpr, tpr, thresholds = roc_curve(Y_val, y_scores)
    roc_auc = auc(fpr, tpr)
    plt.figure()
    plt.plot(fpr, tpr, color='darkorange', lw=2, label='ROC curve (area = %0.4f)' % roc_auc)
    plt.plot([0, 1], [0, 1], color='navy', lw=2, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('Receiver Operating Characteristic')
    plt.legend(loc="lower right")
    plt.savefig(filename+".pdf")
    roc_data = pd.DataFrame({
        'FPR': fpr,
        'TPR': tpr,
        'Thresholds': thresholds
    })
    roc_data.to_csv(filename+".csv", index=False)
    plt.close() 
    return roc_auc
from itertools import cycle
def plot_roc_curve_threeLabel(Y_val, y_scores, filename):
    n_classes = Y_val.shape[1]
    
    # Compute ROC curve and ROC area for each class
    fpr = dict()
    tpr = dict()
    roc_auc = dict()
    for i in range(n_classes):
        fpr[i], tpr[i], _ = roc_curve(Y_val[:, i], y_scores[:, i])
        roc_auc[i] = auc(fpr[i], tpr[i])
    
    # Compute macro-average ROC curve and ROC area
    # Aggregate all false positive rates
    all_fpr = np.unique(np.concatenate([fpr[i] for i in range(n_classes)]))

    # Interpolate all ROC curves at these points
    mean_tpr = np.zeros_like(all_fpr)
    for i in range(n_classes):
        mean_tpr += np.interp(all_fpr, fpr[i], tpr[i])

    # Average it and compute AUC
    mean_tpr /= n_classes

    fpr["macro"] = all_fpr
    tpr["macro"] = mean_tpr
    roc_auc["macro"] = auc(fpr["macro"], tpr["macro"])

    # Plot all ROC curves
    plt.figure()
    colors = cycle(['aqua', 'darkorange', 'cornflowerblue'])
    for i, color in zip(range(n_classes), colors):
        plt.plot(fpr[i], tpr[i], color=color, lw=2,
                 label='ROC curve of class {0} (area = {1:0.4f})'
                 ''.format(i, roc_auc[i]))

    plt.plot(fpr["macro"], tpr["macro"], color='navy', linestyle='--', lw=2,
             label='Macro-average ROC curve (area = {0:0.4f})'
             ''.format(roc_auc["macro"]))

    plt.plot([0, 1], [0, 1], 'k--', lw=2)
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('Receiver Operating Characteristic')
    plt.legend(loc="lower right")
    plt.savefig(filename + ".pdf")
    
    # Save ROC data to CSV
    max_length = max(*[len(fpr[i]) for i in range(n_classes)], len(fpr["macro"]))
    roc_data_dict = {}
    for i in range(n_classes):
        roc_data_dict[f'FPR_class_{i}'] = np.pad(fpr[i], (0, max_length - len(fpr[i])), 'constant', constant_values=np.nan)
        roc_data_dict[f'TPR_class_{i}'] = np.pad(tpr[i], (0, max_length - len(tpr[i])), 'constant', constant_values=np.nan)
    
    roc_data_dict['FPR_macro'] = np.pad(fpr["macro"], (0, max_length - len(fpr["macro"])), 'constant', constant_values=np.nan)
    roc_data_dict['TPR_macro'] = np.pad(tpr["macro"], (0, max_length - len(tpr["macro"])), 'constant', constant_values=np.nan)
    
    roc_data = pd.DataFrame(roc_data_dict)
    roc_data.to_csv(filename + ".csv", index=False)
    
    plt.close()
    return roc_auc
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
    
def add_str(strings,prefix, suffix):
    return [prefix+ s + suffix for s in strings]
def Extract_flat_features(data,branch_to_index,features_name,prefix="",suffix="",return_shape = False):
    features_name = add_str(features_name,prefix,suffix)
    select_index_feature = [branch_to_index[name] for name in features_name]
    if(return_shape):
        data_shape = [row[select_index_feature[0]] for row in data]
        return select_and_convert(data,select_index_feature),data_shape
    else:
        return select_and_convert(data,select_index_feature),[]
    