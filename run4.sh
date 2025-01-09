#!/bin/bash
mkdir -p log

nchunks=50
nparts=50


baseOutputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features_ak8_scale/"
baseInputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/CMSMC/"
jinit_ptlow=700
jinit_pthigh=7000
j2_ptlow=130
j2_pthigh=7000


inputFolders=(
    # AK8_MC/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22
    # AK8_MC/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF
    # AK8_MC/QCD_Pt-15to7000_Flat_pythia8-Run3Summer22
    # AK8_MC/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE
    # AK8_MC/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_SpinOFF 
    AK8_MC/QCD_HT700to1000-madgraphMLM-pythia8-RunIISummer20UL18
    AK8_MC/QCD_HT1000to1500-madgraphMLM-pythia8-RunIISummer20UL18
    AK8_MC/QCD_HT1500to2000-madgraphMLM-pythia8-RunIISummer20UL18
    AK8_MC/QCD_HT2000toInf-madgraphMLM-pythia8-RunIISummer20UL18
    # AK8_MC/QCD_Pt_15to7000_Flat_pythia_RunIISummer20UL18
    # AK8_Data/JetHT_Run2018A-UL2018
    # AK8_Data/JetHT_Run2018B-UL2018
    # AK8_Data/JetHT_Run2018C-UL2018
    # AK8_Data/JetHT_Run2018D-UL2018
    # AK8_Data/JetMET_Run2022C-ReReco2022
    # AK8_Data/JetMET_Run2022D-ReReco2022
    # AK8_Data/JetMET_Run2022E-ReReco2022
    # AK8_Data/JetMET_Run2022F-PromptReco2022
    # AK8_Data/JetMET_Run2022G-PromptReco2022
    
)

outputFolders=(
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_CMSData_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF-Run3Summer22_CMSData_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_pythia8-Run3Summer22_CMSData_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_CMSData_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_SpinOFF_CMSData_jinitpt_700_7000_j2pt_130_7000
    QCD_HT700to1000-madgraphMLM-pythia8-RunIISummer20UL18_CMSData_jinitpt_700_7000_j2pt_130_7000
    QCD_HT1000to1500-madgraphMLM-pythia8-RunIISummer20UL18_CMSData_jinitpt_700_7000_j2pt_130_7000
    QCD_HT1500to2000-madgraphMLM-pythia8-RunIISummer20UL18_CMSData_jinitpt_700_7000_j2pt_130_7000
    QCD_HT2000toInf-madgraphMLM-pythia8-RunIISummer20UL18_CMSData_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt_15to7000_Flat_pythia_RunIISummer20UL18_CMSData_jinitpt_700_7000_j2pt_130_7000
    # JetHT_Run2018A-UL2018_jinitpt_700_7000_j2pt_130_7000
    # JetHT_Run2018B-UL2018_jinitpt_700_7000_j2pt_130_7000
    # JetHT_Run2018C-UL2018_jinitpt_700_7000_j2pt_130_7000
    # JetHT_Run2018D-UL2018_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022C-ReReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022D-ReReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022E-ReReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022F-PromptReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022G-PromptReco2022_jinitpt_700_7000_j2pt_130_7000
)
# sampleTypes=(
#     JetHT_Run2018A-UL2018_
#     JetHT_Run2018B-UL2018_
#     JetHT_Run2018C-UL2018_
#     JetHT_Run2018D-UL2018_
# )
for ((i=0; i<${#inputFolders[@]}; i++)); do
    inputFolder=${baseInputFolder}${inputFolders[$i]}
    outputFolder=${baseOutputFolder}${outputFolders[$i]}
    # rm -r "${outputFolder}"/*.root
    [[ ! -d $outputFolder ]] && mkdir $outputFolder
    # SampleType=${sampleTypes[$i]}
    echo $inputFolder
    echo $outputFolder
    run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType CMSData"
    python3 dnn_load_train_ak8.py --sample_path0 "${outputFolder}/*.root" --entries -1 --mode Prediction --model_path /storage/shuangyuan/code/analysis_spin/Machine_learning/ML/model/Fourlabel1_Private_herwig_spinoff_jinitpt_700_7000_j2pt_130_7000_ak8

done
