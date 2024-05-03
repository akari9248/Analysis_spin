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

   // Declaration of leaf types
   Double_t        z2;
   Double_t        kt2;
   Double_t        deltaR2;
   Double_t        eec2;
   Double_t        phi;
   Double_t        type;
   Float_t         score;
   Int_t           validate;
   Double_t        spin;
   // List of branches
   TBranch        *b_z2;   //!
   TBranch        *b_kt2;   //!
   TBranch        *b_deltaR2;   //!
   TBranch        *b_eec2;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_type;   //!
   TBranch        *b_score;   //!
   TBranch        *b_validate;   //!
   TBranch        *b_spin;   //!
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

   fChain->SetBranchAddress("z2", &z2, &b_z2);
   fChain->SetBranchAddress("kt2", &kt2, &b_kt2);
   fChain->SetBranchAddress("deltaR2", &deltaR2, &b_deltaR2);
   fChain->SetBranchAddress("eec2", &eec2, &b_eec2);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("score", &score, &b_score);
   fChain->SetBranchAddress("validate", &validate, &b_validate);
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
