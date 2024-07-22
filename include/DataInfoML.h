//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Apr 28 19:50:19 2024 by ROOT version 6.24/04
// from TTree DNNTrainTree/
// found on file: ML_spinon.root
//////////////////////////////////////////////////////////

#pragma once


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
using namespace std;
class DataInfoML {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   Double_t        DeltaR;
   Double_t        DeltaR3;
   Double_t        GeneratorWeight;
   Double_t        NextPassedNumber;
   Int_t           Nparticles_1;
   Int_t           Nparticles_2;
   Int_t           Nparticles_3;
   Int_t           Nparticles_4;
   Int_t           Nparticles_5;
   Int_t           Nparticles_6;
   Int_t           Ntracks_1;
   Int_t           Ntracks_2;
   Int_t           Ntracks_3;
   Int_t           Ntracks_4;
   Int_t           Ntracks_5;
   Int_t           Ntracks_6;
   Int_t           PassPileUpRm;
   Double_t        Phi;
   Double_t        Phi3;
   Double_t        dphi12_X;
   Double_t        e_1;
   Double_t        e_2;
   Double_t        e_3;
   Double_t        e_4;
   Double_t        e_5;
   Double_t        e_6;
   Double_t        eta_1;
   Double_t        eta_2;
   Double_t        eta_3;
   Double_t        eta_4;
   Double_t        eta_5;
   Double_t        eta_6;
   Double_t        kt;
   Double_t        kt0;
   Double_t        kt3;
   Int_t           match;
   Double_t        pTD_1;
   Double_t        pTD_2;
   Double_t        pTD_3;
   Double_t        pTD_4;
   Double_t        pTD_5;
   Double_t        pTD_6;
   Double_t        phi_1;
   Double_t        phi_2;
   Double_t        phi_3;
   Double_t        phi_4;
   Double_t        phi_5;
   Double_t        phi_6;
   Double_t        pt;
   Double_t        pt_1;
   Double_t        pt_2;
   Double_t        pt_3;
   Double_t        pt_4;
   Double_t        pt_5;
   Double_t        pt_6;
   Double_t        sigma1_1;
   Double_t        sigma1_2;
   Double_t        sigma1_3;
   Double_t        sigma1_4;
   Double_t        sigma1_5;
   Double_t        sigma1_6;
   Double_t        sigma2_1;
   Double_t        sigma2_2;
   Double_t        sigma2_3;
   Double_t        sigma2_4;
   Double_t        sigma2_5;
   Double_t        sigma2_6;
   Double_t        sigma_1;
   Double_t        sigma_2;
   Double_t        sigma_3;
   Double_t        sigma_4;
   Double_t        sigma_5;
   Double_t        sigma_6;
   Double_t        theta;
   Double_t        theta2;
   Int_t           type;
   Int_t           type3;
   Double_t        z1;
   Double_t        z2;
   Double_t        z3;
   Float_t         score;
   Float_t         score0;
   Float_t         score1;
   Float_t         score2;
   Float_t         score3;
   Int_t           validate;
   Int_t           validate1;
   Int_t           validate2;
   Int_t           validate3;
   Int_t           spin;
   Double_t WeightSpinoff;
   Double_t RecoPhi;
   // List of branches
   TBranch        *b_DeltaR;   //!
   TBranch        *b_DeltaR3;   //!
   TBranch        *b_GeneratorWeight;   //!
   TBranch        *b_NextPassedNumber;   //!
   TBranch        *b_Nparticles_1;   //!
   TBranch        *b_Nparticles_2;   //!
   TBranch        *b_Nparticles_3;   //!
   TBranch        *b_Nparticles_4;   //!
   TBranch        *b_Nparticles_5;   //!
   TBranch        *b_Nparticles_6;   //!
   TBranch        *b_Ntracks_1;   //!
   TBranch        *b_Ntracks_2;   //!
   TBranch        *b_Ntracks_3;   //!
   TBranch        *b_Ntracks_4;   //!
   TBranch        *b_Ntracks_5;   //!
   TBranch        *b_Ntracks_6;   //!
   TBranch        *b_PassPileUpRm;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Phi3;   //!
   TBranch        *b_dphi12_X;   //!
   TBranch        *b_e_1;   //!
   TBranch        *b_e_2;   //!
   TBranch        *b_e_3;   //!
   TBranch        *b_e_4;   //!
   TBranch        *b_e_5;   //!
   TBranch        *b_e_6;   //!
   TBranch        *b_eta_1;   //!
   TBranch        *b_eta_2;   //!
   TBranch        *b_eta_3;   //!
   TBranch        *b_eta_4;   //!
   TBranch        *b_eta_5;   //!
   TBranch        *b_eta_6;   //!
   TBranch        *b_kt;   //!
   TBranch        *b_kt0;   //!
   TBranch        *b_kt3;   //!
   TBranch        *b_match;   //!
   TBranch        *b_pTD_1;   //!
   TBranch        *b_pTD_2;   //!
   TBranch        *b_pTD_3;   //!
   TBranch        *b_pTD_4;   //!
   TBranch        *b_pTD_5;   //!
   TBranch        *b_pTD_6;   //!
   TBranch        *b_phi_1;   //!
   TBranch        *b_phi_2;   //!
   TBranch        *b_phi_3;   //!
   TBranch        *b_phi_4;   //!
   TBranch        *b_phi_5;   //!
   TBranch        *b_phi_6;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_pt_1;   //!
   TBranch        *b_pt_2;   //!
   TBranch        *b_pt_3;   //!
   TBranch        *b_pt_4;   //!
   TBranch        *b_pt_5;   //!
   TBranch        *b_pt_6;   //!
   TBranch        *b_sigma1_1;   //!
   TBranch        *b_sigma1_2;   //!
   TBranch        *b_sigma1_3;   //!
   TBranch        *b_sigma1_4;   //!
   TBranch        *b_sigma1_5;   //!
   TBranch        *b_sigma1_6;   //!
   TBranch        *b_sigma2_1;   //!
   TBranch        *b_sigma2_2;   //!
   TBranch        *b_sigma2_3;   //!
   TBranch        *b_sigma2_4;   //!
   TBranch        *b_sigma2_5;   //!
   TBranch        *b_sigma2_6;   //!
   TBranch        *b_sigma_1;   //!
   TBranch        *b_sigma_2;   //!
   TBranch        *b_sigma_3;   //!
   TBranch        *b_sigma_4;   //!
   TBranch        *b_sigma_5;   //!
   TBranch        *b_sigma_6;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_theta2;   //!
   TBranch        *b_type;   //!
   TBranch        *b_type3;   //!
   TBranch        *b_z1;   //!
   TBranch        *b_z2;   //!
   TBranch        *b_z3;   //!
   TBranch        *b_score;   //!
   TBranch        *b_score0;
   TBranch        *b_score1;
   TBranch        *b_score2;
   TBranch        *b_score3;
   TBranch        *b_validate;   //!
   TBranch        *b_validate1;   //!
   TBranch        *b_validate2;   //!
   TBranch        *b_validate3;   //!
   TBranch        *b_WeightSpinoff;
   TBranch        *b_RecoPhi;
   TBranch        *b_spin;
   DataInfoML(TTree *tree=0);
   virtual ~DataInfoML();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};



