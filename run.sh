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
for spin in "spinon" "spinoff"; do
    inputFolder="/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_0_${spin}_600_Inf_forai/"
    #inputFolder="/extdisk/zlin/Machine_learning/test_datasets/Decay_0_${spin}_600_Inf_forai/"
    SampleType="Private_Herwig_${spin}"

    ptselection="jinitpt${jinit_ptlow}${jinit_pthigh}j2pt${j2_ptlow}${j2_pthigh}"
    outputRecoFolder="${baseOutputFolder}/RecoPlanes/${SampleType}"
    outputTrainFolder="${baseOutputFolder}/RecoPlanesTrain/${SampleType}${ptselection}"
    outputPredictedFolder="${baseOutputFolder}/ML/predict/"

    compile generate_sample.cpp
    rm "${outputRecoFolder}"/*.root
    run_parallel generate_sample -nchunks $nchunks -nparts $nparts -opt "-I ${inputFolder} -O ${outputRecoFolder} --jinit_ptlow ${jinit_ptlow} --jinit_pthigh ${jinit_pthigh} --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --SampleType PrivateMC"
done
############ Extract features #######################
# compile Extract_features_PrivateMC.cpp
# rm $outputFeatureFolder/*.root
# run_parallel Extract_features_PrivateMC -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder} --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh --spin 1 --OneGeVCut 1"
################### Get train results ##############
#python dnn_load_FourLabel.py --sample_path0  ${outputFeatureFolder}'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 1000000000 --suffix $outputPredictedFolder${SampleType}$ptselection
# python dnn_feature_importance_FourLabel.py --sample_path0  ${outputFeatureFolder}'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix $outputPredictedFolder${SampleType}$ptselection
##################  Derive final results ############
# compile Draw_plots_fourLabel_maxscore.cpp
# ./Draw_plots_fourLabel_maxscore -I $outputPredictedFolder${SampleType}$ptselection""  -O  "plots/ML_plots/Maxscore/"${SampleType}$ptselection"/"
# compile Draw_plots_fourLabel.cpp
# ./Draw_plots_fourLabel -I $outputPredictedFolder${SampleType}$ptselection""  -O  "plots/ML_plots/"${SampleType}$ptselection"/"
# compile Draw_plots_type.cpp
# ./Draw_plots_type -I ${outputFeatureFolder}  -O  "plots/plots/"${SampleType}$ptselection"/"