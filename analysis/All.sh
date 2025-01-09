#!/bin/bash
Baseinputfolder="/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets/Prediction/"
Private_hewrig_off_path="${Baseinputfolder}Private_herwig_spinoff_jinitpt_600_7000_j2pt_130_7000_FourLabel1"
Private_hewrig_on_path="${Baseinputfolder}Private_herwig_spinon_jinitpt_600_7000_j2pt_130_7000_FourLabel1"
Private_pythia_off_path="${Baseinputfolder}Private_pythia_spinoff_jinitpt_600_7000_j2pt_130_7000_FourLabel1"
Private_pythia_on_path="${Baseinputfolder}Private_pythia_spinon_jinitpt_600_7000_j2pt_130_7000_FourLabel1"
CMS_herwig_path=""
CMS_pythia_path=""
CMS_data_path=""

# Private_hewrig_off_path=""
# Private_hewrig_on_path=""
# Private_pythia_off_path=""
# Private_pythia_on_path=""
# CMS_herwig_path=""
# CMS_pythia_path=""
# CMS_data_path=""

output_CMS_herwig_name=""
output_CMS_pythia_name=""
output_CMS_data_name=""
weights_qq="1,1,1,1"
weights_gg="1,1,1,1"
entries=-1
Root_outputfolder="root"
Scale_private_herwig=0.496
Scale_private_pythia=1.143
Scale_CMS_herwig=1
Scale_CMS_pythia=1

suffix_qq=""
suffix_gg=""

if [ "$weights_qq" != "1,1,1,1" ]; then
  suffix_qq=${weights_qq//,/_} 
  suffix_qq="_weightqq_${suffix_qq}"
fi 

if [ "$weights_gg" != "1,1,1,1" ]; then
  suffix_gg=${weights_gg//,/_} 
  suffix_gg="_weightgg_${suffix_gg}"
fi

echo $suffix_qq

root -l -q "GetMLHist.cc(\"$Private_hewrig_off_path\", \"$Private_hewrig_on_path\", \"$Private_pythia_off_path\", \"$Private_pythia_on_path\", 
                         \"$CMS_herwig_path\", \"$CMS_pythia_path\", \"$CMS_data_path\", 
                         \"$weights_qq\", \"$weights_gg\", $entries, \"$Root_outputfolder\",
                         \"$output_CMS_herwig_name\", \"$output_CMS_pythia_name\", \"$output_CMS_data_name\")"

Plots_roc_path=""
Plots_Private_herwig_path=""
Plots_Private_pythia_path=""
Plots_CMS_herwig_path=""
Plots_CMS_pythia_path=""
Plots_CMS_data_path=""

if [ "$Private_hewrig_off_path" != "" ] && [ "$Private_hewrig_on_path" != "" ]; then
  Plots_roc_path="${Root_outputfolder}/plots_ML_Roc${suffix_qq}${suffix_gg}"
  Plots_Private_herwig_path="${Root_outputfolder}/plots_ML_Private_herwig${suffix_qq}${suffix_gg}"
  Scale --scale $Scale_private_herwig --root_file "${Plots_Private_herwig_path}.root" --output_file "${Plots_Private_herwig_path}_scale${Scale_private_herwig}.root"
fi

if [ "$Private_pythia_off_path" != "" ] && [ "$Private_pythia_on_path" != "" ]; then
  Plots_Private_pythia_path="${Root_outputfolder}/plots_ML_Private_pythia${suffix_qq}${suffix_gg}"
  Scale --scale $Scale_private_pythia --root_file "${Plots_Private_pythia_path}.root" --output_file "${Plots_Private_pythia_path}_scale${Scale_private_pythia}.root"
fi

if [ "$CMS_herwig_path" != "" ]; then
  Plots_CMS_herwig_path="${Root_outputfolder}/plots_ML_CMSMC_herwig${output_CMS_herwig_name}${suffix_qq}${suffix_gg}"
  Scale --scale $Scale_CMS_herwig --root_file "${Plots_CMS_herwig_path}.root" --output_file "${Plots_CMS_herwig_path}_scale${Scale_CMS_herwig}.root"
fi

if [ "$CMS_pythia_path" != "" ]; then
  Plots_CMS_pythia_path="${Root_outputfolder}/plots_ML_CMSMC_pythia${output_CMS_pythia_name}${suffix_qq}${suffix_gg}"
  Scale --scale $Scale_CMS_pythia --root_file "${Plots_CMS_pythia_path}.root" --output_file "${Plots_CMS_pythia_path}_scale${Scale_CMS_pythia}.root"
fi

if [ "$CMS_data_path" != "" ]; then
  Plots_CMS_data_path="${Root_outputfolder}/plots_ML_CMS_data${output_CMS_data_name}${suffix_qq}${suffix_gg}"
fi

# Plots_roc="${Root_outputfolder}/plots_ML_Roc.root"
# Plots_private_herwig="${Root_outputfolder}/plots_ML_Private_herwig_scale0.496.root"
# Plots_private_pythia="${Root_outputfolder}/plots_ML_Private_pythia_scale1.143.root"
# Plots_cms_herwig=""
# Plots_cms_pythia=""
# Plots_cms_data=""
output_folder="pdf"

root -l -q "AnalyzeML.cc(\"${Plots_roc_path}.root\", 
                         \"${Plots_Private_herwig_path}_scale${Scale_private_herwig}.root\", 
                         \"${Plots_Private_pythia_path}_scale${Scale_private_pythia}.root\",
                         \"${Plots_CMS_herwig_path}_scale${Scale_CMS_herwig}.root\", 
                         \"${Plots_CMS_pythia_path}_scale${Scale_CMS_pythia}.root\", 
                         \"${Plots_CMS_data}.root\", \"$output_folder\",
                         \"$weights_qq\", \"$weights_gg\")"