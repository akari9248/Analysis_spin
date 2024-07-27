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
import math
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, auc, roc_auc_score, accuracy_score
from sklearn.preprocessing import StandardScaler, MinMaxScaler
import dnn
from functools import partial
from sklearn.inspection import permutation_importance
from tensorflow.keras.models import load_model
import seaborn as sns
import ROOT

# 自定义评分函数
def custom_scoring(estimator, X, y, dst=0):
    y_pred_proba = estimator.predict(X)
    class_2_proba = y_pred_proba[:, 2]
    class_3_proba = y_pred_proba[:, dst]
    if y.ndim > 1:
        y = np.argmax(y, axis=1)
    binary_true = np.isin(y, [2, dst]).astype(int)
    binary_pred_proba = class_2_proba / (class_2_proba + class_3_proba)
    auc_score = roc_auc_score(binary_true, binary_pred_proba)
    return auc_score
def custom_scoring_weighted(estimator, X, y):
    y_pred_proba = estimator.predict(X)
    weights = [1, 1, 1, 1]
    class_0_proba = y_pred_proba[:, 0]
    class_1_proba = y_pred_proba[:, 1]
    class_2_proba = y_pred_proba[:, 2]
    #class_3_proba = y_pred_proba[:, 3]

    if y.ndim > 1:
        y = np.argmax(y, axis=1)
    
    binary_true = np.isin(y, [2]).astype(int)
    binary_pred_proba = (class_2_proba * weights[2]) / (
        class_0_proba * weights[0] +
        class_1_proba * weights[1] +
        class_2_proba * weights[2] 
        #+class_3_proba * weights[3]
    )
    auc_score = roc_auc_score(binary_true, binary_pred_proba)    
    return auc_score
def save_corr_matrix_to_root(corr_matrix, output_file):
    # 创建 ROOT 文件
    root_file = ROOT.TFile(output_file, "RECREATE")
    
    # 创建 TH2D 直方图
    n = len(corr_matrix)
    th2d = ROOT.TH2D("corr_matrix", "Correlation Matrix", n, 0, n, n, 0, n)
    
    # 设置轴标签
    for i, name in enumerate(corr_matrix.columns):
        th2d.GetXaxis().SetBinLabel(i+1, name)
        th2d.GetYaxis().SetBinLabel(i+1, name)
    
    # 填充 TH2D 直方图
    for i in range(n):
        for j in range(n):
            th2d.SetBinContent(i+1, j+1, corr_matrix.iloc[i, j])
    
    # 写入并关闭 ROOT 文件
    th2d.Write()
    root_file.Close()

# 计算并绘制特征重要性相关性矩阵
def compute_and_plot_importance_correlation(importance_dfs, output_pdf, output_root):
    # 将每个 DataFrame 的 Importance 列合并到一个新的 DataFrame
    merged_importance = pd.concat([df.set_index('Feature')['Importance'] for df in importance_dfs], axis=1)
    merged_importance.columns = [f'dst={i}' for i in range(len(importance_dfs))]

    # 计算相关性矩阵
    corr_matrix = merged_importance.corr()

    # 保存相关性矩阵为 CSV 文件
    corr_matrix.to_csv(output_pdf.replace('.pdf', '_matrix.csv'))

    # 保存相关性矩阵为 ROOT 文件
    save_corr_matrix_to_root(corr_matrix, output_root)

    # 绘制相关性矩阵的热图
    plt.figure(figsize=(10, 8))
    sns.heatmap(corr_matrix, annot=True, fmt=".2f", cmap="coolwarm", cbar=True, square=True, linewidths=0.5)
    plt.title('Importance Correlation Matrix')
    plt.tight_layout()

    # 保存热图为 PDF 文件
    plt.savefig(output_pdf, format='pdf')
    plt.show()

# 去除高度相关的特征
def remove_highly_correlated_features(X, feature_names, threshold=0.9):
    df = pd.DataFrame(X, columns=feature_names)
    corr_matrix = df.corr()

    corr_matrix.to_csv("feature_correlation_matrix.csv")
    save_corr_matrix_to_root(corr_matrix, "feature_correlation_matrix.root")

    # 选择高度相关的特征
    upper_triangle = corr_matrix.where(np.triu(np.ones(corr_matrix.shape), k=1).astype(bool))
    to_drop = [column for column in upper_triangle.columns if any(upper_triangle[column] > threshold)]

    # 移除高度相关的特征
    X_reduced = df.drop(columns=to_drop).values
    reduced_feature_names = [name for name in feature_names if name not in to_drop]

    return X_reduced, reduced_feature_names, to_drop

