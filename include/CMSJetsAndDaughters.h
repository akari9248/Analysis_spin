
#pragma once
#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
using namespace std;
// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class CMSJetsAndDaughters
{
public:
   TTree *fChain;  //! pointer to the analyzed TTree or TChain
   Int_t fCurrent; //! current Tree number in a TChain

   // Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t RunID;
   Long64_t EventID;
   Int_t LumiID;
   Bool_t RecoPassDijet;
   Int_t NumberPrimaryVertex;
   Int_t NumberGoodVertex;
   vector<double> *RecoJetPt;
   vector<double> *RecoJetEta;
   vector<double> *RecoJetPhi;
   vector<double> *RecoJetEnergy;
   vector<double> *RecoJetEnergySumDaughters;
   vector<int> *RecoJetPartonFlavourHard;
   vector<int> *RecoJetPartonFlavourSoft;
   vector<int> *RecoJetChargedMultiplicity;
   vector<int> *RecoJetNeutralMultiplicity;
   vector<int> *RecoDaughterPdgId;
   vector<int> *RecoDaughterJetId;
   vector<int> *RecoDaughterCharge;
   vector<double> *RecoDaughterPt;
   vector<double> *RecoDaughterEta;
   vector<double> *RecoDaughterPhi;
   vector<double> *RecoDaughterEnergy;
   vector<double> *RecoJetPtJESUp;
   vector<double> *RecoJetPtJESDn;
   vector<double> *RecoJetPtJERNm;
   vector<double> *RecoJetPtJERUp;
   vector<double> *RecoJetPtJERDn;
   vector<double> *RecoJetQGLiklihood;
   vector<bool>    *RecoJetPassHotZone;
   vector<bool>    *RecoDaughterRandomDrop;
   vector<bool> *TriggerBits;
   vector<double> *TriggerPrescales;
   vector<bool>    *MetFilterBits;
   Double_t CrossSection;
   Int_t NumberInteractionPileup;
   Double_t NumberTruePileup;
   Double_t PileupMaxPtHat;
   Bool_t GenPassDijet;
   vector<int> *RecoJetMatching;
   vector<int> *RecoDaughterMatching;
   vector<double> *GenJetPt;
   vector<double> *GenJetEta;
   vector<double> *GenJetPhi;
   vector<double> *GenJetEnergy;
   vector<double> *GenJetEnergySumDaughters;
   vector<int> *GenJetPartonFlavourHard;
   vector<int> *GenJetPartonFlavourSoft;
   vector<int> *GenJetChargedMultiplicity;
   vector<int> *GenJetNeutralMultiplicity;
   vector<int> *GenDaughterPdgId;
   vector<int> *GenDaughterJetId;
   vector<int> *GenDaughterCharge;
   vector<double> *GenDaughterPt;
   vector<double> *GenDaughterEta;
   vector<double> *GenDaughterPhi;
   vector<double> *GenDaughterEnergy;
   vector<int> *GenJetMatching;
   vector<int> *GenDaughterMatching;
   Double_t GeneratorWeight;
   vector<double> *PSWeights;
   vector<double> *QCDScaleWeights;
   vector<double> *PDFWeights;
   vector<double> *GenPartonPt;
   Long64_t TotalEventNumber;
   Double_t NextPassedNumber;

   // List of branches
   TBranch *b_RunID;                      //!
   TBranch *b_EventID;                    //!
   TBranch *b_LumiID;                     //!
   TBranch *b_RecoPassDijet;              //!
   TBranch *b_NumberPrimaryVertex;        //!
   TBranch *b_NumberGoodVertex;           //!
   TBranch *b_RecoJetPt;                  //!
   TBranch *b_RecoJetEta;                 //!
   TBranch *b_RecoJetPhi;                 //!
   TBranch *b_RecoJetEnergy;              //!
   TBranch *b_RecoJetEnergySumDaughters;  //!
   TBranch *b_RecoJetPartonFlavourHard;   //!
   TBranch *b_RecoJetPartonFlavourSoft;   //!
   TBranch *b_RecoJetChargedMultiplicity; //!
   TBranch *b_RecoJetNeutralMultiplicity; //!
   TBranch *b_RecoDaughterPdgId;          //!
   TBranch *b_RecoDaughterJetId;          //!
   TBranch *b_RecoDaughterCharge;         //!
   TBranch *b_RecoDaughterPt;             //!
   TBranch *b_RecoDaughterEta;            //!
   TBranch *b_RecoDaughterPhi;            //!
   TBranch *b_RecoDaughterEnergy;         //!
   TBranch *b_RecoJetPtJESUp;             //!
   TBranch *b_RecoJetPtJESDn;             //!
   TBranch *b_RecoJetPtJERNm;             //!
   TBranch *b_RecoJetPtJERUp;             //!
   TBranch *b_RecoJetPtJERDn;             //!
   TBranch        *b_RecoJetPassHotZone;   //!
   TBranch        *b_RecoDaughterRandomDrop;   //!
   TBranch *b_RecoJetQGLiklihood;         //!
   TBranch *b_TriggerBits;                //!
   TBranch *b_TriggerPrescales;           //!
   TBranch        *b_MetFilterBits;   //!
   TBranch *b_CrossSection;               //!
   TBranch *b_NumberInteractionPileup;    //!
   TBranch *b_NumberTruePileup;           //!
   TBranch *b_PileupMaxPtHat;             //!
   TBranch *b_GenPassDijet;               //!
   TBranch *b_RecoJetMatching;            //!
   TBranch *b_RecoDaughterMatching;       //!
   TBranch *b_GenJetPt;                   //!
   TBranch *b_GenJetEta;                  //!
   TBranch *b_GenJetPhi;                  //!
   TBranch *b_GenJetEnergy;               //!
   TBranch *b_GenJetEnergySumDaughters;   //!
   TBranch *b_GenJetPartonFlavourHard;    //!
   TBranch *b_GenJetPartonFlavourSoft;    //!
   TBranch *b_GenJetChargedMultiplicity;  //!
   TBranch *b_GenJetNeutralMultiplicity;  //!
   TBranch *b_GenDaughterPdgId;           //!
   TBranch *b_GenDaughterJetId;           //!
   TBranch *b_GenDaughterCharge;          //!
   TBranch *b_GenDaughterPt;              //!
   TBranch *b_GenDaughterEta;             //!
   TBranch *b_GenDaughterPhi;             //!
   TBranch *b_GenDaughterEnergy;          //!
   TBranch *b_GenJetMatching;             //!
   TBranch *b_GenDaughterMatching;        //!
   TBranch *b_GeneratorWeight;            //!
   TBranch *b_PSWeights;                  //!
   TBranch *b_QCDScaleWeights;            //!
   TBranch *b_PDFWeights;                 //!
   TBranch *b_GenPartonPt;                //!
   TBranch *b_TotalEventNumber;           //!
   TBranch *b_NextPassedNumber;           //!

   CMSJetsAndDaughters(TTree *tree = 0);
   virtual ~CMSJetsAndDaughters();
   virtual Int_t Cut(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void Init(TTree *tree);
   virtual Bool_t Notify();
   virtual void Show(Long64_t entry = -1);
};

CMSJetsAndDaughters::CMSJetsAndDaughters(TTree *tree) : fChain(0)
{
   // if parameter tree is not specified (or zero), connect the file
   // used to generate this class and read the Tree.
   if (tree != 0)
   {
      Init(tree);
   }
}

CMSJetsAndDaughters::~CMSJetsAndDaughters()
{
   if (!fChain)
      return;
   delete fChain->GetCurrentFile();
}

Int_t CMSJetsAndDaughters::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain)
      return 0;
   return fChain->GetEntry(entry);
}
Long64_t CMSJetsAndDaughters::LoadTree(Long64_t entry)
{
   // Set the environment to read one entry
   if (!fChain)
      return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0)
      return centry;
   if (fChain->GetTreeNumber() != fCurrent)
   {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}