DataInfoML::DataInfoML(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree != 0) {
       Init(tree);

   }
  
}

DataInfoML::~DataInfoML()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DataInfoML::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DataInfoML::LoadTree(Long64_t entry)
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

void DataInfoML::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
   fChain->SetBranchAddress("DeltaR", &DeltaR, &b_DeltaR);
   fChain->SetBranchAddress("DeltaR3", &DeltaR3, &b_DeltaR3);
   fChain->SetBranchAddress("GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   fChain->SetBranchAddress("NextPassedNumber", &NextPassedNumber, &b_NextPassedNumber);
   fChain->SetBranchAddress("Nparticles_1", &Nparticles_1, &b_Nparticles_1);
   fChain->SetBranchAddress("Nparticles_2", &Nparticles_2, &b_Nparticles_2);
   fChain->SetBranchAddress("Nparticles_3", &Nparticles_3, &b_Nparticles_3);
   fChain->SetBranchAddress("Nparticles_4", &Nparticles_4, &b_Nparticles_4);
   fChain->SetBranchAddress("Nparticles_5", &Nparticles_5, &b_Nparticles_5);
   fChain->SetBranchAddress("Nparticles_6", &Nparticles_6, &b_Nparticles_6);
   fChain->SetBranchAddress("Ntracks_1", &Ntracks_1, &b_Ntracks_1);
   fChain->SetBranchAddress("Ntracks_2", &Ntracks_2, &b_Ntracks_2);
   fChain->SetBranchAddress("Ntracks_3", &Ntracks_3, &b_Ntracks_3);
   fChain->SetBranchAddress("Ntracks_4", &Ntracks_4, &b_Ntracks_4);
   fChain->SetBranchAddress("Ntracks_5", &Ntracks_5, &b_Ntracks_5);
   fChain->SetBranchAddress("Ntracks_6", &Ntracks_6, &b_Ntracks_6);
   fChain->SetBranchAddress("PassPileUpRm", &PassPileUpRm, &b_PassPileUpRm);
   fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
   fChain->SetBranchAddress("Phi3", &Phi3, &b_Phi3);
   fChain->SetBranchAddress("dphi12_X", &dphi12_X, &b_dphi12_X);
   fChain->SetBranchAddress("e_1", &e_1, &b_e_1);
   fChain->SetBranchAddress("e_2", &e_2, &b_e_2);
   fChain->SetBranchAddress("e_3", &e_3, &b_e_3);
   fChain->SetBranchAddress("e_4", &e_4, &b_e_4);
   fChain->SetBranchAddress("e_5", &e_5, &b_e_5);
   fChain->SetBranchAddress("e_6", &e_6, &b_e_6);
   fChain->SetBranchAddress("eta_1", &eta_1, &b_eta_1);
   fChain->SetBranchAddress("eta_2", &eta_2, &b_eta_2);
   fChain->SetBranchAddress("eta_3", &eta_3, &b_eta_3);
   fChain->SetBranchAddress("eta_4", &eta_4, &b_eta_4);
   fChain->SetBranchAddress("eta_5", &eta_5, &b_eta_5);
   fChain->SetBranchAddress("eta_6", &eta_6, &b_eta_6);
   fChain->SetBranchAddress("kt", &kt, &b_kt);
   fChain->SetBranchAddress("kt0", &kt0, &b_kt0);
   fChain->SetBranchAddress("kt3", &kt3, &b_kt3);
   fChain->SetBranchAddress("match", &match, &b_match);
   fChain->SetBranchAddress("pTD_1", &pTD_1, &b_pTD_1);
   fChain->SetBranchAddress("pTD_2", &pTD_2, &b_pTD_2);
   fChain->SetBranchAddress("pTD_3", &pTD_3, &b_pTD_3);
   fChain->SetBranchAddress("pTD_4", &pTD_4, &b_pTD_4);
   fChain->SetBranchAddress("pTD_5", &pTD_5, &b_pTD_5);
   fChain->SetBranchAddress("pTD_6", &pTD_6, &b_pTD_6);
   fChain->SetBranchAddress("phi_1", &phi_1, &b_phi_1);
   fChain->SetBranchAddress("phi_2", &phi_2, &b_phi_2);
   fChain->SetBranchAddress("phi_3", &phi_3, &b_phi_3);
   fChain->SetBranchAddress("phi_4", &phi_4, &b_phi_4);
   fChain->SetBranchAddress("phi_5", &phi_5, &b_phi_5);
   fChain->SetBranchAddress("phi_6", &phi_6, &b_phi_6);
   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("pt_1", &pt_1, &b_pt_1);
   fChain->SetBranchAddress("pt_2", &pt_2, &b_pt_2);
   fChain->SetBranchAddress("pt_3", &pt_3, &b_pt_3);
   fChain->SetBranchAddress("pt_4", &pt_4, &b_pt_4);
   fChain->SetBranchAddress("pt_5", &pt_5, &b_pt_5);
   fChain->SetBranchAddress("pt_6", &pt_6, &b_pt_6);
   fChain->SetBranchAddress("sigma1_1", &sigma1_1, &b_sigma1_1);
   fChain->SetBranchAddress("sigma1_2", &sigma1_2, &b_sigma1_2);
   fChain->SetBranchAddress("sigma1_3", &sigma1_3, &b_sigma1_3);
   fChain->SetBranchAddress("sigma1_4", &sigma1_4, &b_sigma1_4);
   fChain->SetBranchAddress("sigma1_5", &sigma1_5, &b_sigma1_5);
   fChain->SetBranchAddress("sigma1_6", &sigma1_6, &b_sigma1_6);
   fChain->SetBranchAddress("sigma2_1", &sigma2_1, &b_sigma2_1);
   fChain->SetBranchAddress("sigma2_2", &sigma2_2, &b_sigma2_2);
   fChain->SetBranchAddress("sigma2_3", &sigma2_3, &b_sigma2_3);
   fChain->SetBranchAddress("sigma2_4", &sigma2_4, &b_sigma2_4);
   fChain->SetBranchAddress("sigma2_5", &sigma2_5, &b_sigma2_5);
   fChain->SetBranchAddress("sigma2_6", &sigma2_6, &b_sigma2_6);
   fChain->SetBranchAddress("sigma_1", &sigma_1, &b_sigma_1);
   fChain->SetBranchAddress("sigma_2", &sigma_2, &b_sigma_2);
   fChain->SetBranchAddress("sigma_3", &sigma_3, &b_sigma_3);
   fChain->SetBranchAddress("sigma_4", &sigma_4, &b_sigma_4);
   fChain->SetBranchAddress("sigma_5", &sigma_5, &b_sigma_5);
   fChain->SetBranchAddress("sigma_6", &sigma_6, &b_sigma_6);
   fChain->SetBranchAddress("theta", &theta, &b_theta);
   fChain->SetBranchAddress("theta2", &theta2, &b_theta2);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("type3", &type3, &b_type3);
   fChain->SetBranchAddress("z1", &z1, &b_z1);
   fChain->SetBranchAddress("z2", &z2, &b_z2);
   fChain->SetBranchAddress("z3", &z3, &b_z3);
   fChain->SetBranchAddress("score", &score, &b_score);
   fChain->SetBranchAddress("score1", &score1, &b_score1);
   fChain->SetBranchAddress("score2", &score2, &b_score2);
   fChain->SetBranchAddress("score0", &score0, &b_score0);
   fChain->SetBranchAddress("score3", &score3, &b_score3);
   fChain->SetBranchAddress("validate", &validate, &b_validate);
   fChain->SetBranchAddress("validate1", &validate1, &b_validate1);
   fChain->SetBranchAddress("validate2", &validate2, &b_validate2);
   fChain->SetBranchAddress("validate3", &validate3, &b_validate3);

   fChain->SetBranchAddress("WeightSpinoff", &WeightSpinoff, &b_WeightSpinoff);
   fChain->SetBranchAddress("RecoPhi", &RecoPhi, &b_RecoPhi);
   fChain->SetBranchAddress("spin", &spin, &b_spin);
   Notify();
}

Bool_t DataInfoML::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DataInfoML::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DataInfoML::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
