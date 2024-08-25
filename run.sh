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

inputFolders=(
    "/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18"
)
sampleTypes=(
    "CMS_herwig_Pt-15to7000"
)
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