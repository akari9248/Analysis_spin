//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 25 13:25:27 2024 by ROOT version 6.24/04
// from TTree DataInfo/DataInfo
// found on file: miniDataInfo/Partonspin_off.root
//////////////////////////////////////////////////////////
#pragma once
#ifndef miniDataInfo_h
#define miniDataInfo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class miniDataInfo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        deltaR1;
   Double_t        deltaR2;
   Double_t        e1;
   Double_t        e2;
   Double_t        e3;
   Double_t        eec1;
   Double_t        eec2;
   Double_t        eta1;
   Double_t        eta2;
   Double_t        eta3;
   Double_t        kt1;
   Double_t        kt2;
   Int_t           nparticles1;
   Int_t           nparticles2;
   Int_t           nparticles3;
   Int_t           ntracks1;
   Int_t           ntracks2;
   Int_t           ntracks3;
   Double_t        phi;
   Double_t        phi1;
   Double_t        phi2;
   Double_t        phi3;
   Double_t        pt1;
   Double_t        pt2;
   Double_t        pt3;
   Int_t           type;
   Double_t        z1;
   Double_t        z2;

   // List of branches
   TBranch        *b_deltaR1;   //!
   TBranch        *b_deltaR2;   //!
   TBranch        *b_e1;   //!
   TBranch        *b_e2;   //!
   TBranch        *b_e3;   //!
   TBranch        *b_eec1;   //!
   TBranch        *b_eec2;   //!
   TBranch        *b_eta1;   //!
   TBranch        *b_eta2;   //!
   TBranch        *b_eta3;   //!
   TBranch        *b_kt1;   //!
   TBranch        *b_kt2;   //!
   TBranch        *b_nparticles1;   //!
   TBranch        *b_nparticles2;   //!
   TBranch        *b_nparticles3;   //!
   TBranch        *b_ntracks1;   //!
   TBranch        *b_ntracks2;   //!
   TBranch        *b_ntracks3;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_phi1;   //!
   TBranch        *b_phi2;   //!
   TBranch        *b_phi3;   //!
   TBranch        *b_pt1;   //!
   TBranch        *b_pt2;   //!
   TBranch        *b_pt3;   //!
   TBranch        *b_type;   //!
   TBranch        *b_z1;   //!
   TBranch        *b_z2;   //!

   miniDataInfo(TTree *tree=0);
   virtual ~miniDataInfo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

miniDataInfo::miniDataInfo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   
   if (tree != 0) {
      
      Init(tree);
      fChain->Print();
   }
   
   
}

miniDataInfo::~miniDataInfo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t miniDataInfo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t miniDataInfo::LoadTree(Long64_t entry)
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

void miniDataInfo::Init(TTree *tree)
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

   fChain->SetBranchAddress("deltaR1", &deltaR1, &b_deltaR1);
   fChain->SetBranchAddress("deltaR2", &deltaR2, &b_deltaR2);
   fChain->SetBranchAddress("e1", &e1, &b_e1);
   fChain->SetBranchAddress("e2", &e2, &b_e2);
   fChain->SetBranchAddress("e3", &e3, &b_e3);
   fChain->SetBranchAddress("eec1", &eec1, &b_eec1);
   fChain->SetBranchAddress("eec2", &eec2, &b_eec2);
   fChain->SetBranchAddress("eta1", &eta1, &b_eta1);
   fChain->SetBranchAddress("eta2", &eta2, &b_eta2);
   fChain->SetBranchAddress("eta3", &eta3, &b_eta3);
   fChain->SetBranchAddress("kt1", &kt1, &b_kt1);
   fChain->SetBranchAddress("kt2", &kt2, &b_kt2);
   fChain->SetBranchAddress("nparticles1", &nparticles1, &b_nparticles1);
   fChain->SetBranchAddress("nparticles2", &nparticles2, &b_nparticles2);
   fChain->SetBranchAddress("nparticles3", &nparticles3, &b_nparticles3);
   fChain->SetBranchAddress("ntracks1", &ntracks1, &b_ntracks1);
   fChain->SetBranchAddress("ntracks2", &ntracks2, &b_ntracks2);
   fChain->SetBranchAddress("ntracks3", &ntracks3, &b_ntracks3);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("phi1", &phi1, &b_phi1);
   fChain->SetBranchAddress("phi2", &phi2, &b_phi2);
   fChain->SetBranchAddress("phi3", &phi3, &b_phi3);
   fChain->SetBranchAddress("pt1", &pt1, &b_pt1);
   fChain->SetBranchAddress("pt2", &pt2, &b_pt2);
   fChain->SetBranchAddress("pt3", &pt3, &b_pt3);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("z1", &z1, &b_z1);
   fChain->SetBranchAddress("z2", &z2, &b_z2);
   Notify();
}

Bool_t miniDataInfo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void miniDataInfo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t miniDataInfo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
