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

class GetRatio
{
public:
  GetRatio(TH2D *input_off, TH2D *input_on)
  {
    phi_score_on = input_on;
    phi_score_off = input_off;
  }

  TGraph Ratio_scan()
  {
    int bins = phi_score_on->GetYaxis()->GetNbins();
    TGraph *graph = new TGraph();
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = phi_score_on->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_off = phi_score_off->ProjectionX("phi_off", i, bins);
      TH1D *phi_on = phi_score_on->ProjectionX("phi_on", i, bins);
      Plots::Histdispose hists;
      hists.rebin({phi_off, phi_on}, 10);
      hists.normalize({phi_off, phi_on});
      TH1D *phi_ratio = (TH1D *)phi_on->Clone("ratio");
      phi_ratio->Divide(phi_off);

      double ratio = GetMinMax(phi_ratio);

      if (scorecut < 0.7)
      {
        graph->SetPoint(i - 1, scorecut, ratio);
        if (ratio > max_ratio)
        {
          max_ratio = ratio;
          max_ratio_scorecut = scorecut;
          max_ratio_bin = i;
        }
      }
      delete phi_off;
      delete phi_on;
    }

    return *graph;
  }

private:
  TH2D *phi_score_on, *phi_score_off;
  double max_ratio = -1.0;
  double max_ratio_scorecut = -1.0;
  double max_ratio_bin = -1.0;

  double GetMinMax(TH1D *hist)
  {
    int bins = hist->GetNbinsX();
    double sign = 1;
    // if (hist->GetBinContent(5) > 1.0 && hist->GetBinContent(1) < 1.0)
    //   sign = 1;
    // else if (hist->GetBinContent(5) < 1.0 && hist->GetBinContent(1) > 1.0)
    //   sign = -1;
    // else
    //   sign = 0;
    if (hist->GetBinContent(1) < 1.0)
      sign = 1;
    else if (hist->GetBinContent(1) > 1.0)
      sign = -1;

    double minVal = hist->GetBinContent(1);
    double maxVal = hist->GetBinContent(1);
    for (int i = 2; i <= bins; i++)
    {
      double binContent = hist->GetBinContent(i);
      if (binContent < minVal)
        minVal = binContent;
      if (binContent > maxVal)
        maxVal = binContent;
    }
    // std::cout << hist->GetBinContent(1) << " " << minVal << " " << maxVal << std::endl;
    double ratio = (maxVal - minVal) * 0.5 * sign;
    return ratio;
  }
};