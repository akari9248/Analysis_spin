
#pragma once

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
using namespace std;
// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class CMSJetsAndDaughters {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           RunID;
   Long64_t        EventID;
   Int_t           LumiID;
   Bool_t          RecoPassDijet;
   Int_t           NumberPrimaryVertex;
   Int_t           NumberGoodVertex;
   vector<double>  *RecoJetPt;
   vector<double>  *RecoJetEta;
   vector<double>  *RecoJetPhi;
   vector<double>  *RecoJetEnergy;
   vector<double>  *RecoJetEnergySumDaughters;
   vector<int>     *RecoJetPartonFlavourHard;
   vector<int>     *RecoJetPartonFlavourSoft;
   vector<int>     *RecoJetChargedMultiplicity;
   vector<int>     *RecoJetNeutralMultiplicity;
   vector<int>     *RecoDaughterPdgId;
   vector<int>     *RecoDaughterJetId;
   vector<int>     *RecoDaughterCharge;
   vector<double>  *RecoDaughterPt;
   vector<double>  *RecoDaughterEta;
   vector<double>  *RecoDaughterPhi;
   vector<double>  *RecoDaughterEnergy;
   vector<double>  *RecoJetPtJESUp;
   vector<double>  *RecoJetPtJESDn;
   vector<double>  *RecoJetPtJERNm;
   vector<double>  *RecoJetPtJERUp;
   vector<double>  *RecoJetPtJERDn;
   vector<double>  *RecoJetQGLiklihood;
   vector<bool>    *TriggerBits;
   vector<double>  *TriggerPrescales;
   Double_t        CrossSection;
   Int_t           NumberInteractionPileup;
   Double_t        NumberTruePileup;
   Double_t        PileupMaxPtHat;
   Bool_t          GenPassDijet;
   vector<int>     *RecoJetMatching;
   vector<int>     *RecoDaughterMatching;
   vector<double>  *GenJetPt;
   vector<double>  *GenJetEta;
   vector<double>  *GenJetPhi;
   vector<double>  *GenJetEnergy;
   vector<double>  *GenJetEnergySumDaughters;
   vector<int>     *GenJetPartonFlavourHard;
   vector<int>     *GenJetPartonFlavourSoft;
   vector<int>     *GenJetChargedMultiplicity;
   vector<int>     *GenJetNeutralMultiplicity;
   vector<int>     *GenDaughterPdgId;
   vector<int>     *GenDaughterJetId;
   vector<int>     *GenDaughterCharge;
   vector<double>  *GenDaughterPt;
   vector<double>  *GenDaughterEta;
   vector<double>  *GenDaughterPhi;
   vector<double>  *GenDaughterEnergy;
   vector<int>     *GenJetMatching;
   vector<int>     *GenDaughterMatching;
   Double_t        GeneratorWeight;
   vector<double>  *PSWeights;
   vector<double>  *QCDScaleWeights;
   vector<double>  *PDFWeights;
   vector<double>  *GenPartonPt;
   Long64_t        TotalEventNumber;
   Double_t        NextPassedNumber;

   // List of branches
   TBranch        *b_RunID;   //!
   TBranch        *b_EventID;   //!
   TBranch        *b_LumiID;   //!
   TBranch        *b_RecoPassDijet;   //!
   TBranch        *b_NumberPrimaryVertex;   //!
   TBranch        *b_NumberGoodVertex;   //!
   TBranch        *b_RecoJetPt;   //!
   TBranch        *b_RecoJetEta;   //!
   TBranch        *b_RecoJetPhi;   //!
   TBranch        *b_RecoJetEnergy;   //!
   TBranch        *b_RecoJetEnergySumDaughters;   //!
   TBranch        *b_RecoJetPartonFlavourHard;   //!
   TBranch        *b_RecoJetPartonFlavourSoft;   //!
   TBranch        *b_RecoJetChargedMultiplicity;   //!
   TBranch        *b_RecoJetNeutralMultiplicity;   //!
   TBranch        *b_RecoDaughterPdgId;   //!
   TBranch        *b_RecoDaughterJetId;   //!
   TBranch        *b_RecoDaughterCharge;   //!
   TBranch        *b_RecoDaughterPt;   //!
   TBranch        *b_RecoDaughterEta;   //!
   TBranch        *b_RecoDaughterPhi;   //!
   TBranch        *b_RecoDaughterEnergy;   //!
   TBranch        *b_RecoJetPtJESUp;   //!
   TBranch        *b_RecoJetPtJESDn;   //!
   TBranch        *b_RecoJetPtJERNm;   //!
   TBranch        *b_RecoJetPtJERUp;   //!
   TBranch        *b_RecoJetPtJERDn;   //!
   TBranch        *b_RecoJetQGLiklihood;   //!
   TBranch        *b_TriggerBits;   //!
   TBranch        *b_TriggerPrescales;   //!
   TBranch        *b_CrossSection;   //!
   TBranch        *b_NumberInteractionPileup;   //!
   TBranch        *b_NumberTruePileup;   //!
   TBranch        *b_PileupMaxPtHat;   //!
   TBranch        *b_GenPassDijet;   //!
   TBranch        *b_RecoJetMatching;   //!
   TBranch        *b_RecoDaughterMatching;   //!
   TBranch        *b_GenJetPt;   //!
   TBranch        *b_GenJetEta;   //!
   TBranch        *b_GenJetPhi;   //!
   TBranch        *b_GenJetEnergy;   //!
   TBranch        *b_GenJetEnergySumDaughters;   //!
   TBranch        *b_GenJetPartonFlavourHard;   //!
   TBranch        *b_GenJetPartonFlavourSoft;   //!
   TBranch        *b_GenJetChargedMultiplicity;   //!
   TBranch        *b_GenJetNeutralMultiplicity;   //!
   TBranch        *b_GenDaughterPdgId;   //!
   TBranch        *b_GenDaughterJetId;   //!
   TBranch        *b_GenDaughterCharge;   //!
   TBranch        *b_GenDaughterPt;   //!
   TBranch        *b_GenDaughterEta;   //!
   TBranch        *b_GenDaughterPhi;   //!
   TBranch        *b_GenDaughterEnergy;   //!
   TBranch        *b_GenJetMatching;   //!
   TBranch        *b_GenDaughterMatching;   //!
   TBranch        *b_GeneratorWeight;   //!
   TBranch        *b_PSWeights;   //!
   TBranch        *b_QCDScaleWeights;   //!
   TBranch        *b_PDFWeights;   //!
   TBranch        *b_GenPartonPt;   //!
   TBranch        *b_TotalEventNumber;   //!
   TBranch        *b_NextPassedNumber;   //!

   CMSJetsAndDaughters(TTree *tree=0);
   virtual ~CMSJetsAndDaughters();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};


