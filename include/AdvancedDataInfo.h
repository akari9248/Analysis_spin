//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr 26 15:39:33 2024 by ROOT version 6.24/04
// from TTree DataInfo/DataInfo
// found on file: test/validation_data_CA_lundplane_parton10Mz00pt200IFN_matchfull_test.root
//////////////////////////////////////////////////////////
#pragma once


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
using namespace std;
class AdvancedDataInfo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        GeneratorWeight;
   Int_t           PassPileUpRm;
   vector<double>  *deltaR1_Hadron;
   vector<double>  *deltaR1_Parton;
   vector<double>  *deltaR2_Hadron;
   vector<double>  *deltaR2_Parton;
   vector<double>  *deltaR3_Hadron;
   vector<double>  *deltaR3_Parton;
   vector<double>  *e1_Hadron;
   vector<double>  *e1_Parton;
   vector<double>  *e2_Hadron;
   vector<double>  *e2_Parton;
   vector<double>  *e3_Hadron;
   vector<double>  *e3_Parton;
   vector<double>  *e4_Hadron;
   vector<double>  *e4_Parton;
   vector<double>  *e5_Hadron;
   vector<double>  *e5_Parton;
   vector<double>  *e6_Hadron;
   vector<double>  *e6_Parton;
   vector<double>  *eec1_Hadron;
   vector<double>  *eec1_Parton;
   vector<double>  *eec2_Hadron;
   vector<double>  *eec2_Parton;
   vector<double>  *eec3_Hadron;
   vector<double>  *eec3_Parton;
   vector<double>  *eta1_Hadron;
   vector<double>  *eta1_Parton;
   vector<double>  *eta2_Hadron;
   vector<double>  *eta2_Parton;
   vector<double>  *eta3_Hadron;
   vector<double>  *eta3_Parton;
   vector<double>  *eta4_Hadron;
   vector<double>  *eta4_Parton;
   vector<double>  *eta5_Hadron;
   vector<double>  *eta5_Parton;
   vector<double>  *eta6_Hadron;
   vector<double>  *eta6_Parton;
   vector<int>     *flavour1_Hadron;
   vector<int>     *flavour1_Parton;
   vector<int>     *flavour2_Hadron;
   vector<int>     *flavour2_Parton;
   vector<int>     *flavour3_Hadron;
   vector<int>     *flavour3_Parton;
   vector<int>     *flavour4_Hadron;
   vector<int>     *flavour4_Parton;
   vector<int>     *flavour5_Hadron;
   vector<int>     *flavour5_Parton;
   vector<int>     *flavour6_Hadron;
   vector<int>     *flavour6_Parton;
   vector<int>     *isgg2_Hadron;
   vector<int>     *isgg2_Parton;
   vector<int>     *isgg_Hadron;
   vector<int>     *isgg_Parton;
   vector<int>     *isqq2_Hadron;
   vector<int>     *isqq2_Parton;
   vector<int>     *isqq_Hadron;
   vector<int>     *isqq_Parton;
   vector<double>  *je_Hadron;
   vector<double>  *je_Parton;
   vector<double>  *jes_scale_Hadron;
   vector<double>  *jes_scale_Parton;
   vector<double>  *jeta_Hadron;
   vector<double>  *jeta_Parton;
   vector<double>  *jphi_Hadron;
   vector<double>  *jphi_Parton;
   vector<double>  *jpt_Hadron;
   vector<double>  *jpt_Parton;
   vector<double>  *kt1_Hadron;
   vector<double>  *kt1_Parton;
   vector<double>  *kt2_Hadron;
   vector<double>  *kt2_Parton;
   vector<double>  *kt3_Hadron;
   vector<double>  *kt3_Parton;
   vector<int>     *match;
   vector<int>     *match3;
   vector<double>  *n1x_Hadron;
   vector<double>  *n1x_Parton;
   vector<double>  *n1y_Hadron;
   vector<double>  *n1y_Parton;
   vector<double>  *n1z_Hadron;
   vector<double>  *n1z_Parton;
   vector<double>  *n2x_Hadron;
   vector<double>  *n2x_Parton;
   vector<double>  *n2y_Hadron;
   vector<double>  *n2y_Parton;
   vector<double>  *n2z_Hadron;
   vector<double>  *n2z_Parton;
   vector<double>  *n3x_Hadron;
   vector<double>  *n3x_Parton;
   vector<double>  *n3y_Hadron;
   vector<double>  *n3y_Parton;
   vector<double>  *n3z_Hadron;
   vector<double>  *n3z_Parton;
   vector<int>     *nparticles1_Hadron;
   vector<int>     *nparticles1_Parton;
   vector<int>     *nparticles2_Hadron;
   vector<int>     *nparticles2_Parton;
   vector<int>     *nparticles3_Hadron;
   vector<int>     *nparticles3_Parton;
   vector<int>     *nparticles4_Hadron;
   vector<int>     *nparticles4_Parton;
   vector<int>     *nparticles5_Hadron;
   vector<int>     *nparticles5_Parton;
   vector<int>     *nparticles6_Hadron;
   vector<int>     *nparticles6_Parton;
   vector<int>     *ntracks1_Hadron;
   vector<int>     *ntracks1_Parton;
   vector<int>     *ntracks2_Hadron;
   vector<int>     *ntracks2_Parton;
   vector<int>     *ntracks3_Hadron;
   vector<int>     *ntracks3_Parton;
   vector<int>     *ntracks4_Hadron;
   vector<int>     *ntracks4_Parton;
   vector<int>     *ntracks5_Hadron;
   vector<int>     *ntracks5_Parton;
   vector<int>     *ntracks6_Hadron;
   vector<int>     *ntracks6_Parton;
   vector<double>  *particle1_charge_Hadron;
   vector<double>  *particle1_charge_Parton;
   vector<double>  *particle1_e_Hadron;
   vector<double>  *particle1_e_Parton;
   vector<double>  *particle1_eta_Hadron;
   vector<double>  *particle1_eta_Parton;
   vector<int>     *particle1_jetid_Hadron;
   vector<int>     *particle1_jetid_Parton;
   vector<double>  *particle1_phi_Hadron;
   vector<double>  *particle1_phi_Parton;
   vector<int>     *particle1_pid_Hadron;
   vector<int>     *particle1_pid_Parton;
   vector<double>  *particle1_pt_Hadron;
   vector<double>  *particle1_pt_Parton;
   vector<double>  *particle2_charge_Hadron;
   vector<double>  *particle2_charge_Parton;
   vector<double>  *particle2_e_Hadron;
   vector<double>  *particle2_e_Parton;
   vector<double>  *particle2_eta_Hadron;
   vector<double>  *particle2_eta_Parton;
   vector<int>     *particle2_jetid_Hadron;
   vector<int>     *particle2_jetid_Parton;
   vector<double>  *particle2_phi_Hadron;
   vector<double>  *particle2_phi_Parton;
   vector<int>     *particle2_pid_Hadron;
   vector<int>     *particle2_pid_Parton;
   vector<double>  *particle2_pt_Hadron;
   vector<double>  *particle2_pt_Parton;
   vector<double>  *particle3_charge_Hadron;
   vector<double>  *particle3_charge_Parton;
   vector<double>  *particle3_e_Hadron;
   vector<double>  *particle3_e_Parton;
   vector<double>  *particle3_eta_Hadron;
   vector<double>  *particle3_eta_Parton;
   vector<int>     *particle3_jetid_Hadron;
   vector<int>     *particle3_jetid_Parton;
   vector<double>  *particle3_phi_Hadron;
   vector<double>  *particle3_phi_Parton;
   vector<int>     *particle3_pid_Hadron;
   vector<int>     *particle3_pid_Parton;
   vector<double>  *particle3_pt_Hadron;
   vector<double>  *particle3_pt_Parton;
   vector<double>  *particle4_charge_Hadron;
   vector<double>  *particle4_charge_Parton;
   vector<double>  *particle4_e_Hadron;
   vector<double>  *particle4_e_Parton;
   vector<double>  *particle4_eta_Hadron;
   vector<double>  *particle4_eta_Parton;
   vector<int>     *particle4_jetid_Hadron;
   vector<int>     *particle4_jetid_Parton;
   vector<double>  *particle4_phi_Hadron;
   vector<double>  *particle4_phi_Parton;
   vector<int>     *particle4_pid_Hadron;
   vector<int>     *particle4_pid_Parton;
   vector<double>  *particle4_pt_Hadron;
   vector<double>  *particle4_pt_Parton;
   vector<double>  *particle5_charge_Hadron;
   vector<double>  *particle5_charge_Parton;
   vector<double>  *particle5_e_Hadron;
   vector<double>  *particle5_e_Parton;
   vector<double>  *particle5_eta_Hadron;
   vector<double>  *particle5_eta_Parton;
   vector<int>     *particle5_jetid_Hadron;
   vector<int>     *particle5_jetid_Parton;
   vector<double>  *particle5_phi_Hadron;
   vector<double>  *particle5_phi_Parton;
   vector<int>     *particle5_pid_Hadron;
   vector<int>     *particle5_pid_Parton;
   vector<double>  *particle5_pt_Hadron;
   vector<double>  *particle5_pt_Parton;
   vector<double>  *particle6_charge_Hadron;
   vector<double>  *particle6_charge_Parton;
   vector<double>  *particle6_e_Hadron;
   vector<double>  *particle6_e_Parton;
   vector<double>  *particle6_eta_Hadron;
   vector<double>  *particle6_eta_Parton;
   vector<int>     *particle6_jetid_Hadron;
   vector<int>     *particle6_jetid_Parton;
   vector<double>  *particle6_phi_Hadron;
   vector<double>  *particle6_phi_Parton;
   vector<int>     *particle6_pid_Hadron;
   vector<int>     *particle6_pid_Parton;
   vector<double>  *particle6_pt_Hadron;
   vector<double>  *particle6_pt_Parton;
   vector<double>  *phi1_Hadron;
   vector<double>  *phi1_Parton;
   vector<double>  *phi2_Hadron;
   vector<double>  *phi2_Parton;
   vector<double>  *phi3_Hadron;
   vector<double>  *phi3_Parton;
   vector<double>  *phi4_Hadron;
   vector<double>  *phi4_Parton;
   vector<double>  *phi5_Hadron;
   vector<double>  *phi5_Parton;
   vector<double>  *phi6_Hadron;
   vector<double>  *phi6_Parton;
   vector<double>  *phi_Hadron;
   vector<double>  *phi_Parton;
   vector<double>  *pt1_Hadron;
   vector<double>  *pt1_Parton;
   vector<double>  *pt2_Hadron;
   vector<double>  *pt2_Parton;
   vector<double>  *pt3_Hadron;
   vector<double>  *pt3_Parton;
   vector<double>  *pt4_Hadron;
   vector<double>  *pt4_Parton;
   vector<double>  *pt5_Hadron;
   vector<double>  *pt5_Parton;
   vector<double>  *pt6_Hadron;
   vector<double>  *pt6_Parton;
   Int_t           spin;
   vector<double>  *theta1_Hadron;
   vector<double>  *theta1_Parton;
   vector<double>  *theta2_Hadron;
   vector<double>  *theta2_Parton;
   vector<double>  *theta3_Hadron;
   vector<double>  *theta3_Parton;
   vector<double>  *thirdphi_Hadron;
   vector<double>  *thirdphi_Parton;
   vector<double>  *z1_Hadron;
   vector<double>  *z1_Parton;
   vector<double>  *z2_Hadron;
   vector<double>  *z2_Parton;
   vector<double>  *z3_Hadron;
   vector<double>  *z3_Parton;

   // List of branches
   TBranch        *b_GeneratorWeight;   //!
   TBranch        *b_PassPileUpRm;   //!
   TBranch        *b_deltaR1_Hadron;   //!
   TBranch        *b_deltaR1_Parton;   //!
   TBranch        *b_deltaR2_Hadron;   //!
   TBranch        *b_deltaR2_Parton;   //!
   TBranch        *b_deltaR3_Hadron;   //!
   TBranch        *b_deltaR3_Parton;   //!
   TBranch        *b_e1_Hadron;   //!
   TBranch        *b_e1_Parton;   //!
   TBranch        *b_e2_Hadron;   //!
   TBranch        *b_e2_Parton;   //!
   TBranch        *b_e3_Hadron;   //!
   TBranch        *b_e3_Parton;   //!
   TBranch        *b_e4_Hadron;   //!
   TBranch        *b_e4_Parton;   //!
   TBranch        *b_e5_Hadron;   //!
   TBranch        *b_e5_Parton;   //!
   TBranch        *b_e6_Hadron;   //!
   TBranch        *b_e6_Parton;   //!
   TBranch        *b_eec1_Hadron;   //!
   TBranch        *b_eec1_Parton;   //!
   TBranch        *b_eec2_Hadron;   //!
   TBranch        *b_eec2_Parton;   //!
   TBranch        *b_eec3_Hadron;   //!
   TBranch        *b_eec3_Parton;   //!
   TBranch        *b_eta1_Hadron;   //!
   TBranch        *b_eta1_Parton;   //!
   TBranch        *b_eta2_Hadron;   //!
   TBranch        *b_eta2_Parton;   //!
   TBranch        *b_eta3_Hadron;   //!
   TBranch        *b_eta3_Parton;   //!
   TBranch        *b_eta4_Hadron;   //!
   TBranch        *b_eta4_Parton;   //!
   TBranch        *b_eta5_Hadron;   //!
   TBranch        *b_eta5_Parton;   //!
   TBranch        *b_eta6_Hadron;   //!
   TBranch        *b_eta6_Parton;   //!
   TBranch        *b_flavour1_Hadron;   //!
   TBranch        *b_flavour1_Parton;   //!
   TBranch        *b_flavour2_Hadron;   //!
   TBranch        *b_flavour2_Parton;   //!
   TBranch        *b_flavour3_Hadron;   //!
   TBranch        *b_flavour3_Parton;   //!
   TBranch        *b_flavour4_Hadron;   //!
   TBranch        *b_flavour4_Parton;   //!
   TBranch        *b_flavour5_Hadron;   //!
   TBranch        *b_flavour5_Parton;   //!
   TBranch        *b_flavour6_Hadron;   //!
   TBranch        *b_flavour6_Parton;   //!
   TBranch        *b_isgg2_Hadron;   //!
   TBranch        *b_isgg2_Parton;   //!
   TBranch        *b_isgg_Hadron;   //!
   TBranch        *b_isgg_Parton;   //!
   TBranch        *b_isqq2_Hadron;   //!
   TBranch        *b_isqq2_Parton;   //!
   TBranch        *b_isqq_Hadron;   //!
   TBranch        *b_isqq_Parton;   //!
   TBranch        *b_je_Hadron;   //!
   TBranch        *b_je_Parton;   //!
   TBranch        *b_jes_scale_Hadron;   //!
   TBranch        *b_jes_scale_Parton;   //!
   TBranch        *b_jeta_Hadron;   //!
   TBranch        *b_jeta_Parton;   //!
   TBranch        *b_jphi_Hadron;   //!
   TBranch        *b_jphi_Parton;   //!
   TBranch        *b_jpt_Hadron;   //!
   TBranch        *b_jpt_Parton;   //!
   TBranch        *b_kt1_Hadron;   //!
   TBranch        *b_kt1_Parton;   //!
   TBranch        *b_kt2_Hadron;   //!
   TBranch        *b_kt2_Parton;   //!
   TBranch        *b_kt3_Hadron;   //!
   TBranch        *b_kt3_Parton;   //!
   TBranch        *b_match;   //!
   TBranch        *b_match3;   //!
   TBranch        *b_n1x_Hadron;   //!
   TBranch        *b_n1x_Parton;   //!
   TBranch        *b_n1y_Hadron;   //!
   TBranch        *b_n1y_Parton;   //!
   TBranch        *b_n1z_Hadron;   //!
   TBranch        *b_n1z_Parton;   //!
   TBranch        *b_n2x_Hadron;   //!
   TBranch        *b_n2x_Parton;   //!
   TBranch        *b_n2y_Hadron;   //!
   TBranch        *b_n2y_Parton;   //!
   TBranch        *b_n2z_Hadron;   //!
   TBranch        *b_n2z_Parton;   //!
   TBranch        *b_n3x_Hadron;   //!
   TBranch        *b_n3x_Parton;   //!
   TBranch        *b_n3y_Hadron;   //!
   TBranch        *b_n3y_Parton;   //!
   TBranch        *b_n3z_Hadron;   //!
   TBranch        *b_n3z_Parton;   //!
   TBranch        *b_nparticles1_Hadron;   //!
   TBranch        *b_nparticles1_Parton;   //!
   TBranch        *b_nparticles2_Hadron;   //!
   TBranch        *b_nparticles2_Parton;   //!
   TBranch        *b_nparticles3_Hadron;   //!
   TBranch        *b_nparticles3_Parton;   //!
   TBranch        *b_nparticles4_Hadron;   //!
   TBranch        *b_nparticles4_Parton;   //!
   TBranch        *b_nparticles5_Hadron;   //!
   TBranch        *b_nparticles5_Parton;   //!
   TBranch        *b_nparticles6_Hadron;   //!
   TBranch        *b_nparticles6_Parton;   //!
   TBranch        *b_ntracks1_Hadron;   //!
   TBranch        *b_ntracks1_Parton;   //!
   TBranch        *b_ntracks2_Hadron;   //!
   TBranch        *b_ntracks2_Parton;   //!
   TBranch        *b_ntracks3_Hadron;   //!
   TBranch        *b_ntracks3_Parton;   //!
   TBranch        *b_ntracks4_Hadron;   //!
   TBranch        *b_ntracks4_Parton;   //!
   TBranch        *b_ntracks5_Hadron;   //!
   TBranch        *b_ntracks5_Parton;   //!
   TBranch        *b_ntracks6_Hadron;   //!
   TBranch        *b_ntracks6_Parton;   //!
   TBranch        *b_particle1_charge_Hadron;   //!
   TBranch        *b_particle1_charge_Parton;   //!
   TBranch        *b_particle1_e_Hadron;   //!
   TBranch        *b_particle1_e_Parton;   //!
   TBranch        *b_particle1_eta_Hadron;   //!
   TBranch        *b_particle1_eta_Parton;   //!
   TBranch        *b_particle1_jetid_Hadron;   //!
   TBranch        *b_particle1_jetid_Parton;   //!
   TBranch        *b_particle1_phi_Hadron;   //!
   TBranch        *b_particle1_phi_Parton;   //!
   TBranch        *b_particle1_pid_Hadron;   //!
   TBranch        *b_particle1_pid_Parton;   //!
   TBranch        *b_particle1_pt_Hadron;   //!
   TBranch        *b_particle1_pt_Parton;   //!
   TBranch        *b_particle2_charge_Hadron;   //!
   TBranch        *b_particle2_charge_Parton;   //!
   TBranch        *b_particle2_e_Hadron;   //!
   TBranch        *b_particle2_e_Parton;   //!
   TBranch        *b_particle2_eta_Hadron;   //!
   TBranch        *b_particle2_eta_Parton;   //!
   TBranch        *b_particle2_jetid_Hadron;   //!
   TBranch        *b_particle2_jetid_Parton;   //!
   TBranch        *b_particle2_phi_Hadron;   //!
   TBranch        *b_particle2_phi_Parton;   //!
   TBranch        *b_particle2_pid_Hadron;   //!
   TBranch        *b_particle2_pid_Parton;   //!
   TBranch        *b_particle2_pt_Hadron;   //!
   TBranch        *b_particle2_pt_Parton;   //!
   TBranch        *b_particle3_charge_Hadron;   //!
   TBranch        *b_particle3_charge_Parton;   //!
   TBranch        *b_particle3_e_Hadron;   //!
   TBranch        *b_particle3_e_Parton;   //!
   TBranch        *b_particle3_eta_Hadron;   //!
   TBranch        *b_particle3_eta_Parton;   //!
   TBranch        *b_particle3_jetid_Hadron;   //!
   TBranch        *b_particle3_jetid_Parton;   //!
   TBranch        *b_particle3_phi_Hadron;   //!
   TBranch        *b_particle3_phi_Parton;   //!
   TBranch        *b_particle3_pid_Hadron;   //!
   TBranch        *b_particle3_pid_Parton;   //!
   TBranch        *b_particle3_pt_Hadron;   //!
   TBranch        *b_particle3_pt_Parton;   //!
   TBranch        *b_particle4_charge_Hadron;   //!
   TBranch        *b_particle4_charge_Parton;   //!
   TBranch        *b_particle4_e_Hadron;   //!
   TBranch        *b_particle4_e_Parton;   //!
   TBranch        *b_particle4_eta_Hadron;   //!
   TBranch        *b_particle4_eta_Parton;   //!
   TBranch        *b_particle4_jetid_Hadron;   //!
   TBranch        *b_particle4_jetid_Parton;   //!
   TBranch        *b_particle4_phi_Hadron;   //!
   TBranch        *b_particle4_phi_Parton;   //!
   TBranch        *b_particle4_pid_Hadron;   //!
   TBranch        *b_particle4_pid_Parton;   //!
   TBranch        *b_particle4_pt_Hadron;   //!
   TBranch        *b_particle4_pt_Parton;   //!
   TBranch        *b_particle5_charge_Hadron;   //!
   TBranch        *b_particle5_charge_Parton;   //!
   TBranch        *b_particle5_e_Hadron;   //!
   TBranch        *b_particle5_e_Parton;   //!
   TBranch        *b_particle5_eta_Hadron;   //!
   TBranch        *b_particle5_eta_Parton;   //!
   TBranch        *b_particle5_jetid_Hadron;   //!
   TBranch        *b_particle5_jetid_Parton;   //!
   TBranch        *b_particle5_phi_Hadron;   //!
   TBranch        *b_particle5_phi_Parton;   //!
   TBranch        *b_particle5_pid_Hadron;   //!
   TBranch        *b_particle5_pid_Parton;   //!
   TBranch        *b_particle5_pt_Hadron;   //!
   TBranch        *b_particle5_pt_Parton;   //!
   TBranch        *b_particle6_charge_Hadron;   //!
   TBranch        *b_particle6_charge_Parton;   //!
   TBranch        *b_particle6_e_Hadron;   //!
   TBranch        *b_particle6_e_Parton;   //!
   TBranch        *b_particle6_eta_Hadron;   //!
   TBranch        *b_particle6_eta_Parton;   //!
   TBranch        *b_particle6_jetid_Hadron;   //!
   TBranch        *b_particle6_jetid_Parton;   //!
   TBranch        *b_particle6_phi_Hadron;   //!
   TBranch        *b_particle6_phi_Parton;   //!
   TBranch        *b_particle6_pid_Hadron;   //!
   TBranch        *b_particle6_pid_Parton;   //!
   TBranch        *b_particle6_pt_Hadron;   //!
   TBranch        *b_particle6_pt_Parton;   //!
   TBranch        *b_phi1_Hadron;   //!
   TBranch        *b_phi1_Parton;   //!
   TBranch        *b_phi2_Hadron;   //!
   TBranch        *b_phi2_Parton;   //!
   TBranch        *b_phi3_Hadron;   //!
   TBranch        *b_phi3_Parton;   //!
   TBranch        *b_phi4_Hadron;   //!
   TBranch        *b_phi4_Parton;   //!
   TBranch        *b_phi5_Hadron;   //!
   TBranch        *b_phi5_Parton;   //!
   TBranch        *b_phi6_Hadron;   //!
   TBranch        *b_phi6_Parton;   //!
   TBranch        *b_phi_Hadron;   //!
   TBranch        *b_phi_Parton;   //!
   TBranch        *b_pt1_Hadron;   //!
   TBranch        *b_pt1_Parton;   //!
   TBranch        *b_pt2_Hadron;   //!
   TBranch        *b_pt2_Parton;   //!
   TBranch        *b_pt3_Hadron;   //!
   TBranch        *b_pt3_Parton;   //!
   TBranch        *b_pt4_Hadron;   //!
   TBranch        *b_pt4_Parton;   //!
   TBranch        *b_pt5_Hadron;   //!
   TBranch        *b_pt5_Parton;   //!
   TBranch        *b_pt6_Hadron;   //!
   TBranch        *b_pt6_Parton;   //!
   TBranch        *b_theta1_Hadron;   //!
   TBranch        *b_theta1_Parton;   //!
   TBranch        *b_theta2_Hadron;   //!
   TBranch        *b_theta2_Parton;   //!
   TBranch        *b_theta3_Hadron;   //!
   TBranch        *b_theta3_Parton;   //!
   TBranch        *b_thirdphi_Hadron;   //!
   TBranch        *b_thirdphi_Parton;   //!
   TBranch        *b_z1_Hadron;   //!
   TBranch        *b_z1_Parton;   //!
   TBranch        *b_z2_Hadron;   //!
   TBranch        *b_z2_Parton;   //!
   TBranch        *b_z3_Hadron;   //!
   TBranch        *b_z3_Parton;   //!

   TBranch        *b_spin;   //!

   AdvancedDataInfo(TTree *tree=0);
   virtual ~AdvancedDataInfo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};


