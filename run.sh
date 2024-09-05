#!/bin/bash
mkdir -p log

nchunks=100
nparts=100

# spin="spinoff"
# inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_off/"
# SampleType="Private_pythia_"$spin

# spin="spinon"
# inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_on/"
# SampleType="Private_pythia_"$spin

# inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_spinon_450_forai/"
# SampleType="Private_Herwig_spinon"


baseOutputFolder="/extdisk/zlin/Machine_learning"
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

# inputFolders=(
#     "/extdisk/zlin/Machine_learning/test_datasets/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22"
#     "/extdisk/zlin/Machine_learning/test_datasets/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF"
# )
# sampleTypes=(
#     "CMS_herwig_Pt-15to7000Run3"
#     "CMS_herwig_Pt-15to7000Run3_SpinOFF"
# )
inputFolders=(
    "/extdisk/zlin/Machine_learning/test_datasets/QCD_Pt-15to7000_Flat_pythia8-Run3Summer22"
)
sampleTypes=(
    "CMS_pythia_Pt-15to7000Run3"
)
nchunks=100
nparts=10
for ((i=0; i<${#inputFolders[@]}; i++)); do
    inputFolder=${inputFolders[$i]}
    SampleType=${sampleTypes[$i]}
    
    ptselection="jinitpt${jinit_ptlow}${jinit_pthigh}j2pt${j2_ptlow}${j2_pthigh}"
    outputRecoFolder="${baseOutputFolder}/RecoPlanes/${SampleType}"${ptselection}
    outputTrainFolder="${baseOutputFolder}/RecoPlanesTrain/${SampleType}${ptselection}"
    outputPredictedFolder="${baseOutputFolder}/ML/predict/"
    compile generate_sample.cpp
    rm "${outputRecoFolder}"/*.root
    run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputRecoFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType CMSMCGen"

done

# inputFolders=(
#     /home/public/Datasets/newdata/JetHT_Run2016B-ver1_HIPM_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016B-ver2_HIPM_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016C_HIPM_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016D_HIPM_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016E_HIPM_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016F_HIPM_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016F_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016G_UL2016
#     /home/public/Datasets/newdata/JetHT_Run2016H_UL2016
# )
# sampleTypes=(
#     JetHT_Run2016B-ver1_HIPM_UL2016
#     JetHT_Run2016B-ver2_HIPM_UL2016
#     JetHT_Run2016C_HIPM_UL2016
#     JetHT_Run2016D_HIPM_UL2016
#     JetHT_Run2016E_HIPM_UL2016
#     JetHT_Run2016F_HIPM_UL2016
#     JetHT_Run2016F_UL2016
#     JetHT_Run2016G_UL2016
#     JetHT_Run2016H_UL2016
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
#     run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputRecoFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType CMSData"

# done