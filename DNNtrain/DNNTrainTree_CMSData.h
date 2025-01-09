//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 29 10:33:03 2024 by ROOT version 6.26/14
// from TTree DNNTrainTree/DNN Train Tree
// found on file: /storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets/Prediction/JetHT_Run2018A-UL2018_jinitpt_600_7000_j2pt_130_7000_FourLabel1/Chunk0_Part0.root
//////////////////////////////////////////////////////////

#ifndef DNNTrainTree_h
#define DNNTrainTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class DNNTrainTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        GeneratorWeight;
   vector<double>  *RecoPhi2;
   vector<double>  *RecoPhi3;
   vector<double>  *RecoTheta2;
   vector<double>  *RecoTheta22;
   vector<double>  *RecoTheta23;
   vector<double>  *RecoTheta3;
   vector<double>  *RecodPhi12_X2;
   vector<double>  *RecodPhi12_X3;
   vector<double>  *RecodeltaR1;
   vector<double>  *RecodeltaR2;
   vector<double>  *RecodeltaR3;
   vector<double>  *Recoe1;
   vector<double>  *Recoe2;
   vector<double>  *Recoe3;
   vector<double>  *Recoe4;
   vector<double>  *Recoe5;
   vector<double>  *Recoe6;
   vector<double>  *Recoeec1;
   vector<double>  *Recoeec2;
   vector<double>  *Recoeec3;
   vector<double>  *Recoeta1;
   vector<double>  *Recoeta2;
   vector<double>  *Recoeta3;
   vector<double>  *Recoeta4;
   vector<double>  *Recoeta5;
   vector<double>  *Recoeta6;
   vector<int>     *Recoflavour1;
   vector<int>     *Recoflavour2;
   vector<int>     *Recoflavour3;
   vector<int>     *Recoflavour4;
   vector<int>     *Recoflavour5;
   vector<int>     *Recoflavour6;
   vector<double>  *Recoje;
   vector<double>  *Recojeta;
   vector<double>  *Recojphi;
   vector<double>  *Recojpt;
   vector<double>  *Recokt1;
   vector<double>  *Recokt2;
   vector<double>  *Recokt3;
   vector<double>  *Recon1x;
   vector<double>  *Recon1y;
   vector<double>  *Recon1z;
   vector<double>  *Recon2x;
   vector<double>  *Recon2y;
   vector<double>  *Recon2z;
   vector<double>  *Recon3x;
   vector<double>  *Recon3y;
   vector<double>  *Recon3z;
   vector<int>     *Reconparticles1;
   vector<int>     *Reconparticles2;
   vector<int>     *Reconparticles3;
   vector<int>     *Reconparticles4;
   vector<int>     *Reconparticles5;
   vector<int>     *Reconparticles6;
   vector<int>     *Recontracks1;
   vector<int>     *Recontracks2;
   vector<int>     *Recontracks3;
   vector<int>     *Recontracks4;
   vector<int>     *Recontracks5;
   vector<int>     *Recontracks6;
   vector<double>  *RecopTD1;
   vector<double>  *RecopTD2;
   vector<double>  *RecopTD3;
   vector<double>  *RecopTD4;
   vector<double>  *RecopTD5;
   vector<double>  *RecopTD6;
   vector<double>  *Recophi1;
   vector<double>  *Recophi2;
   vector<double>  *Recophi3;
   vector<double>  *Recophi4;
   vector<double>  *Recophi5;
   vector<double>  *Recophi6;
   vector<double>  *Recopt1;
   vector<double>  *Recopt2;
   vector<double>  *Recopt3;
   vector<double>  *Recopt4;
   vector<double>  *Recopt5;
   vector<double>  *Recopt6;
   vector<double>  *Recosigma1;
   vector<double>  *Recosigma11;
   vector<double>  *Recosigma12;
   vector<double>  *Recosigma13;
   vector<double>  *Recosigma14;
   vector<double>  *Recosigma15;
   vector<double>  *Recosigma16;
   vector<double>  *Recosigma2;
   vector<double>  *Recosigma21;
   vector<double>  *Recosigma22;
   vector<double>  *Recosigma23;
   vector<double>  *Recosigma24;
   vector<double>  *Recosigma25;
   vector<double>  *Recosigma26;
   vector<double>  *Recosigma3;
   vector<double>  *Recosigma4;
   vector<double>  *Recosigma5;
   vector<double>  *Recosigma6;
   vector<double>  *Recotheta1;
   vector<double>  *Recotheta2;
   vector<double>  *Recotheta3;
   vector<int>     *Recotype1;
   vector<int>     *Recotype2;
   vector<int>     *Recotype3;
   vector<double>  *Recoz1;
   vector<double>  *Recoz2;
   vector<double>  *Recoz3;
   vector<double>  *Recoscore0;
   vector<double>  *Recoscore1;
   vector<double>  *Recoscore2;
   vector<double>  *Recoscore3;

   // List of branches
   TBranch        *b_GeneratorWeight;   //!
   TBranch        *b_RecoPhi2;   //!
   TBranch        *b_RecoPhi3;   //!
   TBranch        *b_RecoTheta2;   //!
   TBranch        *b_RecoTheta22;   //!
   TBranch        *b_RecoTheta23;   //!
   TBranch        *b_RecoTheta3;   //!
   TBranch        *b_RecodPhi12_X2;   //!
   TBranch        *b_RecodPhi12_X3;   //!
   TBranch        *b_RecodeltaR1;   //!
   TBranch        *b_RecodeltaR2;   //!
   TBranch        *b_RecodeltaR3;   //!
   TBranch        *b_Recoe1;   //!
   TBranch        *b_Recoe2;   //!
   TBranch        *b_Recoe3;   //!
   TBranch        *b_Recoe4;   //!
   TBranch        *b_Recoe5;   //!
   TBranch        *b_Recoe6;   //!
   TBranch        *b_Recoeec1;   //!
   TBranch        *b_Recoeec2;   //!
   TBranch        *b_Recoeec3;   //!
   TBranch        *b_Recoeta1;   //!
   TBranch        *b_Recoeta2;   //!
   TBranch        *b_Recoeta3;   //!
   TBranch        *b_Recoeta4;   //!
   TBranch        *b_Recoeta5;   //!
   TBranch        *b_Recoeta6;   //!
   TBranch        *b_Recoflavour1;   //!
   TBranch        *b_Recoflavour2;   //!
   TBranch        *b_Recoflavour3;   //!
   TBranch        *b_Recoflavour4;   //!
   TBranch        *b_Recoflavour5;   //!
   TBranch        *b_Recoflavour6;   //!
   TBranch        *b_Recoje;   //!
   TBranch        *b_Recojeta;   //!
   TBranch        *b_Recojphi;   //!
   TBranch        *b_Recojpt;   //!
   TBranch        *b_Recokt1;   //!
   TBranch        *b_Recokt2;   //!
   TBranch        *b_Recokt3;   //!
   TBranch        *b_Recon1x;   //!
   TBranch        *b_Recon1y;   //!
   TBranch        *b_Recon1z;   //!
   TBranch        *b_Recon2x;   //!
   TBranch        *b_Recon2y;   //!
   TBranch        *b_Recon2z;   //!
   TBranch        *b_Recon3x;   //!
   TBranch        *b_Recon3y;   //!
   TBranch        *b_Recon3z;   //!
   TBranch        *b_Reconparticles1;   //!
   TBranch        *b_Reconparticles2;   //!
   TBranch        *b_Reconparticles3;   //!
   TBranch        *b_Reconparticles4;   //!
   TBranch        *b_Reconparticles5;   //!
   TBranch        *b_Reconparticles6;   //!
   TBranch        *b_Recontracks1;   //!
   TBranch        *b_Recontracks2;   //!
   TBranch        *b_Recontracks3;   //!
   TBranch        *b_Recontracks4;   //!
   TBranch        *b_Recontracks5;   //!
   TBranch        *b_Recontracks6;   //!
   TBranch        *b_RecopTD1;   //!
   TBranch        *b_RecopTD2;   //!
   TBranch        *b_RecopTD3;   //!
   TBranch        *b_RecopTD4;   //!
   TBranch        *b_RecopTD5;   //!
   TBranch        *b_RecopTD6;   //!
   TBranch        *b_Recophi1;   //!
   TBranch        *b_Recophi2;   //!
   TBranch        *b_Recophi3;   //!
   TBranch        *b_Recophi4;   //!
   TBranch        *b_Recophi5;   //!
   TBranch        *b_Recophi6;   //!
   TBranch        *b_Recopt1;   //!
   TBranch        *b_Recopt2;   //!
   TBranch        *b_Recopt3;   //!
   TBranch        *b_Recopt4;   //!
   TBranch        *b_Recopt5;   //!
   TBranch        *b_Recopt6;   //!
   TBranch        *b_Recosigma1;   //!
   TBranch        *b_Recosigma11;   //!
   TBranch        *b_Recosigma12;   //!
   TBranch        *b_Recosigma13;   //!
   TBranch        *b_Recosigma14;   //!
   TBranch        *b_Recosigma15;   //!
   TBranch        *b_Recosigma16;   //!
   TBranch        *b_Recosigma2;   //!
   TBranch        *b_Recosigma21;   //!
   TBranch        *b_Recosigma22;   //!
   TBranch        *b_Recosigma23;   //!
   TBranch        *b_Recosigma24;   //!
   TBranch        *b_Recosigma25;   //!
   TBranch        *b_Recosigma26;   //!
   TBranch        *b_Recosigma3;   //!
   TBranch        *b_Recosigma4;   //!
   TBranch        *b_Recosigma5;   //!
   TBranch        *b_Recosigma6;   //!
   TBranch        *b_Recotheta1;   //!
   TBranch        *b_Recotheta2;   //!
   TBranch        *b_Recotheta3;   //!
   TBranch        *b_Recotype1;   //!
   TBranch        *b_Recotype2;   //!
   TBranch        *b_Recotype3;   //!
   TBranch        *b_Recoz1;   //!
   TBranch        *b_Recoz2;   //!
   TBranch        *b_Recoz3;   //!
   TBranch        *b_Recoscore0;   //!
   TBranch        *b_Recoscore1;   //!
   TBranch        *b_Recoscore2;   //!
   TBranch        *b_Recoscore3;   //!

   DNNTrainTree(TTree *tree=0);
   virtual ~DNNTrainTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DNNTrainTree_cxx
