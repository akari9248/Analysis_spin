import sys, os
path = "X:/storage/ylye/QCDAnalysis/OfflineExamples/python" 
path = "python" 
sys.path.append(path)
from keras.optimizers import Adam
import tensorflow as tf
import pandas as pd
import uproot
import numpy as np
# import argparse
# from sklearn.model_selection import train_test_split
# from tqdm import tqdm
# import os
# import math
# import matplotlib.pyplot as plt
# from sklearn.metrics import roc_curve, auc
# from sklearn.metrics import roc_auc_score
# from sklearn.preprocessing import StandardScaler, MinMaxScaler
# import time
# import dnn
import xgboost as xgb
from tensorflow.keras.models import load_model # type: ignore

def train_and_save_model_bdt(hidden_units=[16], learning_rate=0.0001, l2_reg=0):
    # Determine the number of classes by checking the unique values in Y_train
    X_train = np.random.rand(100, 5)
    Y_train = np.random.randint(0, 2, size=100)
    X_val = np.random.rand(50, 5)
    Y_val = np.random.randint(0, 2, size=50)
    # Y_train = np.argmax(Y_train, axis=1)  # 转换为整数类别
    # Y_val = np.argmax(Y_val, axis=1)

    num_classes = len(np.unique(Y_train))
    # Set the objective based on the number of classes
    if num_classes == 2:
        objective = 'binary:logistic'
        eval_metric = 'logloss'
    else:
        objective = 'multi:softmax'
        eval_metric = 'mlogloss'
    
    # XGBoost parameters
    # params = {
    #     'objective': objective,
    #     'learning_rate': 0.01,
    #     'max_depth': 8,
    #     'min_child_weight': 1,
    #     'gamma': 0.1,
    #     'lambda': 1.0,
    #     'alpha': 0.5,
    #     'subsample': 0.8,
    #     'colsample_bytree': 0.8,
    #     'eval_metric': eval_metric,
    #     'nthread': 1  # 使用单核
    # }
    params = {
        'objective': 'binary:logistic',
        'eval_metric': 'logloss',
        'learning_rate': 0.1,
        'max_depth': 6
    }
    
    if num_classes > 2:
        params['num_class'] = num_classes
    # Create DMatrix for XGBoost
    dtrain = xgb.DMatrix(X_train, label=Y_train)
    dval = xgb.DMatrix(X_val, label=Y_val)
    evals = [(dtrain, 'train'), (dval, 'eval')]
    # Train the model
    model = xgb.train(params, dtrain, num_boost_round=1000, evals=evals, early_stopping_rounds=10)
    
    # Predict on validation set
    y_pred = model.predict(dval)
    
    if num_classes == 2:
        y_pred_binary = [1 if pred > 0.5 else 0 for pred in y_pred]
        accuracy = dnn.accuracy_score(Y_val, y_pred_binary)
    else:
        accuracy = dnn.accuracy_score(Y_val, y_pred)
    
    print(f"Validation Accuracy: {accuracy}")

    return model
if __name__ == "__main__":
    train_and_save_model_bdt()