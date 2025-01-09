#!/bin/bash
mkdir -p log

nchunks=50
nparts=50

# spin="spinoff"
# inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_off/"
# SampleType="Private_pythia_"$spin

# spin="spinon"
# inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_on/"
# SampleType="Private_pythia_"$spin

# inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_spinon_450_forai/"
# SampleType="Private_Herwig_spinon"


# baseOutputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features_ak8_scale"
compile generate_sample.cpp
jinit_ptlow=700
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
baseInputFolder="/storage/shuangyuan/code/analysis_spin/dataset/"
inputFolders=(
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22
    Private_pythia_pt600toinf_off
    Private_pythia_pt600toinf_on
    # Decay_0_spinoff_600_Inf_forai
    # JetMET_Run2022C-ReReco2022
    # JetMET_Run2022D-ReReco2022
    # JetMET_Run2022E-ReReco2022
    # JetMET_Run2022F-PromptReco2022
    # JetMET_Run2022G-PromptReco2022
    # /storage/xiaoxue/code/data/herwig/Dipole_0_spinon_600_7000_forai/
    # /storage/xiaoxue/code/data/herwig/Dipole_0_spinoff_600_7000_forai/
    # /storage/shuangyuan/code/analysis_spin/dataset/Private_pythia_pt600toinf_dipole_on/
    # /storage/shuangyuan/code/analysis_spin/dataset/Private_pythia_pt600toinf_dipole_off/
    # /storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE
    # /storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_SpinOFF
)

baseOutputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features_ak8_flavour/"
outputFolders=(
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_CMSData_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF_CMSData_jinitpt_700_7000_j2pt_130_7000
    Private_pythia_spinoff_jinitpt_700_7000_j2pt_130_7000
    Private_pythia_spinon_jinitpt_700_7000_j2pt_130_7000
    # Private_herwig_spinon_jinitpt_700_7000_j2pt_130_7000
    # Private_herwig_spinoff_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022C-ReReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022D-ReReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022E-ReReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022F-PromptReco2022_jinitpt_700_7000_j2pt_130_7000
    # JetMET_Run2022G-PromptReco2022_jinitpt_700_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_CMSData_jinitpt_600_7000_j2pt_130_7000
    # QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_SpinOFF_CMSData_jinitpt_600_7000_j2pt_130_7000
)
# sampleTypes=(
#     JetHT_Run2018A-UL2018_
#     JetHT_Run2018B-UL2018_
#     JetHT_Run2018C-UL2018_
#     JetHT_Run2018D-UL2018_
# )
for ((i=0; i<${#outputFolders[@]}; i++)); do
    inputFolder=${baseInputFolder}${inputFolders[$i]}
    outputFolder=${baseOutputFolder}${outputFolders[$i]}
    # rm -r "${outputFolder}"/*.root
    [[ ! -d $outputFolder ]] && mkdir $outputFolder
    # SampleType=${sampleTypes[$i]}
    echo $inputFolder
    echo $outputFolder
    run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType PrivateMC"
    python3 dnn_load_train_ak8.py --sample_path0 "${outputFolder}/*.root" --entries 20000000 --mode Prediction --model_path /storage/shuangyuan/code/analysis_spin/Machine_learning/ML/model/Fourlabel1_Private_herwig_spinoff_jinitpt_700_7000_j2pt_130_7000_ak8
done