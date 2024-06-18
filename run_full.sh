#!/bin/bash
mkdir -p log

nchunks=100
nparts=10
inputFolder="/storage/shuangyuan/code/analysis_spin/dataset/QCD_HT1000to1500-madgraphMLM-herwig7-RunIISummer17"
SampleType="CMS_herwig_HT1000to1500Summer17"

# inputFolder="/home/public/Datasets/herwight/QCD_HT1000to1500-madgraphMLM-herwig7-RunIISummer20UL16"
# SampleType="CMS_herwig_HT1000to1500"

# inputFolder="/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL17"
# SampleType="CMS_herwig_Pt-15to7000UL17"

# inputFolder="/home/public/Datasets/newherwig/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL16"
# SampleType="CMS_herwig_Pt-15to7000UL16"

baseOutputFolder="/extdisk/zlin/Machine_learning"
outputRecoFolder=$baseOutputFolder"/RecoPlanes/"$SampleType

jinit_ptlow=450;
jinit_pthigh=600;

j2_ptlow=80;
j2_pthigh=120;
# j2_ptlow=160;
# j2_pthigh=200;

ptselection=_jinitpt${jinit_ptlow}_${jinit_pthigh}_j2pt${j2_ptlow}_${j2_pthigh}
outputFeatureFolder=$baseOutputFolder"/RecoPlanesFeatures/"$SampleType$ptselection
outputTrainFolder=$baseOutputFolder"/RecoPlanesFeaturesTrain/"$SampleType$ptselection


############ Reco Planes #######################

g++ generate_sample_CMSMC.cpp -I/home/zlin/.local/include -I/home/zlin/app/IFNPlugin -L/home/zlin/app/IFNPlugin -L/home/zlin/.local/lib -lRecursiveTools -lIFNPlugin `root-config --cflags --ldflags --glibs` `fastjet-config --cxxflags --libs --plugins` -o generate_sample_CMSMC
if [ $? -ne 0 ]; then
  echo "Compilation failed. Exiting."
  exit 1
fi
echo "Submitting generate_sample_CMSMC processes in $nchunks chunks. Input folder = $inputFolder, output folder = $outputRecoFolder"
for i in $(seq 0 $(($nchunks-1)))
do
  nohup ./generate_sample_CMSMC -i $i -I $inputFolder -O $outputRecoFolder -n $nparts -k $nchunks > log/output_$i.log 2>&1 &
done
wait

############ Extract features #######################

## Reco #####
g++ Extract_features_stdReco.cpp -I/home/zlin/.local/include -I/home/zlin/app/IFNPlugin -L/home/zlin/app/IFNPlugin -L/home/zlin/.local/lib -lRecursiveTools -lIFNPlugin `root-config --cflags --ldflags --glibs` `fastjet-config --cxxflags --libs --plugins` -o Extract_features_stdReco
if [ $? -ne 0 ]; then
  echo "Compilation failed. Exiting."
  exit 1
fi
echo "Submitting Extract_features_stdReco processes in $nchunks chunks. Input folder = $outputRecoFolder, output folder = ${outputFeatureFolder}Reco"
for i in $(seq 0 $(($nchunks-1)))
do
  nohup ./Extract_features_stdReco -I $outputRecoFolder -O ${outputFeatureFolder}Reco --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh -i $i  -n $nparts -k $nchunks > log/output_reco_$i.log 2>&1 &
done
wait

## Gen #####
g++ Extract_features_stdGen.cpp -I/home/zlin/.local/include -I/home/zlin/app/IFNPlugin -L/home/zlin/app/IFNPlugin -L/home/zlin/.local/lib -lRecursiveTools -lIFNPlugin `root-config --cflags --ldflags --glibs` `fastjet-config --cxxflags --libs --plugins` -o Extract_features_stdGen
if [ $? -ne 0 ]; then
  echo "Compilation failed. Exiting."
  exit 1
fi
echo "Submitting Extract_features_stdGen processes in $nchunks chunks. Input folder = $outputRecoFolder, output folder = ${outputFeatureFolder}Gen"
for i in $(seq 0 $(($nchunks-1)))
do
  nohup ./Extract_features_stdGen -I $outputRecoFolder -O ${outputFeatureFolder}Gen --jinit_ptlow $jinit_ptlow  --jinit_pthigh $jinit_pthigh --j2_ptlow $j2_ptlow  --j2_pthigh $j2_pthigh -i $i -n $nparts -k $nchunks > log/output_gen_$i.log 2>&1 &
done
wait

################### Get train results ##############

python dnn_load_FourLabelCMS.py --sample_path0  ${outputFeatureFolder}Gen'/*.root'  --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix ${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen"
python dnn_load_FourLabelCMS.py --sample_path0  ${outputFeatureFolder}Reco'/*.root' --model_path ML/model/fourLabels_j2pt${j2_ptlow}_${j2_pthigh} --entries 100000000 --suffix ${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco"

##################  Derive final results ############

g++ Draw_plots_mini2ML_threeLabelCMS.cpp  -I/home/zlin/.local/include -I/home/zlin/app/IFNPlugin -L/home/zlin/app/IFNPlugin  -L/home/zlin/.local/lib -lRecursiveTools -lIFNPlugin  `root-config --cflags --ldflags --glibs` `fastjet-config --cxxflags --libs --plugins`   -o Draw_plots_mini2ML_threeLabel;
if [ $? -ne 0 ]; then
  echo "Compilation failed. Exiting."
  exit 1
fi
./Draw_plots_mini2ML_threeLabel -I "ML/predict/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen"  -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Gen/"
./Draw_plots_mini2ML_threeLabel -I "ML/predict/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco" -O  "plots/ML_plots/"${SampleType}j2pt${j2_ptlow}_${j2_pthigh}"Reco/"