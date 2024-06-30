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
spin="spinoff"
inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_"$spin"_450_forai/"
SampleType="Private_Herwig_"$spin

baseOutputFolder="/extdisk/zlin/Machine_learning"

jinit_ptlow=600;
jinit_pthigh=800;

j2_ptlow=80;
j2_pthigh=120;

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
python dnn_load_FourLabel.py --sample_path0  ${outputFeatureFolder}'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 1000000000 --suffix $outputPredictedFolder${SampleType}$ptselection
##################  Derive final results ############
compile Draw_plots_fourLabel.cpp
./Draw_plots_fourLabel -I $outputPredictedFolder${SampleType}$ptselection""  -O  "plots/ML_plots/"${SampleType}$ptselection"/"
# compile Draw_plots_type.cpp
# ./Draw_plots_type -I ${outputFeatureFolder}  -O  "plots/plots/"${SampleType}$ptselection"/"