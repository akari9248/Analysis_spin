//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 26 15:04:13 2024 by ROOT version 6.24/04
// from TTree DNNTrainTree/DNN Train Tree
// found on file: /home/zlin/Machine_learning/ML/Datasets/Prediction/Private_Herwig_spinoff_FourLabel_unmatched/Chunk0_Part0.root
//////////////////////////////////////////////////////////

#ifndef DNNTrainTree_h
#define DNNTrainTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

using namespace std;
class DNNTrainTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        GeneratorWeight;
   vector<double>  *Phi2_Hadron;
   vector<double>  *Phi2_Parton;
   vector<double>  *Phi3_Hadron;
   vector<double>  *Phi3_Parton;
   vector<double>  *Theta22_Hadron;
   vector<double>  *Theta22_Parton;
   vector<double>  *Theta23_Hadron;
   vector<double>  *Theta23_Parton;
   vector<double>  *Theta2_Hadron;
   vector<double>  *Theta2_Parton;
   vector<double>  *Theta3_Hadron;
   vector<double>  *Theta3_Parton;
   vector<double>  *dPhi12_X2_Hadron;
   vector<double>  *dPhi12_X2_Parton;
   vector<double>  *dPhi12_X3_Hadron;
   vector<double>  *dPhi12_X3_Parton;
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
   vector<double>  *je_Hadron;
   vector<double>  *je_Parton;
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
   vector<int>     *match2;
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
   vector<double>  *pTD1_Hadron;
   vector<double>  *pTD1_Parton;
   vector<double>  *pTD2_Hadron;
   vector<double>  *pTD2_Parton;
   vector<double>  *pTD3_Hadron;
   vector<double>  *pTD3_Parton;
   vector<double>  *pTD4_Hadron;
   vector<double>  *pTD4_Parton;
   vector<double>  *pTD5_Hadron;
   vector<double>  *pTD5_Parton;
   vector<double>  *pTD6_Hadron;
   vector<double>  *pTD6_Parton;
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
   vector<double>  *sigma11_Hadron;
   vector<double>  *sigma11_Parton;
   vector<double>  *sigma12_Hadron;
   vector<double>  *sigma12_Parton;
   vector<double>  *sigma13_Hadron;
   vector<double>  *sigma13_Parton;
   vector<double>  *sigma14_Hadron;
   vector<double>  *sigma14_Parton;
   vector<double>  *sigma15_Hadron;
   vector<double>  *sigma15_Parton;
   vector<double>  *sigma16_Hadron;
   vector<double>  *sigma16_Parton;
   vector<double>  *sigma1_Hadron;
   vector<double>  *sigma1_Parton;
   vector<double>  *sigma21_Hadron;
   vector<double>  *sigma21_Parton;
   vector<double>  *sigma22_Hadron;
   vector<double>  *sigma22_Parton;
   vector<double>  *sigma23_Hadron;
   vector<double>  *sigma23_Parton;
   vector<double>  *sigma24_Hadron;
   vector<double>  *sigma24_Parton;
   vector<double>  *sigma25_Hadron;
   vector<double>  *sigma25_Parton;
   vector<double>  *sigma26_Hadron;
   vector<double>  *sigma26_Parton;
   vector<double>  *sigma2_Hadron;
   vector<double>  *sigma2_Parton;
   vector<double>  *sigma3_Hadron;
   vector<double>  *sigma3_Parton;
   vector<double>  *sigma4_Hadron;
   vector<double>  *sigma4_Parton;
   vector<double>  *sigma5_Hadron;
   vector<double>  *sigma5_Parton;
   vector<double>  *sigma6_Hadron;
   vector<double>  *sigma6_Parton;
   vector<double>  *theta1_Hadron;
   vector<double>  *theta1_Parton;
   vector<double>  *theta2_Hadron;
   vector<double>  *theta2_Parton;
   vector<double>  *theta3_Hadron;
   vector<double>  *theta3_Parton;
   vector<int>     *type1_Hadron;
   vector<int>     *type1_Parton;
   vector<int>     *type2_Hadron;
   vector<int>     *type2_Parton;
   vector<int>     *type3_Hadron;
   vector<int>     *type3_Parton;
   vector<double>  *z1_Hadron;
   vector<double>  *z1_Parton;
   vector<double>  *z2_Hadron;
   vector<double>  *z2_Parton;
   vector<double>  *z3_Hadron;
   vector<double>  *z3_Parton;
   vector<double>  *score0_Hadron;
   vector<double>  *score1_Hadron;
   vector<double>  *score2_Hadron;
   vector<double>  *score3_Hadron;
   vector<int>     *validate_Hadron;

   // List of branches
   TBranch        *b_GeneratorWeight;   //!
   TBranch        *b_Phi2_Hadron;   //!
   TBranch        *b_Phi2_Parton;   //!
   TBranch        *b_Phi3_Hadron;   //!
   TBranch        *b_Phi3_Parton;   //!
   TBranch        *b_Theta22_Hadron;   //!
   TBranch        *b_Theta22_Parton;   //!
   TBranch        *b_Theta23_Hadron;   //!
   TBranch        *b_Theta23_Parton;   //!
   TBranch        *b_Theta2_Hadron;   //!
   TBranch        *b_Theta2_Parton;   //!
   TBranch        *b_Theta3_Hadron;   //!
   TBranch        *b_Theta3_Parton;   //!
   TBranch        *b_dPhi12_X2_Hadron;   //!
   TBranch        *b_dPhi12_X2_Parton;   //!
   TBranch        *b_dPhi12_X3_Hadron;   //!
   TBranch        *b_dPhi12_X3_Parton;   //!
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
   TBranch        *b_je_Hadron;   //!
   TBranch        *b_je_Parton;   //!
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
   TBranch        *b_match2;   //!
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
   TBranch        *b_pTD1_Hadron;   //!
   TBranch        *b_pTD1_Parton;   //!
   TBranch        *b_pTD2_Hadron;   //!
   TBranch        *b_pTD2_Parton;   //!
   TBranch        *b_pTD3_Hadron;   //!
   TBranch        *b_pTD3_Parton;   //!
   TBranch        *b_pTD4_Hadron;   //!
   TBranch        *b_pTD4_Parton;   //!
   TBranch        *b_pTD5_Hadron;   //!
   TBranch        *b_pTD5_Parton;   //!
   TBranch        *b_pTD6_Hadron;   //!
   TBranch        *b_pTD6_Parton;   //!
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
   TBranch        *b_sigma11_Hadron;   //!
   TBranch        *b_sigma11_Parton;   //!
   TBranch        *b_sigma12_Hadron;   //!
   TBranch        *b_sigma12_Parton;   //!
   TBranch        *b_sigma13_Hadron;   //!
   TBranch        *b_sigma13_Parton;   //!
   TBranch        *b_sigma14_Hadron;   //!
   TBranch        *b_sigma14_Parton;   //!
   TBranch        *b_sigma15_Hadron;   //!
   TBranch        *b_sigma15_Parton;   //!
   TBranch        *b_sigma16_Hadron;   //!
   TBranch        *b_sigma16_Parton;   //!
   TBranch        *b_sigma1_Hadron;   //!
   TBranch        *b_sigma1_Parton;   //!
   TBranch        *b_sigma21_Hadron;   //!
   TBranch        *b_sigma21_Parton;   //!
   TBranch        *b_sigma22_Hadron;   //!
   TBranch        *b_sigma22_Parton;   //!
   TBranch        *b_sigma23_Hadron;   //!
   TBranch        *b_sigma23_Parton;   //!
   TBranch        *b_sigma24_Hadron;   //!
   TBranch        *b_sigma24_Parton;   //!
   TBranch        *b_sigma25_Hadron;   //!
   TBranch        *b_sigma25_Parton;   //!
   TBranch        *b_sigma26_Hadron;   //!
   TBranch        *b_sigma26_Parton;   //!
   TBranch        *b_sigma2_Hadron;   //!
   TBranch        *b_sigma2_Parton;   //!
   TBranch        *b_sigma3_Hadron;   //!
   TBranch        *b_sigma3_Parton;   //!
   TBranch        *b_sigma4_Hadron;   //!
   TBranch        *b_sigma4_Parton;   //!
   TBranch        *b_sigma5_Hadron;   //!
   TBranch        *b_sigma5_Parton;   //!
   TBranch        *b_sigma6_Hadron;   //!
   TBranch        *b_sigma6_Parton;   //!
   TBranch        *b_theta1_Hadron;   //!
   TBranch        *b_theta1_Parton;   //!
   TBranch        *b_theta2_Hadron;   //!
   TBranch        *b_theta2_Parton;   //!
   TBranch        *b_theta3_Hadron;   //!
   TBranch        *b_theta3_Parton;   //!
   TBranch        *b_type1_Hadron;   //!
   TBranch        *b_type1_Parton;   //!
   TBranch        *b_type2_Hadron;   //!
   TBranch        *b_type2_Parton;   //!
   TBranch        *b_type3_Hadron;   //!
   TBranch        *b_type3_Parton;   //!
   TBranch        *b_z1_Hadron;   //!
   TBranch        *b_z1_Parton;   //!
   TBranch        *b_z2_Hadron;   //!
   TBranch        *b_z2_Parton;   //!
   TBranch        *b_z3_Hadron;   //!
   TBranch        *b_z3_Parton;   //!
   TBranch        *b_score0_Hadron;   //!
   TBranch        *b_score1_Hadron;   //!
   TBranch        *b_score2_Hadron;   //!
   TBranch        *b_score3_Hadron;   //!
   TBranch        *b_validate_Hadron;   //!

   DNNTrainTree(TTree *tree=0);
   virtual ~DNNTrainTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   // virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

