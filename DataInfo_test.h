//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr 26 14:30:17 2024 by ROOT version 6.24/04
// from TTree DataInfo/DataInfo
// found on file: test/validation_data_CA_lundplane_parton10Mz00pt200IFN_matchfull_test.root
//////////////////////////////////////////////////////////

#ifndef DataInfo_test_h
#define DataInfo_test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class DataInfo_test {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<double>  *deltaR1_Hadron;
   vector<double>  *deltaR1_Parton;
   vector<double>  *deltaR2_Hadron;
   vector<double>  *deltaR2_Parton;
   vector<double>  *e1_Hadron;
   vector<double>  *e1_Parton;
   vector<double>  *e2_Hadron;
   vector<double>  *e2_Parton;
   vector<double>  *e3_Hadron;
   vector<double>  *e3_Parton;
   vector<double>  *e4_Hadron;
   vector<double>  *e4_Parton;
   vector<double>  *eec1_Hadron;
   vector<double>  *eec1_Parton;
   vector<double>  *eec2_Hadron;
   vector<double>  *eec2_Parton;
   vector<double>  *eta1_Hadron;
   vector<double>  *eta1_Parton;
   vector<double>  *eta2_Hadron;
   vector<double>  *eta2_Parton;
   vector<double>  *eta3_Hadron;
   vector<double>  *eta3_Parton;
   vector<double>  *eta4_Hadron;
   vector<double>  *eta4_Parton;
   vector<int>     *isgg_Hadron;
   vector<int>     *isgg_Parton;
   vector<int>     *isqq_Hadron;
   vector<int>     *isqq_Parton;
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
   vector<int>     *match;
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
   vector<double>  *phi1_Hadron;
   vector<double>  *phi1_Parton;
   vector<double>  *phi2_Hadron;
   vector<double>  *phi2_Parton;
   vector<double>  *phi3_Hadron;
   vector<double>  *phi3_Parton;
   vector<double>  *phi4_Hadron;
   vector<double>  *phi4_Parton;
   vector<double>  *phi_Hadron;
   vector<double>  *phi_Parton;
   vector<double>  *pt1_Hadron;
   vector<double>  *pt1_Parton;
   vector<double>  *pt2_Hadron;
   vector<double>  *pt2_Parton;
   vector<double>  *pt3_Hadron;
   vector<double>  *pt3_Parton;
   vector<double>  *pt4_Hadron;
   vector<double>  *pt4_Parton;
   Int_t           spin;
   vector<double>  *theta1_Hadron;
   vector<double>  *theta1_Parton;
   vector<double>  *theta2_Hadron;
   vector<double>  *theta2_Parton;
   vector<double>  *z1_Hadron;
   vector<double>  *z1_Parton;
   vector<double>  *z2_Hadron;
   vector<double>  *z2_Parton;

   // List of branches
   TBranch        *b_deltaR1_Hadron;   //!
   TBranch        *b_deltaR1_Parton;   //!
   TBranch        *b_deltaR2_Hadron;   //!
   TBranch        *b_deltaR2_Parton;   //!
   TBranch        *b_e1_Hadron;   //!
   TBranch        *b_e1_Parton;   //!
   TBranch        *b_e2_Hadron;   //!
   TBranch        *b_e2_Parton;   //!
   TBranch        *b_e3_Hadron;   //!
   TBranch        *b_e3_Parton;   //!
   TBranch        *b_e4_Hadron;   //!
   TBranch        *b_e4_Parton;   //!
   TBranch        *b_eec1_Hadron;   //!
   TBranch        *b_eec1_Parton;   //!
   TBranch        *b_eec2_Hadron;   //!
   TBranch        *b_eec2_Parton;   //!
   TBranch        *b_eta1_Hadron;   //!
   TBranch        *b_eta1_Parton;   //!
   TBranch        *b_eta2_Hadron;   //!
   TBranch        *b_eta2_Parton;   //!
   TBranch        *b_eta3_Hadron;   //!
   TBranch        *b_eta3_Parton;   //!
   TBranch        *b_eta4_Hadron;   //!
   TBranch        *b_eta4_Parton;   //!
   TBranch        *b_isgg_Hadron;   //!
   TBranch        *b_isgg_Parton;   //!
   TBranch        *b_isqq_Hadron;   //!
   TBranch        *b_isqq_Parton;   //!
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
   TBranch        *b_match;   //!
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
   TBranch        *b_phi1_Hadron;   //!
   TBranch        *b_phi1_Parton;   //!
   TBranch        *b_phi2_Hadron;   //!
   TBranch        *b_phi2_Parton;   //!
   TBranch        *b_phi3_Hadron;   //!
   TBranch        *b_phi3_Parton;   //!
   TBranch        *b_phi4_Hadron;   //!
   TBranch        *b_phi4_Parton;   //!
   TBranch        *b_phi_Hadron;   //!
   TBranch        *b_phi_Parton;   //!
   TBranch        *b_pt1_Hadron;   //!
   TBranch        *b_pt1_Parton;   //!
   TBranch        *b_pt2_Hadron;   //!
   TBranch        *b_pt2_Parton;   //!
   TBranch        *b_pt3_Hadron;   //!
   TBranch        *b_pt3_Parton;   //!
   TBranch        *b_pt4_Hadron;   //!
   TBranch        *b_pt4_Parton;   //!
   TBranch        *b_spin;   //!
   TBranch        *b_theta1_Hadron;   //!
   TBranch        *b_theta1_Parton;   //!
   TBranch        *b_theta2_Hadron;   //!
   TBranch        *b_theta2_Parton;   //!
   TBranch        *b_z1_Hadron;   //!
   TBranch        *b_z1_Parton;   //!
   TBranch        *b_z2_Hadron;   //!
   TBranch        *b_z2_Parton;   //!

   DataInfo_test(TTree *tree=0);
   virtual ~DataInfo_test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DataInfo_test_cxx
