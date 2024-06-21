#!/bin/bash
mkdir -p log

nchunks=100
nparts=10
# inputFolder="/storage/shuangyuan/code/analysis_spin/dataset/QCD_HT1000to1500-madgraphMLM-herwig7-RunIISummer17"
# SampleType="CMS_herwig_HT1000to1500Summer17"

# rm -rf /extdisk/zlin/Machine_learning/*/CMS_herwig_HT1000to1500Summer17*
# rm -rf ML/predict/CMS_herwig_HT1000to1500Summer17*

inputFolder="/home/public/Datasets/herwight/QCD_HT1000to1500-madgraphMLM-herwig7-RunIISummer20UL16"
SampleType="CMS_herwig_HT1000to1500"
# inputFolder="/home/public/Datasets/herwight/QCD_HT1000to1500-madgraphMLM-herwig7-RunIISummer20UL16-preVFP"
# SampleType="CMS_herwig_HT1000to1500-preVFP"

# inputFolder="/home/public/Datasets/herwight/QCD_HT1500to2000-madgraphMLM-herwig7-RunIISummer20UL16-preVFP"
# SampleType="CMS_herwig_HT1500to2000-preVFP"

# inputFolder="/home/public/Datasets/herwight/QCD_HT1500to2000-madgraphMLM-herwig7-RunIISummer20UL16"
# SampleType="CMS_herwig_HT1500to2000"

# inputFolder="/home/public/Datasets/herwight/QCD_HT700to1000-madgraphMLM-herwig7-RunIISummer20UL16-preVFP"
# SampleType="CMS_herwig_HT700to1000-preVFP"

# inputFolder="/home/public/Datasets/herwight/QCD_HT700to1000-madgraphMLM-herwig7-RunIISummer20UL16"
# SampleType="CMS_herwig_HT700to1000"

# inputFolder="/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL17"
# SampleType="CMS_herwig_Pt-15to7000UL17"

# inputFolder="/home/public/Datasets/newherwig/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL16"
# SampleType="CMS_herwig_Pt-15to7000UL16"

baseOutputFolder="/extdisk/zlin/Machine_learning"
outputRecoFolder=$baseOutputFolder"/RecoPlanes/"$SampleType

jinit_ptlow=450;
jinit_pthigh=600;

# j2_ptlow=80;
# j2_pthigh=120;
j2_ptlow=160;
j2_pthigh=200;

ptselection=_jinitpt${jinit_ptlow}_${jinit_pthigh}_j2pt${j2_ptlow}_${j2_pthigh}
outputFeatureFolder=$baseOutputFolder"/RecoPlanesFeatures/"$SampleType$ptselection
outputTrainFolder=$baseOutputFolder"/RecoPlanesFeaturesTrain/"$SampleType$ptselection

############ Reco Planes #######################
compile generate_sample_PrivateMC.cpp
run_parallel generate_sample_PrivateMC -nchunks $nchunks -nparts $nparts -opt "-I $inputFolder -O $outputRecoFolder"
############ Extract features #######################
## Reco #####
compile Extract_features_stdReco.cpp
run_parallel Extract_features_stdReco -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder}Reco --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh"
## Gen #####
compile Extract_features_stdGen.cpp
run_parallel Extract_features_stdGen -nchunks $nchunks -nparts $nparts -opt "-I $outputRecoFolder -O ${outputFeatureFolder}Gen --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh"
################### Get train results ##############
python dnn_load_FourLabelCMS.py --sample_path0  ${outputFeatureFolder}Gen'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix ${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen"
python dnn_load_FourLabelCMS.py --sample_path0  ${outputFeatureFolder}Reco'/*.root' --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix ${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco"
##################  Derive final results ############
compile Draw_plots_mini2ML_threeLabelCMS.cpp
./Draw_plots_mini2ML_threeLabelCMS -I "ML/predict/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen"  -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen/"
./Draw_plots_mini2ML_threeLabelCMS -I "ML/predict/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco" -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco/"