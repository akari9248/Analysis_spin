#!/bin/bash
Baseinputfolder="root/"
Plots_roc="${Baseinputfolder}plots_ML_Roc.root"
Plots_private_herwig="${Baseinputfolder}plots_ML_Private_herwig_scale0.496.root"
Plots_private_pythia="${Baseinputfolder}plots_ML_Private_pythia_scale1.143.root"
Plots_cms_herwig="${Baseinputfolder}plots_ML_CMSMC_herwig_RunIISummer20UL18.root"
Plots_cms_pythia=""
Plots_cms_herwig_reweight="${Baseinputfolder}plots_ML_CMSMC_herwig_RunIISummer20UL18_reweight.root"
Plots_cms_pythia_reweight=""
Plots_cms_data="${Baseinputfolder}plots_ML_CMS_data_JetHT_Run2018.root"
output_folder="pdf"
weights_qq="1,1,1,1"
weights_gg="1,1,1,1"

root -l -q "AnalyzeML.cc(\"$Plots_roc\", \"$Plots_private_herwig\", \"$Plots_private_pythia\",
                         \"$Plots_cms_herwig\", \"$Plots_cms_pythia\",
                         \"$Plots_cms_herwig_reweight\", \"$Plots_cms_pythia_reweight\", 
                         \"$Plots_cms_data\", \"$output_folder\",
                         \"$weights_qq\", \"$weights_gg\")"