DataInfo_test::DataInfo_test(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test/validation_data_CA_lundplane_parton10Mz00pt200IFN_matchfull_test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test/validation_data_CA_lundplane_parton10Mz00pt200IFN_matchfull_test.root");
      }
      f->GetObject("DataInfo",tree);

   }
   Init(tree);
}

DataInfo_test::~DataInfo_test()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DataInfo_test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DataInfo_test::LoadTree(Long64_t entry)
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

void DataInfo_test::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   deltaR1_Hadron = 0;
   deltaR1_Parton = 0;
   deltaR2_Hadron = 0;
   deltaR2_Parton = 0;
   e1_Hadron = 0;
   e1_Parton = 0;
   e2_Hadron = 0;
   e2_Parton = 0;
   e3_Hadron = 0;
   e3_Parton = 0;
   e4_Hadron = 0;
   e4_Parton = 0;
   eec1_Hadron = 0;
   eec1_Parton = 0;
   eec2_Hadron = 0;
   eec2_Parton = 0;
   eta1_Hadron = 0;
   eta1_Parton = 0;
   eta2_Hadron = 0;
   eta2_Parton = 0;
   eta3_Hadron = 0;
   eta3_Parton = 0;
   eta4_Hadron = 0;
   eta4_Parton = 0;
   isgg_Hadron = 0;
   isgg_Parton = 0;
   isqq_Hadron = 0;
   isqq_Parton = 0;
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
   match = 0;
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
   phi1_Hadron = 0;
   phi1_Parton = 0;
   phi2_Hadron = 0;
   phi2_Parton = 0;
   phi3_Hadron = 0;
   phi3_Parton = 0;
   phi4_Hadron = 0;
   phi4_Parton = 0;
   phi_Hadron = 0;
   phi_Parton = 0;
   pt1_Hadron = 0;
   pt1_Parton = 0;
   pt2_Hadron = 0;
   pt2_Parton = 0;
   pt3_Hadron = 0;
   pt3_Parton = 0;
   pt4_Hadron = 0;
   pt4_Parton = 0;
   theta1_Hadron = 0;
   theta1_Parton = 0;
   theta2_Hadron = 0;
   theta2_Parton = 0;
   z1_Hadron = 0;
   z1_Parton = 0;
   z2_Hadron = 0;
   z2_Parton = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("deltaR1_Hadron", &deltaR1_Hadron, &b_deltaR1_Hadron);
   fChain->SetBranchAddress("deltaR1_Parton", &deltaR1_Parton, &b_deltaR1_Parton);
   fChain->SetBranchAddress("deltaR2_Hadron", &deltaR2_Hadron, &b_deltaR2_Hadron);
   fChain->SetBranchAddress("deltaR2_Parton", &deltaR2_Parton, &b_deltaR2_Parton);
   fChain->SetBranchAddress("e1_Hadron", &e1_Hadron, &b_e1_Hadron);
   fChain->SetBranchAddress("e1_Parton", &e1_Parton, &b_e1_Parton);
   fChain->SetBranchAddress("e2_Hadron", &e2_Hadron, &b_e2_Hadron);
   fChain->SetBranchAddress("e2_Parton", &e2_Parton, &b_e2_Parton);
   fChain->SetBranchAddress("e3_Hadron", &e3_Hadron, &b_e3_Hadron);
   fChain->SetBranchAddress("e3_Parton", &e3_Parton, &b_e3_Parton);
   fChain->SetBranchAddress("e4_Hadron", &e4_Hadron, &b_e4_Hadron);
   fChain->SetBranchAddress("e4_Parton", &e4_Parton, &b_e4_Parton);
   fChain->SetBranchAddress("eec1_Hadron", &eec1_Hadron, &b_eec1_Hadron);
   fChain->SetBranchAddress("eec1_Parton", &eec1_Parton, &b_eec1_Parton);
   fChain->SetBranchAddress("eec2_Hadron", &eec2_Hadron, &b_eec2_Hadron);
   fChain->SetBranchAddress("eec2_Parton", &eec2_Parton, &b_eec2_Parton);
   fChain->SetBranchAddress("eta1_Hadron", &eta1_Hadron, &b_eta1_Hadron);
   fChain->SetBranchAddress("eta1_Parton", &eta1_Parton, &b_eta1_Parton);
   fChain->SetBranchAddress("eta2_Hadron", &eta2_Hadron, &b_eta2_Hadron);
   fChain->SetBranchAddress("eta2_Parton", &eta2_Parton, &b_eta2_Parton);
   fChain->SetBranchAddress("eta3_Hadron", &eta3_Hadron, &b_eta3_Hadron);
   fChain->SetBranchAddress("eta3_Parton", &eta3_Parton, &b_eta3_Parton);
   fChain->SetBranchAddress("eta4_Hadron", &eta4_Hadron, &b_eta4_Hadron);
   fChain->SetBranchAddress("eta4_Parton", &eta4_Parton, &b_eta4_Parton);
   fChain->SetBranchAddress("isgg_Hadron", &isgg_Hadron, &b_isgg_Hadron);
   fChain->SetBranchAddress("isgg_Parton", &isgg_Parton, &b_isgg_Parton);
   fChain->SetBranchAddress("isqq_Hadron", &isqq_Hadron, &b_isqq_Hadron);
   fChain->SetBranchAddress("isqq_Parton", &isqq_Parton, &b_isqq_Parton);
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
   fChain->SetBranchAddress("match", &match, &b_match);
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
   fChain->SetBranchAddress("phi1_Hadron", &phi1_Hadron, &b_phi1_Hadron);
   fChain->SetBranchAddress("phi1_Parton", &phi1_Parton, &b_phi1_Parton);
   fChain->SetBranchAddress("phi2_Hadron", &phi2_Hadron, &b_phi2_Hadron);
   fChain->SetBranchAddress("phi2_Parton", &phi2_Parton, &b_phi2_Parton);
   fChain->SetBranchAddress("phi3_Hadron", &phi3_Hadron, &b_phi3_Hadron);
   fChain->SetBranchAddress("phi3_Parton", &phi3_Parton, &b_phi3_Parton);
   fChain->SetBranchAddress("phi4_Hadron", &phi4_Hadron, &b_phi4_Hadron);
   fChain->SetBranchAddress("phi4_Parton", &phi4_Parton, &b_phi4_Parton);
   fChain->SetBranchAddress("phi_Hadron", &phi_Hadron, &b_phi_Hadron);
   fChain->SetBranchAddress("phi_Parton", &phi_Parton, &b_phi_Parton);
   fChain->SetBranchAddress("pt1_Hadron", &pt1_Hadron, &b_pt1_Hadron);
   fChain->SetBranchAddress("pt1_Parton", &pt1_Parton, &b_pt1_Parton);
   fChain->SetBranchAddress("pt2_Hadron", &pt2_Hadron, &b_pt2_Hadron);
   fChain->SetBranchAddress("pt2_Parton", &pt2_Parton, &b_pt2_Parton);
   fChain->SetBranchAddress("pt3_Hadron", &pt3_Hadron, &b_pt3_Hadron);
   fChain->SetBranchAddress("pt3_Parton", &pt3_Parton, &b_pt3_Parton);
   fChain->SetBranchAddress("pt4_Hadron", &pt4_Hadron, &b_pt4_Hadron);
   fChain->SetBranchAddress("pt4_Parton", &pt4_Parton, &b_pt4_Parton);
   fChain->SetBranchAddress("spin", &spin, &b_spin);
   fChain->SetBranchAddress("theta1_Hadron", &theta1_Hadron, &b_theta1_Hadron);
   fChain->SetBranchAddress("theta1_Parton", &theta1_Parton, &b_theta1_Parton);
   fChain->SetBranchAddress("theta2_Hadron", &theta2_Hadron, &b_theta2_Hadron);
   fChain->SetBranchAddress("theta2_Parton", &theta2_Parton, &b_theta2_Parton);
   fChain->SetBranchAddress("z1_Hadron", &z1_Hadron, &b_z1_Hadron);
   fChain->SetBranchAddress("z1_Parton", &z1_Parton, &b_z1_Parton);
   fChain->SetBranchAddress("z2_Hadron", &z2_Hadron, &b_z2_Hadron);
   fChain->SetBranchAddress("z2_Parton", &z2_Parton, &b_z2_Parton);
   Notify();
}

Bool_t DataInfo_test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DataInfo_test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DataInfo_test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DataInfo_test_cxx
