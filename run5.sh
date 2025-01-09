#!/bin/bash
mkdir -p log

nchunks=50
nparts=50

jinit_ptlow=700
jinit_pthigh=7000
j2_ptlow=130
j2_pthigh=7000

inputFolder="/storage/xiaoxue/code/data/CMSMC/AK8/AK8_MC/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF"
baseOutputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features_ak8_scale_uncertainty/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22_SpinOFF-Run3Summer22_CMSData_jinitpt_700_7000_j2pt_130_7000"
# inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/CMSMC/AK8_MC/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE"
# baseOutputFolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/features_ak8_scale_uncertainty/QCD_Pt-15to7000_Flat_herwig7-Run3Summer22EE_CMSData_jinitpt_700_7000_j2pt_130_7000"

# uncertaintyTypes=(
#     JESUp JESDn JERUp JERDn JERNm
#     ChargedUp ChargedDn PhotonUp PhotonDn
#     NeutralUp NeutralDn TrackEff
# )
uncertaintyTypes=(
    JESUp JESDn JERUp JERDn JERNm
    ChargedUp ChargedDn PhotonUp PhotonDn
    NeutralUp NeutralDn TrackEff
)
# uncertaintyTypes=(PhotonDn)
for ((i=0; i<${#uncertaintyTypes[@]}; i++)); do
    outputFolder=${baseOutputFolder}"_"${uncertaintyTypes[$i]}
    # echo ${inputFolder}
    # echo ${outputFolder}
    [[ ! -d $outputFolder ]] && mkdir $outputFolder
    run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputFolder} --jinit_ptlow 700 --jinit_pthigh 7000 --j2_ptlow 130 --j2_pthigh 7000 --SampleType CMSData --jdEnergyUncertainty ${uncertaintyTypes[$i]}"
    python3 dnn_load_train_ak8_uncertainty.py --sample_path0 "${outputFolder}/*.root" --entries -1 --mode Prediction --model_path /storage/shuangyuan/code/analysis_spin/Machine_learning/ML/model/Fourlabel1_Private_herwig_spinoff_jinitpt_700_7000_j2pt_130_7000_ak8 
done