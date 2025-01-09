#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include <limits>
#include <vector>

class Draw
{
public:
  Draw(std::vector<TGraph *> inputs) : graphs(inputs), cc(nullptr)
  {
    if (cc != nullptr)
    {
      delete cc;
      cc = nullptr;
    }
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100000);
    int random_num = dist(rd);
    cc = new TCanvas(TString::Format("cc%d", random_num), "canvas", 900, 800);
    cc->SetLeftMargin(0.12);
    cc->SetRightMargin(0.05);
    cc->SetTopMargin(0.05);
    for (int i = 0; i < graphs.size(); i++)
    {
      graphs.at(i)->SetLineColor(colors.at(i));
      graphs.at(i)->SetMarkerColor(colors.at(i));
      graphs.at(i)->SetLineWidth(static_cast<Width_t>(2.5));
      graphs.at(i)->GetXaxis()->SetLimits(0, 1);
      graphs.at(i)->GetXaxis()->CenterTitle();
      graphs.at(i)->GetXaxis()->SetTitleSize(0.05);
      graphs.at(i)->GetXaxis()->SetTitleOffset(0.85);
      graphs.at(i)->GetYaxis()->CenterTitle();
      graphs.at(i)->GetYaxis()->SetTitleSize(0.05);
      graphs.at(i)->GetYaxis()->SetTitleOffset(1.1);
    }
  }

  void SetXYTitle(TString xinput, TString yinput)
  {
    graphs.at(0)->GetXaxis()->SetTitle(xinput);
    graphs.at(0)->GetYaxis()->SetTitle(yinput);
  }

  void SetYRange(double dn, double up)
  {
    graphs.at(0)->GetYaxis()->SetRangeUser(dn, up);
  }

  void SetAutoRange()
  {
    double minVal, maxVal;
    getMinMax(graphs, minVal, maxVal);
    double minus = maxVal - minVal;
    graphs.at(0)->GetYaxis()->SetRangeUser(minVal - minus * 0.02, maxVal + minus * 0.1);
  }

  void DrawGraph()
  {
    cc->cd();
    graphs.at(0)->Draw();
    for (int i = 1; i < graphs.size(); i++)
    {
      graphs.at(i)->Draw("same");
    }
  }

  void AddLine(double x1, double y1, double x2, double y2)
  {
    TLine *line = new TLine(x1, y1, x2, y2);
    line->SetLineColor(kBlack);
    line->SetLineWidth(2);
    line->SetLineStyle(2);
    line->Draw("same");
  }

  void AddLegend(std::vector<TString> inputs, double x1 = 0.55, double y1 = 0.8, double x2 = 0.88, double y2 = 0.88)
  {
    TLegend *leg = new TLegend(x1, y1, x2, y2);
    for (int i = 0; i < inputs.size(); i++)
      leg->AddEntry(graphs.at(i), inputs.at(i), "lq");
    leg->SetBorderSize(0);
    leg->SetFillColorAlpha(0, 0);
    leg->SetTextFont(42);
    leg->SetTextSize(0.04);
    leg->Draw("same");
  }

  void AddPave(std::vector<TString> inputs, double x1, double y1, double x2, double y2, double size = 0.04)
  {
    TPaveText *pavetext = new TPaveText(x1, y1, x2, y2, "NDC");
    for (int i = 0; i < inputs.size(); i++)
      pavetext->AddText(inputs.at(i));
    pavetext->SetBorderSize(0);
    pavetext->SetFillColor(0);
    pavetext->SetFillStyle(0);
    pavetext->SetTextFont(42);
    pavetext->SetTextSize(size);
    pavetext->SetTextAlign(12);
    pavetext->Draw("same");
  }

  void Write(TString output)
  {
    cc->SaveAs(output);
  }

private:
  TCanvas *cc;
  std::vector<TGraph *> graphs;
  std::vector<int> colors = {kBlue, kRed, kBlack, 226}; 

  void getMinMax(const std::vector<TGraph *> &graphs, double &globalMin, double &globalMax)
  {
    // Initial values based on limits of double
    globalMin = std::numeric_limits<double>::max();
    globalMax = std::numeric_limits<double>::lowest();
    // Loop over all graphs
    for (TGraph *graph : graphs)
    {
      double x, y;
      for (int i = 0; i < graph->GetN(); ++i)
      {
        graph->GetPoint(i, x, y);
        if (y < globalMin)
        {
          globalMin = y;
        }
        if (y > globalMax)
        {
          globalMax = y;
        }
      }
    }
  }
};