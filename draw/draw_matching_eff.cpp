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
void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void draw_matching_eff(){
    TChain * tchain = new TChain();
    //TString sample_name = "pythia_pt200_IFN_May23drcut1";
    TString sample_name = "pythia_pt200_IFN_May21";

    tchain->Add("../test/"+sample_name+"/Chunk*.root/DataInfo",10000);
    Hists hists;
    hists.addHist("spinon",3,0,3);
    hists.addHist("spinon_match",3,0,3);
    hists.addHist("spinon_unmatch",3,0,3);
    hists.addHist("spinoff",3,0,3);
    hists.addHist("spinoff_match",3,0,3);
    hists.addHist("spinoff_unmatch",3,0,3);


    tchain->Draw("isqq_Parton*2 + isgg_Parton>>spinon_match","(match>=0)*(spin==1)","");
    tchain->Draw("isqq_Parton*2 + isgg_Parton>>spinoff_match","(match>=0)*(spin==0)","");
    tchain->Draw("isqq_Parton*2 + isgg_Parton>>spinon_unmatch","(match==-1)*(spin==1)","");
    tchain->Draw("isqq_Parton*2 + isgg_Parton>>spinoff_unmatch","(match==-1)*(spin==0)","");
    
    hists["spinon"]->Add(hists["spinon_match"]);
    hists["spinon"]->Add(hists["spinon_unmatch"]);

    hists["spinoff"]->Add(hists["spinoff_match"]);
    hists["spinoff"]->Add(hists["spinoff_unmatch"]);


    // TwoPads({(TH1D *)hists["spinon"],(TH1D *)hists["spinon_match"],(TH1D *)hists["spinon_unmatch"]},"spinon_match_May23drcut1.pdf");
    // TwoPads({(TH1D *)hists["spinoff"],(TH1D *)hists["spinoff_match"],(TH1D *)hists["spinoff_unmatch"]},"spinoff_match_May23drcut1.pdf");

    TwoPads({(TH1D *)hists["spinon"],(TH1D *)hists["spinon_match"],(TH1D *)hists["spinon_unmatch"]},"spinon_match_May21.pdf");
    TwoPads({(TH1D *)hists["spinoff"],(TH1D *)hists["spinoff_match"],(TH1D *)hists["spinoff_unmatch"]},"spinoff_match_May21.pdf");
}

void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
    double inte = hists.at(0)->Integral();
    for(int i=0;i<hists.size();i++){
        hists.at(i)->Scale(1.0/inte);
    }
   
      ROOTPlot plot1(hists);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists.at(0)->GetNbinsX());
      plot1.SetLegend(0.15, 0.15, 0.32, 0.35);
      if(legend_name.size()==0)
        plot1.SetLegendName(Draw_Template::GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText({ExtraText});
      plot1.SetLogy();

      plot1.Draw();
      for(int i=0;i<plot1.ratiosArray.at(0).size();i++){
        plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetBinLabel(1,"rest");
        plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetBinLabel(2,"gg");
        plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetBinLabel(3,"qq");
        //cout<<hists.at(i)->GetXaxis()->GetLabelSize()<<endl;
        // plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetLabelOffset(-0.005);
        plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetLabelFont(recommeded_font);
        plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetLabelSize(recommeded_fontsize-4);
        // plot1.ratiosArray.at(0).at(i)->GetXaxis()->SetLabelSize(hists.at(i)->GetXaxis()->GetLabelSize()*1);
        
      }
      plot1.pads.at(0).at(1)->Update();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
}