def main(args):
    sample_path0 = args.sample_path0
    model_path = args.model_path
    select_opt = args.select_opt
    suffix = args.suffix
    entries = args.entries
    branches_name = ["match", "type", "Nparticles_2", "Ntracks_2", "pTD_2", "sigma1_2", "sigma2_2", "sigma_2",
                     "Nparticles_3", "Ntracks_3", "pTD_3", "sigma1_3", "sigma2_3", "sigma_3", "pt_3", "eta_3", "phi_3",
                     "e_3", "Nparticles_4", "Ntracks_4", "pTD_4", "sigma1_4", "sigma2_4", "sigma_4", "pt_4", "eta_4",
                     "phi_4", "e_4", "z1", "z2", "DeltaR", "kt", "Phi", "kt0", "GeneratorWeight", "PassPileUpRm",
                     "NextPassedNumber", "theta", "theta2", "WeightSpinoff", "pt", "pt_1", "pt_2"]
    
    if "Gen" in sample_path0:
        branches_name.append("RecoPhi")

    X_data, branch_to_index, index_to_branch, branch_names = dnn.LoadROOTFile(
        sample_paths=[sample_path0], entries=args.entries, branches_name=branches_name)
    
    select_item = [["Nparticles_2", "Ntracks_2", "pTD_2", "sigma1_2", "sigma2_2", "sigma_2",
                    "Nparticles_3", "Ntracks_3", "pTD_3", "sigma1_3", "sigma2_3", "sigma_3",
                    "Nparticles_4", "Ntracks_4", "pTD_4", "sigma1_4", "sigma2_4", "sigma_4",
                    "z1", "z2", "DeltaR", "kt"]]
    
    match_index = ["match"]
    Y_data_index = ["type"]
    select_index = [branch_to_index[name] for name in Y_data_index]
    Y_data = X_data[:, select_index]
    select_index = [branch_to_index[name] for name in match_index]
    match_data = X_data[:, select_index]
    match_data = match_data[:, 0]
    Y_data = dnn.convert_to_one_hot_threeLabel(Y_data, match_data)
    
    all_importance_dfs = []

    for i in range(len(select_item)):
        if select_opt != -1:
            i = select_opt
        indices_type = dnn.balance_data_multiLabel(Y_data)
        X_data0 = X_data[indices_type]
        select_index_feature = [branch_to_index[name] for name in select_item[i]]
        X_data1 = X_data0[:, select_index_feature]
        Y_data0 = Y_data[indices_type]
        
        # 去除高度相关的特征
        X_data1_reduced, reduced_feature_names, dropped_features = remove_highly_correlated_features(X_data1, select_item[i])
        print(f"Removed highly correlated features: {dropped_features}")
        
        model = load_model(model_path)
        folder_name = suffix
        if not os.path.exists(folder_name):
            os.makedirs(folder_name)
        
        dsts = [0]
        for dst in dsts:
            scoring_func = partial(custom_scoring, dst=dst)
            #result = permutation_importance(model, X_data1_reduced, Y_data0, n_repeats=10, random_state=42, scoring=scoring_func, n_jobs=50)
            result = permutation_importance(model, X_data1, Y_data0, n_repeats=10, random_state=42, scoring=custom_scoring_weighted, n_jobs=50)

            importances = result.importances_mean
            std = result.importances_std
            feature_names = select_item[i]
            
            feature_importances = pd.DataFrame({
                'Feature': feature_names,
                'Importance': importances,
                'Std': std
            })
            
            feature_importances = feature_importances.sort_values(by='Importance', ascending=False)
            print(feature_importances)
            
            plt.figure(figsize=(10, 6))
            plt.barh(feature_importances['Feature'], feature_importances['Importance'], xerr=feature_importances['Std'], align='center')
            plt.xlabel('Feature Importance')
            plt.ylabel('Feature')
            plt.title(f'Permutation Feature Importance (dst={dst})')
            plt.gca().invert_yaxis()
            folder_name = "ML/importance/"
            plt.savefig(os.path.join(folder_name, f'feature_importance_{dst}_threelabel.pdf'), format='pdf')
            plt.show()
            feature_importances.to_csv(os.path.join(folder_name, f'feature_importance_{dst}_threelabel.csv'), index=False)
            
            # 保存每个 dst 的特征重要性 DataFrame
            all_importance_dfs.append(feature_importances)
        
        # 计算并绘制特征重要性相关性矩阵
        compute_and_plot_importance_correlation(all_importance_dfs, os.path.join(folder_name, 'importance_correlation_matrix_threelabel.pdf'), 
                                                os.path.join(folder_name, 'importance_correlation_matrix_threelabel.root'))
        
        if select_opt != -1:
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