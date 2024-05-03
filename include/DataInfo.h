//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 22 20:46:06 2024 by ROOT version 6.24/04
// from TTree DataInfo/DataInfo
// found on file: test/validation_data_CA_lundplane_parton1wz00pt200IFN.root
//////////////////////////////////////////////////////////
#pragma once
#ifndef DataInfo_h
#define DataInfo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
// Header file for the classes stored in the TTree if any.
using namespace std;
class DataInfo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        pt1_Parton;
   Double_t        eta1_Parton;
   Double_t        phi1_Parton;
   Double_t        e1_Parton;
   Double_t        pt2_Parton;
   Double_t        eta2_Parton;
   Double_t        phi2_Parton;
   Double_t        e2_Parton;
   Double_t        pt3_Parton;
   Double_t        eta3_Parton;
   Double_t        phi3_Parton;
   Double_t        e3_Parton;
   Double_t        pt4_Parton;
   Double_t        eta4_Parton;
   Double_t        phi4_Parton;
   Double_t        e4_Parton;
   Double_t        z1_Parton;
   Double_t        kt1_Parton;
   Double_t        theta1_Parton;
   Double_t        deltaR1_Parton;
   Double_t        eec1_Parton;
   Double_t        z2_Parton;
   Double_t        kt2_Parton;
   Double_t        theta2_Parton;
   Double_t        deltaR2_Parton;
   Double_t        eec2_Parton;
   Double_t        n1x_Parton;
   Double_t        n1y_Parton;
   Double_t        n1z_Parton;
   Double_t        n2x_Parton;
   Double_t        n2y_Parton;
   Double_t        n2z_Parton;
   Double_t        isqq_Parton;
   Double_t        isgg_Parton;
   Double_t        phi_Parton;
   Double_t        jpt_Parton;
   Double_t        jeta_Parton;
   Double_t        jphi_Parton;
   Double_t        je_Parton;
   Double_t        pt1_Hadron;
   Double_t        eta1_Hadron;
   Double_t        phi1_Hadron;
   Double_t        e1_Hadron;
   Double_t        pt2_Hadron;
   Double_t        eta2_Hadron;
   Double_t        phi2_Hadron;
   Double_t        e2_Hadron;
   Double_t        pt3_Hadron;
   Double_t        eta3_Hadron;
   Double_t        phi3_Hadron;
   Double_t        e3_Hadron;
   Double_t        pt4_Hadron;
   Double_t        eta4_Hadron;
   Double_t        phi4_Hadron;
   Double_t        e4_Hadron;
   Double_t        z1_Hadron;
   Double_t        kt1_Hadron;
   Double_t        theta1_Hadron;
   Double_t        deltaR1_Hadron;
   Double_t        eec1_Hadron;
   Double_t        z2_Hadron;
   Double_t        kt2_Hadron;
   Double_t        theta2_Hadron;
   Double_t        deltaR2_Hadron;
   Double_t        eec2_Hadron;
   Double_t        n1x_Hadron;
   Double_t        n1y_Hadron;
   Double_t        n1z_Hadron;
   Double_t        n2x_Hadron;
   Double_t        n2y_Hadron;
   Double_t        n2z_Hadron;
   Double_t        isqq_Hadron;
   Double_t        isgg_Hadron;
   Double_t        phi_Hadron;
   Double_t        jpt_Hadron;
   Double_t        jeta_Hadron;
   Double_t        jphi_Hadron;
   Double_t        je_Hadron;
   Double_t        match;
   Double_t        spin;

   // List of branches
   TBranch        *b_pt1_Parton;   //!
   TBranch        *b_eta1_Parton;   //!
   TBranch        *b_phi1_Parton;   //!
   TBranch        *b_e1_Parton;   //!
   TBranch        *b_pt2_Parton;   //!
   TBranch        *b_eta2_Parton;   //!
   TBranch        *b_phi2_Parton;   //!
   TBranch        *b_e2_Parton;   //!
   TBranch        *b_pt3_Parton;   //!
   TBranch        *b_eta3_Parton;   //!
   TBranch        *b_phi3_Parton;   //!
   TBranch        *b_e3_Parton;   //!
   TBranch        *b_pt4_Parton;   //!
   TBranch        *b_eta4_Parton;   //!
   TBranch        *b_phi4_Parton;   //!
   TBranch        *b_e4_Parton;   //!
   TBranch        *b_z1_Parton;   //!
   TBranch        *b_kt1_Parton;   //!
   TBranch        *b_theta1_Parton;   //!
   TBranch        *b_deltaR1_Parton;   //!
   TBranch        *b_eec1_Parton;   //!
   TBranch        *b_z2_Parton;   //!
   TBranch        *b_kt2_Parton;   //!
   TBranch        *b_theta2_Parton;   //!
   TBranch        *b_deltaR2_Parton;   //!
   TBranch        *b_eec2_Parton;   //!
   TBranch        *b_n1x_Parton;   //!
   TBranch        *b_n1y_Parton;   //!
   TBranch        *b_n1z_Parton;   //!
   TBranch        *b_n2x_Parton;   //!
   TBranch        *b_n2y_Parton;   //!
   TBranch        *b_n2z_Parton;   //!
   TBranch        *b_isqq_Parton;   //!
   TBranch        *b_isgg_Parton;   //!
   TBranch        *b_phi_Parton;   //!
   TBranch        *b_jpt_Parton;   //!
   TBranch        *b_jeta_Parton;   //!
   TBranch        *b_jphi_Parton;   //!
   TBranch        *b_je_Parton;   //!
   TBranch        *b_pt1_Hadron;   //!
   TBranch        *b_eta1_Hadron;   //!
   TBranch        *b_phi1_Hadron;   //!
   TBranch        *b_e1_Hadron;   //!
   TBranch        *b_pt2_Hadron;   //!
   TBranch        *b_eta2_Hadron;   //!
   TBranch        *b_phi2_Hadron;   //!
   TBranch        *b_e2_Hadron;   //!
   TBranch        *b_pt3_Hadron;   //!
   TBranch        *b_eta3_Hadron;   //!
   TBranch        *b_phi3_Hadron;   //!
   TBranch        *b_e3_Hadron;   //!
   TBranch        *b_pt4_Hadron;   //!
   TBranch        *b_eta4_Hadron;   //!
   TBranch        *b_phi4_Hadron;   //!
   TBranch        *b_e4_Hadron;   //!
   TBranch        *b_z1_Hadron;   //!
   TBranch        *b_kt1_Hadron;   //!
   TBranch        *b_theta1_Hadron;   //!
   TBranch        *b_deltaR1_Hadron;   //!
   TBranch        *b_eec1_Hadron;   //!
   TBranch        *b_z2_Hadron;   //!
   TBranch        *b_kt2_Hadron;   //!
   TBranch        *b_theta2_Hadron;   //!
   TBranch        *b_deltaR2_Hadron;   //!
   TBranch        *b_eec2_Hadron;   //!
   TBranch        *b_n1x_Hadron;   //!
   TBranch        *b_n1y_Hadron;   //!
   TBranch        *b_n1z_Hadron;   //!
   TBranch        *b_n2x_Hadron;   //!
   TBranch        *b_n2y_Hadron;   //!
   TBranch        *b_n2z_Hadron;   //!
   TBranch        *b_isqq_Hadron;   //!
   TBranch        *b_isgg_Hadron;   //!
   TBranch        *b_phi_Hadron;   //!
   TBranch        *b_jpt_Hadron;   //!
   TBranch        *b_jeta_Hadron;   //!
   TBranch        *b_jphi_Hadron;   //!
   TBranch        *b_je_Hadron;   //!
   TBranch        *b_match;   //!
   TBranch        *b_spin;   //!

   DataInfo(TTree *tree=0);
   virtual ~DataInfo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

