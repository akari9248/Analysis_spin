#!/bin/bash
Baseinputfolder1="root/"
Plots_private_herwig="${Baseinputfolder1}plots_ML_Private_herwig.root"
Plots_private_pythia="${Baseinputfolder1}plots_ML_Private_pythia.root"
weights_qq="1,1,1,1"
weights_gg="1,1,1,1"
entries=1000000
Baseinputfolder2="/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets/Prediction/"
CMS_herwig_path="${Baseinputfolder2}QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18_CMSGen_jinitpt_600_7000_j2pt_130_7000_FourLabel1"
CMS_pythia_path=""
CMS_data_path="${Baseinputfolder2}JetHT_Run2018A-UL2018_jinitpt_600_7000_j2pt_130_7000_FourLabel1"
output_folder="root"
output_name="_RunIISummer20UL18"

root -l -q "Reweight.cc(\"$Plots_private_herwig\", \"$Plots_private_pythia\",
                        \"$CMS_herwig_path\", \"$CMS_pythia_path\", 
                        \"$CMS_data_path\", \"$output_folder\", \"$output_name\",
                        \"$weights_qq\", \"$weights_gg\", $entries)"