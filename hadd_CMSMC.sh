#!/bin/bash
lumi=59800
HaddToLumi --lumi $lumi --root_file hadd_list/hadd_pythia160_200Spinoff.txt \
--xsection_file tabel/Xsection/pythia_Pt_slice.txt \
--output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt160_200GenReweightSpinoff_lumi$lumi/ML_SpinObservable.root

HaddToLumi --lumi $lumi --root_file hadd_list/hadd_pythia80_120Spinoff.txt \
--xsection_file tabel/Xsection/pythia_Pt_slice.txt \
--output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt80_120GenReweightSpinoff_lumi$lumi/ML_SpinObservable.root

HaddToLumi --lumi $lumi --root_file hadd_list/hadd_pythia160_200.txt \
--xsection_file tabel/Xsection/pythia_Pt_slice.txt \
--output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt160_200Gen_lumi$lumi/ML_SpinObservable.root

HaddToLumi --lumi $lumi --root_file hadd_list/hadd_pythia80_120.txt \
--xsection_file tabel/Xsection/pythia_Pt_slice.txt \
--output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt80_120Gen_lumi$lumi/ML_SpinObservable.root

# HaddToLumi --lumi $lumi --root_file hadd_list/hadd_herwig80_120.txt \
# --xsection_file tabel/Xsection/herwig_flat.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt80_120Gen_lumi$lumi/ML_SpinObservable.root

# HaddToLumi --lumi $lumi --root_file hadd_list/hadd_herwig160_200.txt \
# --xsection_file tabel/Xsection/herwig_flat.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt160_200Gen_lumi$lumi/ML_SpinObservable.root

# HaddToLumi --lumi $lumi --root_file hadd_list/hadd_herwig80_120Spinoff.txt \
# --xsection_file tabel/Xsection/herwig_flat.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt80_120GenReweightSpinoff_lumi$lumi/ML_SpinObservable.root

# HaddToLumi --lumi $lumi --root_file hadd_list/hadd_herwig160_200Spinoff.txt \
# --xsection_file tabel/Xsection/herwig_flat.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt160_200GenReweightSpinoff_lumi$lumi/ML_SpinObservable.root
############fixed scale #######################

# HaddToLumi --root_file hadd_list/hadd_pythia160_200Spinoff.txt \
# --output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt160_200GenReweightSpinoff_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_pythia80_120Spinoff.txt \
# --output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt80_120GenReweightSpinoff_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_pythia160_200.txt \
# --output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt160_200Gen_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_pythia80_120.txt \
# --output_file plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt80_120Gen_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_herwig80_120.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt80_120Gen_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_herwig160_200.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt160_200Gen_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_herwig80_120Spinoff.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt80_120GenReweightSpinoff_fixedscale/ML_SpinObservable.root

# HaddToLumi --root_file hadd_list/hadd_herwig160_200Spinoff.txt \
# --output_file plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt160_200GenReweightSpinoff_fixedscale/ML_SpinObservable.root