#include "ROOTPlot.h"

class Draw_Template{
    public:
    static void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      auto hists_sym = SymmetryHists(hists,true);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists_sym.at(0)->GetNbinsX());
      plot1.SetLegend(0.15, 0.35, 0.32, 0.7);
      if(legend_name.size()==0)
        plot1.SetLegendName(GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText({ExtraText});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
    }
    static void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      ROOTPlot plot1(hists);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists.at(0)->GetNbinsX());
      plot1.SetLegend(0.15, 0.35, 0.32, 0.7);
      if(legend_name.size()==0)
        plot1.SetLegendName(GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText({ExtraText});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
    }
    static void NorTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      auto hists_nor = NorHists(hists);
      ROOTPlot plot1(hists_nor);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists.at(0)->GetNbinsX());
      plot1.SetLegend(0.75, 0.65, 0.82, 0.8);
      if(legend_name.size()==0)
        plot1.SetLegendName(GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText({ExtraText});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
    }
    static void NorOnePad(vector<TH1D *> hists,TString filename,TString ExtraText=""){
      auto hists_nor = NorHists(hists);
      ROOTPlot plot1(hists_nor);
      plot1.Load.SinglePad();
      plot1.SetXbinRange(1,hists_nor.at(0)->GetNbinsX());
      plot1.SetLegend(0.45, 0.5, 0.72, 0.85);
      plot1.SetLegendName(GetTitles(hists));
      plot1.SetXTitle("score") ;
      plot1.AddExtraText({ExtraText});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
    }
    static void NorOnePad_frac(vector<TH1D *> hists,TString filename,TString ExtraText=""){                        
      vector<TH1D *> frac_hists;
      TH1D *hist_sum = (TH1D*)hists.at(0)->Clone();
      for(int i=1;i<hists.size();i++){
        hist_sum->Add(hists.at(i));
      }
      for(int i=0;i<hists.size();i++){
        frac_hists.push_back((TH1D *)hists.at(i)->Clone());
        frac_hists.at(i)->Divide(hist_sum);
      }
      ROOTPlot plot1(frac_hists);
      plot1.Load.SinglePad();
      plot1.SetXbinRange(1,frac_hists.at(0)->GetNbinsX());
      plot1.SetLegend(0.55, 0.15, 0.72, 0.35);
      plot1.SetLegendName(GetTitles(hists));
      plot1.SetXTitle("score") ;
      plot1.AddExtraText({ExtraText});
      plot1.SetLogy();
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
    }
    static vector<TString> GetTitles(vector<TH1D *> hists){
        vector<TString> Titles;
        for(int i=0;i<hists.size();i++){
            Titles.push_back(hists.at(i)->GetTitle());
        }
        return Titles;
    }
    static vector<TH1D *> SymmetryHists(vector<TH1D *> hists,bool isnormalized=false) {
      vector<TH1D *> hist_out;
      for (int nhist = 0; nhist < hists.size(); nhist++) {
        TH1D *histogram = (TH1D *)hists.at(nhist)->Clone();
        histogram->Rebin(10);
        int n_bins = histogram->GetNbinsX();
        if(isnormalized) histogram->Scale(1.0/histogram->Integral(1,n_bins));
        
        for (int i = 1; i <= n_bins / 2; ++i) {
          double first_bin_content = histogram->GetBinContent(i);
          double symmetric_bin_content =
              histogram->GetBinContent(n_bins - i + 1);
          double first_bin_error = histogram->GetBinError(i);
          double symmetric_bin_error =
              histogram->GetBinError(n_bins - i + 1);

          double average_content =
              (first_bin_content + symmetric_bin_content) / 2.0;
          double average_error =
              sqrt((first_bin_error*first_bin_error + symmetric_bin_error*symmetric_bin_error) / 2.0);
          histogram->SetBinContent(i, average_content);
          histogram->SetBinContent(n_bins - i + 1, average_content);
          histogram->SetBinError(i, average_error);
          histogram->SetBinError(n_bins - i + 1, average_error);
        }
        hist_out.push_back(histogram);
      }
      return hist_out;
    }
    static vector<TH1D *> NorHists(vector<TH1D *> hists){
      vector<TH1D *> hists_out;
      for(auto &hist :hists)
      {
        TH1D *histogram = (TH1D *)hist->Clone();
        histogram->Scale(1.0/histogram->Integral());
        hists_out.push_back(histogram);
      }
      return hists_out;
    }
};