// #ifdef DNNTrainTree_cxx
DNNTrainTree::DNNTrainTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/zlin/Machine_learning/ML/Datasets/Prediction/Private_Herwig_spinoff_FourLabel_unmatched/Chunk0_Part0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/zlin/Machine_learning/ML/Datasets/Prediction/Private_Herwig_spinoff_FourLabel_unmatched/Chunk0_Part0.root");
      }
      f->GetObject("DNNTrainTree",tree);

   }
   Init(tree);
}

DNNTrainTree::~DNNTrainTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DNNTrainTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DNNTrainTree::LoadTree(Long64_t entry)
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

void DNNTrainTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Phi2_Hadron = 0;
   Phi2_Parton = 0;
   Phi3_Hadron = 0;
   Phi3_Parton = 0;
   Theta22_Hadron = 0;
   Theta22_Parton = 0;
   Theta23_Hadron = 0;
   Theta23_Parton = 0;
   Theta2_Hadron = 0;
   Theta2_Parton = 0;
   Theta3_Hadron = 0;
   Theta3_Parton = 0;
   dPhi12_X2_Hadron = 0;
   dPhi12_X2_Parton = 0;
   dPhi12_X3_Hadron = 0;
   dPhi12_X3_Parton = 0;
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
   je_Hadron = 0;
   je_Parton = 0;
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
   match2 = 0;
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
   pTD1_Hadron = 0;
   pTD1_Parton = 0;
   pTD2_Hadron = 0;
   pTD2_Parton = 0;
   pTD3_Hadron = 0;
   pTD3_Parton = 0;
   pTD4_Hadron = 0;
   pTD4_Parton = 0;
   pTD5_Hadron = 0;
   pTD5_Parton = 0;
   pTD6_Hadron = 0;
   pTD6_Parton = 0;
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
   sigma11_Hadron = 0;
   sigma11_Parton = 0;
   sigma12_Hadron = 0;
   sigma12_Parton = 0;
   sigma13_Hadron = 0;
   sigma13_Parton = 0;
   sigma14_Hadron = 0;
   sigma14_Parton = 0;
   sigma15_Hadron = 0;
   sigma15_Parton = 0;
   sigma16_Hadron = 0;
   sigma16_Parton = 0;
   sigma1_Hadron = 0;
   sigma1_Parton = 0;
   sigma21_Hadron = 0;
   sigma21_Parton = 0;
   sigma22_Hadron = 0;
   sigma22_Parton = 0;
   sigma23_Hadron = 0;
   sigma23_Parton = 0;
   sigma24_Hadron = 0;
   sigma24_Parton = 0;
   sigma25_Hadron = 0;
   sigma25_Parton = 0;
   sigma26_Hadron = 0;
   sigma26_Parton = 0;
   sigma2_Hadron = 0;
   sigma2_Parton = 0;
   sigma3_Hadron = 0;
   sigma3_Parton = 0;
   sigma4_Hadron = 0;
   sigma4_Parton = 0;
   sigma5_Hadron = 0;
   sigma5_Parton = 0;
   sigma6_Hadron = 0;
   sigma6_Parton = 0;
   theta1_Hadron = 0;
   theta1_Parton = 0;
   theta2_Hadron = 0;
   theta2_Parton = 0;
   theta3_Hadron = 0;
   theta3_Parton = 0;
   type1_Hadron = 0;
   type1_Parton = 0;
   type2_Hadron = 0;
   type2_Parton = 0;
   type3_Hadron = 0;
   type3_Parton = 0;
   z1_Hadron = 0;
   z1_Parton = 0;
   z2_Hadron = 0;
   z2_Parton = 0;
   z3_Hadron = 0;
   z3_Parton = 0;
   score0_Hadron = 0;
   score1_Hadron = 0;
   score2_Hadron = 0;
   score3_Hadron = 0;
   validate_Hadron = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   fChain->SetBranchAddress("Phi2_Hadron", &Phi2_Hadron, &b_Phi2_Hadron);
   fChain->SetBranchAddress("Phi2_Parton", &Phi2_Parton, &b_Phi2_Parton);
   fChain->SetBranchAddress("Phi3_Hadron", &Phi3_Hadron, &b_Phi3_Hadron);
   fChain->SetBranchAddress("Phi3_Parton", &Phi3_Parton, &b_Phi3_Parton);
   fChain->SetBranchAddress("Theta22_Hadron", &Theta22_Hadron, &b_Theta22_Hadron);
   fChain->SetBranchAddress("Theta22_Parton", &Theta22_Parton, &b_Theta22_Parton);
   fChain->SetBranchAddress("Theta23_Hadron", &Theta23_Hadron, &b_Theta23_Hadron);
   fChain->SetBranchAddress("Theta23_Parton", &Theta23_Parton, &b_Theta23_Parton);
   fChain->SetBranchAddress("Theta2_Hadron", &Theta2_Hadron, &b_Theta2_Hadron);
   fChain->SetBranchAddress("Theta2_Parton", &Theta2_Parton, &b_Theta2_Parton);
   fChain->SetBranchAddress("Theta3_Hadron", &Theta3_Hadron, &b_Theta3_Hadron);
   fChain->SetBranchAddress("Theta3_Parton", &Theta3_Parton, &b_Theta3_Parton);
   fChain->SetBranchAddress("dPhi12_X2_Hadron", &dPhi12_X2_Hadron, &b_dPhi12_X2_Hadron);
   fChain->SetBranchAddress("dPhi12_X2_Parton", &dPhi12_X2_Parton, &b_dPhi12_X2_Parton);
   fChain->SetBranchAddress("dPhi12_X3_Hadron", &dPhi12_X3_Hadron, &b_dPhi12_X3_Hadron);
   fChain->SetBranchAddress("dPhi12_X3_Parton", &dPhi12_X3_Parton, &b_dPhi12_X3_Parton);
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
   fChain->SetBranchAddress("je_Hadron", &je_Hadron, &b_je_Hadron);
   fChain->SetBranchAddress("je_Parton", &je_Parton, &b_je_Parton);
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
   fChain->SetBranchAddress("match2", &match2, &b_match2);
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
   fChain->SetBranchAddress("pTD1_Hadron", &pTD1_Hadron, &b_pTD1_Hadron);
   fChain->SetBranchAddress("pTD1_Parton", &pTD1_Parton, &b_pTD1_Parton);
   fChain->SetBranchAddress("pTD2_Hadron", &pTD2_Hadron, &b_pTD2_Hadron);
   fChain->SetBranchAddress("pTD2_Parton", &pTD2_Parton, &b_pTD2_Parton);
   fChain->SetBranchAddress("pTD3_Hadron", &pTD3_Hadron, &b_pTD3_Hadron);
   fChain->SetBranchAddress("pTD3_Parton", &pTD3_Parton, &b_pTD3_Parton);
   fChain->SetBranchAddress("pTD4_Hadron", &pTD4_Hadron, &b_pTD4_Hadron);
   fChain->SetBranchAddress("pTD4_Parton", &pTD4_Parton, &b_pTD4_Parton);
   fChain->SetBranchAddress("pTD5_Hadron", &pTD5_Hadron, &b_pTD5_Hadron);
   fChain->SetBranchAddress("pTD5_Parton", &pTD5_Parton, &b_pTD5_Parton);
   fChain->SetBranchAddress("pTD6_Hadron", &pTD6_Hadron, &b_pTD6_Hadron);
   fChain->SetBranchAddress("pTD6_Parton", &pTD6_Parton, &b_pTD6_Parton);
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
   fChain->SetBranchAddress("sigma11_Hadron", &sigma11_Hadron, &b_sigma11_Hadron);
   fChain->SetBranchAddress("sigma11_Parton", &sigma11_Parton, &b_sigma11_Parton);
   fChain->SetBranchAddress("sigma12_Hadron", &sigma12_Hadron, &b_sigma12_Hadron);
   fChain->SetBranchAddress("sigma12_Parton", &sigma12_Parton, &b_sigma12_Parton);
   fChain->SetBranchAddress("sigma13_Hadron", &sigma13_Hadron, &b_sigma13_Hadron);
   fChain->SetBranchAddress("sigma13_Parton", &sigma13_Parton, &b_sigma13_Parton);
   fChain->SetBranchAddress("sigma14_Hadron", &sigma14_Hadron, &b_sigma14_Hadron);
   fChain->SetBranchAddress("sigma14_Parton", &sigma14_Parton, &b_sigma14_Parton);
   fChain->SetBranchAddress("sigma15_Hadron", &sigma15_Hadron, &b_sigma15_Hadron);
   fChain->SetBranchAddress("sigma15_Parton", &sigma15_Parton, &b_sigma15_Parton);
   fChain->SetBranchAddress("sigma16_Hadron", &sigma16_Hadron, &b_sigma16_Hadron);
   fChain->SetBranchAddress("sigma16_Parton", &sigma16_Parton, &b_sigma16_Parton);
   fChain->SetBranchAddress("sigma1_Hadron", &sigma1_Hadron, &b_sigma1_Hadron);
   fChain->SetBranchAddress("sigma1_Parton", &sigma1_Parton, &b_sigma1_Parton);
   fChain->SetBranchAddress("sigma21_Hadron", &sigma21_Hadron, &b_sigma21_Hadron);
   fChain->SetBranchAddress("sigma21_Parton", &sigma21_Parton, &b_sigma21_Parton);
   fChain->SetBranchAddress("sigma22_Hadron", &sigma22_Hadron, &b_sigma22_Hadron);
   fChain->SetBranchAddress("sigma22_Parton", &sigma22_Parton, &b_sigma22_Parton);
   fChain->SetBranchAddress("sigma23_Hadron", &sigma23_Hadron, &b_sigma23_Hadron);
   fChain->SetBranchAddress("sigma23_Parton", &sigma23_Parton, &b_sigma23_Parton);
   fChain->SetBranchAddress("sigma24_Hadron", &sigma24_Hadron, &b_sigma24_Hadron);
   fChain->SetBranchAddress("sigma24_Parton", &sigma24_Parton, &b_sigma24_Parton);
   fChain->SetBranchAddress("sigma25_Hadron", &sigma25_Hadron, &b_sigma25_Hadron);
   fChain->SetBranchAddress("sigma25_Parton", &sigma25_Parton, &b_sigma25_Parton);
   fChain->SetBranchAddress("sigma26_Hadron", &sigma26_Hadron, &b_sigma26_Hadron);
   fChain->SetBranchAddress("sigma26_Parton", &sigma26_Parton, &b_sigma26_Parton);
   fChain->SetBranchAddress("sigma2_Hadron", &sigma2_Hadron, &b_sigma2_Hadron);
   fChain->SetBranchAddress("sigma2_Parton", &sigma2_Parton, &b_sigma2_Parton);
   fChain->SetBranchAddress("sigma3_Hadron", &sigma3_Hadron, &b_sigma3_Hadron);
   fChain->SetBranchAddress("sigma3_Parton", &sigma3_Parton, &b_sigma3_Parton);
   fChain->SetBranchAddress("sigma4_Hadron", &sigma4_Hadron, &b_sigma4_Hadron);
   fChain->SetBranchAddress("sigma4_Parton", &sigma4_Parton, &b_sigma4_Parton);
   fChain->SetBranchAddress("sigma5_Hadron", &sigma5_Hadron, &b_sigma5_Hadron);
   fChain->SetBranchAddress("sigma5_Parton", &sigma5_Parton, &b_sigma5_Parton);
   fChain->SetBranchAddress("sigma6_Hadron", &sigma6_Hadron, &b_sigma6_Hadron);
   fChain->SetBranchAddress("sigma6_Parton", &sigma6_Parton, &b_sigma6_Parton);
   fChain->SetBranchAddress("theta1_Hadron", &theta1_Hadron, &b_theta1_Hadron);
   fChain->SetBranchAddress("theta1_Parton", &theta1_Parton, &b_theta1_Parton);
   fChain->SetBranchAddress("theta2_Hadron", &theta2_Hadron, &b_theta2_Hadron);
   fChain->SetBranchAddress("theta2_Parton", &theta2_Parton, &b_theta2_Parton);
   fChain->SetBranchAddress("theta3_Hadron", &theta3_Hadron, &b_theta3_Hadron);
   fChain->SetBranchAddress("theta3_Parton", &theta3_Parton, &b_theta3_Parton);
   fChain->SetBranchAddress("type1_Hadron", &type1_Hadron, &b_type1_Hadron);
   fChain->SetBranchAddress("type1_Parton", &type1_Parton, &b_type1_Parton);
   fChain->SetBranchAddress("type2_Hadron", &type2_Hadron, &b_type2_Hadron);
   fChain->SetBranchAddress("type2_Parton", &type2_Parton, &b_type2_Parton);
   fChain->SetBranchAddress("type3_Hadron", &type3_Hadron, &b_type3_Hadron);
   fChain->SetBranchAddress("type3_Parton", &type3_Parton, &b_type3_Parton);
   fChain->SetBranchAddress("z1_Hadron", &z1_Hadron, &b_z1_Hadron);
   fChain->SetBranchAddress("z1_Parton", &z1_Parton, &b_z1_Parton);
   fChain->SetBranchAddress("z2_Hadron", &z2_Hadron, &b_z2_Hadron);
   fChain->SetBranchAddress("z2_Parton", &z2_Parton, &b_z2_Parton);
   fChain->SetBranchAddress("z3_Hadron", &z3_Hadron, &b_z3_Hadron);
   fChain->SetBranchAddress("z3_Parton", &z3_Parton, &b_z3_Parton);
   fChain->SetBranchAddress("score0_Hadron", &score0_Hadron, &b_score0_Hadron);
   fChain->SetBranchAddress("score1_Hadron", &score1_Hadron, &b_score1_Hadron);
   fChain->SetBranchAddress("score2_Hadron", &score2_Hadron, &b_score2_Hadron);
   fChain->SetBranchAddress("score3_Hadron", &score3_Hadron, &b_score3_Hadron);
   fChain->SetBranchAddress("validate_Hadron", &validate_Hadron, &b_validate_Hadron);
   Notify();
}

Bool_t DNNTrainTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DNNTrainTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DNNTrainTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
// #endif // #ifdef DNNTrainTree_cxx
