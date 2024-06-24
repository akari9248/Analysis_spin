#!/bin/bash
mkdir -p log

nchunks=100
nparts=100

spin="spinoff"
inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_off/"
SampleType="Private_pythia_"$spin

# spin="spinoff"
# inputFolder="/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_off/"
# SampleType="Private_pythia_"$spin

# inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_spinon_450_forai/"
# SampleType="Private_Herwig_spinon"
# spin="spinon"
# inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_"$spin"_450_forai/"
# SampleType="Private_Herwig_"$spin

baseOutputFolder="/extdisk/zlin/Machine_learning"

jinit_ptlow=450;
jinit_pthigh=600;

j2_ptlow=160;
j2_pthigh=200;

ptselection=_jinitpt${jinit_ptlow}_${jinit_pthigh}_j2pt${j2_ptlow}_${j2_pthigh}
outputRecoFolder=$baseOutputFolder"/RecoPlanes/"$SampleType
outputFeatureFolder=$baseOutputFolder"/RecoPlanesFeatures/"$SampleType$ptselection
outputTrainFolder=$baseOutputFolder"/RecoPlanesFeaturesTrain/"$SampleType$ptselection
outputPredictedFolder=$baseOutputFolder"/ML/predict/"
############ Reco Planes #######################
# compile generate_sample_PrivateMC.cpp
# rm $outputRecoFolder/*.root
# run_parallel generate_sample_PrivateMC -nchunks $nchunks -nparts $nparts -opt "-I $inputFolder -O $outputRecoFolder"
############ Extract features #######################
compile Extract_features_PrivateMC.cpp
rm $outputFeatureFolder/*.root
run_parallel Extract_features_PrivateMC -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder} --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --spin 1 --OneGeVCut 1"
################### Get train results ##############
python dnn_load_FourLabel.py --sample_path0  ${outputFeatureFolder}'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}
##################  Derive final results ############
compile Draw_plots_mini2ML_threeLabel.cpp
./Draw_plots_mini2ML_threeLabel -I $outputPredictedFolder${SampleType}j2pt${j2_ptlow}_${j2_pthigh}""  -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"/"