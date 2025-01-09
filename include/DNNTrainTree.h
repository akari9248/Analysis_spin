//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 22 15:54:14 2024 by ROOT version 6.24/04
// from TTree DNNTrainTree/DNN Train Tree
// found on file: ML/Datasets/Prediction/Private_Herwig_spinoff/Chunk0_Part0.root
//////////////////////////////////////////////////////////

#pragma once

#include <TROOT.h>
#include <TChain.h>
#include <iostream>
#include <TFile.h>
using namespace std;
// Header file for the classes stored in the TTree if any.
#include "vector"

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
   vector<int>  *flavour1_Hadron;
   vector<int>  *flavour1_Parton;
   vector<int>  *flavour2_Hadron;
   vector<int>  *flavour2_Parton;
   vector<int>  *flavour3_Hadron;
   vector<int>  *flavour3_Parton;
   vector<int>  *flavour4_Hadron;
   vector<int>  *flavour4_Parton;
   vector<int>  *flavour5_Hadron;
   vector<int>  *flavour5_Parton;
   vector<int>  *flavour6_Hadron;
   vector<int>  *flavour6_Parton;
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
   vector<int>  *match2;
   vector<int>  *match3;
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
   vector<int>  *nparticles1_Hadron;
   vector<int>  *nparticles1_Parton;
   vector<int>  *nparticles2_Hadron;
   vector<int>  *nparticles2_Parton;
   vector<int>  *nparticles3_Hadron;
   vector<int>  *nparticles3_Parton;
   vector<int>  *nparticles4_Hadron;
   vector<int>  *nparticles4_Parton;
   vector<int>  *nparticles5_Hadron;
   vector<int>  *nparticles5_Parton;
   vector<int>  *nparticles6_Hadron;
   vector<int>  *nparticles6_Parton;
   vector<int>  *ntracks1_Hadron;
   vector<int>  *ntracks1_Parton;
   vector<int>  *ntracks2_Hadron;
   vector<int>  *ntracks2_Parton;
   vector<int>  *ntracks3_Hadron;
   vector<int>  *ntracks3_Parton;
   vector<int>  *ntracks4_Hadron;
   vector<int>  *ntracks4_Parton;
   vector<int>  *ntracks5_Hadron;
   vector<int>  *ntracks5_Parton;
   vector<int>  *ntracks6_Hadron;
   vector<int>  *ntracks6_Parton;
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
   vector<double>  *type1_Hadron;
   vector<int>  *type1_Parton;
   vector<int>  *type2_Hadron;
   vector<int>  *type2_Parton;
   vector<int>  *type3_Hadron;
   vector<int>  *type3_Parton;
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
   vector<int>  *validate_Hadron;

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
   vector<double>  *Genscore0;
   vector<double>  *Genscore1;
   vector<double>  *Genscore2;
   vector<double>  *Genscore3;
   vector<double>  *Recoscore0;
   vector<double>  *Recoscore1;
   vector<double>  *Recoscore2;
   vector<double>  *Recoscore3;
   Int_t           NumberGoodVertex;
   Int_t           NumberPrimaryVertex;
   Double_t        NumberTruePileup;
   Double_t        PileupWeight;
   vector<vector<int> > *bHadron_PdgId;
   vector<vector<double> > *bHadron_Pt;
   vector<vector<double> > *bHadron_Eta;
   vector<vector<double> > *bHadron_Phi;
   vector<vector<double> > *bHadron_Energy;
   vector<vector<int> > *bHadron_PdgId;
   vector<vector<double> > *cHadron_Pt;
   vector<vector<double> > *cHadron_Eta;
   vector<vector<double> > *cHadron_Phi;
   vector<vector<double> > *cHadron_Energy;
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
   TBranch        *b_NumberGoodVertex;   //!
   TBranch        *b_NumberPrimaryVertex;   //!
   TBranch        *b_NumberTruePileup;   //!
   TBranch        *b_PileupWeight;   //!
   TBranch        *b_bHadron_PdgId;   //!
   TBranch        *b_bHadron_Pt;   //!
   TBranch        *b_bHadron_Eta;   //!
   TBranch        *b_bHadron_Phi;   //!
   TBranch        *b_bHadron_Energy;   //!
   // TBranch        *b_bHadron_PdgId;   //!
   TBranch        *b_cHadron_Pt;   //!
   TBranch        *b_cHadron_Eta;   //!
   TBranch        *b_cHadron_Phi;   //!
   TBranch        *b_cHadron_Energy;   //!
   DNNTrainTree(TTree *tree=0);
   virtual ~DNNTrainTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};


