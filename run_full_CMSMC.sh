#!/bin/bash

inputFolders=(
    "/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt_470to600_pythia8-RunIISummer20UL16"
    "/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt_600to800_pythia8-RunIISummer20UL16"
    "/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt_800to1000_pythia8-RunIISummer20UL16"
)
sampleTypes=(
    "CMS_pythia_Pt470to600"
    "CMS_pythia_Pt600to800"
    "CMS_pythia_Pt800to1000"
)
# inputFolders=(
#     "/home/public/Datasets/herwight/QCD_HT700to1000-madgraphMLM-herwig7-RunIISummer20UL16"
#     "/home/public/Datasets/herwight/QCD_HT1000to1500-madgraphMLM-herwig7-RunIISummer20UL16"
#     "/home/public/Datasets/herwight/QCD_HT1500to2000-madgraphMLM-herwig7-RunIISummer20UL16"
#     "/home/public/Datasets/herwight/QCD_HT2000toInf-madgraphMLM-herwig7-RunIISummer20UL16"
# )
# sampleTypes=(
#     "CMS_herwig_HT700to1000"
#     "CMS_herwig_HT1000to1500"
#     "CMS_herwig_HT1500to2000"
#     "CMS_herwig_HT2000toInf"
# )

# 确保两个数组长度相同
if [ ${#inputFolders[@]} -ne ${#sampleTypes[@]} ]; then
    echo "Error: The number of input folders and sample types must be the same."
    exit 1
fi

# 其他变量
mkdir -p log
baseOutputFolder="/extdisk/zlin/Machine_learning"
nchunks=100
nparts=10

jinit_ptlow=450
jinit_pthigh=600

j2_ptlow=80
j2_pthigh=120
# j2_ptlow=160
# j2_pthigh=200

ptselection="_jinitpt${jinit_ptlow}_${jinit_pthigh}_j2pt${j2_ptlow}_${j2_pthigh}"

# 循环处理每个输入文件夹和样本类型
for ((i=0; i<${#inputFolders[@]}; i++)); do
    inputFolder=${inputFolders[$i]}
    SampleType=${sampleTypes[$i]}
    
    outputRecoFolder=$baseOutputFolder"/RecoPlanes/"$SampleType
    outputFeatureFolder=$baseOutputFolder"/RecoPlanesFeatures/"$SampleType$ptselection
    outputTrainFolder=$baseOutputFolder"/RecoPlanesFeaturesTrain/"$SampleType$ptselection
    outputPredictedFolder=$baseOutputFolder"/ML/predict/"
    ############ Reco Planes #######################
    # compile generate_sample_CMSMC.cpp
    # run_parallel generate_sample_CMSMC -nchunks $nchunks -nparts $nparts -opt "-I $inputFolder -O $outputRecoFolder"
    
    ############ Extract features #######################
    ## Reco #####
    # compile Extract_features_stdCMSReco.cpp
    run_parallel Extract_features_stdCMSReco -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder}Reco --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh"
    
    ## Gen #####
    # compile Extract_features_stdCMSGen.cpp
    run_parallel Extract_features_stdCMSGen -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder}Gen --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh"
    
    ################### Get train results ##############
    python dnn_load_FourLabel.py --sample_path0 ${outputFeatureFolder}Gen'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen"
    python dnn_load_FourLabel.py --sample_path0 ${outputFeatureFolder}Reco'/*.root' --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco"
    
    ##################  Derive final results ############
    # compile Draw_plots_mini2ML_threeLabel.cpp
    ./Draw_plots_mini2ML_threeLabel -I $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen"  -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen/"
    ./Draw_plots_mini2ML_threeLabel -I $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco" -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco/"
done