DNNTrainTree::DNNTrainTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets/Prediction/JetHT_Run2018A-UL2018_jinitpt_600_7000_j2pt_130_7000_FourLabel1/Chunk0_Part0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/storage/shuangyuan/code/analysis_spin/Machine_learning/ML/Datasets/Prediction/JetHT_Run2018A-UL2018_jinitpt_600_7000_j2pt_130_7000_FourLabel1/Chunk0_Part0.root");
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
   RecoPhi2 = 0;
   RecoPhi3 = 0;
   RecoTheta2 = 0;
   RecoTheta22 = 0;
   RecoTheta23 = 0;
   RecoTheta3 = 0;
   RecodPhi12_X2 = 0;
   RecodPhi12_X3 = 0;
   RecodeltaR1 = 0;
   RecodeltaR2 = 0;
   RecodeltaR3 = 0;
   Recoe1 = 0;
   Recoe2 = 0;
   Recoe3 = 0;
   Recoe4 = 0;
   Recoe5 = 0;
   Recoe6 = 0;
   Recoeec1 = 0;
   Recoeec2 = 0;
   Recoeec3 = 0;
   Recoeta1 = 0;
   Recoeta2 = 0;
   Recoeta3 = 0;
   Recoeta4 = 0;
   Recoeta5 = 0;
   Recoeta6 = 0;
   Recoflavour1 = 0;
   Recoflavour2 = 0;
   Recoflavour3 = 0;
   Recoflavour4 = 0;
   Recoflavour5 = 0;
   Recoflavour6 = 0;
   Recoje = 0;
   Recojeta = 0;
   Recojphi = 0;
   Recojpt = 0;
   Recokt1 = 0;
   Recokt2 = 0;
   Recokt3 = 0;
   Recon1x = 0;
   Recon1y = 0;
   Recon1z = 0;
   Recon2x = 0;
   Recon2y = 0;
   Recon2z = 0;
   Recon3x = 0;
   Recon3y = 0;
   Recon3z = 0;
   Reconparticles1 = 0;
   Reconparticles2 = 0;
   Reconparticles3 = 0;
   Reconparticles4 = 0;
   Reconparticles5 = 0;
   Reconparticles6 = 0;
   Recontracks1 = 0;
   Recontracks2 = 0;
   Recontracks3 = 0;
   Recontracks4 = 0;
   Recontracks5 = 0;
   Recontracks6 = 0;
   RecopTD1 = 0;
   RecopTD2 = 0;
   RecopTD3 = 0;
   RecopTD4 = 0;
   RecopTD5 = 0;
   RecopTD6 = 0;
   Recophi1 = 0;
   Recophi2 = 0;
   Recophi3 = 0;
   Recophi4 = 0;
   Recophi5 = 0;
   Recophi6 = 0;
   Recopt1 = 0;
   Recopt2 = 0;
   Recopt3 = 0;
   Recopt4 = 0;
   Recopt5 = 0;
   Recopt6 = 0;
   Recosigma1 = 0;
   Recosigma11 = 0;
   Recosigma12 = 0;
   Recosigma13 = 0;
   Recosigma14 = 0;
   Recosigma15 = 0;
   Recosigma16 = 0;
   Recosigma2 = 0;
   Recosigma21 = 0;
   Recosigma22 = 0;
   Recosigma23 = 0;
   Recosigma24 = 0;
   Recosigma25 = 0;
   Recosigma26 = 0;
   Recosigma3 = 0;
   Recosigma4 = 0;
   Recosigma5 = 0;
   Recosigma6 = 0;
   Recotheta1 = 0;
   Recotheta2 = 0;
   Recotheta3 = 0;
   Recotype1 = 0;
   Recotype2 = 0;
   Recotype3 = 0;
   Recoz1 = 0;
   Recoz2 = 0;
   Recoz3 = 0;
   Recoscore0 = 0;
   Recoscore1 = 0;
   Recoscore2 = 0;
   Recoscore3 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   fChain->SetBranchAddress("RecoPhi2", &RecoPhi2, &b_RecoPhi2);
   fChain->SetBranchAddress("RecoPhi3", &RecoPhi3, &b_RecoPhi3);
   fChain->SetBranchAddress("RecoTheta2", &RecoTheta2, &b_RecoTheta2);
   fChain->SetBranchAddress("RecoTheta22", &RecoTheta22, &b_RecoTheta22);
   fChain->SetBranchAddress("RecoTheta23", &RecoTheta23, &b_RecoTheta23);
   fChain->SetBranchAddress("RecoTheta3", &RecoTheta3, &b_RecoTheta3);
   fChain->SetBranchAddress("RecodPhi12_X2", &RecodPhi12_X2, &b_RecodPhi12_X2);
   fChain->SetBranchAddress("RecodPhi12_X3", &RecodPhi12_X3, &b_RecodPhi12_X3);
   fChain->SetBranchAddress("RecodeltaR1", &RecodeltaR1, &b_RecodeltaR1);
   fChain->SetBranchAddress("RecodeltaR2", &RecodeltaR2, &b_RecodeltaR2);
   fChain->SetBranchAddress("RecodeltaR3", &RecodeltaR3, &b_RecodeltaR3);
   fChain->SetBranchAddress("Recoe1", &Recoe1, &b_Recoe1);
   fChain->SetBranchAddress("Recoe2", &Recoe2, &b_Recoe2);
   fChain->SetBranchAddress("Recoe3", &Recoe3, &b_Recoe3);
   fChain->SetBranchAddress("Recoe4", &Recoe4, &b_Recoe4);
   fChain->SetBranchAddress("Recoe5", &Recoe5, &b_Recoe5);
   fChain->SetBranchAddress("Recoe6", &Recoe6, &b_Recoe6);
   fChain->SetBranchAddress("Recoeec1", &Recoeec1, &b_Recoeec1);
   fChain->SetBranchAddress("Recoeec2", &Recoeec2, &b_Recoeec2);
   fChain->SetBranchAddress("Recoeec3", &Recoeec3, &b_Recoeec3);
   fChain->SetBranchAddress("Recoeta1", &Recoeta1, &b_Recoeta1);
   fChain->SetBranchAddress("Recoeta2", &Recoeta2, &b_Recoeta2);
   fChain->SetBranchAddress("Recoeta3", &Recoeta3, &b_Recoeta3);
   fChain->SetBranchAddress("Recoeta4", &Recoeta4, &b_Recoeta4);
   fChain->SetBranchAddress("Recoeta5", &Recoeta5, &b_Recoeta5);
   fChain->SetBranchAddress("Recoeta6", &Recoeta6, &b_Recoeta6);
   fChain->SetBranchAddress("Recoflavour1", &Recoflavour1, &b_Recoflavour1);
   fChain->SetBranchAddress("Recoflavour2", &Recoflavour2, &b_Recoflavour2);
   fChain->SetBranchAddress("Recoflavour3", &Recoflavour3, &b_Recoflavour3);
   fChain->SetBranchAddress("Recoflavour4", &Recoflavour4, &b_Recoflavour4);
   fChain->SetBranchAddress("Recoflavour5", &Recoflavour5, &b_Recoflavour5);
   fChain->SetBranchAddress("Recoflavour6", &Recoflavour6, &b_Recoflavour6);
   fChain->SetBranchAddress("Recoje", &Recoje, &b_Recoje);
   fChain->SetBranchAddress("Recojeta", &Recojeta, &b_Recojeta);
   fChain->SetBranchAddress("Recojphi", &Recojphi, &b_Recojphi);
   fChain->SetBranchAddress("Recojpt", &Recojpt, &b_Recojpt);
   fChain->SetBranchAddress("Recokt1", &Recokt1, &b_Recokt1);
   fChain->SetBranchAddress("Recokt2", &Recokt2, &b_Recokt2);
   fChain->SetBranchAddress("Recokt3", &Recokt3, &b_Recokt3);
   fChain->SetBranchAddress("Recon1x", &Recon1x, &b_Recon1x);
   fChain->SetBranchAddress("Recon1y", &Recon1y, &b_Recon1y);
   fChain->SetBranchAddress("Recon1z", &Recon1z, &b_Recon1z);
   fChain->SetBranchAddress("Recon2x", &Recon2x, &b_Recon2x);
   fChain->SetBranchAddress("Recon2y", &Recon2y, &b_Recon2y);
   fChain->SetBranchAddress("Recon2z", &Recon2z, &b_Recon2z);
   fChain->SetBranchAddress("Recon3x", &Recon3x, &b_Recon3x);
   fChain->SetBranchAddress("Recon3y", &Recon3y, &b_Recon3y);
   fChain->SetBranchAddress("Recon3z", &Recon3z, &b_Recon3z);
   fChain->SetBranchAddress("Reconparticles1", &Reconparticles1, &b_Reconparticles1);
   fChain->SetBranchAddress("Reconparticles2", &Reconparticles2, &b_Reconparticles2);
   fChain->SetBranchAddress("Reconparticles3", &Reconparticles3, &b_Reconparticles3);
   fChain->SetBranchAddress("Reconparticles4", &Reconparticles4, &b_Reconparticles4);
   fChain->SetBranchAddress("Reconparticles5", &Reconparticles5, &b_Reconparticles5);
   fChain->SetBranchAddress("Reconparticles6", &Reconparticles6, &b_Reconparticles6);
   fChain->SetBranchAddress("Recontracks1", &Recontracks1, &b_Recontracks1);
   fChain->SetBranchAddress("Recontracks2", &Recontracks2, &b_Recontracks2);
   fChain->SetBranchAddress("Recontracks3", &Recontracks3, &b_Recontracks3);
   fChain->SetBranchAddress("Recontracks4", &Recontracks4, &b_Recontracks4);
   fChain->SetBranchAddress("Recontracks5", &Recontracks5, &b_Recontracks5);
   fChain->SetBranchAddress("Recontracks6", &Recontracks6, &b_Recontracks6);
   fChain->SetBranchAddress("RecopTD1", &RecopTD1, &b_RecopTD1);
   fChain->SetBranchAddress("RecopTD2", &RecopTD2, &b_RecopTD2);
   fChain->SetBranchAddress("RecopTD3", &RecopTD3, &b_RecopTD3);
   fChain->SetBranchAddress("RecopTD4", &RecopTD4, &b_RecopTD4);
   fChain->SetBranchAddress("RecopTD5", &RecopTD5, &b_RecopTD5);
   fChain->SetBranchAddress("RecopTD6", &RecopTD6, &b_RecopTD6);
   fChain->SetBranchAddress("Recophi1", &Recophi1, &b_Recophi1);
   fChain->SetBranchAddress("Recophi2", &Recophi2, &b_Recophi2);
   fChain->SetBranchAddress("Recophi3", &Recophi3, &b_Recophi3);
   fChain->SetBranchAddress("Recophi4", &Recophi4, &b_Recophi4);
   fChain->SetBranchAddress("Recophi5", &Recophi5, &b_Recophi5);
   fChain->SetBranchAddress("Recophi6", &Recophi6, &b_Recophi6);
   fChain->SetBranchAddress("Recopt1", &Recopt1, &b_Recopt1);
   fChain->SetBranchAddress("Recopt2", &Recopt2, &b_Recopt2);
   fChain->SetBranchAddress("Recopt3", &Recopt3, &b_Recopt3);
   fChain->SetBranchAddress("Recopt4", &Recopt4, &b_Recopt4);
   fChain->SetBranchAddress("Recopt5", &Recopt5, &b_Recopt5);
   fChain->SetBranchAddress("Recopt6", &Recopt6, &b_Recopt6);
   fChain->SetBranchAddress("Recosigma1", &Recosigma1, &b_Recosigma1);
   fChain->SetBranchAddress("Recosigma11", &Recosigma11, &b_Recosigma11);
   fChain->SetBranchAddress("Recosigma12", &Recosigma12, &b_Recosigma12);
   fChain->SetBranchAddress("Recosigma13", &Recosigma13, &b_Recosigma13);
   fChain->SetBranchAddress("Recosigma14", &Recosigma14, &b_Recosigma14);
   fChain->SetBranchAddress("Recosigma15", &Recosigma15, &b_Recosigma15);
   fChain->SetBranchAddress("Recosigma16", &Recosigma16, &b_Recosigma16);
   fChain->SetBranchAddress("Recosigma2", &Recosigma2, &b_Recosigma2);
   fChain->SetBranchAddress("Recosigma21", &Recosigma21, &b_Recosigma21);
   fChain->SetBranchAddress("Recosigma22", &Recosigma22, &b_Recosigma22);
   fChain->SetBranchAddress("Recosigma23", &Recosigma23, &b_Recosigma23);
   fChain->SetBranchAddress("Recosigma24", &Recosigma24, &b_Recosigma24);
   fChain->SetBranchAddress("Recosigma25", &Recosigma25, &b_Recosigma25);
   fChain->SetBranchAddress("Recosigma26", &Recosigma26, &b_Recosigma26);
   fChain->SetBranchAddress("Recosigma3", &Recosigma3, &b_Recosigma3);
   fChain->SetBranchAddress("Recosigma4", &Recosigma4, &b_Recosigma4);
   fChain->SetBranchAddress("Recosigma5", &Recosigma5, &b_Recosigma5);
   fChain->SetBranchAddress("Recosigma6", &Recosigma6, &b_Recosigma6);
   fChain->SetBranchAddress("Recotheta1", &Recotheta1, &b_Recotheta1);
   fChain->SetBranchAddress("Recotheta2", &Recotheta2, &b_Recotheta2);
   fChain->SetBranchAddress("Recotheta3", &Recotheta3, &b_Recotheta3);
   fChain->SetBranchAddress("Recotype1", &Recotype1, &b_Recotype1);
   fChain->SetBranchAddress("Recotype2", &Recotype2, &b_Recotype2);
   fChain->SetBranchAddress("Recotype3", &Recotype3, &b_Recotype3);
   fChain->SetBranchAddress("Recoz1", &Recoz1, &b_Recoz1);
   fChain->SetBranchAddress("Recoz2", &Recoz2, &b_Recoz2);
   fChain->SetBranchAddress("Recoz3", &Recoz3, &b_Recoz3);
   fChain->SetBranchAddress("Recoscore0", &Recoscore0, &b_Recoscore0);
   fChain->SetBranchAddress("Recoscore1", &Recoscore1, &b_Recoscore1);
   fChain->SetBranchAddress("Recoscore2", &Recoscore2, &b_Recoscore2);
   fChain->SetBranchAddress("Recoscore3", &Recoscore3, &b_Recoscore3);
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
#endif // #ifdef DNNTrainTree_cxx
