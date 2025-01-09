#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"

class GetRoc
{
public:
  GetRoc(TH1D *input_true, TH1D *input_false)
  {
    true_distribute = input_true;
    false_distribute = input_false;
  }

  // ~GetRoc()
  // {
  //   delete true_distribute, false_distribute;
  // }

  TGraph GetROC()
  {
    TGraph *graph = new TGraph();
    int bins = true_distribute->GetNbinsX();
    for (int i = 1; i <= bins; i++)
    {
      double true_rate = true_distribute->Integral(i, bins);
      double false_rate = false_distribute->Integral(i, bins);
      graph->SetPoint(i - 1, false_rate, true_rate);
    }
    return *graph;
  }

  double CalculateArea(TGraph *g)
  {
    int nPoints = g->GetN();
    double *x = g->GetX();
    double *y = g->GetY();
    double area = 0;
    for (int i = 0; i < nPoints; i++)
    {
      double dx = x[i + 1] - x[i];
      double avgHeight = (y[i + 1] + y[i]) / 2;
      if (!isnan(dx * avgHeight))
        area += dx * avgHeight;
    }
    double auc = std::abs(area);
    return auc;
  }

private:
  TH1D *true_distribute, *false_distribute;
};