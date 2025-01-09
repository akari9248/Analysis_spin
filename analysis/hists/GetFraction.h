#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"

class GetFraction
{
public:
  GetFraction(TH2D *input_off, TH2D *input_on)
  {
    phi_score_on = input_on;
    phi_score_off = input_off;
  }

  // ~GetFraction()
  // {
  //   delete phi_score_off, phi_score_on;
  //   delete true_distribute;
  // }

  TGraph Fraction_scan()
  {
    int bins = phi_score_on->GetYaxis()->GetNbins();
    double entries = phi_score_on->GetEntries();

    TGraph *graph_events_frac = new TGraph();

    for (int i = 1; i <= bins; i++)
    {
      double scorecut = phi_score_on->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_on = phi_score_on->ProjectionX("phi_on", i, bins);
      double events_frac = phi_on->GetEntries() / entries;
      graph_events_frac->SetPoint(i - 1, scorecut, events_frac);
    }

    return *graph_events_frac;
  }

private:
  TH2D *phi_score_on, *phi_score_off;
  TH1D *true_distribute;
  bool istrue = false;
};