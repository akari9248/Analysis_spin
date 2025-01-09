//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 26 12:38:38 2024 by ROOT version 6.24/04
// from TTree DNNTrainTree/DNN Train Tree
// found on file: /home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_herwig_Pt-15to7000jinitpt6007000j2pt1307000_FourLabel_unmatched/Chunk0_Part0.root
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
   vector<double>  *GenPhi2;
   vector<double>  *GenPhi3;
   vector<double>  *GenTheta2;
   vector<double>  *GenTheta22;
   vector<double>  *GenTheta23;
   vector<double>  *GenTheta3;
   vector<double>  *GendPhi12_X2;
   vector<double>  *GendPhi12_X3;
   vector<double>  *GendeltaR1;
   vector<double>  *GendeltaR2;
   vector<double>  *GendeltaR3;
   vector<double>  *Gene1;
   vector<double>  *Gene2;
   vector<double>  *Gene3;
   vector<double>  *Gene4;
   vector<double>  *Gene5;
   vector<double>  *Gene6;
   vector<double>  *Geneec1;
   vector<double>  *Geneec2;
   vector<double>  *Geneec3;
   Double_t        GeneratorWeight;
   vector<double>  *Geneta1;
   vector<double>  *Geneta2;
   vector<double>  *Geneta3;
   vector<double>  *Geneta4;
   vector<double>  *Geneta5;
   vector<double>  *Geneta6;
   vector<int>     *Genflavour1;
   vector<int>     *Genflavour2;
   vector<int>     *Genflavour3;
   vector<int>     *Genflavour4;
   vector<int>     *Genflavour5;
   vector<int>     *Genflavour6;
   vector<double>  *Genje;
   vector<double>  *Genjeta;
   vector<double>  *Genjphi;
   vector<double>  *Genjpt;
   vector<double>  *Genkt1;
   vector<double>  *Genkt2;
   vector<double>  *Genkt3;
   vector<double>  *Genn1x;
   vector<double>  *Genn1y;
   vector<double>  *Genn1z;
   vector<double>  *Genn2x;
   vector<double>  *Genn2y;
   vector<double>  *Genn2z;
   vector<double>  *Genn3x;
   vector<double>  *Genn3y;
   vector<double>  *Genn3z;
   vector<int>     *Gennparticles1;
   vector<int>     *Gennparticles2;
   vector<int>     *Gennparticles3;
   vector<int>     *Gennparticles4;
   vector<int>     *Gennparticles5;
   vector<int>     *Gennparticles6;
   vector<int>     *Genntracks1;
   vector<int>     *Genntracks2;
   vector<int>     *Genntracks3;
   vector<int>     *Genntracks4;
   vector<int>     *Genntracks5;
   vector<int>     *Genntracks6;
   vector<double>  *GenpTD1;
   vector<double>  *GenpTD2;
   vector<double>  *GenpTD3;
   vector<double>  *GenpTD4;
   vector<double>  *GenpTD5;
   vector<double>  *GenpTD6;
   vector<double>  *Genphi1;
   vector<double>  *Genphi2;
   vector<double>  *Genphi3;
   vector<double>  *Genphi4;
   vector<double>  *Genphi5;
   vector<double>  *Genphi6;
   vector<double>  *Genpt1;
   vector<double>  *Genpt2;
   vector<double>  *Genpt3;
   vector<double>  *Genpt4;
   vector<double>  *Genpt5;
   vector<double>  *Genpt6;
   vector<double>  *Gensigma1;
   vector<double>  *Gensigma11;
   vector<double>  *Gensigma12;
   vector<double>  *Gensigma13;
   vector<double>  *Gensigma14;
   vector<double>  *Gensigma15;
   vector<double>  *Gensigma16;
   vector<double>  *Gensigma2;
   vector<double>  *Gensigma21;
   vector<double>  *Gensigma22;
   vector<double>  *Gensigma23;
   vector<double>  *Gensigma24;
   vector<double>  *Gensigma25;
   vector<double>  *Gensigma26;
   vector<double>  *Gensigma3;
   vector<double>  *Gensigma4;
   vector<double>  *Gensigma5;
   vector<double>  *Gensigma6;
   vector<double>  *Gentheta1;
   vector<double>  *Gentheta2;
   vector<double>  *Gentheta3;
   vector<int>     *Gentype1;
   vector<int>     *Gentype2;
   vector<int>     *Gentype3;
   vector<double>  *Genz1;
   vector<double>  *Genz2;
   vector<double>  *Genz3;
   vector<double>  *MatchedRecoPhi;
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
   vector<int>     *match2;
   vector<int>     *match3;
   vector<double>  *Genscore0;
   vector<double>  *Genscore1;
   vector<double>  *Genscore2;
   vector<double>  *Genscore3;
   vector<double>  *Recoscore0;
   vector<double>  *Recoscore1;
   vector<double>  *Recoscore2;
   vector<double>  *Recoscore3;

   // List of branches
   TBranch        *b_GenPhi2;   //!
   TBranch        *b_GenPhi3;   //!
   TBranch        *b_GenTheta2;   //!
   TBranch        *b_GenTheta22;   //!
   TBranch        *b_GenTheta23;   //!
   TBranch        *b_GenTheta3;   //!
   TBranch        *b_GendPhi12_X2;   //!
   TBranch        *b_GendPhi12_X3;   //!
   TBranch        *b_GendeltaR1;   //!
   TBranch        *b_GendeltaR2;   //!
   TBranch        *b_GendeltaR3;   //!
   TBranch        *b_Gene1;   //!
   TBranch        *b_Gene2;   //!
   TBranch        *b_Gene3;   //!
   TBranch        *b_Gene4;   //!
   TBranch        *b_Gene5;   //!
   TBranch        *b_Gene6;   //!
   TBranch        *b_Geneec1;   //!
   TBranch        *b_Geneec2;   //!
   TBranch        *b_Geneec3;   //!
   TBranch        *b_GeneratorWeight;   //!
   TBranch        *b_Geneta1;   //!
   TBranch        *b_Geneta2;   //!
   TBranch        *b_Geneta3;   //!
   TBranch        *b_Geneta4;   //!
   TBranch        *b_Geneta5;   //!
   TBranch        *b_Geneta6;   //!
   TBranch        *b_Genflavour1;   //!
   TBranch        *b_Genflavour2;   //!
   TBranch        *b_Genflavour3;   //!
   TBranch        *b_Genflavour4;   //!
   TBranch        *b_Genflavour5;   //!
   TBranch        *b_Genflavour6;   //!
   TBranch        *b_Genje;   //!
   TBranch        *b_Genjeta;   //!
   TBranch        *b_Genjphi;   //!
   TBranch        *b_Genjpt;   //!
   TBranch        *b_Genkt1;   //!
   TBranch        *b_Genkt2;   //!
   TBranch        *b_Genkt3;   //!
   TBranch        *b_Genn1x;   //!
   TBranch        *b_Genn1y;   //!
   TBranch        *b_Genn1z;   //!
   TBranch        *b_Genn2x;   //!
   TBranch        *b_Genn2y;   //!
   TBranch        *b_Genn2z;   //!
   TBranch        *b_Genn3x;   //!
   TBranch        *b_Genn3y;   //!
   TBranch        *b_Genn3z;   //!
   TBranch        *b_Gennparticles1;   //!
   TBranch        *b_Gennparticles2;   //!
   TBranch        *b_Gennparticles3;   //!
   TBranch        *b_Gennparticles4;   //!
   TBranch        *b_Gennparticles5;   //!
   TBranch        *b_Gennparticles6;   //!
   TBranch        *b_Genntracks1;   //!
   TBranch        *b_Genntracks2;   //!
   TBranch        *b_Genntracks3;   //!
   TBranch        *b_Genntracks4;   //!
   TBranch        *b_Genntracks5;   //!
   TBranch        *b_Genntracks6;   //!
   TBranch        *b_GenpTD1;   //!
   TBranch        *b_GenpTD2;   //!
   TBranch        *b_GenpTD3;   //!
   TBranch        *b_GenpTD4;   //!
   TBranch        *b_GenpTD5;   //!
   TBranch        *b_GenpTD6;   //!
   TBranch        *b_Genphi1;   //!
   TBranch        *b_Genphi2;   //!
   TBranch        *b_Genphi3;   //!
   TBranch        *b_Genphi4;   //!
   TBranch        *b_Genphi5;   //!
   TBranch        *b_Genphi6;   //!
   TBranch        *b_Genpt1;   //!
   TBranch        *b_Genpt2;   //!
   TBranch        *b_Genpt3;   //!
   TBranch        *b_Genpt4;   //!
   TBranch        *b_Genpt5;   //!
   TBranch        *b_Genpt6;   //!
   TBranch        *b_Gensigma1;   //!
   TBranch        *b_Gensigma11;   //!
   TBranch        *b_Gensigma12;   //!
   TBranch        *b_Gensigma13;   //!
   TBranch        *b_Gensigma14;   //!
   TBranch        *b_Gensigma15;   //!
   TBranch        *b_Gensigma16;   //!
   TBranch        *b_Gensigma2;   //!
   TBranch        *b_Gensigma21;   //!
   TBranch        *b_Gensigma22;   //!
   TBranch        *b_Gensigma23;   //!
   TBranch        *b_Gensigma24;   //!
   TBranch        *b_Gensigma25;   //!
   TBranch        *b_Gensigma26;   //!
   TBranch        *b_Gensigma3;   //!
   TBranch        *b_Gensigma4;   //!
   TBranch        *b_Gensigma5;   //!
   TBranch        *b_Gensigma6;   //!
   TBranch        *b_Gentheta1;   //!
   TBranch        *b_Gentheta2;   //!
   TBranch        *b_Gentheta3;   //!
   TBranch        *b_Gentype1;   //!
   TBranch        *b_Gentype2;   //!
   TBranch        *b_Gentype3;   //!
   TBranch        *b_Genz1;   //!
   TBranch        *b_Genz2;   //!
   TBranch        *b_Genz3;   //!
   TBranch        *b_MatchedRecoPhi;   //!
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
   TBranch        *b_match2;   //!
   TBranch        *b_match3;   //!
   TBranch        *b_Genscore0;   //!
   TBranch        *b_Genscore1;   //!
   TBranch        *b_Genscore2;   //!
   TBranch        *b_Genscore3;   //!
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_herwig_Pt-15to7000jinitpt6007000j2pt1307000_FourLabel_unmatched/Chunk0_Part0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_herwig_Pt-15to7000jinitpt6007000j2pt1307000_FourLabel_unmatched/Chunk0_Part0.root");
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
   GenPhi2 = 0;
   GenPhi3 = 0;
   GenTheta2 = 0;
   GenTheta22 = 0;
   GenTheta23 = 0;
   GenTheta3 = 0;
   GendPhi12_X2 = 0;
   GendPhi12_X3 = 0;
   GendeltaR1 = 0;
   GendeltaR2 = 0;
   GendeltaR3 = 0;
   Gene1 = 0;
   Gene2 = 0;
   Gene3 = 0;
   Gene4 = 0;
   Gene5 = 0;
   Gene6 = 0;
   Geneec1 = 0;
   Geneec2 = 0;
   Geneec3 = 0;
   Geneta1 = 0;
   Geneta2 = 0;
   Geneta3 = 0;
   Geneta4 = 0;
   Geneta5 = 0;
   Geneta6 = 0;
   Genflavour1 = 0;
   Genflavour2 = 0;
   Genflavour3 = 0;
   Genflavour4 = 0;
   Genflavour5 = 0;
   Genflavour6 = 0;
   Genje = 0;
   Genjeta = 0;
   Genjphi = 0;
   Genjpt = 0;
   Genkt1 = 0;
   Genkt2 = 0;
   Genkt3 = 0;
   Genn1x = 0;
   Genn1y = 0;
   Genn1z = 0;
   Genn2x = 0;
   Genn2y = 0;
   Genn2z = 0;
   Genn3x = 0;
   Genn3y = 0;
   Genn3z = 0;
   Gennparticles1 = 0;
   Gennparticles2 = 0;
   Gennparticles3 = 0;
   Gennparticles4 = 0;
   Gennparticles5 = 0;
   Gennparticles6 = 0;
   Genntracks1 = 0;
   Genntracks2 = 0;
   Genntracks3 = 0;
   Genntracks4 = 0;
   Genntracks5 = 0;
   Genntracks6 = 0;
   GenpTD1 = 0;
   GenpTD2 = 0;
   GenpTD3 = 0;
   GenpTD4 = 0;
   GenpTD5 = 0;
   GenpTD6 = 0;
   Genphi1 = 0;
   Genphi2 = 0;
   Genphi3 = 0;
   Genphi4 = 0;
   Genphi5 = 0;
   Genphi6 = 0;
   Genpt1 = 0;
   Genpt2 = 0;
   Genpt3 = 0;
   Genpt4 = 0;
   Genpt5 = 0;
   Genpt6 = 0;
   Gensigma1 = 0;
   Gensigma11 = 0;
   Gensigma12 = 0;
   Gensigma13 = 0;
   Gensigma14 = 0;
   Gensigma15 = 0;
   Gensigma16 = 0;
   Gensigma2 = 0;
   Gensigma21 = 0;
   Gensigma22 = 0;
   Gensigma23 = 0;
   Gensigma24 = 0;
   Gensigma25 = 0;
   Gensigma26 = 0;
   Gensigma3 = 0;
   Gensigma4 = 0;
   Gensigma5 = 0;
   Gensigma6 = 0;
   Gentheta1 = 0;
   Gentheta2 = 0;
   Gentheta3 = 0;
   Gentype1 = 0;
   Gentype2 = 0;
   Gentype3 = 0;
   Genz1 = 0;
   Genz2 = 0;
   Genz3 = 0;
   MatchedRecoPhi = 0;
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
   match2 = 0;
   match3 = 0;
   Genscore0 = 0;
   Genscore1 = 0;
   Genscore2 = 0;
   Genscore3 = 0;
   Recoscore0 = 0;
   Recoscore1 = 0;
   Recoscore2 = 0;
   Recoscore3 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GenPhi2", &GenPhi2, &b_GenPhi2);
   fChain->SetBranchAddress("GenPhi3", &GenPhi3, &b_GenPhi3);
   fChain->SetBranchAddress("GenTheta2", &GenTheta2, &b_GenTheta2);
   fChain->SetBranchAddress("GenTheta22", &GenTheta22, &b_GenTheta22);
   fChain->SetBranchAddress("GenTheta23", &GenTheta23, &b_GenTheta23);
   fChain->SetBranchAddress("GenTheta3", &GenTheta3, &b_GenTheta3);
   fChain->SetBranchAddress("GendPhi12_X2", &GendPhi12_X2, &b_GendPhi12_X2);
   fChain->SetBranchAddress("GendPhi12_X3", &GendPhi12_X3, &b_GendPhi12_X3);
   fChain->SetBranchAddress("GendeltaR1", &GendeltaR1, &b_GendeltaR1);
   fChain->SetBranchAddress("GendeltaR2", &GendeltaR2, &b_GendeltaR2);
   fChain->SetBranchAddress("GendeltaR3", &GendeltaR3, &b_GendeltaR3);
   fChain->SetBranchAddress("Gene1", &Gene1, &b_Gene1);
   fChain->SetBranchAddress("Gene2", &Gene2, &b_Gene2);
   fChain->SetBranchAddress("Gene3", &Gene3, &b_Gene3);
   fChain->SetBranchAddress("Gene4", &Gene4, &b_Gene4);
   fChain->SetBranchAddress("Gene5", &Gene5, &b_Gene5);
   fChain->SetBranchAddress("Gene6", &Gene6, &b_Gene6);
   fChain->SetBranchAddress("Geneec1", &Geneec1, &b_Geneec1);
   fChain->SetBranchAddress("Geneec2", &Geneec2, &b_Geneec2);
   fChain->SetBranchAddress("Geneec3", &Geneec3, &b_Geneec3);
   fChain->SetBranchAddress("GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   fChain->SetBranchAddress("Geneta1", &Geneta1, &b_Geneta1);
   fChain->SetBranchAddress("Geneta2", &Geneta2, &b_Geneta2);
   fChain->SetBranchAddress("Geneta3", &Geneta3, &b_Geneta3);
   fChain->SetBranchAddress("Geneta4", &Geneta4, &b_Geneta4);
   fChain->SetBranchAddress("Geneta5", &Geneta5, &b_Geneta5);
   fChain->SetBranchAddress("Geneta6", &Geneta6, &b_Geneta6);
   fChain->SetBranchAddress("Genflavour1", &Genflavour1, &b_Genflavour1);
   fChain->SetBranchAddress("Genflavour2", &Genflavour2, &b_Genflavour2);
   fChain->SetBranchAddress("Genflavour3", &Genflavour3, &b_Genflavour3);
   fChain->SetBranchAddress("Genflavour4", &Genflavour4, &b_Genflavour4);
   fChain->SetBranchAddress("Genflavour5", &Genflavour5, &b_Genflavour5);
   fChain->SetBranchAddress("Genflavour6", &Genflavour6, &b_Genflavour6);
   fChain->SetBranchAddress("Genje", &Genje, &b_Genje);
   fChain->SetBranchAddress("Genjeta", &Genjeta, &b_Genjeta);
   fChain->SetBranchAddress("Genjphi", &Genjphi, &b_Genjphi);
   fChain->SetBranchAddress("Genjpt", &Genjpt, &b_Genjpt);
   fChain->SetBranchAddress("Genkt1", &Genkt1, &b_Genkt1);
   fChain->SetBranchAddress("Genkt2", &Genkt2, &b_Genkt2);
   fChain->SetBranchAddress("Genkt3", &Genkt3, &b_Genkt3);
   fChain->SetBranchAddress("Genn1x", &Genn1x, &b_Genn1x);
   fChain->SetBranchAddress("Genn1y", &Genn1y, &b_Genn1y);
   fChain->SetBranchAddress("Genn1z", &Genn1z, &b_Genn1z);
   fChain->SetBranchAddress("Genn2x", &Genn2x, &b_Genn2x);
   fChain->SetBranchAddress("Genn2y", &Genn2y, &b_Genn2y);
   fChain->SetBranchAddress("Genn2z", &Genn2z, &b_Genn2z);
   fChain->SetBranchAddress("Genn3x", &Genn3x, &b_Genn3x);
   fChain->SetBranchAddress("Genn3y", &Genn3y, &b_Genn3y);
   fChain->SetBranchAddress("Genn3z", &Genn3z, &b_Genn3z);
   fChain->SetBranchAddress("Gennparticles1", &Gennparticles1, &b_Gennparticles1);
   fChain->SetBranchAddress("Gennparticles2", &Gennparticles2, &b_Gennparticles2);
   fChain->SetBranchAddress("Gennparticles3", &Gennparticles3, &b_Gennparticles3);
   fChain->SetBranchAddress("Gennparticles4", &Gennparticles4, &b_Gennparticles4);
   fChain->SetBranchAddress("Gennparticles5", &Gennparticles5, &b_Gennparticles5);
   fChain->SetBranchAddress("Gennparticles6", &Gennparticles6, &b_Gennparticles6);
   fChain->SetBranchAddress("Genntracks1", &Genntracks1, &b_Genntracks1);
   fChain->SetBranchAddress("Genntracks2", &Genntracks2, &b_Genntracks2);
   fChain->SetBranchAddress("Genntracks3", &Genntracks3, &b_Genntracks3);
   fChain->SetBranchAddress("Genntracks4", &Genntracks4, &b_Genntracks4);
   fChain->SetBranchAddress("Genntracks5", &Genntracks5, &b_Genntracks5);
   fChain->SetBranchAddress("Genntracks6", &Genntracks6, &b_Genntracks6);
   fChain->SetBranchAddress("GenpTD1", &GenpTD1, &b_GenpTD1);
   fChain->SetBranchAddress("GenpTD2", &GenpTD2, &b_GenpTD2);
   fChain->SetBranchAddress("GenpTD3", &GenpTD3, &b_GenpTD3);
   fChain->SetBranchAddress("GenpTD4", &GenpTD4, &b_GenpTD4);
   fChain->SetBranchAddress("GenpTD5", &GenpTD5, &b_GenpTD5);
   fChain->SetBranchAddress("GenpTD6", &GenpTD6, &b_GenpTD6);
   fChain->SetBranchAddress("Genphi1", &Genphi1, &b_Genphi1);
   fChain->SetBranchAddress("Genphi2", &Genphi2, &b_Genphi2);
   fChain->SetBranchAddress("Genphi3", &Genphi3, &b_Genphi3);
   fChain->SetBranchAddress("Genphi4", &Genphi4, &b_Genphi4);
   fChain->SetBranchAddress("Genphi5", &Genphi5, &b_Genphi5);
   fChain->SetBranchAddress("Genphi6", &Genphi6, &b_Genphi6);
   fChain->SetBranchAddress("Genpt1", &Genpt1, &b_Genpt1);
   fChain->SetBranchAddress("Genpt2", &Genpt2, &b_Genpt2);
   fChain->SetBranchAddress("Genpt3", &Genpt3, &b_Genpt3);
   fChain->SetBranchAddress("Genpt4", &Genpt4, &b_Genpt4);
   fChain->SetBranchAddress("Genpt5", &Genpt5, &b_Genpt5);
   fChain->SetBranchAddress("Genpt6", &Genpt6, &b_Genpt6);
   fChain->SetBranchAddress("Gensigma1", &Gensigma1, &b_Gensigma1);
   fChain->SetBranchAddress("Gensigma11", &Gensigma11, &b_Gensigma11);
   fChain->SetBranchAddress("Gensigma12", &Gensigma12, &b_Gensigma12);
   fChain->SetBranchAddress("Gensigma13", &Gensigma13, &b_Gensigma13);
   fChain->SetBranchAddress("Gensigma14", &Gensigma14, &b_Gensigma14);
   fChain->SetBranchAddress("Gensigma15", &Gensigma15, &b_Gensigma15);
   fChain->SetBranchAddress("Gensigma16", &Gensigma16, &b_Gensigma16);
   fChain->SetBranchAddress("Gensigma2", &Gensigma2, &b_Gensigma2);
   fChain->SetBranchAddress("Gensigma21", &Gensigma21, &b_Gensigma21);
   fChain->SetBranchAddress("Gensigma22", &Gensigma22, &b_Gensigma22);
   fChain->SetBranchAddress("Gensigma23", &Gensigma23, &b_Gensigma23);
   fChain->SetBranchAddress("Gensigma24", &Gensigma24, &b_Gensigma24);
   fChain->SetBranchAddress("Gensigma25", &Gensigma25, &b_Gensigma25);
   fChain->SetBranchAddress("Gensigma26", &Gensigma26, &b_Gensigma26);
   fChain->SetBranchAddress("Gensigma3", &Gensigma3, &b_Gensigma3);
   fChain->SetBranchAddress("Gensigma4", &Gensigma4, &b_Gensigma4);
   fChain->SetBranchAddress("Gensigma5", &Gensigma5, &b_Gensigma5);
   fChain->SetBranchAddress("Gensigma6", &Gensigma6, &b_Gensigma6);
   fChain->SetBranchAddress("Gentheta1", &Gentheta1, &b_Gentheta1);
   fChain->SetBranchAddress("Gentheta2", &Gentheta2, &b_Gentheta2);
   fChain->SetBranchAddress("Gentheta3", &Gentheta3, &b_Gentheta3);
   fChain->SetBranchAddress("Gentype1", &Gentype1, &b_Gentype1);
   fChain->SetBranchAddress("Gentype2", &Gentype2, &b_Gentype2);
   fChain->SetBranchAddress("Gentype3", &Gentype3, &b_Gentype3);
   fChain->SetBranchAddress("Genz1", &Genz1, &b_Genz1);
   fChain->SetBranchAddress("Genz2", &Genz2, &b_Genz2);
   fChain->SetBranchAddress("Genz3", &Genz3, &b_Genz3);
   fChain->SetBranchAddress("MatchedRecoPhi", &MatchedRecoPhi, &b_MatchedRecoPhi);
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
   fChain->SetBranchAddress("match2", &match2, &b_match2);
   fChain->SetBranchAddress("match3", &match3, &b_match3);
   fChain->SetBranchAddress("Genscore0", &Genscore0, &b_Genscore0);
   fChain->SetBranchAddress("Genscore1", &Genscore1, &b_Genscore1);
   fChain->SetBranchAddress("Genscore2", &Genscore2, &b_Genscore2);
   fChain->SetBranchAddress("Genscore3", &Genscore3, &b_Genscore3);
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
// #endif // #ifdef DNNTrainTree_cxx
