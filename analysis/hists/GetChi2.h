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

class GetChi2
{
public:
  GetChi2(TH2D *input_off, TH2D *input_on)
  {
    phi_score_on = input_on;
    phi_score_off = input_off;
    max_chi2 = -1.0;
    max_chi2_scorecut = -1.0;
    max_chi2_bin = -1.0;
  }

  // ~GetChi2()
  // {
  //   delete phi_score_off, phi_score_on;
  // }

  TGraph Chi2_scan()
  {
    int bins = phi_score_on->GetYaxis()->GetNbins();
    TGraph *graph = new TGraph();
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = phi_score_on->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_off = phi_score_off->ProjectionX("phi_off", i, bins);
      TH1D *phi_on = phi_score_on->ProjectionX("phi_on", i, bins);
      std::vector<TH1D *> phis = {phi_off, phi_on};
      Plots::Histdispose hists;
      hists.rebin(phis, 10);
      hists.normalize(phis);
      std::vector<double> chi2s = hists.chi_square(phis);

      if (scorecut < 0.9)
      {
        graph->SetPoint(i - 1, scorecut, chi2s.at(0));
        if (chi2s.at(0) > max_chi2)
        {
          max_chi2 = chi2s.at(0);
          max_chi2_scorecut = scorecut;
          max_chi2_bin = i;
        }
      }

      delete phi_off, phi_on;
    }
    return *graph;
  }

  std::vector<TH1D *> Chi2_max()
  {
    int bins = phi_score_on->GetYaxis()->GetNbins();
    TH1D *phi_off = phi_score_off->ProjectionX("phi_off", max_chi2_bin, bins);
    TH1D *phi_on = phi_score_on->ProjectionX("phi_on", max_chi2_bin, bins);
    std::vector<TH1D *> temp = {phi_off, phi_on};
    Plots::Histdispose hists;
    hists.rebin(temp, 10);
    hists.normalize(temp);
    return temp;
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
  TH2D *phi_score_on, *phi_score_off;
  double max_chi2 = -1.0;
  double max_chi2_scorecut = -1.0;
  double max_chi2_bin = -1.0;
};