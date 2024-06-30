#!/bin/bash

inputFolders=(
    "/home/public/Datasets/newdata/JetHT_Run2016F_UL2016"
    "/home/public/Datasets/newdata/JetHT_Run2016G_UL2016"
    "/home/public/Datasets/newdata/JetHT_Run2016H_UL2016"
)
sampleTypes=(
    "JetHT_Run2016F_UL2016"
    "JetHT_Run2016G_UL2016"
    "JetHT_Run2016H_UL2016"
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

# j2_ptlow=80
# j2_pthigh=120
j2_ptlow=160
j2_pthigh=200

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
    # compile generate_sample_CMSData.cpp
    # run_parallel generate_sample_CMSData -nchunks $nchunks -nparts $nparts -opt "-I $inputFolder -O $outputRecoFolder"
    
    ############ Extract features #######################
    ## Reco #####
    compile Extract_features_stdCMSReco.cpp
    run_parallel Extract_features_stdCMSReco -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder}Reco --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh"
    
    ################### Get train results ##############
    python dnn_load_FourLabel.py --sample_path0 ${outputFeatureFolder}Reco'/*.root' --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco"
    
    ##################  Derive final results ############
    compile Draw_plots_fourLabel.cpp
    ./Draw_plots_fourLabel -I $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco" -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco/"
done