DNNTrainTree::DNNTrainTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree != 0) {
      Init(tree);
   }

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
void SetBranchAddressSafe(TTree *tree, const char *branchName, void *address, TBranch **branch)
{
   // if(tree->GetEntries()==0){
   //    tree->SetBranchAddress(branchName, address, branch);
   // }   
   if (tree->FindBranch(branchName))
   {
      tree->SetBranchAddress(branchName, address, branch);
   }
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
   bHadron_PdgId = 0;
   bHadron_Pt = 0;
   bHadron_Eta = 0;
   bHadron_Phi = 0;
   bHadron_Energy = 0;
   bHadron_PdgId = 0;
   cHadron_Pt = 0;
   cHadron_Eta = 0;
   cHadron_Phi = 0;
   cHadron_Energy = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   SetBranchAddressSafe(fChain,"GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   SetBranchAddressSafe(fChain,"Phi2_Hadron", &Phi2_Hadron, &b_Phi2_Hadron);
   SetBranchAddressSafe(fChain,"Phi2_Parton", &Phi2_Parton, &b_Phi2_Parton);
   SetBranchAddressSafe(fChain,"Phi3_Hadron", &Phi3_Hadron, &b_Phi3_Hadron);
   SetBranchAddressSafe(fChain,"Phi3_Parton", &Phi3_Parton, &b_Phi3_Parton);
   SetBranchAddressSafe(fChain,"Theta22_Hadron", &Theta22_Hadron, &b_Theta22_Hadron);
   SetBranchAddressSafe(fChain,"Theta22_Parton", &Theta22_Parton, &b_Theta22_Parton);
   SetBranchAddressSafe(fChain,"Theta23_Hadron", &Theta23_Hadron, &b_Theta23_Hadron);
   SetBranchAddressSafe(fChain,"Theta23_Parton", &Theta23_Parton, &b_Theta23_Parton);
   SetBranchAddressSafe(fChain,"Theta2_Hadron", &Theta2_Hadron, &b_Theta2_Hadron);
   SetBranchAddressSafe(fChain,"Theta2_Parton", &Theta2_Parton, &b_Theta2_Parton);
   SetBranchAddressSafe(fChain,"Theta3_Hadron", &Theta3_Hadron, &b_Theta3_Hadron);
   SetBranchAddressSafe(fChain,"Theta3_Parton", &Theta3_Parton, &b_Theta3_Parton);
   SetBranchAddressSafe(fChain,"dPhi12_X2_Hadron", &dPhi12_X2_Hadron, &b_dPhi12_X2_Hadron);
   SetBranchAddressSafe(fChain,"dPhi12_X2_Parton", &dPhi12_X2_Parton, &b_dPhi12_X2_Parton);
   SetBranchAddressSafe(fChain,"dPhi12_X3_Hadron", &dPhi12_X3_Hadron, &b_dPhi12_X3_Hadron);
   SetBranchAddressSafe(fChain,"dPhi12_X3_Parton", &dPhi12_X3_Parton, &b_dPhi12_X3_Parton);
   SetBranchAddressSafe(fChain,"deltaR1_Hadron", &deltaR1_Hadron, &b_deltaR1_Hadron);
   SetBranchAddressSafe(fChain,"deltaR1_Parton", &deltaR1_Parton, &b_deltaR1_Parton);
   SetBranchAddressSafe(fChain,"deltaR2_Hadron", &deltaR2_Hadron, &b_deltaR2_Hadron);
   SetBranchAddressSafe(fChain,"deltaR2_Parton", &deltaR2_Parton, &b_deltaR2_Parton);
   SetBranchAddressSafe(fChain,"deltaR3_Hadron", &deltaR3_Hadron, &b_deltaR3_Hadron);
   SetBranchAddressSafe(fChain,"deltaR3_Parton", &deltaR3_Parton, &b_deltaR3_Parton);
   SetBranchAddressSafe(fChain,"e1_Hadron", &e1_Hadron, &b_e1_Hadron);
   SetBranchAddressSafe(fChain,"e1_Parton", &e1_Parton, &b_e1_Parton);
   SetBranchAddressSafe(fChain,"e2_Hadron", &e2_Hadron, &b_e2_Hadron);
   SetBranchAddressSafe(fChain,"e2_Parton", &e2_Parton, &b_e2_Parton);
   SetBranchAddressSafe(fChain,"e3_Hadron", &e3_Hadron, &b_e3_Hadron);
   SetBranchAddressSafe(fChain,"e3_Parton", &e3_Parton, &b_e3_Parton);
   SetBranchAddressSafe(fChain,"e4_Hadron", &e4_Hadron, &b_e4_Hadron);
   SetBranchAddressSafe(fChain,"e4_Parton", &e4_Parton, &b_e4_Parton);
   SetBranchAddressSafe(fChain,"e5_Hadron", &e5_Hadron, &b_e5_Hadron);
   SetBranchAddressSafe(fChain,"e5_Parton", &e5_Parton, &b_e5_Parton);
   SetBranchAddressSafe(fChain,"e6_Hadron", &e6_Hadron, &b_e6_Hadron);
   SetBranchAddressSafe(fChain,"e6_Parton", &e6_Parton, &b_e6_Parton);
   SetBranchAddressSafe(fChain,"eec1_Hadron", &eec1_Hadron, &b_eec1_Hadron);
   SetBranchAddressSafe(fChain,"eec1_Parton", &eec1_Parton, &b_eec1_Parton);
   SetBranchAddressSafe(fChain,"eec2_Hadron", &eec2_Hadron, &b_eec2_Hadron);
   SetBranchAddressSafe(fChain,"eec2_Parton", &eec2_Parton, &b_eec2_Parton);
   SetBranchAddressSafe(fChain,"eec3_Hadron", &eec3_Hadron, &b_eec3_Hadron);
   SetBranchAddressSafe(fChain,"eec3_Parton", &eec3_Parton, &b_eec3_Parton);
   SetBranchAddressSafe(fChain,"eta1_Hadron", &eta1_Hadron, &b_eta1_Hadron);
   SetBranchAddressSafe(fChain,"eta1_Parton", &eta1_Parton, &b_eta1_Parton);
   SetBranchAddressSafe(fChain,"eta2_Hadron", &eta2_Hadron, &b_eta2_Hadron);
   SetBranchAddressSafe(fChain,"eta2_Parton", &eta2_Parton, &b_eta2_Parton);
   SetBranchAddressSafe(fChain,"eta3_Hadron", &eta3_Hadron, &b_eta3_Hadron);
   SetBranchAddressSafe(fChain,"eta3_Parton", &eta3_Parton, &b_eta3_Parton);
   SetBranchAddressSafe(fChain,"eta4_Hadron", &eta4_Hadron, &b_eta4_Hadron);
   SetBranchAddressSafe(fChain,"eta4_Parton", &eta4_Parton, &b_eta4_Parton);
   SetBranchAddressSafe(fChain,"eta5_Hadron", &eta5_Hadron, &b_eta5_Hadron);
   SetBranchAddressSafe(fChain,"eta5_Parton", &eta5_Parton, &b_eta5_Parton);
   SetBranchAddressSafe(fChain,"eta6_Hadron", &eta6_Hadron, &b_eta6_Hadron);
   SetBranchAddressSafe(fChain,"eta6_Parton", &eta6_Parton, &b_eta6_Parton);
   SetBranchAddressSafe(fChain,"flavour1_Hadron", &flavour1_Hadron, &b_flavour1_Hadron);
   SetBranchAddressSafe(fChain,"flavour1_Parton", &flavour1_Parton, &b_flavour1_Parton);
   SetBranchAddressSafe(fChain,"flavour2_Hadron", &flavour2_Hadron, &b_flavour2_Hadron);
   SetBranchAddressSafe(fChain,"flavour2_Parton", &flavour2_Parton, &b_flavour2_Parton);
   SetBranchAddressSafe(fChain,"flavour3_Hadron", &flavour3_Hadron, &b_flavour3_Hadron);
   SetBranchAddressSafe(fChain,"flavour3_Parton", &flavour3_Parton, &b_flavour3_Parton);
   SetBranchAddressSafe(fChain,"flavour4_Hadron", &flavour4_Hadron, &b_flavour4_Hadron);
   SetBranchAddressSafe(fChain,"flavour4_Parton", &flavour4_Parton, &b_flavour4_Parton);
   SetBranchAddressSafe(fChain,"flavour5_Hadron", &flavour5_Hadron, &b_flavour5_Hadron);
   SetBranchAddressSafe(fChain,"flavour5_Parton", &flavour5_Parton, &b_flavour5_Parton);
   SetBranchAddressSafe(fChain,"flavour6_Hadron", &flavour6_Hadron, &b_flavour6_Hadron);
   SetBranchAddressSafe(fChain,"flavour6_Parton", &flavour6_Parton, &b_flavour6_Parton);
   SetBranchAddressSafe(fChain,"je_Hadron", &je_Hadron, &b_je_Hadron);
   SetBranchAddressSafe(fChain,"je_Parton", &je_Parton, &b_je_Parton);
   SetBranchAddressSafe(fChain,"jeta_Hadron", &jeta_Hadron, &b_jeta_Hadron);
   SetBranchAddressSafe(fChain,"jeta_Parton", &jeta_Parton, &b_jeta_Parton);
   SetBranchAddressSafe(fChain,"jphi_Hadron", &jphi_Hadron, &b_jphi_Hadron);
   SetBranchAddressSafe(fChain,"jphi_Parton", &jphi_Parton, &b_jphi_Parton);
   SetBranchAddressSafe(fChain,"jpt_Hadron", &jpt_Hadron, &b_jpt_Hadron);
   SetBranchAddressSafe(fChain,"jpt_Parton", &jpt_Parton, &b_jpt_Parton);
   SetBranchAddressSafe(fChain,"kt1_Hadron", &kt1_Hadron, &b_kt1_Hadron);
   SetBranchAddressSafe(fChain,"kt1_Parton", &kt1_Parton, &b_kt1_Parton);
   SetBranchAddressSafe(fChain,"kt2_Hadron", &kt2_Hadron, &b_kt2_Hadron);
   SetBranchAddressSafe(fChain,"kt2_Parton", &kt2_Parton, &b_kt2_Parton);
   SetBranchAddressSafe(fChain,"kt3_Hadron", &kt3_Hadron, &b_kt3_Hadron);
   SetBranchAddressSafe(fChain,"kt3_Parton", &kt3_Parton, &b_kt3_Parton);
   SetBranchAddressSafe(fChain,"match2", &match2, &b_match2);
   SetBranchAddressSafe(fChain,"match3", &match3, &b_match3);
   SetBranchAddressSafe(fChain,"n1x_Hadron", &n1x_Hadron, &b_n1x_Hadron);
   SetBranchAddressSafe(fChain,"n1x_Parton", &n1x_Parton, &b_n1x_Parton);
   SetBranchAddressSafe(fChain,"n1y_Hadron", &n1y_Hadron, &b_n1y_Hadron);
   SetBranchAddressSafe(fChain,"n1y_Parton", &n1y_Parton, &b_n1y_Parton);
   SetBranchAddressSafe(fChain,"n1z_Hadron", &n1z_Hadron, &b_n1z_Hadron);
   SetBranchAddressSafe(fChain,"n1z_Parton", &n1z_Parton, &b_n1z_Parton);
   SetBranchAddressSafe(fChain,"n2x_Hadron", &n2x_Hadron, &b_n2x_Hadron);
   SetBranchAddressSafe(fChain,"n2x_Parton", &n2x_Parton, &b_n2x_Parton);
   SetBranchAddressSafe(fChain,"n2y_Hadron", &n2y_Hadron, &b_n2y_Hadron);
   SetBranchAddressSafe(fChain,"n2y_Parton", &n2y_Parton, &b_n2y_Parton);
   SetBranchAddressSafe(fChain,"n2z_Hadron", &n2z_Hadron, &b_n2z_Hadron);
   SetBranchAddressSafe(fChain,"n2z_Parton", &n2z_Parton, &b_n2z_Parton);
   SetBranchAddressSafe(fChain,"n3x_Hadron", &n3x_Hadron, &b_n3x_Hadron);
   SetBranchAddressSafe(fChain,"n3x_Parton", &n3x_Parton, &b_n3x_Parton);
   SetBranchAddressSafe(fChain,"n3y_Hadron", &n3y_Hadron, &b_n3y_Hadron);
   SetBranchAddressSafe(fChain,"n3y_Parton", &n3y_Parton, &b_n3y_Parton);
   SetBranchAddressSafe(fChain,"n3z_Hadron", &n3z_Hadron, &b_n3z_Hadron);
   SetBranchAddressSafe(fChain,"n3z_Parton", &n3z_Parton, &b_n3z_Parton);
   SetBranchAddressSafe(fChain,"nparticles1_Hadron", &nparticles1_Hadron, &b_nparticles1_Hadron);
   SetBranchAddressSafe(fChain,"nparticles1_Parton", &nparticles1_Parton, &b_nparticles1_Parton);
   SetBranchAddressSafe(fChain,"nparticles2_Hadron", &nparticles2_Hadron, &b_nparticles2_Hadron);
   SetBranchAddressSafe(fChain,"nparticles2_Parton", &nparticles2_Parton, &b_nparticles2_Parton);
   SetBranchAddressSafe(fChain,"nparticles3_Hadron", &nparticles3_Hadron, &b_nparticles3_Hadron);
   SetBranchAddressSafe(fChain,"nparticles3_Parton", &nparticles3_Parton, &b_nparticles3_Parton);
   SetBranchAddressSafe(fChain,"nparticles4_Hadron", &nparticles4_Hadron, &b_nparticles4_Hadron);
   SetBranchAddressSafe(fChain,"nparticles4_Parton", &nparticles4_Parton, &b_nparticles4_Parton);
   SetBranchAddressSafe(fChain,"nparticles5_Hadron", &nparticles5_Hadron, &b_nparticles5_Hadron);
   SetBranchAddressSafe(fChain,"nparticles5_Parton", &nparticles5_Parton, &b_nparticles5_Parton);
   SetBranchAddressSafe(fChain,"nparticles6_Hadron", &nparticles6_Hadron, &b_nparticles6_Hadron);
   SetBranchAddressSafe(fChain,"nparticles6_Parton", &nparticles6_Parton, &b_nparticles6_Parton);
   SetBranchAddressSafe(fChain,"ntracks1_Hadron", &ntracks1_Hadron, &b_ntracks1_Hadron);
   SetBranchAddressSafe(fChain,"ntracks1_Parton", &ntracks1_Parton, &b_ntracks1_Parton);
   SetBranchAddressSafe(fChain,"ntracks2_Hadron", &ntracks2_Hadron, &b_ntracks2_Hadron);
   SetBranchAddressSafe(fChain,"ntracks2_Parton", &ntracks2_Parton, &b_ntracks2_Parton);
   SetBranchAddressSafe(fChain,"ntracks3_Hadron", &ntracks3_Hadron, &b_ntracks3_Hadron);
   SetBranchAddressSafe(fChain,"ntracks3_Parton", &ntracks3_Parton, &b_ntracks3_Parton);
   SetBranchAddressSafe(fChain,"ntracks4_Hadron", &ntracks4_Hadron, &b_ntracks4_Hadron);
   SetBranchAddressSafe(fChain,"ntracks4_Parton", &ntracks4_Parton, &b_ntracks4_Parton);
   SetBranchAddressSafe(fChain,"ntracks5_Hadron", &ntracks5_Hadron, &b_ntracks5_Hadron);
   SetBranchAddressSafe(fChain,"ntracks5_Parton", &ntracks5_Parton, &b_ntracks5_Parton);
   SetBranchAddressSafe(fChain,"ntracks6_Hadron", &ntracks6_Hadron, &b_ntracks6_Hadron);
   SetBranchAddressSafe(fChain,"ntracks6_Parton", &ntracks6_Parton, &b_ntracks6_Parton);
   SetBranchAddressSafe(fChain,"pTD1_Hadron", &pTD1_Hadron, &b_pTD1_Hadron);
   SetBranchAddressSafe(fChain,"pTD1_Parton", &pTD1_Parton, &b_pTD1_Parton);
   SetBranchAddressSafe(fChain,"pTD2_Hadron", &pTD2_Hadron, &b_pTD2_Hadron);
   SetBranchAddressSafe(fChain,"pTD2_Parton", &pTD2_Parton, &b_pTD2_Parton);
   SetBranchAddressSafe(fChain,"pTD3_Hadron", &pTD3_Hadron, &b_pTD3_Hadron);
   SetBranchAddressSafe(fChain,"pTD3_Parton", &pTD3_Parton, &b_pTD3_Parton);
   SetBranchAddressSafe(fChain,"pTD4_Hadron", &pTD4_Hadron, &b_pTD4_Hadron);
   SetBranchAddressSafe(fChain,"pTD4_Parton", &pTD4_Parton, &b_pTD4_Parton);
   SetBranchAddressSafe(fChain,"pTD5_Hadron", &pTD5_Hadron, &b_pTD5_Hadron);
   SetBranchAddressSafe(fChain,"pTD5_Parton", &pTD5_Parton, &b_pTD5_Parton);
   SetBranchAddressSafe(fChain,"pTD6_Hadron", &pTD6_Hadron, &b_pTD6_Hadron);
   SetBranchAddressSafe(fChain,"pTD6_Parton", &pTD6_Parton, &b_pTD6_Parton);
   SetBranchAddressSafe(fChain,"phi1_Hadron", &phi1_Hadron, &b_phi1_Hadron);
   SetBranchAddressSafe(fChain,"phi1_Parton", &phi1_Parton, &b_phi1_Parton);
   SetBranchAddressSafe(fChain,"phi2_Hadron", &phi2_Hadron, &b_phi2_Hadron);
   SetBranchAddressSafe(fChain,"phi2_Parton", &phi2_Parton, &b_phi2_Parton);
   SetBranchAddressSafe(fChain,"phi3_Hadron", &phi3_Hadron, &b_phi3_Hadron);
   SetBranchAddressSafe(fChain,"phi3_Parton", &phi3_Parton, &b_phi3_Parton);
   SetBranchAddressSafe(fChain,"phi4_Hadron", &phi4_Hadron, &b_phi4_Hadron);
   SetBranchAddressSafe(fChain,"phi4_Parton", &phi4_Parton, &b_phi4_Parton);
   SetBranchAddressSafe(fChain,"phi5_Hadron", &phi5_Hadron, &b_phi5_Hadron);
   SetBranchAddressSafe(fChain,"phi5_Parton", &phi5_Parton, &b_phi5_Parton);
   SetBranchAddressSafe(fChain,"phi6_Hadron", &phi6_Hadron, &b_phi6_Hadron);
   SetBranchAddressSafe(fChain,"phi6_Parton", &phi6_Parton, &b_phi6_Parton);
   SetBranchAddressSafe(fChain,"pt1_Hadron", &pt1_Hadron, &b_pt1_Hadron);
   SetBranchAddressSafe(fChain,"pt1_Parton", &pt1_Parton, &b_pt1_Parton);
   SetBranchAddressSafe(fChain,"pt2_Hadron", &pt2_Hadron, &b_pt2_Hadron);
   SetBranchAddressSafe(fChain,"pt2_Parton", &pt2_Parton, &b_pt2_Parton);
   SetBranchAddressSafe(fChain,"pt3_Hadron", &pt3_Hadron, &b_pt3_Hadron);
   SetBranchAddressSafe(fChain,"pt3_Parton", &pt3_Parton, &b_pt3_Parton);
   SetBranchAddressSafe(fChain,"pt4_Hadron", &pt4_Hadron, &b_pt4_Hadron);
   SetBranchAddressSafe(fChain,"pt4_Parton", &pt4_Parton, &b_pt4_Parton);
   SetBranchAddressSafe(fChain,"pt5_Hadron", &pt5_Hadron, &b_pt5_Hadron);
   SetBranchAddressSafe(fChain,"pt5_Parton", &pt5_Parton, &b_pt5_Parton);
   SetBranchAddressSafe(fChain,"pt6_Hadron", &pt6_Hadron, &b_pt6_Hadron);
   SetBranchAddressSafe(fChain,"pt6_Parton", &pt6_Parton, &b_pt6_Parton);
   SetBranchAddressSafe(fChain,"sigma11_Hadron", &sigma11_Hadron, &b_sigma11_Hadron);
   SetBranchAddressSafe(fChain,"sigma11_Parton", &sigma11_Parton, &b_sigma11_Parton);
   SetBranchAddressSafe(fChain,"sigma12_Hadron", &sigma12_Hadron, &b_sigma12_Hadron);
   SetBranchAddressSafe(fChain,"sigma12_Parton", &sigma12_Parton, &b_sigma12_Parton);
   SetBranchAddressSafe(fChain,"sigma13_Hadron", &sigma13_Hadron, &b_sigma13_Hadron);
   SetBranchAddressSafe(fChain,"sigma13_Parton", &sigma13_Parton, &b_sigma13_Parton);
   SetBranchAddressSafe(fChain,"sigma14_Hadron", &sigma14_Hadron, &b_sigma14_Hadron);
   SetBranchAddressSafe(fChain,"sigma14_Parton", &sigma14_Parton, &b_sigma14_Parton);
   SetBranchAddressSafe(fChain,"sigma15_Hadron", &sigma15_Hadron, &b_sigma15_Hadron);
   SetBranchAddressSafe(fChain,"sigma15_Parton", &sigma15_Parton, &b_sigma15_Parton);
   SetBranchAddressSafe(fChain,"sigma16_Hadron", &sigma16_Hadron, &b_sigma16_Hadron);
   SetBranchAddressSafe(fChain,"sigma16_Parton", &sigma16_Parton, &b_sigma16_Parton);
   SetBranchAddressSafe(fChain,"sigma1_Hadron", &sigma1_Hadron, &b_sigma1_Hadron);
   SetBranchAddressSafe(fChain,"sigma1_Parton", &sigma1_Parton, &b_sigma1_Parton);
   SetBranchAddressSafe(fChain,"sigma21_Hadron", &sigma21_Hadron, &b_sigma21_Hadron);
   SetBranchAddressSafe(fChain,"sigma21_Parton", &sigma21_Parton, &b_sigma21_Parton);
   SetBranchAddressSafe(fChain,"sigma22_Hadron", &sigma22_Hadron, &b_sigma22_Hadron);
   SetBranchAddressSafe(fChain,"sigma22_Parton", &sigma22_Parton, &b_sigma22_Parton);
   SetBranchAddressSafe(fChain,"sigma23_Hadron", &sigma23_Hadron, &b_sigma23_Hadron);
   SetBranchAddressSafe(fChain,"sigma23_Parton", &sigma23_Parton, &b_sigma23_Parton);
   SetBranchAddressSafe(fChain,"sigma24_Hadron", &sigma24_Hadron, &b_sigma24_Hadron);
   SetBranchAddressSafe(fChain,"sigma24_Parton", &sigma24_Parton, &b_sigma24_Parton);
   SetBranchAddressSafe(fChain,"sigma25_Hadron", &sigma25_Hadron, &b_sigma25_Hadron);
   SetBranchAddressSafe(fChain,"sigma25_Parton", &sigma25_Parton, &b_sigma25_Parton);
   SetBranchAddressSafe(fChain,"sigma26_Hadron", &sigma26_Hadron, &b_sigma26_Hadron);
   SetBranchAddressSafe(fChain,"sigma26_Parton", &sigma26_Parton, &b_sigma26_Parton);
   SetBranchAddressSafe(fChain,"sigma2_Hadron", &sigma2_Hadron, &b_sigma2_Hadron);
   SetBranchAddressSafe(fChain,"sigma2_Parton", &sigma2_Parton, &b_sigma2_Parton);
   SetBranchAddressSafe(fChain,"sigma3_Hadron", &sigma3_Hadron, &b_sigma3_Hadron);
   SetBranchAddressSafe(fChain,"sigma3_Parton", &sigma3_Parton, &b_sigma3_Parton);
   SetBranchAddressSafe(fChain,"sigma4_Hadron", &sigma4_Hadron, &b_sigma4_Hadron);
   SetBranchAddressSafe(fChain,"sigma4_Parton", &sigma4_Parton, &b_sigma4_Parton);
   SetBranchAddressSafe(fChain,"sigma5_Hadron", &sigma5_Hadron, &b_sigma5_Hadron);
   SetBranchAddressSafe(fChain,"sigma5_Parton", &sigma5_Parton, &b_sigma5_Parton);
   SetBranchAddressSafe(fChain,"sigma6_Hadron", &sigma6_Hadron, &b_sigma6_Hadron);
   SetBranchAddressSafe(fChain,"sigma6_Parton", &sigma6_Parton, &b_sigma6_Parton);
   SetBranchAddressSafe(fChain,"theta1_Hadron", &theta1_Hadron, &b_theta1_Hadron);
   SetBranchAddressSafe(fChain,"theta1_Parton", &theta1_Parton, &b_theta1_Parton);
   SetBranchAddressSafe(fChain,"theta2_Hadron", &theta2_Hadron, &b_theta2_Hadron);
   SetBranchAddressSafe(fChain,"theta2_Parton", &theta2_Parton, &b_theta2_Parton);
   SetBranchAddressSafe(fChain,"theta3_Hadron", &theta3_Hadron, &b_theta3_Hadron);
   SetBranchAddressSafe(fChain,"theta3_Parton", &theta3_Parton, &b_theta3_Parton);
   SetBranchAddressSafe(fChain,"type1_Hadron", &type1_Hadron, &b_type1_Hadron);
   SetBranchAddressSafe(fChain,"type1_Parton", &type1_Parton, &b_type1_Parton);
   SetBranchAddressSafe(fChain,"type2_Hadron", &type2_Hadron, &b_type2_Hadron);
   SetBranchAddressSafe(fChain,"type2_Parton", &type2_Parton, &b_type2_Parton);
   SetBranchAddressSafe(fChain,"type3_Hadron", &type3_Hadron, &b_type3_Hadron);
   SetBranchAddressSafe(fChain,"type3_Parton", &type3_Parton, &b_type3_Parton);
   SetBranchAddressSafe(fChain,"z1_Hadron", &z1_Hadron, &b_z1_Hadron);
   SetBranchAddressSafe(fChain,"z1_Parton", &z1_Parton, &b_z1_Parton);
   SetBranchAddressSafe(fChain,"z2_Hadron", &z2_Hadron, &b_z2_Hadron);
   SetBranchAddressSafe(fChain,"z2_Parton", &z2_Parton, &b_z2_Parton);
   SetBranchAddressSafe(fChain,"z3_Hadron", &z3_Hadron, &b_z3_Hadron);
   SetBranchAddressSafe(fChain,"z3_Parton", &z3_Parton, &b_z3_Parton);
   SetBranchAddressSafe(fChain,"score0_Hadron", &score0_Hadron, &b_score0_Hadron);
   SetBranchAddressSafe(fChain,"score1_Hadron", &score1_Hadron, &b_score1_Hadron);
   SetBranchAddressSafe(fChain,"score2_Hadron", &score2_Hadron, &b_score2_Hadron);
   SetBranchAddressSafe(fChain,"score3_Hadron", &score3_Hadron, &b_score3_Hadron);
   SetBranchAddressSafe(fChain,"validate_Hadron", &validate_Hadron, &b_validate_Hadron);
   SetBranchAddressSafe(fChain,"GenPhi2", &GenPhi2, &b_GenPhi2);
   SetBranchAddressSafe(fChain,"GenPhi3", &GenPhi3, &b_GenPhi3);
   SetBranchAddressSafe(fChain,"GenTheta2", &GenTheta2, &b_GenTheta2);
   SetBranchAddressSafe(fChain,"GenTheta22", &GenTheta22, &b_GenTheta22);
   SetBranchAddressSafe(fChain,"GenTheta23", &GenTheta23, &b_GenTheta23);
   SetBranchAddressSafe(fChain,"GenTheta3", &GenTheta3, &b_GenTheta3);
   SetBranchAddressSafe(fChain,"GendPhi12_X2", &GendPhi12_X2, &b_GendPhi12_X2);
   SetBranchAddressSafe(fChain,"GendPhi12_X3", &GendPhi12_X3, &b_GendPhi12_X3);
   SetBranchAddressSafe(fChain,"GendeltaR1", &GendeltaR1, &b_GendeltaR1);
   SetBranchAddressSafe(fChain,"GendeltaR2", &GendeltaR2, &b_GendeltaR2);
   SetBranchAddressSafe(fChain,"GendeltaR3", &GendeltaR3, &b_GendeltaR3);
   SetBranchAddressSafe(fChain,"Gene1", &Gene1, &b_Gene1);
   SetBranchAddressSafe(fChain,"Gene2", &Gene2, &b_Gene2);
   SetBranchAddressSafe(fChain,"Gene3", &Gene3, &b_Gene3);
   SetBranchAddressSafe(fChain,"Gene4", &Gene4, &b_Gene4);
   SetBranchAddressSafe(fChain,"Gene5", &Gene5, &b_Gene5);
   SetBranchAddressSafe(fChain,"Gene6", &Gene6, &b_Gene6);
   SetBranchAddressSafe(fChain,"Geneec1", &Geneec1, &b_Geneec1);
   SetBranchAddressSafe(fChain,"Geneec2", &Geneec2, &b_Geneec2);
   SetBranchAddressSafe(fChain,"Geneec3", &Geneec3, &b_Geneec3);
   SetBranchAddressSafe(fChain,"GeneratorWeight", &GeneratorWeight, &b_GeneratorWeight);
   SetBranchAddressSafe(fChain,"Geneta1", &Geneta1, &b_Geneta1);
   SetBranchAddressSafe(fChain,"Geneta2", &Geneta2, &b_Geneta2);
   SetBranchAddressSafe(fChain,"Geneta3", &Geneta3, &b_Geneta3);
   SetBranchAddressSafe(fChain,"Geneta4", &Geneta4, &b_Geneta4);
   SetBranchAddressSafe(fChain,"Geneta5", &Geneta5, &b_Geneta5);
   SetBranchAddressSafe(fChain,"Geneta6", &Geneta6, &b_Geneta6);
   SetBranchAddressSafe(fChain,"Genflavour1", &Genflavour1, &b_Genflavour1);
   SetBranchAddressSafe(fChain,"Genflavour2", &Genflavour2, &b_Genflavour2);
   SetBranchAddressSafe(fChain,"Genflavour3", &Genflavour3, &b_Genflavour3);
   SetBranchAddressSafe(fChain,"Genflavour4", &Genflavour4, &b_Genflavour4);
   SetBranchAddressSafe(fChain,"Genflavour5", &Genflavour5, &b_Genflavour5);
   SetBranchAddressSafe(fChain,"Genflavour6", &Genflavour6, &b_Genflavour6);
   SetBranchAddressSafe(fChain,"Genje", &Genje, &b_Genje);
   SetBranchAddressSafe(fChain,"Genjeta", &Genjeta, &b_Genjeta);
   SetBranchAddressSafe(fChain,"Genjphi", &Genjphi, &b_Genjphi);
   SetBranchAddressSafe(fChain,"Genjpt", &Genjpt, &b_Genjpt);
   SetBranchAddressSafe(fChain,"Genkt1", &Genkt1, &b_Genkt1);
   SetBranchAddressSafe(fChain,"Genkt2", &Genkt2, &b_Genkt2);
   SetBranchAddressSafe(fChain,"Genkt3", &Genkt3, &b_Genkt3);
   SetBranchAddressSafe(fChain,"Genn1x", &Genn1x, &b_Genn1x);
   SetBranchAddressSafe(fChain,"Genn1y", &Genn1y, &b_Genn1y);
   SetBranchAddressSafe(fChain,"Genn1z", &Genn1z, &b_Genn1z);
   SetBranchAddressSafe(fChain,"Genn2x", &Genn2x, &b_Genn2x);
   SetBranchAddressSafe(fChain,"Genn2y", &Genn2y, &b_Genn2y);
   SetBranchAddressSafe(fChain,"Genn2z", &Genn2z, &b_Genn2z);
   SetBranchAddressSafe(fChain,"Genn3x", &Genn3x, &b_Genn3x);
   SetBranchAddressSafe(fChain,"Genn3y", &Genn3y, &b_Genn3y);
   SetBranchAddressSafe(fChain,"Genn3z", &Genn3z, &b_Genn3z);
   SetBranchAddressSafe(fChain,"Gennparticles1", &Gennparticles1, &b_Gennparticles1);
   SetBranchAddressSafe(fChain,"Gennparticles2", &Gennparticles2, &b_Gennparticles2);
   SetBranchAddressSafe(fChain,"Gennparticles3", &Gennparticles3, &b_Gennparticles3);
   SetBranchAddressSafe(fChain,"Gennparticles4", &Gennparticles4, &b_Gennparticles4);
   SetBranchAddressSafe(fChain,"Gennparticles5", &Gennparticles5, &b_Gennparticles5);
   SetBranchAddressSafe(fChain,"Gennparticles6", &Gennparticles6, &b_Gennparticles6);
   SetBranchAddressSafe(fChain,"Genntracks1", &Genntracks1, &b_Genntracks1);
   SetBranchAddressSafe(fChain,"Genntracks2", &Genntracks2, &b_Genntracks2);
   SetBranchAddressSafe(fChain,"Genntracks3", &Genntracks3, &b_Genntracks3);
   SetBranchAddressSafe(fChain,"Genntracks4", &Genntracks4, &b_Genntracks4);
   SetBranchAddressSafe(fChain,"Genntracks5", &Genntracks5, &b_Genntracks5);
   SetBranchAddressSafe(fChain,"Genntracks6", &Genntracks6, &b_Genntracks6);
   SetBranchAddressSafe(fChain,"GenpTD1", &GenpTD1, &b_GenpTD1);
   SetBranchAddressSafe(fChain,"GenpTD2", &GenpTD2, &b_GenpTD2);
   SetBranchAddressSafe(fChain,"GenpTD3", &GenpTD3, &b_GenpTD3);
   SetBranchAddressSafe(fChain,"GenpTD4", &GenpTD4, &b_GenpTD4);
   SetBranchAddressSafe(fChain,"GenpTD5", &GenpTD5, &b_GenpTD5);
   SetBranchAddressSafe(fChain,"GenpTD6", &GenpTD6, &b_GenpTD6);
   SetBranchAddressSafe(fChain,"Genphi1", &Genphi1, &b_Genphi1);
   SetBranchAddressSafe(fChain,"Genphi2", &Genphi2, &b_Genphi2);
   SetBranchAddressSafe(fChain,"Genphi3", &Genphi3, &b_Genphi3);
   SetBranchAddressSafe(fChain,"Genphi4", &Genphi4, &b_Genphi4);
   SetBranchAddressSafe(fChain,"Genphi5", &Genphi5, &b_Genphi5);
   SetBranchAddressSafe(fChain,"Genphi6", &Genphi6, &b_Genphi6);
   SetBranchAddressSafe(fChain,"Genpt1", &Genpt1, &b_Genpt1);
   SetBranchAddressSafe(fChain,"Genpt2", &Genpt2, &b_Genpt2);
   SetBranchAddressSafe(fChain,"Genpt3", &Genpt3, &b_Genpt3);
   SetBranchAddressSafe(fChain,"Genpt4", &Genpt4, &b_Genpt4);
   SetBranchAddressSafe(fChain,"Genpt5", &Genpt5, &b_Genpt5);
   SetBranchAddressSafe(fChain,"Genpt6", &Genpt6, &b_Genpt6);
   SetBranchAddressSafe(fChain,"Gensigma1", &Gensigma1, &b_Gensigma1);
   SetBranchAddressSafe(fChain,"Gensigma11", &Gensigma11, &b_Gensigma11);
   SetBranchAddressSafe(fChain,"Gensigma12", &Gensigma12, &b_Gensigma12);
   SetBranchAddressSafe(fChain,"Gensigma13", &Gensigma13, &b_Gensigma13);
   SetBranchAddressSafe(fChain,"Gensigma14", &Gensigma14, &b_Gensigma14);
   SetBranchAddressSafe(fChain,"Gensigma15", &Gensigma15, &b_Gensigma15);
   SetBranchAddressSafe(fChain,"Gensigma16", &Gensigma16, &b_Gensigma16);
   SetBranchAddressSafe(fChain,"Gensigma2", &Gensigma2, &b_Gensigma2);
   SetBranchAddressSafe(fChain,"Gensigma21", &Gensigma21, &b_Gensigma21);
   SetBranchAddressSafe(fChain,"Gensigma22", &Gensigma22, &b_Gensigma22);
   SetBranchAddressSafe(fChain,"Gensigma23", &Gensigma23, &b_Gensigma23);
   SetBranchAddressSafe(fChain,"Gensigma24", &Gensigma24, &b_Gensigma24);
   SetBranchAddressSafe(fChain,"Gensigma25", &Gensigma25, &b_Gensigma25);
   SetBranchAddressSafe(fChain,"Gensigma26", &Gensigma26, &b_Gensigma26);
   SetBranchAddressSafe(fChain,"Gensigma3", &Gensigma3, &b_Gensigma3);
   SetBranchAddressSafe(fChain,"Gensigma4", &Gensigma4, &b_Gensigma4);
   SetBranchAddressSafe(fChain,"Gensigma5", &Gensigma5, &b_Gensigma5);
   SetBranchAddressSafe(fChain,"Gensigma6", &Gensigma6, &b_Gensigma6);
   SetBranchAddressSafe(fChain,"Gentheta1", &Gentheta1, &b_Gentheta1);
   SetBranchAddressSafe(fChain,"Gentheta2", &Gentheta2, &b_Gentheta2);
   SetBranchAddressSafe(fChain,"Gentheta3", &Gentheta3, &b_Gentheta3);
   SetBranchAddressSafe(fChain,"Gentype1", &Gentype1, &b_Gentype1);
   SetBranchAddressSafe(fChain,"Gentype2", &Gentype2, &b_Gentype2);
   SetBranchAddressSafe(fChain,"Gentype3", &Gentype3, &b_Gentype3);
   SetBranchAddressSafe(fChain,"Genz1", &Genz1, &b_Genz1);
   SetBranchAddressSafe(fChain,"Genz2", &Genz2, &b_Genz2);
   SetBranchAddressSafe(fChain,"Genz3", &Genz3, &b_Genz3);
   SetBranchAddressSafe(fChain,"MatchedRecoPhi", &MatchedRecoPhi, &b_MatchedRecoPhi);
   SetBranchAddressSafe(fChain,"RecoPhi2", &RecoPhi2, &b_RecoPhi2);
   SetBranchAddressSafe(fChain,"RecoPhi3", &RecoPhi3, &b_RecoPhi3);
   SetBranchAddressSafe(fChain,"RecoTheta2", &RecoTheta2, &b_RecoTheta2);
   SetBranchAddressSafe(fChain,"RecoTheta22", &RecoTheta22, &b_RecoTheta22);
   SetBranchAddressSafe(fChain,"RecoTheta23", &RecoTheta23, &b_RecoTheta23);
   SetBranchAddressSafe(fChain,"RecoTheta3", &RecoTheta3, &b_RecoTheta3);
   SetBranchAddressSafe(fChain,"RecodPhi12_X2", &RecodPhi12_X2, &b_RecodPhi12_X2);
   SetBranchAddressSafe(fChain,"RecodPhi12_X3", &RecodPhi12_X3, &b_RecodPhi12_X3);
   SetBranchAddressSafe(fChain,"RecodeltaR1", &RecodeltaR1, &b_RecodeltaR1);
   SetBranchAddressSafe(fChain,"RecodeltaR2", &RecodeltaR2, &b_RecodeltaR2);
   SetBranchAddressSafe(fChain,"RecodeltaR3", &RecodeltaR3, &b_RecodeltaR3);
   SetBranchAddressSafe(fChain,"Recoe1", &Recoe1, &b_Recoe1);
   SetBranchAddressSafe(fChain,"Recoe2", &Recoe2, &b_Recoe2);
   SetBranchAddressSafe(fChain,"Recoe3", &Recoe3, &b_Recoe3);
   SetBranchAddressSafe(fChain,"Recoe4", &Recoe4, &b_Recoe4);
   SetBranchAddressSafe(fChain,"Recoe5", &Recoe5, &b_Recoe5);
   SetBranchAddressSafe(fChain,"Recoe6", &Recoe6, &b_Recoe6);
   SetBranchAddressSafe(fChain,"Recoeec1", &Recoeec1, &b_Recoeec1);
   SetBranchAddressSafe(fChain,"Recoeec2", &Recoeec2, &b_Recoeec2);
   SetBranchAddressSafe(fChain,"Recoeec3", &Recoeec3, &b_Recoeec3);
   SetBranchAddressSafe(fChain,"Recoeta1", &Recoeta1, &b_Recoeta1);
   SetBranchAddressSafe(fChain,"Recoeta2", &Recoeta2, &b_Recoeta2);
   SetBranchAddressSafe(fChain,"Recoeta3", &Recoeta3, &b_Recoeta3);
   SetBranchAddressSafe(fChain,"Recoeta4", &Recoeta4, &b_Recoeta4);
   SetBranchAddressSafe(fChain,"Recoeta5", &Recoeta5, &b_Recoeta5);
   SetBranchAddressSafe(fChain,"Recoeta6", &Recoeta6, &b_Recoeta6);
   SetBranchAddressSafe(fChain,"Recoflavour1", &Recoflavour1, &b_Recoflavour1);
   SetBranchAddressSafe(fChain,"Recoflavour2", &Recoflavour2, &b_Recoflavour2);
   SetBranchAddressSafe(fChain,"Recoflavour3", &Recoflavour3, &b_Recoflavour3);
   SetBranchAddressSafe(fChain,"Recoflavour4", &Recoflavour4, &b_Recoflavour4);
   SetBranchAddressSafe(fChain,"Recoflavour5", &Recoflavour5, &b_Recoflavour5);
   SetBranchAddressSafe(fChain,"Recoflavour6", &Recoflavour6, &b_Recoflavour6);
   SetBranchAddressSafe(fChain,"Recoje", &Recoje, &b_Recoje);
   SetBranchAddressSafe(fChain,"Recojeta", &Recojeta, &b_Recojeta);
   SetBranchAddressSafe(fChain,"Recojphi", &Recojphi, &b_Recojphi);
   SetBranchAddressSafe(fChain,"Recojpt", &Recojpt, &b_Recojpt);
   SetBranchAddressSafe(fChain,"Recokt1", &Recokt1, &b_Recokt1);
   SetBranchAddressSafe(fChain,"Recokt2", &Recokt2, &b_Recokt2);
   SetBranchAddressSafe(fChain,"Recokt3", &Recokt3, &b_Recokt3);
   SetBranchAddressSafe(fChain,"Recon1x", &Recon1x, &b_Recon1x);
   SetBranchAddressSafe(fChain,"Recon1y", &Recon1y, &b_Recon1y);
   SetBranchAddressSafe(fChain,"Recon1z", &Recon1z, &b_Recon1z);
   SetBranchAddressSafe(fChain,"Recon2x", &Recon2x, &b_Recon2x);
   SetBranchAddressSafe(fChain,"Recon2y", &Recon2y, &b_Recon2y);
   SetBranchAddressSafe(fChain,"Recon2z", &Recon2z, &b_Recon2z);
   SetBranchAddressSafe(fChain,"Recon3x", &Recon3x, &b_Recon3x);
   SetBranchAddressSafe(fChain,"Recon3y", &Recon3y, &b_Recon3y);
   SetBranchAddressSafe(fChain,"Recon3z", &Recon3z, &b_Recon3z);
   SetBranchAddressSafe(fChain,"Reconparticles1", &Reconparticles1, &b_Reconparticles1);
   SetBranchAddressSafe(fChain,"Reconparticles2", &Reconparticles2, &b_Reconparticles2);
   SetBranchAddressSafe(fChain,"Reconparticles3", &Reconparticles3, &b_Reconparticles3);
   SetBranchAddressSafe(fChain,"Reconparticles4", &Reconparticles4, &b_Reconparticles4);
   SetBranchAddressSafe(fChain,"Reconparticles5", &Reconparticles5, &b_Reconparticles5);
   SetBranchAddressSafe(fChain,"Reconparticles6", &Reconparticles6, &b_Reconparticles6);
   SetBranchAddressSafe(fChain,"Recontracks1", &Recontracks1, &b_Recontracks1);
   SetBranchAddressSafe(fChain,"Recontracks2", &Recontracks2, &b_Recontracks2);
   SetBranchAddressSafe(fChain,"Recontracks3", &Recontracks3, &b_Recontracks3);
   SetBranchAddressSafe(fChain,"Recontracks4", &Recontracks4, &b_Recontracks4);
   SetBranchAddressSafe(fChain,"Recontracks5", &Recontracks5, &b_Recontracks5);
   SetBranchAddressSafe(fChain,"Recontracks6", &Recontracks6, &b_Recontracks6);
   SetBranchAddressSafe(fChain,"RecopTD1", &RecopTD1, &b_RecopTD1);
   SetBranchAddressSafe(fChain,"RecopTD2", &RecopTD2, &b_RecopTD2);
   SetBranchAddressSafe(fChain,"RecopTD3", &RecopTD3, &b_RecopTD3);
   SetBranchAddressSafe(fChain,"RecopTD4", &RecopTD4, &b_RecopTD4);
   SetBranchAddressSafe(fChain,"RecopTD5", &RecopTD5, &b_RecopTD5);
   SetBranchAddressSafe(fChain,"RecopTD6", &RecopTD6, &b_RecopTD6);
   SetBranchAddressSafe(fChain,"Recophi1", &Recophi1, &b_Recophi1);
   SetBranchAddressSafe(fChain,"Recophi2", &Recophi2, &b_Recophi2);
   SetBranchAddressSafe(fChain,"Recophi3", &Recophi3, &b_Recophi3);
   SetBranchAddressSafe(fChain,"Recophi4", &Recophi4, &b_Recophi4);
   SetBranchAddressSafe(fChain,"Recophi5", &Recophi5, &b_Recophi5);
   SetBranchAddressSafe(fChain,"Recophi6", &Recophi6, &b_Recophi6);
   SetBranchAddressSafe(fChain,"Recopt1", &Recopt1, &b_Recopt1);
   SetBranchAddressSafe(fChain,"Recopt2", &Recopt2, &b_Recopt2);
   SetBranchAddressSafe(fChain,"Recopt3", &Recopt3, &b_Recopt3);
   SetBranchAddressSafe(fChain,"Recopt4", &Recopt4, &b_Recopt4);
   SetBranchAddressSafe(fChain,"Recopt5", &Recopt5, &b_Recopt5);
   SetBranchAddressSafe(fChain,"Recopt6", &Recopt6, &b_Recopt6);
   SetBranchAddressSafe(fChain,"Recosigma1", &Recosigma1, &b_Recosigma1);
   SetBranchAddressSafe(fChain,"Recosigma11", &Recosigma11, &b_Recosigma11);
   SetBranchAddressSafe(fChain,"Recosigma12", &Recosigma12, &b_Recosigma12);
   SetBranchAddressSafe(fChain,"Recosigma13", &Recosigma13, &b_Recosigma13);
   SetBranchAddressSafe(fChain,"Recosigma14", &Recosigma14, &b_Recosigma14);
   SetBranchAddressSafe(fChain,"Recosigma15", &Recosigma15, &b_Recosigma15);
   SetBranchAddressSafe(fChain,"Recosigma16", &Recosigma16, &b_Recosigma16);
   SetBranchAddressSafe(fChain,"Recosigma2", &Recosigma2, &b_Recosigma2);
   SetBranchAddressSafe(fChain,"Recosigma21", &Recosigma21, &b_Recosigma21);
   SetBranchAddressSafe(fChain,"Recosigma22", &Recosigma22, &b_Recosigma22);
   SetBranchAddressSafe(fChain,"Recosigma23", &Recosigma23, &b_Recosigma23);
   SetBranchAddressSafe(fChain,"Recosigma24", &Recosigma24, &b_Recosigma24);
   SetBranchAddressSafe(fChain,"Recosigma25", &Recosigma25, &b_Recosigma25);
   SetBranchAddressSafe(fChain,"Recosigma26", &Recosigma26, &b_Recosigma26);
   SetBranchAddressSafe(fChain,"Recosigma3", &Recosigma3, &b_Recosigma3);
   SetBranchAddressSafe(fChain,"Recosigma4", &Recosigma4, &b_Recosigma4);
   SetBranchAddressSafe(fChain,"Recosigma5", &Recosigma5, &b_Recosigma5);
   SetBranchAddressSafe(fChain,"Recosigma6", &Recosigma6, &b_Recosigma6);
   SetBranchAddressSafe(fChain,"Recotheta1", &Recotheta1, &b_Recotheta1);
   SetBranchAddressSafe(fChain,"Recotheta2", &Recotheta2, &b_Recotheta2);
   SetBranchAddressSafe(fChain,"Recotheta3", &Recotheta3, &b_Recotheta3);
   SetBranchAddressSafe(fChain,"Recotype1", &Recotype1, &b_Recotype1);
   SetBranchAddressSafe(fChain,"Recotype2", &Recotype2, &b_Recotype2);
   SetBranchAddressSafe(fChain,"Recotype3", &Recotype3, &b_Recotype3);
   SetBranchAddressSafe(fChain,"Recoz1", &Recoz1, &b_Recoz1);
   SetBranchAddressSafe(fChain,"Recoz2", &Recoz2, &b_Recoz2);
   SetBranchAddressSafe(fChain,"Recoz3", &Recoz3, &b_Recoz3);
   SetBranchAddressSafe(fChain,"match2", &match2, &b_match2);
   SetBranchAddressSafe(fChain,"match3", &match3, &b_match3);
   SetBranchAddressSafe(fChain,"Genscore0", &Genscore0, &b_Genscore0);
   SetBranchAddressSafe(fChain,"Genscore1", &Genscore1, &b_Genscore1);
   SetBranchAddressSafe(fChain,"Genscore2", &Genscore2, &b_Genscore2);
   SetBranchAddressSafe(fChain,"Genscore3", &Genscore3, &b_Genscore3);
   SetBranchAddressSafe(fChain,"Recoscore0", &Recoscore0, &b_Recoscore0);
   SetBranchAddressSafe(fChain,"Recoscore1", &Recoscore1, &b_Recoscore1);
   SetBranchAddressSafe(fChain,"Recoscore2", &Recoscore2, &b_Recoscore2);
   SetBranchAddressSafe(fChain,"Recoscore3", &Recoscore3, &b_Recoscore3);
   SetBranchAddressSafe(fChain,"MatchedRecoPhi", &MatchedRecoPhi, &b_MatchedRecoPhi);
   SetBranchAddressSafe(fChain,"NumberGoodVertex", &NumberGoodVertex, &b_NumberGoodVertex);
   SetBranchAddressSafe(fChain,"NumberPrimaryVertex", &NumberPrimaryVertex, &b_NumberPrimaryVertex);
   SetBranchAddressSafe(fChain,"NumberTruePileup", &NumberTruePileup, &b_NumberTruePileup);
   SetBranchAddressSafe(fChain,"PileupWeight", &PileupWeight, &b_PileupWeight);
   SetBranchAddressSafe(fChain,"bHadron_PdgId", &bHadron_PdgId, &b_bHadron_PdgId);
   SetBranchAddressSafe(fChain,"bHadron_Pt", &bHadron_Pt, &b_bHadron_Pt);
   SetBranchAddressSafe(fChain,"bHadron_Eta", &bHadron_Eta, &b_bHadron_Eta);
   SetBranchAddressSafe(fChain,"bHadron_Phi", &bHadron_Phi, &b_bHadron_Phi);
   SetBranchAddressSafe(fChain,"bHadron_Energy", &bHadron_Energy, &b_bHadron_Energy);
//    SetBranchAddressSafe("bHadron_PdgId", &bHadron_PdgId, &b_bHadron_PdgId);
   SetBranchAddressSafe(fChain,"cHadron_Pt", &cHadron_Pt, &b_cHadron_Pt);
   SetBranchAddressSafe(fChain,"cHadron_Eta", &cHadron_Eta, &b_cHadron_Eta);
   SetBranchAddressSafe(fChain,"cHadron_Phi", &cHadron_Phi, &b_cHadron_Phi);
   SetBranchAddressSafe(fChain,"cHadron_Energy", &cHadron_Energy, &b_cHadron_Energy);
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