CMSJetsAndDaughters::CMSJetsAndDaughters(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree!= 0) {
      Init(tree);
   }
   
}

CMSJetsAndDaughters::~CMSJetsAndDaughters()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CMSJetsAndDaughters::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CMSJetsAndDaughters::LoadTree(Long64_t entry)
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

void CMSJetsAndDaughters::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   RecoJetPt = 0;
   RecoJetEta = 0;
   RecoJetPhi = 0;
   RecoJetEnergy = 0;
   RecoJetEnergySumDaughters = 0;
   RecoJetPartonFlavourHard = 0;
   RecoJetPartonFlavourSoft = 0;
   RecoJetChargedMultiplicity = 0;
   RecoJetNeutralMultiplicity = 0;
   RecoDaughterPdgId = 0;
   RecoDaughterJetId = 0;
   RecoDaughterCharge = 0;
   RecoDaughterPt = 0;
   RecoDaughterEta = 0;
   RecoDaughterPhi = 0;
   RecoDaughterEnergy = 0;
   RecoJetPtJESUp = 0;
   RecoJetPtJESDn = 0;
   RecoJetPtJERNm = 0;
   RecoJetPtJERUp = 0;
   RecoJetPtJERDn = 0;
   RecoJetQGLiklihood = 0;
   TriggerBits = 0;
   TriggerPrescales = 0;
   RecoJetMatching = 0;
   RecoDaughterMatching = 0;
   GenJetPt = 0;
   GenJetEta = 0;
   GenJetPhi = 0;
   GenJetEnergy = 0;
   GenJetEnergySumDaughters = 0;
   GenJetPartonFlavourHard = 0;
   GenJetPartonFlavourSoft = 0;
   GenJetChargedMultiplicity = 0;
   GenJetNeutralMultiplicity = 0;
   GenDaughterPdgId = 0;
   GenDaughterJetId = 0;
   GenDaughterCharge = 0;
   GenDaughterPt = 0;
   GenDaughterEta = 0;
   GenDaughterPhi = 0;
   GenDaughterEnergy = 0;
   GenJetMatching = 0;
   GenDaughterMatching = 0;
   PSWeights = 0;
   QCDScaleWeights = 0;
   PDFWeights = 0;
   GenPartonPt = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunID", &RunID, &b_RunID);
   fChain->SetBranchAddress("EventID", &EventID, &b_EventID);
   fChain->SetBranchAddress("LumiID", &LumiID, &b_LumiID);
   fChain->SetBranchAddress("RecoPassDijet", &RecoPassDijet, &b_RecoPassDijet);
   fChain->SetBranchAddress("NumberPrimaryVertex", &NumberPrimaryVertex, &b_NumberPrimaryVertex);
   fChain->SetBranchAddress("NumberGoodVertex", &NumberGoodVertex, &b_NumberGoodVertex);
   fChain->SetBranchAddress("RecoJetPt", &RecoJetPt, &b_RecoJetPt);
   fChain->SetBranchAddress("RecoJetEta", &RecoJetEta, &b_RecoJetEta);
   fChain->SetBranchAddress("RecoJetPhi", &RecoJetPhi, &b_RecoJetPhi);
   fChain->SetBranchAddress("RecoJetEnergy", &RecoJetEnergy, &b_RecoJetEnergy);
   fChain->SetBranchAddress("RecoJetEnergySumDaughters", &RecoJetEnergySumDaughters, &b_RecoJetEnergySumDaughters);
   fChain->SetBranchAddress("RecoJetPartonFlavourHard", &RecoJetPartonFlavourHard, &b_RecoJetPartonFlavourHard);
   fChain->SetBranchAddress("RecoJetPartonFlavourSoft", &RecoJetPartonFlavourSoft, &b_RecoJetPartonFlavourSoft);
   fChain->SetBranchAddress("RecoJetChargedMultiplicity", &RecoJetChargedMultiplicity, &b_RecoJetChargedMultiplicity);
   fChain->SetBranchAddress("RecoJetNeutralMultiplicity", &RecoJetNeutralMultiplicity, &b_RecoJetNeutralMultiplicity);
   fChain->SetBranchAddress("RecoDaughterPdgId", &RecoDaughterPdgId, &b_RecoDaughterPdgId);
   fChain->SetBranchAddress("RecoDaughterJetId", &RecoDaughterJetId, &b_RecoDaughterJetId);
   fChain->SetBranchAddress("RecoDaughterCharge", &RecoDaughterCharge, &b_RecoDaughterCharge);
   fChain->SetBranchAddress("RecoDaughterPt", &RecoDaughterPt, &b_RecoDaughterPt);
   fChain->SetBranchAddress("RecoDaughterEta", &RecoDaughterEta, &b_RecoDaughterEta);
   fChain->SetBranchAddress("RecoDaughterPhi", &RecoDaughterPhi, &b_RecoDaughterPhi);
   fChain->SetBranchAddress("RecoDaughterEnergy", &RecoDaughterEnergy, &b_RecoDaughterEnergy);
   fChain->SetBranchAddress("RecoJetPtJESUp", &RecoJetPtJESUp, &b_RecoJetPtJESUp);
   fChain->SetBranchAddress("RecoJetPtJESDn", &RecoJetPtJESDn, &b_RecoJetPtJESDn);
   fChain->SetBranchAddress("RecoJetPtJERNm", &RecoJetPtJERNm, &b_RecoJetPtJERNm);
   fChain->SetBranchAddress("RecoJetPtJERUp", &RecoJetPtJERUp, &b_RecoJetPtJERUp);
   fChain->SetBranchAddress("RecoJetPtJERDn", &RecoJetPtJERDn, &b_RecoJetPtJERDn);
   fChain->SetBranchAddress("RecoJetQGLiklihood", &RecoJetQGLiklihood, &b_RecoJetQGLiklihood);
   fChain->SetBranchAddress("TriggerBits", &TriggerBits, &b_TriggerBits);
   fChain->SetBranchAddress("TriggerPrescales", &TriggerPrescales, &b_TriggerPrescales);
   fChain->SetBranchAddress("CrossSection", &CrossSection, &b_CrossSection);
   fChain->SetBranchAddress("NumberInteractionPileup", &NumberInteractionPileup, &b_NumberInteractionPileup);
   fChain->SetBranchAddress("NumberTruePileup", &NumberTruePileup, &b_NumberTruePileup);
   fChain->SetBranchAddress("PileupMaxPtHat", &PileupMaxPtHat, &b_PileupMaxPtHat);
   fChain->SetBranchAddress("GenPassDijet", &GenPassDijet, &b_GenPassDijet);
   fChain->SetBranchAddress("RecoJetMatching", &RecoJetMatching, &b_RecoJetMatching);
   fChain->SetBranchAddress("RecoDaughterMatching", &RecoDaughterMatching, &b_RecoDaughterMatching);
   fChain->SetBranchAddress("GenJetPt", &GenJetPt, &b_GenJetPt);
   fChain->SetBranchAddress("GenJetEta", &GenJetEta, &b_GenJetEta);
   fChain->SetBranchAddress("GenJetPhi", &GenJetPhi, &b_GenJetPhi);
   fChain->SetBranchAddress("GenJetEnergy", &GenJetEnergy, &b_GenJetEnergy);
   fChain->SetBranchAddress("GenJetEnergySumDaughters", &GenJetEnergySumDaughters, &b_GenJetEnergySumDaughters);
   fChain->SetBranchAddress("GenJetPartonFlavourHard", &GenJetPartonFlavourHard, &b_GenJetPartonFlavourHard);
   fChain->SetBranchAddress("GenJetPartonFlavourSoft", &GenJetPartonFlavourSoft, &b_GenJetPartonFlavourSoft);
   fChain->SetBranchAddress("GenJetChargedMultiplicity", &GenJetChargedMultiplicity, &b_GenJetChargedMultiplicity);
   fChain->SetBranchAddress("GenJetNeutralMultiplicity", &GenJetNeutralMultiplicity, &b_GenJetNeutralMultiplicity);
   fChain->SetBranchAddress("GenDaughterPdgId", &GenDaughterPdgId, &b_GenDaughterPdgId);
   fChain->SetBranchAddress("GenDaughterJetId", &GenDaughterJetId, &b_GenDaughterJetId);
   fChain->SetBranchAddress("GenDaughterCharge", &GenDaughterCharge, &b_GenDaughterCharge);
   fChain->SetBranchAddress("GenDaughterPt", &GenDaughterPt, &b_GenDaughterPt);
   fChain->SetBranchAddress("GenDaughterEta", &GenDaughterEta, &b_GenDaughterEta);
   fChain->SetBranchAddress("GenDaughterPhi", &GenDaughterPhi, &b_GenDaughterPhi);
   fChain->SetBranchAddress("GenDaughterEnergy", &GenDaughterEnergy, &b_GenDaughterEnergy);
   fChain->SetBranchAddress("GenJetMatching", &GenJetMatching, &b_GenJetMatching);
   fChain->SetBranchAddress("GenDaughterMatching", &GenDaughterMatching, &b_GenDaughterMatching);
   fChain->SetBranchAddress("GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   fChain->SetBranchAddress("PSWeights", &PSWeights, &b_PSWeights);
   fChain->SetBranchAddress("QCDScaleWeights", &QCDScaleWeights, &b_QCDScaleWeights);
   fChain->SetBranchAddress("PDFWeights", &PDFWeights, &b_PDFWeights);
   fChain->SetBranchAddress("GenPartonPt", &GenPartonPt, &b_GenPartonPt);
   fChain->SetBranchAddress("TotalEventNumber", &TotalEventNumber, &b_TotalEventNumber);
   fChain->SetBranchAddress("NextPassedNumber", &NextPassedNumber, &b_NextPassedNumber);
   Notify();
}

Bool_t CMSJetsAndDaughters::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CMSJetsAndDaughters::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CMSJetsAndDaughters::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