AdvancedDataInfo::AdvancedDataInfo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree != 0) {
      Init(tree);
   }
   
}

AdvancedDataInfo::~AdvancedDataInfo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AdvancedDataInfo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AdvancedDataInfo::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void AdvancedDataInfo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

  // Set object pointer
   deltaR1_Hadron = 0;
   deltaR1_Parton = 0;
   deltaR2_Hadron = 0;
   deltaR2_Parton = 0;
   deltaR3_Hadron = 0;
   deltaR3_Parton = 0;
   e1_Hadron = 0;
   e1_Parton = 0;
   e2_Hadron = 0;
   e2_Parton = 0;
   e3_Hadron = 0;
   e3_Parton = 0;
   e4_Hadron = 0;
   e4_Parton = 0;
   e5_Hadron = 0;
   e5_Parton = 0;
   e6_Hadron = 0;
   e6_Parton = 0;
   eec1_Hadron = 0;
   eec1_Parton = 0;
   eec2_Hadron = 0;
   eec2_Parton = 0;
   eec3_Hadron = 0;
   eec3_Parton = 0;
   eta1_Hadron = 0;
   eta1_Parton = 0;
   eta2_Hadron = 0;
   eta2_Parton = 0;
   eta3_Hadron = 0;
   eta3_Parton = 0;
   eta4_Hadron = 0;
   eta4_Parton = 0;
   eta5_Hadron = 0;
   eta5_Parton = 0;
   eta6_Hadron = 0;
   eta6_Parton = 0;
   flavour1_Hadron = 0;
   flavour1_Parton = 0;
   flavour2_Hadron = 0;
   flavour2_Parton = 0;
   flavour3_Hadron = 0;
   flavour3_Parton = 0;
   flavour4_Hadron = 0;
   flavour4_Parton = 0;
   flavour5_Hadron = 0;
   flavour5_Parton = 0;
   flavour6_Hadron = 0;
   flavour6_Parton = 0;
   isgg2_Hadron = 0;
   isgg2_Parton = 0;
   isgg_Hadron = 0;
   isgg_Parton = 0;
   isqq2_Hadron = 0;
   isqq2_Parton = 0;
   isqq_Hadron = 0;
   isqq_Parton = 0;
   je_Hadron = 0;
   je_Parton = 0;
   jes_scale_Hadron = 0;
   jes_scale_Parton = 0;
   jeta_Hadron = 0;
   jeta_Parton = 0;
   jphi_Hadron = 0;
   jphi_Parton = 0;
   jpt_Hadron = 0;
   jpt_Parton = 0;
   kt1_Hadron = 0;
   kt1_Parton = 0;
   kt2_Hadron = 0;
   kt2_Parton = 0;
   kt3_Hadron = 0;
   kt3_Parton = 0;
   match = 0;
   match3 = 0;
   n1x_Hadron = 0;
   n1x_Parton = 0;
   n1y_Hadron = 0;
   n1y_Parton = 0;
   n1z_Hadron = 0;
   n1z_Parton = 0;
   n2x_Hadron = 0;
   n2x_Parton = 0;
   n2y_Hadron = 0;
   n2y_Parton = 0;
   n2z_Hadron = 0;
   n2z_Parton = 0;
   n3x_Hadron = 0;
   n3x_Parton = 0;
   n3y_Hadron = 0;
   n3y_Parton = 0;
   n3z_Hadron = 0;
   n3z_Parton = 0;
   nparticles1_Hadron = 0;
   nparticles1_Parton = 0;
   nparticles2_Hadron = 0;
   nparticles2_Parton = 0;
   nparticles3_Hadron = 0;
   nparticles3_Parton = 0;
   nparticles4_Hadron = 0;
   nparticles4_Parton = 0;
   nparticles5_Hadron = 0;
   nparticles5_Parton = 0;
   nparticles6_Hadron = 0;
   nparticles6_Parton = 0;
   ntracks1_Hadron = 0;
   ntracks1_Parton = 0;
   ntracks2_Hadron = 0;
   ntracks2_Parton = 0;
   ntracks3_Hadron = 0;
   ntracks3_Parton = 0;
   ntracks4_Hadron = 0;
   ntracks4_Parton = 0;
   ntracks5_Hadron = 0;
   ntracks5_Parton = 0;
   ntracks6_Hadron = 0;
   ntracks6_Parton = 0;
   particle1_charge_Hadron = 0;
   particle1_charge_Parton = 0;
   particle1_e_Hadron = 0;
   particle1_e_Parton = 0;
   particle1_eta_Hadron = 0;
   particle1_eta_Parton = 0;
   particle1_jetid_Hadron = 0;
   particle1_jetid_Parton = 0;
   particle1_phi_Hadron = 0;
   particle1_phi_Parton = 0;
   particle1_pid_Hadron = 0;
   particle1_pid_Parton = 0;
   particle1_pt_Hadron = 0;
   particle1_pt_Parton = 0;
   particle2_charge_Hadron = 0;
   particle2_charge_Parton = 0;
   particle2_e_Hadron = 0;
   particle2_e_Parton = 0;
   particle2_eta_Hadron = 0;
   particle2_eta_Parton = 0;
   particle2_jetid_Hadron = 0;
   particle2_jetid_Parton = 0;
   particle2_phi_Hadron = 0;
   particle2_phi_Parton = 0;
   particle2_pid_Hadron = 0;
   particle2_pid_Parton = 0;
   particle2_pt_Hadron = 0;
   particle2_pt_Parton = 0;
   particle3_charge_Hadron = 0;
   particle3_charge_Parton = 0;
   particle3_e_Hadron = 0;
   particle3_e_Parton = 0;
   particle3_eta_Hadron = 0;
   particle3_eta_Parton = 0;
   particle3_jetid_Hadron = 0;
   particle3_jetid_Parton = 0;
   particle3_phi_Hadron = 0;
   particle3_phi_Parton = 0;
   particle3_pid_Hadron = 0;
   particle3_pid_Parton = 0;
   particle3_pt_Hadron = 0;
   particle3_pt_Parton = 0;
   particle4_charge_Hadron = 0;
   particle4_charge_Parton = 0;
   particle4_e_Hadron = 0;
   particle4_e_Parton = 0;
   particle4_eta_Hadron = 0;
   particle4_eta_Parton = 0;
   particle4_jetid_Hadron = 0;
   particle4_jetid_Parton = 0;
   particle4_phi_Hadron = 0;
   particle4_phi_Parton = 0;
   particle4_pid_Hadron = 0;
   particle4_pid_Parton = 0;
   particle4_pt_Hadron = 0;
   particle4_pt_Parton = 0;
   particle5_charge_Hadron = 0;
   particle5_charge_Parton = 0;
   particle5_e_Hadron = 0;
   particle5_e_Parton = 0;
   particle5_eta_Hadron = 0;
   particle5_eta_Parton = 0;
   particle5_jetid_Hadron = 0;
   particle5_jetid_Parton = 0;
   particle5_phi_Hadron = 0;
   particle5_phi_Parton = 0;
   particle5_pid_Hadron = 0;
   particle5_pid_Parton = 0;
   particle5_pt_Hadron = 0;
   particle5_pt_Parton = 0;
   particle6_charge_Hadron = 0;
   particle6_charge_Parton = 0;
   particle6_e_Hadron = 0;
   particle6_e_Parton = 0;
   particle6_eta_Hadron = 0;
   particle6_eta_Parton = 0;
   particle6_jetid_Hadron = 0;
   particle6_jetid_Parton = 0;
   particle6_phi_Hadron = 0;
   particle6_phi_Parton = 0;
   particle6_pid_Hadron = 0;
   particle6_pid_Parton = 0;
   particle6_pt_Hadron = 0;
   particle6_pt_Parton = 0;
   phi1_Hadron = 0;
   phi1_Parton = 0;
   phi2_Hadron = 0;
   phi2_Parton = 0;
   phi3_Hadron = 0;
   phi3_Parton = 0;
   phi4_Hadron = 0;
   phi4_Parton = 0;
   phi5_Hadron = 0;
   phi5_Parton = 0;
   phi6_Hadron = 0;
   phi6_Parton = 0;
   phi_Hadron = 0;
   phi_Parton = 0;
   pt1_Hadron = 0;
   pt1_Parton = 0;
   pt2_Hadron = 0;
   pt2_Parton = 0;
   pt3_Hadron = 0;
   pt3_Parton = 0;
   pt4_Hadron = 0;
   pt4_Parton = 0;
   pt5_Hadron = 0;
   pt5_Parton = 0;
   pt6_Hadron = 0;
   pt6_Parton = 0;
   theta1_Hadron = 0;
   theta1_Parton = 0;
   theta2_Hadron = 0;
   theta2_Parton = 0;
   theta3_Hadron = 0;
   theta3_Parton = 0;
   thirdphi_Hadron = 0;
   thirdphi_Parton = 0;
   z1_Hadron = 0;
   z1_Parton = 0;
   z2_Hadron = 0;
   z2_Parton = 0;
   z3_Hadron = 0;
   z3_Parton = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   fChain->SetBranchAddress("PassPileUpRm", &PassPileUpRm, &b_PassPileUpRm);
   fChain->SetBranchAddress("deltaR1_Hadron", &deltaR1_Hadron, &b_deltaR1_Hadron);
   fChain->SetBranchAddress("deltaR1_Parton", &deltaR1_Parton, &b_deltaR1_Parton);
   fChain->SetBranchAddress("deltaR2_Hadron", &deltaR2_Hadron, &b_deltaR2_Hadron);
   fChain->SetBranchAddress("deltaR2_Parton", &deltaR2_Parton, &b_deltaR2_Parton);
   fChain->SetBranchAddress("deltaR3_Hadron", &deltaR3_Hadron, &b_deltaR3_Hadron);
   fChain->SetBranchAddress("deltaR3_Parton", &deltaR3_Parton, &b_deltaR3_Parton);
   fChain->SetBranchAddress("e1_Hadron", &e1_Hadron, &b_e1_Hadron);
   fChain->SetBranchAddress("e1_Parton", &e1_Parton, &b_e1_Parton);
   fChain->SetBranchAddress("e2_Hadron", &e2_Hadron, &b_e2_Hadron);
   fChain->SetBranchAddress("e2_Parton", &e2_Parton, &b_e2_Parton);
   fChain->SetBranchAddress("e3_Hadron", &e3_Hadron, &b_e3_Hadron);
   fChain->SetBranchAddress("e3_Parton", &e3_Parton, &b_e3_Parton);
   fChain->SetBranchAddress("e4_Hadron", &e4_Hadron, &b_e4_Hadron);
   fChain->SetBranchAddress("e4_Parton", &e4_Parton, &b_e4_Parton);
   fChain->SetBranchAddress("e5_Hadron", &e5_Hadron, &b_e5_Hadron);
   fChain->SetBranchAddress("e5_Parton", &e5_Parton, &b_e5_Parton);
   fChain->SetBranchAddress("e6_Hadron", &e6_Hadron, &b_e6_Hadron);
   fChain->SetBranchAddress("e6_Parton", &e6_Parton, &b_e6_Parton);
   fChain->SetBranchAddress("eec1_Hadron", &eec1_Hadron, &b_eec1_Hadron);
   fChain->SetBranchAddress("eec1_Parton", &eec1_Parton, &b_eec1_Parton);
   fChain->SetBranchAddress("eec2_Hadron", &eec2_Hadron, &b_eec2_Hadron);
   fChain->SetBranchAddress("eec2_Parton", &eec2_Parton, &b_eec2_Parton);
   fChain->SetBranchAddress("eec3_Hadron", &eec3_Hadron, &b_eec3_Hadron);
   fChain->SetBranchAddress("eec3_Parton", &eec3_Parton, &b_eec3_Parton);
   fChain->SetBranchAddress("eta1_Hadron", &eta1_Hadron, &b_eta1_Hadron);
   fChain->SetBranchAddress("eta1_Parton", &eta1_Parton, &b_eta1_Parton);
   fChain->SetBranchAddress("eta2_Hadron", &eta2_Hadron, &b_eta2_Hadron);
   fChain->SetBranchAddress("eta2_Parton", &eta2_Parton, &b_eta2_Parton);
   fChain->SetBranchAddress("eta3_Hadron", &eta3_Hadron, &b_eta3_Hadron);
   fChain->SetBranchAddress("eta3_Parton", &eta3_Parton, &b_eta3_Parton);
   fChain->SetBranchAddress("eta4_Hadron", &eta4_Hadron, &b_eta4_Hadron);
   fChain->SetBranchAddress("eta4_Parton", &eta4_Parton, &b_eta4_Parton);
   fChain->SetBranchAddress("eta5_Hadron", &eta5_Hadron, &b_eta5_Hadron);
   fChain->SetBranchAddress("eta5_Parton", &eta5_Parton, &b_eta5_Parton);
   fChain->SetBranchAddress("eta6_Hadron", &eta6_Hadron, &b_eta6_Hadron);
   fChain->SetBranchAddress("eta6_Parton", &eta6_Parton, &b_eta6_Parton);
   fChain->SetBranchAddress("flavour1_Hadron", &flavour1_Hadron, &b_flavour1_Hadron);
   fChain->SetBranchAddress("flavour1_Parton", &flavour1_Parton, &b_flavour1_Parton);
   fChain->SetBranchAddress("flavour2_Hadron", &flavour2_Hadron, &b_flavour2_Hadron);
   fChain->SetBranchAddress("flavour2_Parton", &flavour2_Parton, &b_flavour2_Parton);
   fChain->SetBranchAddress("flavour3_Hadron", &flavour3_Hadron, &b_flavour3_Hadron);
   fChain->SetBranchAddress("flavour3_Parton", &flavour3_Parton, &b_flavour3_Parton);
   fChain->SetBranchAddress("flavour4_Hadron", &flavour4_Hadron, &b_flavour4_Hadron);
   fChain->SetBranchAddress("flavour4_Parton", &flavour4_Parton, &b_flavour4_Parton);
   fChain->SetBranchAddress("flavour5_Hadron", &flavour5_Hadron, &b_flavour5_Hadron);
   fChain->SetBranchAddress("flavour5_Parton", &flavour5_Parton, &b_flavour5_Parton);
   fChain->SetBranchAddress("flavour6_Hadron", &flavour6_Hadron, &b_flavour6_Hadron);
   fChain->SetBranchAddress("flavour6_Parton", &flavour6_Parton, &b_flavour6_Parton);
   fChain->SetBranchAddress("isgg2_Hadron", &isgg2_Hadron, &b_isgg2_Hadron);
   fChain->SetBranchAddress("isgg2_Parton", &isgg2_Parton, &b_isgg2_Parton);
   fChain->SetBranchAddress("isgg_Hadron", &isgg_Hadron, &b_isgg_Hadron);
   fChain->SetBranchAddress("isgg_Parton", &isgg_Parton, &b_isgg_Parton);
   fChain->SetBranchAddress("isqq2_Hadron", &isqq2_Hadron, &b_isqq2_Hadron);
   fChain->SetBranchAddress("isqq2_Parton", &isqq2_Parton, &b_isqq2_Parton);
   fChain->SetBranchAddress("isqq_Hadron", &isqq_Hadron, &b_isqq_Hadron);
   fChain->SetBranchAddress("isqq_Parton", &isqq_Parton, &b_isqq_Parton);
   fChain->SetBranchAddress("je_Hadron", &je_Hadron, &b_je_Hadron);
   fChain->SetBranchAddress("je_Parton", &je_Parton, &b_je_Parton);
   fChain->SetBranchAddress("jes_scale_Hadron", &jes_scale_Hadron, &b_jes_scale_Hadron);
   fChain->SetBranchAddress("jes_scale_Parton", &jes_scale_Parton, &b_jes_scale_Parton);
   fChain->SetBranchAddress("jeta_Hadron", &jeta_Hadron, &b_jeta_Hadron);
   fChain->SetBranchAddress("jeta_Parton", &jeta_Parton, &b_jeta_Parton);
   fChain->SetBranchAddress("jphi_Hadron", &jphi_Hadron, &b_jphi_Hadron);
   fChain->SetBranchAddress("jphi_Parton", &jphi_Parton, &b_jphi_Parton);
   fChain->SetBranchAddress("jpt_Hadron", &jpt_Hadron, &b_jpt_Hadron);
   fChain->SetBranchAddress("jpt_Parton", &jpt_Parton, &b_jpt_Parton);
   fChain->SetBranchAddress("kt1_Hadron", &kt1_Hadron, &b_kt1_Hadron);
   fChain->SetBranchAddress("kt1_Parton", &kt1_Parton, &b_kt1_Parton);
   fChain->SetBranchAddress("kt2_Hadron", &kt2_Hadron, &b_kt2_Hadron);
   fChain->SetBranchAddress("kt2_Parton", &kt2_Parton, &b_kt2_Parton);
   fChain->SetBranchAddress("kt3_Hadron", &kt3_Hadron, &b_kt3_Hadron);
   fChain->SetBranchAddress("kt3_Parton", &kt3_Parton, &b_kt3_Parton);
   fChain->SetBranchAddress("match2", &match, &b_match);
   fChain->SetBranchAddress("match3", &match3, &b_match3);
   fChain->SetBranchAddress("n1x_Hadron", &n1x_Hadron, &b_n1x_Hadron);
   fChain->SetBranchAddress("n1x_Parton", &n1x_Parton, &b_n1x_Parton);
   fChain->SetBranchAddress("n1y_Hadron", &n1y_Hadron, &b_n1y_Hadron);
   fChain->SetBranchAddress("n1y_Parton", &n1y_Parton, &b_n1y_Parton);
   fChain->SetBranchAddress("n1z_Hadron", &n1z_Hadron, &b_n1z_Hadron);
   fChain->SetBranchAddress("n1z_Parton", &n1z_Parton, &b_n1z_Parton);
   fChain->SetBranchAddress("n2x_Hadron", &n2x_Hadron, &b_n2x_Hadron);
   fChain->SetBranchAddress("n2x_Parton", &n2x_Parton, &b_n2x_Parton);
   fChain->SetBranchAddress("n2y_Hadron", &n2y_Hadron, &b_n2y_Hadron);
   fChain->SetBranchAddress("n2y_Parton", &n2y_Parton, &b_n2y_Parton);
   fChain->SetBranchAddress("n2z_Hadron", &n2z_Hadron, &b_n2z_Hadron);
   fChain->SetBranchAddress("n2z_Parton", &n2z_Parton, &b_n2z_Parton);
   fChain->SetBranchAddress("n3x_Hadron", &n3x_Hadron, &b_n3x_Hadron);
   fChain->SetBranchAddress("n3x_Parton", &n3x_Parton, &b_n3x_Parton);
   fChain->SetBranchAddress("n3y_Hadron", &n3y_Hadron, &b_n3y_Hadron);
   fChain->SetBranchAddress("n3y_Parton", &n3y_Parton, &b_n3y_Parton);
   fChain->SetBranchAddress("n3z_Hadron", &n3z_Hadron, &b_n3z_Hadron);
   fChain->SetBranchAddress("n3z_Parton", &n3z_Parton, &b_n3z_Parton);
   fChain->SetBranchAddress("nparticles1_Hadron", &nparticles1_Hadron, &b_nparticles1_Hadron);
   fChain->SetBranchAddress("nparticles1_Parton", &nparticles1_Parton, &b_nparticles1_Parton);
   fChain->SetBranchAddress("nparticles2_Hadron", &nparticles2_Hadron, &b_nparticles2_Hadron);
   fChain->SetBranchAddress("nparticles2_Parton", &nparticles2_Parton, &b_nparticles2_Parton);
   fChain->SetBranchAddress("nparticles3_Hadron", &nparticles3_Hadron, &b_nparticles3_Hadron);
   fChain->SetBranchAddress("nparticles3_Parton", &nparticles3_Parton, &b_nparticles3_Parton);
   fChain->SetBranchAddress("nparticles4_Hadron", &nparticles4_Hadron, &b_nparticles4_Hadron);
   fChain->SetBranchAddress("nparticles4_Parton", &nparticles4_Parton, &b_nparticles4_Parton);
   fChain->SetBranchAddress("nparticles5_Hadron", &nparticles5_Hadron, &b_nparticles5_Hadron);
   fChain->SetBranchAddress("nparticles5_Parton", &nparticles5_Parton, &b_nparticles5_Parton);
   fChain->SetBranchAddress("nparticles6_Hadron", &nparticles6_Hadron, &b_nparticles6_Hadron);
   fChain->SetBranchAddress("nparticles6_Parton", &nparticles6_Parton, &b_nparticles6_Parton);
   fChain->SetBranchAddress("ntracks1_Hadron", &ntracks1_Hadron, &b_ntracks1_Hadron);
   fChain->SetBranchAddress("ntracks1_Parton", &ntracks1_Parton, &b_ntracks1_Parton);
   fChain->SetBranchAddress("ntracks2_Hadron", &ntracks2_Hadron, &b_ntracks2_Hadron);
   fChain->SetBranchAddress("ntracks2_Parton", &ntracks2_Parton, &b_ntracks2_Parton);
   fChain->SetBranchAddress("ntracks3_Hadron", &ntracks3_Hadron, &b_ntracks3_Hadron);
   fChain->SetBranchAddress("ntracks3_Parton", &ntracks3_Parton, &b_ntracks3_Parton);
   fChain->SetBranchAddress("ntracks4_Hadron", &ntracks4_Hadron, &b_ntracks4_Hadron);
   fChain->SetBranchAddress("ntracks4_Parton", &ntracks4_Parton, &b_ntracks4_Parton);
   fChain->SetBranchAddress("ntracks5_Hadron", &ntracks5_Hadron, &b_ntracks5_Hadron);
   fChain->SetBranchAddress("ntracks5_Parton", &ntracks5_Parton, &b_ntracks5_Parton);
   fChain->SetBranchAddress("ntracks6_Hadron", &ntracks6_Hadron, &b_ntracks6_Hadron);
   fChain->SetBranchAddress("ntracks6_Parton", &ntracks6_Parton, &b_ntracks6_Parton);
   fChain->SetBranchAddress("particle1_charge_Hadron", &particle1_charge_Hadron, &b_particle1_charge_Hadron);
   fChain->SetBranchAddress("particle1_charge_Parton", &particle1_charge_Parton, &b_particle1_charge_Parton);
   fChain->SetBranchAddress("particle1_e_Hadron", &particle1_e_Hadron, &b_particle1_e_Hadron);
   fChain->SetBranchAddress("particle1_e_Parton", &particle1_e_Parton, &b_particle1_e_Parton);
   fChain->SetBranchAddress("particle1_eta_Hadron", &particle1_eta_Hadron, &b_particle1_eta_Hadron);
   fChain->SetBranchAddress("particle1_eta_Parton", &particle1_eta_Parton, &b_particle1_eta_Parton);
   fChain->SetBranchAddress("particle1_jetid_Hadron", &particle1_jetid_Hadron, &b_particle1_jetid_Hadron);
   fChain->SetBranchAddress("particle1_jetid_Parton", &particle1_jetid_Parton, &b_particle1_jetid_Parton);
   fChain->SetBranchAddress("particle1_phi_Hadron", &particle1_phi_Hadron, &b_particle1_phi_Hadron);
   fChain->SetBranchAddress("particle1_phi_Parton", &particle1_phi_Parton, &b_particle1_phi_Parton);
   fChain->SetBranchAddress("particle1_pid_Hadron", &particle1_pid_Hadron, &b_particle1_pid_Hadron);
   fChain->SetBranchAddress("particle1_pid_Parton", &particle1_pid_Parton, &b_particle1_pid_Parton);
   fChain->SetBranchAddress("particle1_pt_Hadron", &particle1_pt_Hadron, &b_particle1_pt_Hadron);
   fChain->SetBranchAddress("particle1_pt_Parton", &particle1_pt_Parton, &b_particle1_pt_Parton);
   fChain->SetBranchAddress("particle2_charge_Hadron", &particle2_charge_Hadron, &b_particle2_charge_Hadron);
   fChain->SetBranchAddress("particle2_charge_Parton", &particle2_charge_Parton, &b_particle2_charge_Parton);
   fChain->SetBranchAddress("particle2_e_Hadron", &particle2_e_Hadron, &b_particle2_e_Hadron);
   fChain->SetBranchAddress("particle2_e_Parton", &particle2_e_Parton, &b_particle2_e_Parton);
   fChain->SetBranchAddress("particle2_eta_Hadron", &particle2_eta_Hadron, &b_particle2_eta_Hadron);
   fChain->SetBranchAddress("particle2_eta_Parton", &particle2_eta_Parton, &b_particle2_eta_Parton);
   fChain->SetBranchAddress("particle2_jetid_Hadron", &particle2_jetid_Hadron, &b_particle2_jetid_Hadron);
   fChain->SetBranchAddress("particle2_jetid_Parton", &particle2_jetid_Parton, &b_particle2_jetid_Parton);
   fChain->SetBranchAddress("particle2_phi_Hadron", &particle2_phi_Hadron, &b_particle2_phi_Hadron);
   fChain->SetBranchAddress("particle2_phi_Parton", &particle2_phi_Parton, &b_particle2_phi_Parton);
   fChain->SetBranchAddress("particle2_pid_Hadron", &particle2_pid_Hadron, &b_particle2_pid_Hadron);
   fChain->SetBranchAddress("particle2_pid_Parton", &particle2_pid_Parton, &b_particle2_pid_Parton);
   fChain->SetBranchAddress("particle2_pt_Hadron", &particle2_pt_Hadron, &b_particle2_pt_Hadron);
   fChain->SetBranchAddress("particle2_pt_Parton", &particle2_pt_Parton, &b_particle2_pt_Parton);
   fChain->SetBranchAddress("particle3_charge_Hadron", &particle3_charge_Hadron, &b_particle3_charge_Hadron);
   fChain->SetBranchAddress("particle3_charge_Parton", &particle3_charge_Parton, &b_particle3_charge_Parton);
   fChain->SetBranchAddress("particle3_e_Hadron", &particle3_e_Hadron, &b_particle3_e_Hadron);
   fChain->SetBranchAddress("particle3_e_Parton", &particle3_e_Parton, &b_particle3_e_Parton);
   fChain->SetBranchAddress("particle3_eta_Hadron", &particle3_eta_Hadron, &b_particle3_eta_Hadron);
   fChain->SetBranchAddress("particle3_eta_Parton", &particle3_eta_Parton, &b_particle3_eta_Parton);
   fChain->SetBranchAddress("particle3_jetid_Hadron", &particle3_jetid_Hadron, &b_particle3_jetid_Hadron);
   fChain->SetBranchAddress("particle3_jetid_Parton", &particle3_jetid_Parton, &b_particle3_jetid_Parton);
   fChain->SetBranchAddress("particle3_phi_Hadron", &particle3_phi_Hadron, &b_particle3_phi_Hadron);
   fChain->SetBranchAddress("particle3_phi_Parton", &particle3_phi_Parton, &b_particle3_phi_Parton);
   fChain->SetBranchAddress("particle3_pid_Hadron", &particle3_pid_Hadron, &b_particle3_pid_Hadron);
   fChain->SetBranchAddress("particle3_pid_Parton", &particle3_pid_Parton, &b_particle3_pid_Parton);
   fChain->SetBranchAddress("particle3_pt_Hadron", &particle3_pt_Hadron, &b_particle3_pt_Hadron);
   fChain->SetBranchAddress("particle3_pt_Parton", &particle3_pt_Parton, &b_particle3_pt_Parton);
   fChain->SetBranchAddress("particle4_charge_Hadron", &particle4_charge_Hadron, &b_particle4_charge_Hadron);
   fChain->SetBranchAddress("particle4_charge_Parton", &particle4_charge_Parton, &b_particle4_charge_Parton);
   fChain->SetBranchAddress("particle4_e_Hadron", &particle4_e_Hadron, &b_particle4_e_Hadron);
   fChain->SetBranchAddress("particle4_e_Parton", &particle4_e_Parton, &b_particle4_e_Parton);
   fChain->SetBranchAddress("particle4_eta_Hadron", &particle4_eta_Hadron, &b_particle4_eta_Hadron);
   fChain->SetBranchAddress("particle4_eta_Parton", &particle4_eta_Parton, &b_particle4_eta_Parton);
   fChain->SetBranchAddress("particle4_jetid_Hadron", &particle4_jetid_Hadron, &b_particle4_jetid_Hadron);
   fChain->SetBranchAddress("particle4_jetid_Parton", &particle4_jetid_Parton, &b_particle4_jetid_Parton);
   fChain->SetBranchAddress("particle4_phi_Hadron", &particle4_phi_Hadron, &b_particle4_phi_Hadron);
   fChain->SetBranchAddress("particle4_phi_Parton", &particle4_phi_Parton, &b_particle4_phi_Parton);
   fChain->SetBranchAddress("particle4_pid_Hadron", &particle4_pid_Hadron, &b_particle4_pid_Hadron);
   fChain->SetBranchAddress("particle4_pid_Parton", &particle4_pid_Parton, &b_particle4_pid_Parton);
   fChain->SetBranchAddress("particle4_pt_Hadron", &particle4_pt_Hadron, &b_particle4_pt_Hadron);
   fChain->SetBranchAddress("particle4_pt_Parton", &particle4_pt_Parton, &b_particle4_pt_Parton);
   fChain->SetBranchAddress("particle5_charge_Hadron", &particle5_charge_Hadron, &b_particle5_charge_Hadron);
   fChain->SetBranchAddress("particle5_charge_Parton", &particle5_charge_Parton, &b_particle5_charge_Parton);
   fChain->SetBranchAddress("particle5_e_Hadron", &particle5_e_Hadron, &b_particle5_e_Hadron);
   fChain->SetBranchAddress("particle5_e_Parton", &particle5_e_Parton, &b_particle5_e_Parton);
   fChain->SetBranchAddress("particle5_eta_Hadron", &particle5_eta_Hadron, &b_particle5_eta_Hadron);
   fChain->SetBranchAddress("particle5_eta_Parton", &particle5_eta_Parton, &b_particle5_eta_Parton);
   fChain->SetBranchAddress("particle5_jetid_Hadron", &particle5_jetid_Hadron, &b_particle5_jetid_Hadron);
   fChain->SetBranchAddress("particle5_jetid_Parton", &particle5_jetid_Parton, &b_particle5_jetid_Parton);
   fChain->SetBranchAddress("particle5_phi_Hadron", &particle5_phi_Hadron, &b_particle5_phi_Hadron);
   fChain->SetBranchAddress("particle5_phi_Parton", &particle5_phi_Parton, &b_particle5_phi_Parton);
   fChain->SetBranchAddress("particle5_pid_Hadron", &particle5_pid_Hadron, &b_particle5_pid_Hadron);
   fChain->SetBranchAddress("particle5_pid_Parton", &particle5_pid_Parton, &b_particle5_pid_Parton);
   fChain->SetBranchAddress("particle5_pt_Hadron", &particle5_pt_Hadron, &b_particle5_pt_Hadron);
   fChain->SetBranchAddress("particle5_pt_Parton", &particle5_pt_Parton, &b_particle5_pt_Parton);
   fChain->SetBranchAddress("particle6_charge_Hadron", &particle6_charge_Hadron, &b_particle6_charge_Hadron);
   fChain->SetBranchAddress("particle6_charge_Parton", &particle6_charge_Parton, &b_particle6_charge_Parton);
   fChain->SetBranchAddress("particle6_e_Hadron", &particle6_e_Hadron, &b_particle6_e_Hadron);
   fChain->SetBranchAddress("particle6_e_Parton", &particle6_e_Parton, &b_particle6_e_Parton);
   fChain->SetBranchAddress("particle6_eta_Hadron", &particle6_eta_Hadron, &b_particle6_eta_Hadron);
   fChain->SetBranchAddress("particle6_eta_Parton", &particle6_eta_Parton, &b_particle6_eta_Parton);
   fChain->SetBranchAddress("particle6_jetid_Hadron", &particle6_jetid_Hadron, &b_particle6_jetid_Hadron);
   fChain->SetBranchAddress("particle6_jetid_Parton", &particle6_jetid_Parton, &b_particle6_jetid_Parton);
   fChain->SetBranchAddress("particle6_phi_Hadron", &particle6_phi_Hadron, &b_particle6_phi_Hadron);
   fChain->SetBranchAddress("particle6_phi_Parton", &particle6_phi_Parton, &b_particle6_phi_Parton);
   fChain->SetBranchAddress("particle6_pid_Hadron", &particle6_pid_Hadron, &b_particle6_pid_Hadron);
   fChain->SetBranchAddress("particle6_pid_Parton", &particle6_pid_Parton, &b_particle6_pid_Parton);
   fChain->SetBranchAddress("particle6_pt_Hadron", &particle6_pt_Hadron, &b_particle6_pt_Hadron);
   fChain->SetBranchAddress("particle6_pt_Parton", &particle6_pt_Parton, &b_particle6_pt_Parton);
   fChain->SetBranchAddress("phi1_Hadron", &phi1_Hadron, &b_phi1_Hadron);
   fChain->SetBranchAddress("phi1_Parton", &phi1_Parton, &b_phi1_Parton);
   fChain->SetBranchAddress("phi2_Hadron", &phi2_Hadron, &b_phi2_Hadron);
   fChain->SetBranchAddress("phi2_Parton", &phi2_Parton, &b_phi2_Parton);
   fChain->SetBranchAddress("phi3_Hadron", &phi3_Hadron, &b_phi3_Hadron);
   fChain->SetBranchAddress("phi3_Parton", &phi3_Parton, &b_phi3_Parton);
   fChain->SetBranchAddress("phi4_Hadron", &phi4_Hadron, &b_phi4_Hadron);
   fChain->SetBranchAddress("phi4_Parton", &phi4_Parton, &b_phi4_Parton);
   fChain->SetBranchAddress("phi5_Hadron", &phi5_Hadron, &b_phi5_Hadron);
   fChain->SetBranchAddress("phi5_Parton", &phi5_Parton, &b_phi5_Parton);
   fChain->SetBranchAddress("phi6_Hadron", &phi6_Hadron, &b_phi6_Hadron);
   fChain->SetBranchAddress("phi6_Parton", &phi6_Parton, &b_phi6_Parton);
   fChain->SetBranchAddress("phi_Hadron", &phi_Hadron, &b_phi_Hadron);
   fChain->SetBranchAddress("phi_Parton", &phi_Parton, &b_phi_Parton);
   fChain->SetBranchAddress("pt1_Hadron", &pt1_Hadron, &b_pt1_Hadron);
   fChain->SetBranchAddress("pt1_Parton", &pt1_Parton, &b_pt1_Parton);
   fChain->SetBranchAddress("pt2_Hadron", &pt2_Hadron, &b_pt2_Hadron);
   fChain->SetBranchAddress("pt2_Parton", &pt2_Parton, &b_pt2_Parton);
   fChain->SetBranchAddress("pt3_Hadron", &pt3_Hadron, &b_pt3_Hadron);
   fChain->SetBranchAddress("pt3_Parton", &pt3_Parton, &b_pt3_Parton);
   fChain->SetBranchAddress("pt4_Hadron", &pt4_Hadron, &b_pt4_Hadron);
   fChain->SetBranchAddress("pt4_Parton", &pt4_Parton, &b_pt4_Parton);
   fChain->SetBranchAddress("pt5_Hadron", &pt5_Hadron, &b_pt5_Hadron);
   fChain->SetBranchAddress("pt5_Parton", &pt5_Parton, &b_pt5_Parton);
   fChain->SetBranchAddress("pt6_Hadron", &pt6_Hadron, &b_pt6_Hadron);
   fChain->SetBranchAddress("pt6_Parton", &pt6_Parton, &b_pt6_Parton);
   fChain->SetBranchAddress("theta1_Hadron", &theta1_Hadron, &b_theta1_Hadron);
   fChain->SetBranchAddress("theta1_Parton", &theta1_Parton, &b_theta1_Parton);
   fChain->SetBranchAddress("theta2_Hadron", &theta2_Hadron, &b_theta2_Hadron);
   fChain->SetBranchAddress("theta2_Parton", &theta2_Parton, &b_theta2_Parton);
   fChain->SetBranchAddress("theta3_Hadron", &theta3_Hadron, &b_theta3_Hadron);
   fChain->SetBranchAddress("theta3_Parton", &theta3_Parton, &b_theta3_Parton);
   fChain->SetBranchAddress("thirdphi_Hadron", &thirdphi_Hadron, &b_thirdphi_Hadron);
   fChain->SetBranchAddress("thirdphi_Parton", &thirdphi_Parton, &b_thirdphi_Parton);
   fChain->SetBranchAddress("z1_Hadron", &z1_Hadron, &b_z1_Hadron);
   fChain->SetBranchAddress("z1_Parton", &z1_Parton, &b_z1_Parton);
   fChain->SetBranchAddress("z2_Hadron", &z2_Hadron, &b_z2_Hadron);
   fChain->SetBranchAddress("z2_Parton", &z2_Parton, &b_z2_Parton);
   fChain->SetBranchAddress("z3_Hadron", &z3_Hadron, &b_z3_Hadron);
   fChain->SetBranchAddress("z3_Parton", &z3_Parton, &b_z3_Parton);
   
   fChain->SetBranchAddress("spin", &spin, &b_spin);

   Notify();
}

Bool_t AdvancedDataInfo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AdvancedDataInfo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AdvancedDataInfo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