DataInfo::DataInfo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   
   if (tree != 0) {
      
      Init(tree);
      fChain->Print();
   }
   
   
}

DataInfo::~DataInfo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DataInfo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DataInfo::LoadTree(Long64_t entry)
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

void DataInfo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   std::cout<<"init tree"<<std::endl;
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pt1_Parton", &pt1_Parton, &b_pt1_Parton);
   fChain->SetBranchAddress("eta1_Parton", &eta1_Parton, &b_eta1_Parton);
   fChain->SetBranchAddress("phi1_Parton", &phi1_Parton, &b_phi1_Parton);
   fChain->SetBranchAddress("e1_Parton", &e1_Parton, &b_e1_Parton);
   fChain->SetBranchAddress("pt2_Parton", &pt2_Parton, &b_pt2_Parton);
   fChain->SetBranchAddress("eta2_Parton", &eta2_Parton, &b_eta2_Parton);
   fChain->SetBranchAddress("phi2_Parton", &phi2_Parton, &b_phi2_Parton);
   fChain->SetBranchAddress("e2_Parton", &e2_Parton, &b_e2_Parton);
   fChain->SetBranchAddress("pt3_Parton", &pt3_Parton, &b_pt3_Parton);
   fChain->SetBranchAddress("eta3_Parton", &eta3_Parton, &b_eta3_Parton);
   fChain->SetBranchAddress("phi3_Parton", &phi3_Parton, &b_phi3_Parton);
   fChain->SetBranchAddress("e3_Parton", &e3_Parton, &b_e3_Parton);
   fChain->SetBranchAddress("pt4_Parton", &pt4_Parton, &b_pt4_Parton);
   fChain->SetBranchAddress("eta4_Parton", &eta4_Parton, &b_eta4_Parton);
   fChain->SetBranchAddress("phi4_Parton", &phi4_Parton, &b_phi4_Parton);
   fChain->SetBranchAddress("e4_Parton", &e4_Parton, &b_e4_Parton);
   fChain->SetBranchAddress("z1_Parton", &z1_Parton, &b_z1_Parton);
   fChain->SetBranchAddress("kt1_Parton", &kt1_Parton, &b_kt1_Parton);
   fChain->SetBranchAddress("theta1_Parton", &theta1_Parton, &b_theta1_Parton);
   fChain->SetBranchAddress("deltaR1_Parton", &deltaR1_Parton, &b_deltaR1_Parton);
   fChain->SetBranchAddress("eec1_Parton", &eec1_Parton, &b_eec1_Parton);
   fChain->SetBranchAddress("z2_Parton", &z2_Parton, &b_z2_Parton);
   fChain->SetBranchAddress("kt2_Parton", &kt2_Parton, &b_kt2_Parton);
   fChain->SetBranchAddress("theta2_Parton", &theta2_Parton, &b_theta2_Parton);
   fChain->SetBranchAddress("deltaR2_Parton", &deltaR2_Parton, &b_deltaR2_Parton);
   fChain->SetBranchAddress("eec2_Parton", &eec2_Parton, &b_eec2_Parton);
   fChain->SetBranchAddress("n1x_Parton", &n1x_Parton, &b_n1x_Parton);
   fChain->SetBranchAddress("n1y_Parton", &n1y_Parton, &b_n1y_Parton);
   fChain->SetBranchAddress("n1z_Parton", &n1z_Parton, &b_n1z_Parton);
   fChain->SetBranchAddress("n2x_Parton", &n2x_Parton, &b_n2x_Parton);
   fChain->SetBranchAddress("n2y_Parton", &n2y_Parton, &b_n2y_Parton);
   fChain->SetBranchAddress("n2z_Parton", &n2z_Parton, &b_n2z_Parton);
   fChain->SetBranchAddress("isqq_Parton", &isqq_Parton, &b_isqq_Parton);
   fChain->SetBranchAddress("isgg_Parton", &isgg_Parton, &b_isgg_Parton);
   fChain->SetBranchAddress("phi_Parton", &phi_Parton, &b_phi_Parton);
   fChain->SetBranchAddress("jpt_Parton", &jpt_Parton, &b_jpt_Parton);
   fChain->SetBranchAddress("jeta_Parton", &jeta_Parton, &b_jeta_Parton);
   fChain->SetBranchAddress("jphi_Parton", &jphi_Parton, &b_jphi_Parton);
   fChain->SetBranchAddress("je_Parton", &je_Parton, &b_je_Parton);
   fChain->SetBranchAddress("pt1_Hadron", &pt1_Hadron, &b_pt1_Hadron);
   fChain->SetBranchAddress("eta1_Hadron", &eta1_Hadron, &b_eta1_Hadron);
   fChain->SetBranchAddress("phi1_Hadron", &phi1_Hadron, &b_phi1_Hadron);
   fChain->SetBranchAddress("e1_Hadron", &e1_Hadron, &b_e1_Hadron);
   fChain->SetBranchAddress("pt2_Hadron", &pt2_Hadron, &b_pt2_Hadron);
   fChain->SetBranchAddress("eta2_Hadron", &eta2_Hadron, &b_eta2_Hadron);
   fChain->SetBranchAddress("phi2_Hadron", &phi2_Hadron, &b_phi2_Hadron);
   fChain->SetBranchAddress("e2_Hadron", &e2_Hadron, &b_e2_Hadron);
   fChain->SetBranchAddress("pt3_Hadron", &pt3_Hadron, &b_pt3_Hadron);
   fChain->SetBranchAddress("eta3_Hadron", &eta3_Hadron, &b_eta3_Hadron);
   fChain->SetBranchAddress("phi3_Hadron", &phi3_Hadron, &b_phi3_Hadron);
   fChain->SetBranchAddress("e3_Hadron", &e3_Hadron, &b_e3_Hadron);
   fChain->SetBranchAddress("pt4_Hadron", &pt4_Hadron, &b_pt4_Hadron);
   fChain->SetBranchAddress("eta4_Hadron", &eta4_Hadron, &b_eta4_Hadron);
   fChain->SetBranchAddress("phi4_Hadron", &phi4_Hadron, &b_phi4_Hadron);
   fChain->SetBranchAddress("e4_Hadron", &e4_Hadron, &b_e4_Hadron);
   fChain->SetBranchAddress("z1_Hadron", &z1_Hadron, &b_z1_Hadron);
   fChain->SetBranchAddress("kt1_Hadron", &kt1_Hadron, &b_kt1_Hadron);
   fChain->SetBranchAddress("theta1_Hadron", &theta1_Hadron, &b_theta1_Hadron);
   fChain->SetBranchAddress("deltaR1_Hadron", &deltaR1_Hadron, &b_deltaR1_Hadron);
   fChain->SetBranchAddress("eec1_Hadron", &eec1_Hadron, &b_eec1_Hadron);
   fChain->SetBranchAddress("z2_Hadron", &z2_Hadron, &b_z2_Hadron);
   fChain->SetBranchAddress("kt2_Hadron", &kt2_Hadron, &b_kt2_Hadron);
   fChain->SetBranchAddress("theta2_Hadron", &theta2_Hadron, &b_theta2_Hadron);
   fChain->SetBranchAddress("deltaR2_Hadron", &deltaR2_Hadron, &b_deltaR2_Hadron);
   fChain->SetBranchAddress("eec2_Hadron", &eec2_Hadron, &b_eec2_Hadron);
   fChain->SetBranchAddress("n1x_Hadron", &n1x_Hadron, &b_n1x_Hadron);
   fChain->SetBranchAddress("n1y_Hadron", &n1y_Hadron, &b_n1y_Hadron);
   fChain->SetBranchAddress("n1z_Hadron", &n1z_Hadron, &b_n1z_Hadron);
   fChain->SetBranchAddress("n2x_Hadron", &n2x_Hadron, &b_n2x_Hadron);
   fChain->SetBranchAddress("n2y_Hadron", &n2y_Hadron, &b_n2y_Hadron);
   fChain->SetBranchAddress("n2z_Hadron", &n2z_Hadron, &b_n2z_Hadron);
   fChain->SetBranchAddress("isqq_Hadron", &isqq_Hadron, &b_isqq_Hadron);
   fChain->SetBranchAddress("isgg_Hadron", &isgg_Hadron, &b_isgg_Hadron);
   fChain->SetBranchAddress("phi_Hadron", &phi_Hadron, &b_phi_Hadron);
   fChain->SetBranchAddress("jpt_Hadron", &jpt_Hadron, &b_jpt_Hadron);
   fChain->SetBranchAddress("jeta_Hadron", &jeta_Hadron, &b_jeta_Hadron);
   fChain->SetBranchAddress("jphi_Hadron", &jphi_Hadron, &b_jphi_Hadron);
   fChain->SetBranchAddress("je_Hadron", &je_Hadron, &b_je_Hadron);
   fChain->SetBranchAddress("match", &match, &b_match);
   fChain->SetBranchAddress("spin", &spin, &b_spin);
   Notify();
}

Bool_t DataInfo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DataInfo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DataInfo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