void SetBranchAddressSafe(TTree *tree, const char *branchName, void *address, TBranch **branch)
{
   if(tree->GetEntries()==0){
      tree->SetBranchAddress(branchName, address, branch);
   }   
   if (tree->FindBranch(branchName))
   {
      tree->SetBranchAddress(branchName, address, branch);
   }
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
   if (!tree)
      return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   SetBranchAddressSafe(fChain, "RunID", &RunID, &b_RunID);
   SetBranchAddressSafe(fChain, "EventID", &EventID, &b_EventID);
   SetBranchAddressSafe(fChain, "LumiID", &LumiID, &b_LumiID);
   SetBranchAddressSafe(fChain, "RecoPassDijet", &RecoPassDijet, &b_RecoPassDijet);
   SetBranchAddressSafe(fChain, "NumberPrimaryVertex", &NumberPrimaryVertex, &b_NumberPrimaryVertex);
   SetBranchAddressSafe(fChain, "NumberGoodVertex", &NumberGoodVertex, &b_NumberGoodVertex);
   SetBranchAddressSafe(fChain, "RecoJetPt", &RecoJetPt, &b_RecoJetPt);
   SetBranchAddressSafe(fChain, "RecoJetEta", &RecoJetEta, &b_RecoJetEta);
   SetBranchAddressSafe(fChain, "RecoJetPhi", &RecoJetPhi, &b_RecoJetPhi);
   SetBranchAddressSafe(fChain, "RecoJetEnergy", &RecoJetEnergy, &b_RecoJetEnergy);
   SetBranchAddressSafe(fChain, "RecoJetEnergySumDaughters", &RecoJetEnergySumDaughters, &b_RecoJetEnergySumDaughters);
   SetBranchAddressSafe(fChain, "RecoJetPartonFlavourHard", &RecoJetPartonFlavourHard, &b_RecoJetPartonFlavourHard);
   SetBranchAddressSafe(fChain, "RecoJetPartonFlavourSoft", &RecoJetPartonFlavourSoft, &b_RecoJetPartonFlavourSoft);
   SetBranchAddressSafe(fChain, "RecoJetChargedMultiplicity", &RecoJetChargedMultiplicity, &b_RecoJetChargedMultiplicity);
   SetBranchAddressSafe(fChain, "RecoJetNeutralMultiplicity", &RecoJetNeutralMultiplicity, &b_RecoJetNeutralMultiplicity);
   SetBranchAddressSafe(fChain, "RecoDaughterPdgId", &RecoDaughterPdgId, &b_RecoDaughterPdgId);
   SetBranchAddressSafe(fChain, "RecoDaughterJetId", &RecoDaughterJetId, &b_RecoDaughterJetId);
   SetBranchAddressSafe(fChain, "RecoDaughterCharge", &RecoDaughterCharge, &b_RecoDaughterCharge);
   SetBranchAddressSafe(fChain, "RecoDaughterPt", &RecoDaughterPt, &b_RecoDaughterPt);
   SetBranchAddressSafe(fChain, "RecoDaughterEta", &RecoDaughterEta, &b_RecoDaughterEta);
   SetBranchAddressSafe(fChain, "RecoDaughterPhi", &RecoDaughterPhi, &b_RecoDaughterPhi);
   SetBranchAddressSafe(fChain, "RecoDaughterEnergy", &RecoDaughterEnergy, &b_RecoDaughterEnergy);
   SetBranchAddressSafe(fChain, "RecoJetPtJESUp", &RecoJetPtJESUp, &b_RecoJetPtJESUp);
   SetBranchAddressSafe(fChain, "RecoJetPtJESDn", &RecoJetPtJESDn, &b_RecoJetPtJESDn);
   SetBranchAddressSafe(fChain, "RecoJetPtJERNm", &RecoJetPtJERNm, &b_RecoJetPtJERNm);
   SetBranchAddressSafe(fChain, "RecoJetPtJERUp", &RecoJetPtJERUp, &b_RecoJetPtJERUp);
   SetBranchAddressSafe(fChain, "RecoJetPtJERDn", &RecoJetPtJERDn, &b_RecoJetPtJERDn);
   SetBranchAddressSafe(fChain, "RecoJetQGLiklihood", &RecoJetQGLiklihood, &b_RecoJetQGLiklihood);
   SetBranchAddressSafe(fChain, "RecoJetPassHotZone", &RecoJetPassHotZone, &b_RecoJetPassHotZone);
   SetBranchAddressSafe(fChain, "RecoDaughterRandomDrop", &RecoDaughterRandomDrop, &b_RecoDaughterRandomDrop);
   SetBranchAddressSafe(fChain, "MetFilterBits", &MetFilterBits, &b_MetFilterBits);
   SetBranchAddressSafe(fChain, "TriggerBits", &TriggerBits, &b_TriggerBits);
   SetBranchAddressSafe(fChain, "TriggerPrescales", &TriggerPrescales, &b_TriggerPrescales);
   SetBranchAddressSafe(fChain, "CrossSection", &CrossSection, &b_CrossSection);
   SetBranchAddressSafe(fChain, "NumberInteractionPileup", &NumberInteractionPileup, &b_NumberInteractionPileup);
   SetBranchAddressSafe(fChain, "NumberTruePileup", &NumberTruePileup, &b_NumberTruePileup);
   SetBranchAddressSafe(fChain, "PileupMaxPtHat", &PileupMaxPtHat, &b_PileupMaxPtHat);
   SetBranchAddressSafe(fChain, "GenPassDijet", &GenPassDijet, &b_GenPassDijet);
   SetBranchAddressSafe(fChain, "RecoJetMatching", &RecoJetMatching, &b_RecoJetMatching);
   SetBranchAddressSafe(fChain, "RecoDaughterMatching", &RecoDaughterMatching, &b_RecoDaughterMatching);
   SetBranchAddressSafe(fChain, "GenJetPt", &GenJetPt, &b_GenJetPt);
   SetBranchAddressSafe(fChain, "GenJetEta", &GenJetEta, &b_GenJetEta);
   SetBranchAddressSafe(fChain, "GenJetPhi", &GenJetPhi, &b_GenJetPhi);
   SetBranchAddressSafe(fChain, "GenJetEnergy", &GenJetEnergy, &b_GenJetEnergy);
   SetBranchAddressSafe(fChain, "GenJetEnergySumDaughters", &GenJetEnergySumDaughters, &b_GenJetEnergySumDaughters);
   SetBranchAddressSafe(fChain, "GenJetPartonFlavourHard", &GenJetPartonFlavourHard, &b_GenJetPartonFlavourHard);
   SetBranchAddressSafe(fChain, "GenJetPartonFlavourSoft", &GenJetPartonFlavourSoft, &b_GenJetPartonFlavourSoft);
   SetBranchAddressSafe(fChain, "GenJetChargedMultiplicity", &GenJetChargedMultiplicity, &b_GenJetChargedMultiplicity);
   SetBranchAddressSafe(fChain, "GenJetNeutralMultiplicity", &GenJetNeutralMultiplicity, &b_GenJetNeutralMultiplicity);
   SetBranchAddressSafe(fChain, "GenDaughterPdgId", &GenDaughterPdgId, &b_GenDaughterPdgId);
   SetBranchAddressSafe(fChain, "GenDaughterJetId", &GenDaughterJetId, &b_GenDaughterJetId);
   SetBranchAddressSafe(fChain, "GenDaughterCharge", &GenDaughterCharge, &b_GenDaughterCharge);
   SetBranchAddressSafe(fChain, "GenDaughterPt", &GenDaughterPt, &b_GenDaughterPt);
   SetBranchAddressSafe(fChain, "GenDaughterEta", &GenDaughterEta, &b_GenDaughterEta);
   SetBranchAddressSafe(fChain, "GenDaughterPhi", &GenDaughterPhi, &b_GenDaughterPhi);
   SetBranchAddressSafe(fChain, "GenDaughterEnergy", &GenDaughterEnergy, &b_GenDaughterEnergy);
   SetBranchAddressSafe(fChain, "GenJetMatching", &GenJetMatching, &b_GenJetMatching);
   SetBranchAddressSafe(fChain, "GenDaughterMatching", &GenDaughterMatching, &b_GenDaughterMatching);
   SetBranchAddressSafe(fChain, "GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   SetBranchAddressSafe(fChain, "PSWeights", &PSWeights, &b_PSWeights);
   SetBranchAddressSafe(fChain, "QCDScaleWeights", &QCDScaleWeights, &b_QCDScaleWeights);
   SetBranchAddressSafe(fChain, "PDFWeights", &PDFWeights, &b_PDFWeights);
   SetBranchAddressSafe(fChain, "GenPartonPt", &GenPartonPt, &b_GenPartonPt);
   SetBranchAddressSafe(fChain, "TotalEventNumber", &TotalEventNumber, &b_TotalEventNumber);
   SetBranchAddressSafe(fChain, "NextPassedNumber", &NextPassedNumber, &b_NextPassedNumber);
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
   if (!fChain)
      return;
   fChain->Show(entry);
}
Int_t CMSJetsAndDaughters::Cut(Long64_t entry)
{
   // This function may be called from Loop.
   // returns  1 if entry is accepted.
   // returns -1 otherwise.
   return 1;
}
