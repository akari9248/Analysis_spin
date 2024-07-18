#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "../include/Hists.h"
#include "../include/Process_bar.h"
#include "../include/Draw_Template.h"
#include <getopt.h>
#include "TDirectory.h"
#include "TH2D.h"
#include "../include/Smooth_fit.h"
#include "../../EEC_Analysis/include/Draw_help.h"
#include "TF1.h"
void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void GenerateWeightCutDerive(){

    Hists hists("GeneratorWeight.root");
    TH2D *GeneratorWeight=(TH2D *)hists["GeneratorWeight"];
    TH1D *GeneratorWeightCut = GeneratorWeight->ProjectionX();
    for(int i=0;i<GeneratorWeightCut->GetNbinsX()+1;i++){
        double count=0;
        for(int j=0;j<GeneratorWeight->GetNbinsY();j++){
            count+=GeneratorWeight->GetBinContent(i,j);
            if(count>=GeneratorWeightCut->GetBinContent(i)*0.9999){
                double cot= GeneratorWeightCut->GetBinContent(i);
                GeneratorWeightCut->SetBinContent(i,GeneratorWeight->GetYaxis()->GetBinCenter(j));
                GeneratorWeightCut->SetBinError(i,abs(GeneratorWeightCut->GetBinContent(i)-GeneratorWeightCut->GetBinContent(i-1)));
                //GeneratorWeightCut->SetBinError(i,GeneratorWeightCut->GetBinError(i)/cot*GeneratorWeightCut->GetBinContent(i));
                if(cot==0) GeneratorWeightCut->SetBinError(i,0);
                //GeneratorWeightCut->SetBinError(i,0);
                break;
            }
        }
        
    }
    TFile *f = new TFile("GeneratorWeightcut.root","recreate");
    GeneratorWeightCut->Write();
    TF1 *GeneratorWeightCut_fit=GetSmoothFit(GeneratorWeightCut,30,7000,40,true,2.0);
    GeneratorWeightCut_fit->SetRange(30,5000);
    GeneratorWeightCut_fit->Write();
    f->Close();
}

