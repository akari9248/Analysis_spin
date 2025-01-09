#!/bin/bash
mkdir -p log
# source /usr/local/root/6.32.04/bin/thisroot.sh
nchunks=50
nparts=50

# spin="spinoff"
# inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_off/"
# SampleType="Private_pythia_"$spin

# spin="spinon"
BaseinputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features/"
# SampleType="Private_pythia_"$spin

# inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_spinon_450_forai/"
# SampleType="Private_Herwig_spinon"


# baseOutputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features"
jinit_ptlow=600
jinit_pthigh=7000
j2_ptlow=130
j2_pthigh=7000
# for spin in "spinon" "spinoff"; do
#     #inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_0_${spin}_800_infinity_forai/"
#     inputFolder="/extdisk/zlin/Machine_learning/test_datasets/Decay_0_${spin}_600_Inf_forai/"
#     SampleType="Private_Herwig_${spin}"
#     ptselection="jinitpt${jinit_ptlow}${jinit_pthigh}j2pt${j2_ptlow}${j2_pthigh}"
#     outputRecoFolder="${baseOutputFolder}/RecoPlanes/${SampleType}"${ptselection}
#     outputTrainFolder="${baseOutputFolder}/RecoPlanesTrain/${SampleType}${ptselection}"
#     outputPredictedFolder="${baseOutputFolder}/ML/predict/"
#     compile generate_sample.cpp
#     rm "${outputRecoFolder}"/*.root
#     run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputRecoFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType PrivateMC"
# done

# inputFolders=(
#     "/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18"
# )
# sampleTypes=(
#     "CMS_herwig_Pt-15to7000"
# )
# for ((i=0; i<${#inputFolders[@]}; i++)); do
#     inputFolder=${inputFolders[$i]}
#     SampleType=${sampleTypes[$i]}
    
#     ptselection="jinitpt${jinit_ptlow}${jinit_pthigh}j2pt${j2_ptlow}${j2_pthigh}"
#     outputRecoFolder="${baseOutputFolder}/RecoPlanes/${SampleType}"${ptselection}
#     outputTrainFolder="${baseOutputFolder}/RecoPlanesTrain/${SampleType}${ptselection}"
#     outputPredictedFolder="${baseOutputFolder}/ML/predict/"
#     compile generate_sample.cpp
#     rm "${outputRecoFolder}"/*.root
#     run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputRecoFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType CMSMCGen"

# done

inputFolders=(
    "JetHT_Run2018A-UL2018_jinitpt_600_7000_j2pt_130_7000"
    "JetHT_Run2018B-UL2018_jinitpt_600_7000_j2pt_130_7000"
    "JetHT_Run2018C-UL2018_jinitpt_600_7000_j2pt_130_7000"
    "JetHT_Run2018D-UL2018_jinitpt_600_7000_j2pt_130_7000"
    "JetMET_Run2022C-ReReco2022_jinitpt_600_7000_j2pt_130_7000"
    "JetMET_Run2022D-ReReco2022_jinitpt_600_7000_j2pt_130_7000"
    "JetMET_Run2022E-ReReco2022_jinitpt_600_7000_j2pt_130_7000"
    "JetMET_Run2022F-PromptReco2022_jinitpt_600_7000_j2pt_130_7000"
    "JetMET_Run2022G-PromptReco2022_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_1000to1400_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_1000to1400_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_1400to1800_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_1400to1800_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_CMSData_newMC_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF_CMSData_newMC_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt-15to7000_Flat_pythia8-Run3Summer22_CMSData_newMC_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt-15to7000_Flat_pythia8-Run3Summer22_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_1800to2400_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_1800to2400_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_2400to3200_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_2400to3200_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_3200toInf_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_3200toInf_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_600to800_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_600to800_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_800to1000_pythia8-RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000"
    "QCD_Pt_800to1000_pythia8-RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000"
)

baseOutputFolder="/storage/xiaoxue/code/analysis_rootfile/Machine_learning/"
outputFolders=(
    # QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18_CMSData_jinitpt_600_7000_j2pt_130_7000
    QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_CMSGData_newMC_jinitpt_600_7000_j2pt_130_7000
    QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF_CMSGData_newMC_jinitpt_600_7000_j2pt_130_7000
    QCD_Pt-15to7000_Flat_pythia8-Run3Summer22_CMSGData_newMC_jinitpt_600_7000_j2pt_130_7000
)
# sampleTypes=(
#     JetHT_Run2018A-UL2018_
#     JetHT_Run2018B-UL2018_
#     JetHT_Run2018C-UL2018_
#     JetHT_Run2018D-UL2018_
# )
compile generate_sample.cpp
for ((i=0; i<${#inputFolders[@]}; i++)); do
    inputFolder=${BaseinputFolder}${inputFolders[$i]}
    # outputFolder=${baseOutputFolder}${outputFolders[$i]}
    # rm -r "${outputFolder}"/*.root
    # [[ ! -d $outputFolder ]] && mkdir $outputFolder
    # SampleType=${sampleTypes[$i]}
    
    # ptselection="jinitpt_${jinit_ptlow}_${jinit_pthigh}_j2pt_${j2_ptlow}_${j2_pthigh}"
    # outputRecoFolder="${baseOutputFolder}/${SampleType}"${ptselection}
    # outputTrainFolder="${baseOutputFolder}/RecoPlanesTrain/${SampleType}${ptselection}"
    # outputPredictedFolder="${baseOutputFolder}/ML/predict/"
    # compile generate_sample.cpp
    # rm "${outputRecoFolder}"/*.root
    # run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType CMSData"
    python3 dnn_load_train_kt.py --sample_path0 "${inputFolder}/*.root" --entries -1 --mode Prediction --model_path /storage/shuangyuan/code/analysis_spin/Machine_learning/ML/model/Fourlabel1_Private_herwig_spinoff_jinitpt_600_7000_j2pt_130_7000_kt2_2_Inf
done