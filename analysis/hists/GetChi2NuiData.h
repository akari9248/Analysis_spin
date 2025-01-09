#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"

#ifndef PLOTRATIO_H
#define PLOTRATIO_H
#include "/storage/shuangyuan/code/headfile/plotratio_beta.h"
#endif

#include "/storage/shuangyuan/code/analysis_spin/Machine_learning/include/chiscan.h"

class GetChi2NuiData
{
public:
  GetChi2NuiData(TH2D *input_off_herwig, TH2D *input_on_herwig,
                 TH2D *input_off_pythia, TH2D *input_on_pythia, TH2D *input_data)
  {
    herwig_phi_score_on = input_on_herwig;
    herwig_phi_score_off = input_off_herwig;
    pythia_phi_score_on = input_on_pythia;
    pythia_phi_score_off = input_off_pythia;
    data_phi_score = input_data;
  }

  // ~GetChi2_nuisance()
  // {
  //   delete herwig_phi_score_on, herwig_phi_score_off, pythia_phi_score_on, pythia_phi_score_off;
  // }

  TGraph Chi2_scan(TString mode = "off")
  {
    int bins = herwig_phi_score_on->GetYaxis()->GetNbins();
    TGraph *graph = new TGraph();
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = herwig_phi_score_on->GetYaxis()->GetBinLowEdge(i);
      if (scorecut > 0.9)
        continue;
      TH1D *herwig_off = herwig_phi_score_off->ProjectionX("phi_off_herwig", i, bins);
      TH1D *pythia_off = pythia_phi_score_off->ProjectionX("phi_off_pythia", i, bins);
      TH1D *herwig_on = herwig_phi_score_on->ProjectionX("phi_on_herwig", i, bins);
      TH1D *pythia_on = pythia_phi_score_on->ProjectionX("phi_on_pythia", i, bins);
      TH1D *phi_data = data_phi_score->ProjectionX("phi_data", i, bins);
      std::vector<TH1D *> phis = {herwig_off, pythia_off, herwig_on, pythia_on, phi_data};
      Plots::Histdispose hists;
      hists.rebin(phis, 10);
      hists.normalize(phis);

      TH1D *average, *up, *dn;
      if (mode == "off")
      {
        average = (TH1D *)pythia_off->Clone("average");
        average->Add(herwig_off);
        average->Scale(0.5);
        up = (TH1D *)pythia_off->Clone("up");
        up->Divide(average);
        dn = (TH1D *)herwig_off->Clone("dn");
        dn->Divide(average);
        int xbins = up->GetXaxis()->GetNbins();
        for (int i = 1; i <= xbins; i++)
        {
          double upbin = up->GetBinContent(i);
          double dnbin = dn->GetBinContent(i);
          up->SetBinContent(i, upbin - 1.0);
          dn->SetBinContent(i, dnbin - 1.0);
        }
        chiscan::chiscan chi2(herwig_on, chiscan::chiscan::GetStandarCov(phi_data), herwig_off, {up}, {dn});
        chi2.HiddenOutput();
        chi2.scanchi2();
        graph->SetPoint(i - 1, herwig_phi_score_on->GetYaxis()->GetBinLowEdge(i), chi2.chi2_best);
        if (chi2.chi2_best > max_chi2)
        {
          max_chi2 = chi2.chi2_best;
          max_chi2_scorecut = herwig_phi_score_on->GetYaxis()->GetBinLowEdge(i);
          max_chi2_bin = i;
        }
      }

      if (mode == "on")
      {
        average = (TH1D *)pythia_on->Clone("average");
        average->Add(herwig_on);
        average->Scale(0.5);
        up = (TH1D *)pythia_on->Clone("up");
        up->Divide(average);
        dn = (TH1D *)herwig_on->Clone("dn");
        dn->Divide(average);
        int xbins = up->GetXaxis()->GetNbins();
        for (int i = 1; i <= xbins; i++)
        {
          double upbin = up->GetBinContent(i);
          double dnbin = dn->GetBinContent(i);
          up->SetBinContent(i, upbin - 1.0);
          dn->SetBinContent(i, dnbin - 1.0);
        }
        chiscan::chiscan chi2(herwig_on, chiscan::chiscan::GetStandarCov(phi_data), herwig_off, {up}, {dn});
        chi2.HiddenOutput();
        chi2.scanchi2();
        graph->SetPoint(i - 1, herwig_phi_score_on->GetYaxis()->GetBinLowEdge(i), chi2.chi2_best);
        if (chi2.chi2_best > max_chi2)
        {
          max_chi2 = chi2.chi2_best;
          max_chi2_scorecut = herwig_phi_score_on->GetYaxis()->GetBinLowEdge(i);
          max_chi2_bin = i;
        }
      }
    }
    return *graph;
  }

  void Chi2_max(TString name, TString mode = "off")
  {
    int bins = herwig_phi_score_on->GetYaxis()->GetNbins();
    TH1D *herwig_off = herwig_phi_score_off->ProjectionX("phi_off_herwig", max_chi2_bin, bins);
    TH1D *pythia_off = pythia_phi_score_off->ProjectionX("phi_off_pythia", max_chi2_bin, bins);
    TH1D *herwig_on = herwig_phi_score_on->ProjectionX("phi_on_herwig", max_chi2_bin, bins);
    TH1D *pythia_on = pythia_phi_score_on->ProjectionX("phi_on", max_chi2_bin, bins);
    TH1D *phi_data = data_phi_score->ProjectionX("phi_data", max_chi2_bin, bins);
    std::vector<TH1D *> phis = {herwig_off, pythia_off, herwig_on, pythia_on, phi_data};
    Plots::Histdispose hists;
    hists.rebin(phis, 10);
    hists.normalize(phis);

    if (mode == "off")
    {
      TH1D *average = (TH1D *)pythia_off->Clone("average");
      average->Add(herwig_off);
      average->Scale(0.5);
      TH1D *up = (TH1D *)pythia_off->Clone("up");
      up->Divide(average);
      TH1D *dn = (TH1D *)herwig_off->Clone("dn");
      dn->Divide(average);
      int xbins = up->GetXaxis()->GetNbins();
      for (int i = 1; i <= xbins; i++)
      {
        double upbin = up->GetBinContent(i);
        double dnbin = dn->GetBinContent(i);
        up->SetBinContent(i, upbin - 1.0);
        dn->SetBinContent(i, dnbin - 1.0);
      }
      chiscan::chiscan chi2(herwig_on, chiscan::chiscan::GetStandarCov(phi_data), herwig_off, {up}, {dn});
      chi2.HiddenOutput();
      chi2.scanchi2();
      chi2.write_result(name);
    }

    if (mode == "on")
    {
      TH1D *average = (TH1D *)pythia_on->Clone("average");
      average->Add(herwig_on);
      average->Scale(0.5);
      TH1D *up = (TH1D *)pythia_on->Clone("up");
      up->Divide(average);
      TH1D *dn = (TH1D *)herwig_on->Clone("dn");
      dn->Divide(average);
      int xbins = up->GetXaxis()->GetNbins();
      for (int i = 1; i <= xbins; i++)
      {
        double upbin = up->GetBinContent(i);
        double dnbin = dn->GetBinContent(i);
        up->SetBinContent(i, upbin - 1.0);
        dn->SetBinContent(i, dnbin - 1.0);
      }
      chiscan::chiscan chi2(herwig_on, chiscan::chiscan::GetStandarCov(phi_data), herwig_off, {up}, {dn});
      chi2.HiddenOutput();
      chi2.scanchi2();
      chi2.write_result(name);
    }
  }

  std::vector<TString> Chi2_pave(TString mode)
  {
    std::vector<TString> paves;
    paves.push_back(mode);
    paves.push_back(TString::Format("max chi2 = %.4f", max_chi2));
    paves.push_back(TString::Format("max chi2 scorecut = %.2f", max_chi2_scorecut));
    return paves;
  }

private:
  TH2D *herwig_phi_score_on, *herwig_phi_score_off;
  TH2D *pythia_phi_score_on, *pythia_phi_score_off;
  TH2D *data_phi_score;
  double max_chi2 = -1.0;
  double max_chi2_scorecut = -1.0;
  double max_chi2_bin = -1.0;
};