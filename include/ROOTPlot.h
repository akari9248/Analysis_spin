#include "TCanvas.h"
#include "TColor.h"
#include "TGraph.h"
#include "TH1.h"
#include "TH2D.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLine.h"
#include "TPad.h"
#include "TStyle.h"
#include <iostream>
#include <vector>
// #include "CMS_lumi.C"
#include "TGaxis.h"
#include "TGraphAsymmErrors.h"
using namespace std;

Style_t recommeded_font = 43;
Float_t recommeded_fontsize = 38;
class ROOTPlot {
public:
  // Hists number in each pad must lower than 11 due to the size of Colors.
  vector<Color_t> Colors = {1,  4, kRed,       226, kOrange + 2, 8, kYellow + 1,
                            93, 7, kGreen + 3, 9};
  TString ratiostr="#frac{d#sigma^{[3]}/d#DeltaR}{d#sigma^{[2]}/d#DeltaR}";
  TString E2Cstr="d#sigma^{[2]}/d#DeltaR";
  TString E3Cstr="d#sigma^{[3]}/d#DeltaR";
  TString DeltaRstr="#DeltaR";
  TCanvas *canvas;
  vector<TH1D *> hists;
  vector<vector<TH1D *>> histsArray;
  vector<TH1D *> ratios;
  vector<vector<TH1D *>> ratiosArray;

  vector<Color_t> hists_color = Colors;
  vector<int> hists_linestyle;

  TH2D *hist2D = 0;
  bool draw2D = false;
  TPad *LegendPad = nullptr;
  TLegend *legend;
  TString hists_Xtitle = "";
  TString hists_Ytitle = "";

  TString ratios_Xtitle = "";
  TString ratios_Ytitle = "Ratio";

  bool histsLogx = false;
  bool histsLogy = false;

  bool ratiosLogx = false;
  bool ratiosLogy = false;

  double hists_XtitleOffset = 0.8;
  double hists_YtitleOffset = 1.2;

  double hists_XtitleSize = 0.06;
  double hists_YtitleSize = 0.06;

  double ratios_XtitleOffset = 0.8;
  double ratios_YtitleOffset = 1.2;

  double ratios_XtitleSize = 0.06;
  double ratios_YtitleSize = 0.06;

  int canvas_width = 800;
  int canvas_height = 600;

  double linewidth = 4;

  double LeftMargin = 0.04;
  double BottomMargin = 0.13;
  double Xaxislabelsize = 0.05;
  double Yaxislabelsize = 0.05;

  int RatioColorBegin=0;

  TPad *transparentPad;
  vector<vector<TPad *>> pads;
  vector<vector<vector<double>>> padsshape;
  vector<double> rangey;
  vector<double> rangey_ratio;

  vector<int> rangex;
  vector<double> rangexnumber;

  vector<double> rangez;

  vector<vector<double>> padsTopMargin;
  vector<vector<double>> padsBottomMargin;
  vector<vector<double>> padsRightMargin;
  vector<vector<double>> padsLeftMargin;
  vector<vector<double>> padsXaxisLabelSize;
  vector<vector<double>> padsYaxisLabelSize;

  double legendxlow;
  double legendylow;
  double legendxup;
  double legendyup;
  vector<TString> LegendName;

  vector<vector<TLine *>> Line;
  vector<vector<TLine *>> LineRatio;

  vector<TLatex *> extrastr;
  class LoadTemplate {
  public:
    LoadTemplate(ROOTPlot &ROOTPlot) : plot(ROOTPlot) {}
    void SinglePad() {
      plot.canvas_width = 600;
      plot.canvas_height = 600;

      plot.padsshape.push_back({{0, 0, 1, 1}});

      plot.padsTopMargin.push_back({0.07});
      plot.padsBottomMargin.push_back({0.11});
      plot.padsLeftMargin.push_back({0.13});
      plot.padsRightMargin.push_back({0.05});

      plot.padsXaxisLabelSize.push_back({0.045});
      plot.padsYaxisLabelSize.push_back({0.045});

      plot.hists_XtitleSize = 0.062;
      plot.hists_YtitleSize = 0.062;
      plot.hists_XtitleOffset = 0.66;
      plot.hists_YtitleOffset = 0.91;

      plot.LoadsParameter();
      cout << "\033[1m"
           << "Complete Loading SinglePads Template."
           << "\033[0m" << endl;
    }
    void TwoPads() {
      plot.canvas_width = 600;
      plot.canvas_height = 600;
      plot.padsshape.push_back({{0, 0.32, 1, 1}, {0, 0, 1, 0.32}});

      plot.padsTopMargin.push_back({0.12, 0.03});
      plot.padsBottomMargin.push_back({0.03, 0.3});
      plot.padsLeftMargin.push_back({0.14, 0.14});
      plot.padsRightMargin.push_back({0.04, 0.04});
    
      plot.padsXaxisLabelSize.push_back({0, 0.045 * 0.65 / 0.3});
      plot.padsYaxisLabelSize.push_back({0.045, 0.045 * 0.65 / 0.3});

      plot.hists_XtitleSize = 0;
      plot.hists_YtitleSize = 0.082;
      plot.hists_XtitleOffset = 0.6;
      plot.hists_YtitleOffset = 0.75;

      plot.ratios_XtitleSize = 0.082 * 0.68 / 0.32;
      plot.ratios_YtitleSize = 0.082 * 0.68 / 0.32;
      plot.ratios_XtitleOffset = 0.28 * 0.68 / 0.32;
      plot.ratios_YtitleOffset = 0.75 / (0.68 / 0.32);

      // Get Ratios and ranges of y axis in ratio and hists
      for (int i = 0; i < plot.histsArray.size(); i++) {
        plot.ratiosArray.push_back({});
        for (int j = 0; j < plot.histsArray.at(i).size(); j++) {
          plot.ratiosArray.at(i).push_back(plot.GetRatio(
              plot.histsArray.at(i).at(j), plot.histsArray.at(i).at(0)));
        }
      }
      //
      plot.LoadsParameter();
      cout << "\033[1m"
           << "Complete Loading TwoPads Template."
           << "\033[0m" << endl;
    }
    void Pad2D() {
      plot.draw2D = true;
      plot.canvas_height = 600;
      plot.canvas_width = 678;

      plot.padsshape.push_back({{0, 0, 1, 1}});
      plot.padsTopMargin.push_back({0.08});
      plot.padsBottomMargin.push_back({0.10});
      plot.padsLeftMargin.push_back({0.12});
      plot.padsRightMargin.push_back({0.12});
      //plot.padsRightMargin.push_back({0.02});

      plot.padsXaxisLabelSize.push_back({0.03});
      plot.padsYaxisLabelSize.push_back({0.03});

      plot.hists_XtitleSize = 0.05;
      plot.hists_YtitleSize = 0.05;
      plot.hists_XtitleOffset = 0.7;
      plot.hists_YtitleOffset = 1.1;
      // plot.hists_XtitleOffset = 0;
      // plot.hists_YtitleOffset = 0;
      plot.LoadsParameter();
      cout << "\033[1m"
           << "Complete Loading Pad2D Template."
           << "\033[0m" << endl;
    }

  private:
    ROOTPlot &plot;
  };
 ROOTPlot(initializer_list<TH1D *> input_hists) : Load(*this) {
    vector<TH1D*> input_hists0(input_hists.begin(), input_hists.end());
    histsArray.push_back(input_hists0);
    Init();
  }
  ROOTPlot(vector<TH1D *> input_hists) : Load(*this) {
    histsArray.push_back(input_hists);
    Init();
  }
  ROOTPlot(vector<vector<TH1D *>> input_hists) : Load(*this) {
    histsArray = input_hists;
    Init();
  }
  ROOTPlot(TH2D *input_hist) : Load(*this) {
    hist2D = (TH2D *)input_hist->Clone(GetRandName());
  }
  void Init() {
    if (histsArray.at(0).size() > Colors.size()) {
      cerr << "\033[1m"
           << TString::Format("hists number in each pad mush lower than %d",
                              (int)Colors.size())
           << "\033[0m" << endl;
      exit(0);
    }
    rangex.push_back(1);
    rangex.push_back(histsArray.at(0).at(0)->GetNbinsX());
    for (int i = 0; i < histsArray.at(0).size(); i++) {
      hists_linestyle.push_back(1);
    }
  }

  void SetTitles(TString xtitle, TString ytitle) {
    hists_Xtitle = xtitle;
    hists_Ytitle = ytitle;
  }
  void SetXTitle(TString input) { hists_Xtitle = input; ratios_Xtitle=input;}
  void SetYTitle(TString input) { hists_Ytitle = input; }
  static TString GetRandName(TString prefix = "") {
    return prefix + TString::Format("%d", rand());
  }
  static void Format_canvas(TCanvas *c) {
    gStyle->SetOptStat(0);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    c->SetTickx(1);
    c->SetTicky(1);
  }
  void formathist(TH1 *hist, TString xtitle = "", TString ytitle = "",
                  Color_t hist_color = 0, double linewidth_local = -1,
                  double Xlabelsize = 0, double Ylabelsize = 0,
                  double Xtitlesize = 0, double Ytitlesize = 0,
                  double Xtitleoffset = 0, double Ytitleoffset = 0) {
    if (linewidth_local == -1) {
      linewidth_local = linewidth;
    }
    if (!draw2D) {
      hist->SetLineWidth(linewidth_local);
      hist->SetMarkerSize(0);
      hist->SetLineColor(hist_color);
    }
    hist->SetTitle("");
    hist->GetXaxis()->SetNdivisions(505);
    hist->GetYaxis()->SetNdivisions(501);
    hist->GetXaxis()->SetNdivisions(10);
    hist->GetYaxis()->SetNdivisions(10);

    hist->SetXTitle(xtitle);
    hist->SetYTitle(ytitle);
    hist->GetXaxis()->SetLabelSize(Xlabelsize);
    hist->GetYaxis()->SetLabelSize(Ylabelsize);
    hist->GetXaxis()->SetTitleSize(Xtitlesize);
    hist->GetYaxis()->SetTitleSize(Ytitlesize);
    hist->GetXaxis()->SetTitleOffset(Xtitleoffset);
    hist->GetYaxis()->SetTitleOffset(Ytitleoffset);
  }
  void SetLineStyle(vector<int> LineStyle) {
    if (LineStyle.size() < histsArray.at(0).size()) {
      cerr << "\033[1m"
           << "Warning: Input Line style vector size is less than hists number "
              "in one pads"
           << "\033[0m" << endl;
    }
    for (int i = 0; i < histsArray.size(); i++) {
      for (int j = 0; j < histsArray.at(i).size(); j++) {
        histsArray.at(i).at(j)->SetLineStyle(LineStyle.at(j));
        if (ratiosArray.size() > 0) {
          ratiosArray.at(i).at(j)->SetLineStyle(LineStyle.at(j));
        }
      }
    }
  }
  void SetErrorStyle(vector<int> LineStyle) {
    if (LineStyle.size() < histsArray.at(0).size()) {
      cerr << "\033[1m"
           << "Warning: Input Line style vector size is less than hists number "
              "in one pads"
           << "\033[0m" << endl;
    }
    for (int i = 0; i < histsArray.size(); i++) {
      for (int j = 0; j < histsArray.at(i).size(); j++) {
        if (LineStyle.at(j) != 0) {
          histsArray.at(i).at(j)->SetFillStyle(LineStyle.at(j));
          histsArray.at(i).at(j)->SetFillColorAlpha(hists_color.at(j), 0.3);
          if (ratiosArray.size() > 0) {
            ratiosArray.at(i).at(j)->SetFillStyle(LineStyle.at(j));
            ratiosArray.at(i).at(j)->SetFillColorAlpha(hists_color.at(j), 0.3);
          }
        }
      }
    }
  }
  //CMS_lumi(c, 0, 0, false);
  // void CMSLumi(int iPeriod = 0, int iPosX = 0, bool isPreliminary = false, TString extratexts = ""){
  //   transparentPad=new TPad(GetRandName(), GetRandName(), 0,0,1,1);
  //   double transTopMargin=pads.at(0).at(0)->GetWh()*1.0*pads.at(0).at(0)->GetTopMargin()*1.0/canvas_height;
  //   double transLeftMargin=pads.at(0).at(0)->GetWw()*pads.at(0).at(0)->GetLeftMargin()*1.0/canvas_width;
  //   double transRightMargin=pads.at(0).at(0)->GetWw()*pads.at(0).at(0)->GetRightMargin()*1.0/canvas_height;
  //   double transBottomMargin=pads.at(0).at(pads.at(0).size()-1)->GetWh()*pads.at(0).at(pads.at(0).size()-1)->GetBottomMargin()*1.0/canvas_height;
  //   transparentPad->SetTopMargin(transTopMargin);
  //   transparentPad->SetLeftMargin(transLeftMargin);
  //   transparentPad->SetRightMargin(transRightMargin);
  //   transparentPad->SetBottomMargin(transBottomMargin);
  //   transparentPad->SetFillStyle(4000);
  //   transparentPad->Draw();
  //   CMS_lumi(transparentPad,iPeriod,iPosX,isPreliminary,extratexts);    
  // }
  /*
   * @brief Rebin histogram in log scale
   * @param hist: input histotgram
   * @param nbin: bin number of output histogram (by default = 30).
   * @param binleftedge: left edge of output histogram (by default = The biggest
   * positive bin in input histogram).
   * @param binrightedge: right edge of output histogram (by default = The right
   * edge of input histogram).
   * @return Rebined histogram
   */
  static TH1D *Relogbin(
      TH1D *hist, int nbin = 30, double binleftedge = -1,
      double binrightedge = -1) { // Return a rebined histogram in log scale,
    if (nbin >= hist->GetNbinsX()) {
      cerr << "The rebinning number must be greater than the number of bins in "
              "the input histogram."
           << endl;
      return NULL;
    }
    if (binleftedge == -1) {
      for (int i = 1; i <= hist->GetNbinsX(); i++) {
        binleftedge = hist->GetBinLowEdge(i);
        if (binleftedge > 0) {
          cout << "\033[1m"
               << TString::Format(
                      "Relog bin started at bin %d, at point of %.4f.", i,
                      binleftedge)
               << "\033[0m" << endl;
          break;
        }
        if (i == hist->GetNbinsX()) {
          cerr << "There are no positive values in the bin ranges." << endl;
          return NULL;
        }
      }
    }
    if (binrightedge == -1) {
      binrightedge = hist->GetBinLowEdge(hist->GetNbinsX() + 1);
    }
    double bin[nbin + 1];
    double binwidth;
    binwidth = (log10(binrightedge) - log10(binleftedge)) / nbin;

    for (int i = 0; i < nbin + 1; i++) {
      bin[i] = pow(10, log10(binleftedge) + i * binwidth);
    }
    TH1D *output = new TH1D(hist->GetName() + GetRandName("Rebin"),
                            hist->GetName() + GetRandName("Rebin"), nbin, bin);
    output->SetBinContent(0, hist->GetBinContent(0));
    output->SetBinContent(hist->GetNbinsX() + 1,
                          hist->GetBinContent(hist->GetNbinsX() + 1));
    for (int i = 1; i < nbin + 1; i++) {
      int k = hist->FindBin(bin[i - 1]);
      int j = hist->FindBin(bin[i]);
      for (int m = k + 1; m < j; m++) {
        output->SetBinContent(i, output->GetBinContent(i) +
                                     hist->GetBinContent(m));
        output->SetBinError(
            i, sqrt(output->GetBinError(i) * output->GetBinError(i) +
                    hist->GetBinError(m) * hist->GetBinError(m)));
      }

      double kpart = (-bin[i - 1] + hist->GetBinLowEdge(k + 1)) /
                     (hist->GetBinLowEdge(k + 1) - hist->GetBinLowEdge(k));
      double jpart = (bin[i] - hist->GetBinLowEdge(j)) /
                     (hist->GetBinLowEdge(j + 1) - hist->GetBinLowEdge(j));
      output->SetBinContent(i, output->GetBinContent(i) +
                                   kpart * hist->GetBinContent(k));
      output->SetBinError(
          i, sqrt(output->GetBinError(i) * output->GetBinError(i) +
                  kpart * kpart * hist->GetBinError(k) * hist->GetBinError(k)));
      output->SetBinContent(i, output->GetBinContent(i) +
                                   jpart * hist->GetBinContent(j));
      output->SetBinError(
          i, sqrt(output->GetBinError(i) * output->GetBinError(i) +
                  jpart * jpart * hist->GetBinError(j) * hist->GetBinError(j)));
    }
    return output;
  }
  void Formathistrange(vector<TH1D *> hist, vector<double> histrange) {
    for (int i = 0; i < hist.size(); i++) {
      hist.at(i)->GetYaxis()->SetRangeUser(histrange.at(0), histrange.at(1));
      hist.at(i)->GetXaxis()->SetRangeUser(rangexnumber.at(0),
                                           rangexnumber.at(1));
    }
  }
  void Formathistrange(vector<vector<TH1D *>> hist, vector<double> histrange) {
    for (int i = 0; i < hist.size(); i++) {
      for (int j = 0; j < hist.at(i).size(); j++) {
        hist.at(i).at(j)->GetYaxis()->SetRangeUser(histrange.at(0),
                                                   histrange.at(1));
        hist.at(i).at(j)->GetXaxis()->SetRangeUser(rangexnumber.at(0),
                                                   rangexnumber.at(1));
      }
    }
  }

  /*
   * @brief Format hists range in Y axis in a given x bin index range
   * @param hist: a vector of input histotgrams
   * @param xbegin: The index of first bin (by default = 1).
   * @param xend: The index of last bin (by default = The last bin in the input
   * histogram).
   * @param rangetool:the y ranges 0. [0.8 * min, 1.2 * max] 1. [1.2 * min -
   * 0.2*max, 1.2 * max - 0.2 * min] 2. [1.2 * min - 0.2*max, 1.2 * max - 0.2 *
   * min] in log scale (by default = range tool 0).
   * @return hists y axis range
   */
  vector<double> Gethistrange(vector<TH1D *> hist, int xbegin = -1,
                              int xend = -1, int rangetool = 1) {
    vector<double> range;
    double max1, max2, min1, min2;
    if (xend < 0) {
      xend = hist.at(0)->GetNbinsX();
    }
    if (xbegin < 0) {
      xbegin = 1;
    }
    for (int i = 0; i < hist.size(); i++) {
      hist.at(i)->GetXaxis()->SetRangeUser(hist.at(i)->GetBinLowEdge(xbegin),
                                           hist.at(i)->GetBinLowEdge(xend + 1));
      hist.at(i)->GetMinimumAndMaximum(min1, max1);
      if (min1 < min2 || i == 0) {
        min2 = min1;
      }
      if (max1 > max2 || i == 0) {
        max2 = max1;
      }
    }
    for (int i = 0; i < hist.size(); i++) {
      if (rangetool == 0) {
        range.push_back(min2 * 0.8);
        range.push_back(max2 * 1.2);
      } else if (rangetool == 1) {
        range.push_back(min2 - 0.2 * (max2 - min2));
        range.push_back(max2 + 0.2 * (max2 - min2));
      } else if (rangetool == 2) {
        if(min2<=0) min2=1e-3;
        range.push_back(
            pow(10, log10(min2) - 0.2 * (log10(max2) - log10(min2))));
        range.push_back(
            pow(10, log10(max2) + 0.2 * (log10(max2) - log10(min2))));
      }
    }
    return range;
  }
  vector<double> Gethistrange(vector<vector<TH1D *>> hist, int xbegin = -1,
                              int xend = -1, int rangetool = 1) {
    vector<TH1D *> hists = {};
    for (int i = 0; i < hist.size(); i++) {
      for (int j = 0; j < hist.at(i).size(); j++) {
        hists.push_back(hist.at(i).at(j));
      }
    }
    return Gethistrange(hists, xbegin, xend, rangetool);
  }
  /*
   * @brief Get the ratio of two histogram ( hist1 / hist2 )
   * @param hist1 : numerator
   * @param hist2 : denominator
   * @param CorrelatedError: The index of last bin (by default = The last bin in
   * the input histogram).
   * @return Get the ratio of hist1 and hist2
   */
  static TH1D *GetRatio(TH1D *hist1, TH1D *hist2, bool CorrelatedError = false) {
    TH1D *hist1_clone = (TH1D *)hist1->Clone(TString::Format("%d", rand()));
    TH1D *hist2_clone = (TH1D *)hist2->Clone(TString::Format("%d", rand()));
    if (!CorrelatedError) {
      for (int i = 0; i < hist2_clone->GetNbinsX() + 2; i++) {
        hist2_clone->SetBinError(i, 0);
      }
    }
    hist1_clone->Divide(hist2_clone);
    return hist1_clone;
  }
  TCanvas *CreatCanvas(Int_t wtopx = 8, Int_t wtopy = 30, Int_t ww = 800,
                       Int_t wh = 600) {
    TCanvas *canvas = new TCanvas(GetRandName("Canvas"), GetRandName("Canvas"),
                                  wtopx, wtopy, ww, wh); // draw on this canvas
    return canvas;
  }
  void Addhist(TH1D *hist) { hists.push_back(hist); }
  void Sethists(vector<TH1D *> hists_in) { hists = hists_in; }
  void Addhists(vector<TH1D *> hists) { histsArray.push_back(hists); }
  void SethistsArray(vector<vector<TH1D *>> histsArray_in) {
    histsArray = histsArray_in;
  }
  void AddVerticalLine(double x) {
    for (int i = Line.size(); i < pads.size(); i++) {
      Line.push_back({});
    }
    for (int i = 0; i < pads.size(); i++) {
      TLine *line_temp = new TLine(x, rangey.at(0), x, rangey.at(1));
      line_temp->SetLineStyle(9);
      line_temp->SetLineWidth(2);
      line_temp->SetLineColor(1);
      Line.at(i).push_back(line_temp);
    }
    if (pads.at(0).size() > 1) {
      for (int i = LineRatio.size(); i < pads.size(); i++) {
        LineRatio.push_back({});
      }
      for (int i = 0; i < pads.size(); i++) {
        TLine *line_temp_ratio =
            new TLine(x, rangey_ratio.at(0), x, rangey_ratio.at(1));
        line_temp_ratio->SetLineStyle(9);
        line_temp_ratio->SetLineWidth(2);
        line_temp_ratio->SetLineColor(1);
        LineRatio.at(i).push_back(line_temp_ratio);
      }
    }
  }
  void AddHorizontalLine(double y) {
    
    for (int i = Line.size(); i < pads.size(); i++) {
      Line.push_back({});
    }
    for (int i = 0; i < pads.size(); i++) {
      TLine *line_temp =
          new TLine(rangexnumber.at(0), y, rangexnumber.at(1), y);
      line_temp->SetLineStyle(9);
      line_temp->SetLineWidth(2);
      line_temp->SetLineColor(1);
      Line.at(i).push_back(line_temp);
    }
  }
  void AddHorizontalLineRatio(double y) {
    for (int i = LineRatio.size(); i < pads.size(); i++) {
      LineRatio.push_back({});
    }
    for (int i = 0; i < pads.size(); i++) {
      TLine *line_temp =
          new TLine(rangexnumber.at(0), y, rangexnumber.at(1), y);
      line_temp->SetLineStyle(9);
      line_temp->SetLineWidth(2);
      line_temp->SetLineColor(1);
      LineRatio.at(i).push_back(line_temp);
    }
  }
  void Draw_Line() {
    for (int i = 0; i < Line.size(); i++) {
      pads.at(i).at(0)->cd();
      for (int j = 0; j < Line.at(i).size(); j++) {
        Line.at(i).at(j)->Draw("same");
      }
    }
    for (int i = 0; i < LineRatio.size(); i++) {
      pads.at(i).at(1)->cd();
      for (int j = 0; j < LineRatio.at(i).size(); j++) {
        LineRatio.at(i).at(j)->Draw("same");
      }
    }
  }
  void SetLogx() {
    for (int i = 0; i < pads.size(); i++) {
      for (int j = 0; j < pads.at(i).size(); j++) {
        pads.at(i).at(j)->cd();
        gPad->SetLogx();
      }
    }
    histsLogx = true;
    ratiosLogx = true;
    SetxyRanges();
  }
  void SetLogz() {
    gPad->SetLogz();
  }
  void SetLogy() {
    for (int i = 0; i < pads.size(); i++) {
      pads.at(i).at(0)->cd();
      gPad->SetLogy();
    }
    rangey = Gethistrange(histsArray, rangex.at(0), rangex.at(1), 2);
    //if(rangey.at(0)<=0) rangey.at(0)=0.001;
    histsLogy = true;
    SetxyRanges();
  }
  void SetLogyratio() {
    for (int i = 0; i < pads.size(); i++) {
      pads.at(i).at(1)->cd();
      gPad->SetLogy();
    }
    rangey_ratio = Gethistrange(histsArray, rangex.at(0), rangex.at(1), 1);
    ratiosLogy = true;
    SetxyRanges();
  }
  void Format_hists() {
    if (draw2D) {
      formathist(hist2D, hists_Xtitle, hists_Ytitle, 0, 0,
                 padsXaxisLabelSize.at(0).at(0), padsYaxisLabelSize.at(0).at(0),
                 hists_XtitleSize, hists_YtitleSize, hists_XtitleOffset,
                 hists_YtitleOffset);
    } else {
      for (int i = 0; i < histsArray.size(); i++) {
        for (int j = 0; j < histsArray.at(i).size(); j++) {
          if (i == 0 && ratiosArray.size() == 0) {
            formathist(
                histsArray.at(i).at(j), hists_Xtitle, hists_Ytitle,
                hists_color.at(j), linewidth, padsXaxisLabelSize.at(i).at(0),
                padsYaxisLabelSize.at(i).at(0), hists_XtitleSize,
                hists_YtitleSize, hists_XtitleOffset, hists_YtitleOffset);
          } else if (i == 0 && ratiosArray.size() != 0) {
            formathist(histsArray.at(i).at(j), hists_Xtitle, hists_Ytitle,
                       hists_color.at(j), linewidth,
                       padsXaxisLabelSize.at(i).at(0),
                       padsYaxisLabelSize.at(i).at(0), 0, hists_YtitleSize,
                       hists_XtitleOffset, hists_YtitleOffset);
          } else {
            formathist(histsArray.at(i).at(j), "", "", hists_color.at(j),
                       linewidth);
          }
        }
        SetxyRanges();
      }
      for (int i = 0; i < ratiosArray.size(); i++) {
        for (int j = 0; j < ratiosArray.at(i).size(); j++) {
          ratiosArray.at(i).at(j)->GetYaxis()->CenterTitle();
          if (i == 0 && i == ratiosArray.size() - 1) {
            formathist(
                ratiosArray.at(i).at(j), ratios_Xtitle, ratios_Ytitle,
                hists_color.at(j+RatioColorBegin), linewidth, padsXaxisLabelSize.at(i).at(1),
                padsYaxisLabelSize.at(i).at(1), ratios_XtitleSize,
                ratios_YtitleSize, ratios_XtitleOffset, ratios_YtitleOffset);
          } else if (i == 0) {
            formathist(ratiosArray.at(i).at(j), ratios_Xtitle, ratios_Ytitle,
                       hists_color.at(j+RatioColorBegin), linewidth,
                       padsXaxisLabelSize.at(i).at(1),
                       padsYaxisLabelSize.at(i).at(1), 0, ratios_YtitleSize, 0,
                       ratios_YtitleOffset);
          } else if (i == ratiosArray.size() - 1) {
            formathist(ratiosArray.at(i).at(j), ratios_Xtitle, ratios_Ytitle,
                       hists_color.at(j+RatioColorBegin), linewidth,

                       padsXaxisLabelSize.at(i).at(1),
                       padsYaxisLabelSize.at(i).at(j), ratios_XtitleSize, 0,
                       ratios_XtitleOffset, 0);
          } else {
            formathist(ratiosArray.at(i).at(j), ratios_Xtitle, ratios_Ytitle,
                       hists_color.at(j+RatioColorBegin), linewidth,
                       padsXaxisLabelSize.at(i).at(1));
          }
        }
      }
    }
  }
  void SetXbinRange(int ibegin = -1, int iend = -1) {
    if (ibegin == -1) {
      rangex.at(0) = 1;
    } else {
      rangex.at(0) = ibegin;
    }
    if (iend == -1) {
      rangex.at(1) = histsArray.at(0).at(0)->GetNbinsX();
    } else {
      rangex.at(1) = iend;
    }
    rangey = Gethistrange(histsArray, rangex.at(0), rangex.at(1));
    SetxyRanges();
    rangexnumber = {histsArray.at(0).at(0)->GetBinLowEdge(rangex.at(0)),
                    histsArray.at(0).at(0)->GetBinLowEdge(rangex.at(1) + 1)};
  }
  void SetYRange(double ibegin, double iend) {
    rangey.at(0) = ibegin;
    rangey.at(1) = iend;
    SetxyRanges();
  }
  void SetZRange(double ibegin, double iend) {
    if (rangez.size() == 0) {
      rangez.push_back(ibegin);
      rangez.push_back(iend);
    } else {
      rangez.at(0) = ibegin;
      rangez.at(1) = iend;
    }
    hist2D->GetZaxis()->SetRangeUser(rangez.at(0), rangez.at(1));
  }
  void SetYRangeRatio(double ibegin, double iend) {
    rangey_ratio.at(0) = ibegin;
    rangey_ratio.at(1) = iend;
    SetxyRanges();
  }
  void RatiodisapearNor() {
    RatioColorBegin=1;
    ratiosArray.clear();
    for (int i = 0; i < histsArray.size(); i++) {
      ratiosArray.push_back({});
      for (int j = 1; j < histsArray.at(i).size(); j++) {
        ratiosArray.at(i).push_back(
            GetRatio(histsArray.at(i).at(j), histsArray.at(i).at(0)));
      }
    }
    rangey_ratio = Gethistrange(ratiosArray, rangex.at(0), rangex.at(1),1);
  }
  void CreatePads() {
    for (int i = 0; i < padsshape.size(); i++) {
      pads.push_back({});
      for (int j = 0; j < padsshape.at(i).size(); j++) {
        pads.at(i).push_back(
            new TPad(GetRandName(), GetRandName(), padsshape.at(i).at(j).at(0),
                     padsshape.at(i).at(j).at(1), padsshape.at(i).at(j).at(2),
                     padsshape.at(i).at(j).at(3)));
      }
    }
    for (int i = 0; i < pads.size(); i++) {
      for (int j = 0; j < pads.at(i).size(); j++) {
        pads.at(i).at(j)->SetTopMargin(padsTopMargin.at(i).at(j));
        pads.at(i).at(j)->SetBottomMargin(padsBottomMargin.at(i).at(j));
        pads.at(i).at(j)->SetLeftMargin(padsLeftMargin.at(i).at(j));
        pads.at(i).at(j)->SetRightMargin(padsRightMargin.at(i).at(j));
        pads.at(i).at(j)->SetFrameLineWidth(2);
        pads.at(i).at(j)->Draw();
      }
    }
  }
  void Draw_histogram(TString opt = "") {
    Format_hists();
    for (int i = 0; i < histsArray.size(); i++) {
      pads.at(i).at(0)->cd();
      histsArray.at(i).at(0)->Draw(opt);
      for (int j = 1; j < histsArray.at(i).size(); j++) {
        histsArray.at(i).at(j)->Draw(opt + "same");
      }
    }
    for (int i = 0; i < ratiosArray.size(); i++) {
      if (ratiosArray.at(i).size() != 0) {
        pads.at(i).at(1)->cd();
        ratiosArray.at(i).at(0)->Draw(opt);
        for (int j = 1; j < ratiosArray.at(i).size(); j++) {
          ratiosArray.at(i).at(j)->Draw(opt + "same");
        }
      }
    }
    if (draw2D) {
      pads.at(0).at(0)->cd();
      if (opt.Length() == 0)
        opt = "colz";
      hist2D->Draw(opt);
    }
  }
  ///https://root.cern.ch/doc/master/classTColor.html color Palette
  void SetPalette(Color_t level = kRainBow) {
    gStyle->SetPalette(level);
  }
  void AddExtraText(vector<TString> text, double x = 777, double y = 777) {
    double originx = x;
    double originy = y;
    if (x == y && x == 777) {
      originx = rangexnumber.at(0);
      originy = rangey.at(0);
      if (histsLogx) {
        originx = log(originx);
      }
      if (histsLogy) {
        originy = log(originy);
      }
    }
    for (int i = 0; i < text.size(); i++) {
      double posix = 0.0357;
      double posiy = 0.917 - i * 0.06;
      double posix0 =
          originx + (rangexnumber.at(1) - rangexnumber.at(0)) * posix;
      double posiy0 = originy + (rangey.at(1) - rangey.at(0)) * posiy;
      if (histsLogx) {
        posix0 =
            exp(posix * (log(rangexnumber.at(1)) - log(rangexnumber.at(0))) +
                originx);
      }
      if (histsLogy) {
        posiy0 = exp(posiy * (log(rangey.at(1)) - log(rangey.at(0))) + originy);
      }
      TLatex *str1 = new TLatex(posix0, posiy0, text.at(i));
      extrastr.push_back(str1);
    }
  }
  void SetLegend(double xlow = 0.35, double ylow = 0.70, double xup = 0.83,
                 double yup = 0.86) {
    legendxlow = xlow;
    legendylow = ylow;
    legendxup = xup;
    legendyup = yup;
  }
  void DrawExtraText() {
    pads.at(0).at(0)->cd();
    for (int i = 0; i < extrastr.size(); i++) {
      extrastr.at(i)->SetTextAlign(11);
      extrastr.at(i)->SetTextColor(1);
      extrastr.at(i)->SetTextFont(43);
      extrastr.at(i)->SetTextSize(20);
      extrastr.at(i)->SetTextAngle(0);
      extrastr.at(i)->Draw("same");
    }
  }
  void SetLegendName(vector<TString> LegendName_in) {
    LegendName = LegendName_in;
  }
  void Draw_Legend() {
    if (LegendPad == NULL)
      LegendPad = pads.at(0).at(0);
    LegendPad->cd();
    pads.at(0).at(0)->cd();
    legend = new TLegend(legendxlow, legendylow, legendxup, legendyup);
    for (int i = 0; i < LegendName.size(); i++) {
      TLegendEntry *legenden0 =
          legend->AddEntry(histsArray.at(0).at(i), LegendName.at(i));
      legenden0->SetTextColor(histsArray.at(0).at(i)->GetLineColor());
    }
    legend->SetTextSize(0.06);
    legend->SetBorderSize(0);
    legend->Draw();
  }
  void LoadsParameter() {
    // Create Canvas and Format the Canvas
    canvas = CreatCanvas(8, 30, canvas_width, canvas_height);
    Format_canvas(canvas);
    // Draw pads
    CreatePads();
    // Set a primary histogram ranges
    if (!draw2D)
      SetxyRanges();
  }
  void Draw(TString opt = "") {
    // Format histogram range and draw histogram
    Draw_histogram(opt);
    if (draw2D)
      return;
    // Draw Legend
    Draw_Legend();
    // Draw Line if exist
    Draw_Line();
    // Draw extra text
    DrawExtraText();
  }
  void convert(TString filename1,TString filename2){
    std::system("convert -density 500 "+filename1+ " -quality 100 "+ filename2);
    std::system("rm "+filename1);
  }
  void Write(TString outname) {
    TString tempout="";
    if(outname.Contains(":")){
      tempout=outname;
      outname = outname(outname.Last('/')+1, outname.Length());
    }

    if (outname.Contains(".png")){
      TString temp = outname.ReplaceAll(".", " ");
      outname.ReplaceAll(" ", ".");
    // 获取最后一个空格之前的子字符串
      TString basename = temp(0, temp.Last(' '));
      TString outnamepdf=basename+".pdf";
      canvas->SaveAs(outnamepdf);
      convert(outnamepdf,outname);
    }else{
      canvas->SaveAs(outname);
    }
    if(tempout.Contains(":")){
      std::system("scp "+outname+ " "+ tempout);
    }
  }
  static TGraphAsymmErrors*  draw_graph_asymx(double x,double y,double xErrLeft,double xErrRight,int linecolor=1){
    TGraphAsymmErrors* graph=init_asymxy(x,y,xErrLeft,xErrRight,0,0);
    graph->SetMarkerStyle(20); // 设置数据点的标记样式为圆形
    graph->SetMarkerSize(1.5); // 设置数据点的标记大小
    graph->SetLineWidth(2);
    graph->SetLineColor(linecolor);
    graph->Draw("Psame");
    return graph;
  }
  static TGraphAsymmErrors* init_asymxy(double x,double y,double xErrLeft,double xErrRight,double yErrLow,double yErrHigh){
    TGraphAsymmErrors* graph = new TGraphAsymmErrors(1);
    graph->SetPoint(0, x, y);
    graph->SetPointError(0, xErrLeft, xErrRight, yErrLow, yErrHigh);
    return graph;
  }
  static void  set_pad_range(double x_low,double x_high,double y_low,double y_high,TString opt=""){
    TH1D *empty_hist = new TH1D(TString::Format("%d",rand()),"",1,x_low,x_high);
    empty_hist->GetYaxis()->SetRangeUser(y_low,y_high);
    empty_hist->Draw(opt);
  }

  static vector<TGaxis *> DrawPadsAxis(TCanvas *canvas, double xmin, double ymin, double xmax, double ymax, double xl, double xh, double yl, double yh, vector<int> axis_label={0,1,1,0},vector<int> axis_draw={1,1,1,1})
  {
      canvas->cd();
      
      TGaxis *axis_b = LoadGaxis(xmin, ymin, xmax, ymin, xl, xh, "SU+");
      TGaxis *axis_t = LoadGaxis(xmin, ymax, xmax, ymax, xl, xh, "SU-");
      TGaxis *axis_l = LoadGaxis(xmin, ymin, xmin, ymax, yl, yh, "SU-");
      TGaxis *axis_r = LoadGaxis(xmax, ymin, xmax, ymax, yl, yh, "SU+");
      double length = xmax - xmin;
          if (xmin == xmax)
              length = ymax - ymin;
      if (axis_label.at(0))
      {
          axis_t = LoadGaxis(xmin, ymax, xmax, ymax, xl, xh, "S-");
          axis_t->SetLabelOffset(+0.00);
          axis_t->SetLabelOffset(+0.01 / length);
      }
      if (axis_label.at(1))
      {
          axis_b = LoadGaxis(xmin, ymin, xmax, ymin, xl, xh, "S+");
          axis_b->SetLabelOffset(+0.00);
      }
      if (axis_label.at(2))
      {
          axis_l = LoadGaxis(xmin, ymin, xmin, ymax, yl, yh, "S-");
          axis_l->SetLabelOffset(+0.002 / length);
      }
      if (axis_label.at(3))
      {
          axis_r = LoadGaxis(xmax, ymin, xmax, ymax, yl, yh, "S+");
          
          axis_r->SetLabelOffset(+0.065);
          axis_r->SetTextAlign(23);
      }
      
      if(axis_draw.at(0))
      axis_t->Draw();
      if(axis_draw.at(1))
      axis_b->Draw();
      if(axis_draw.at(2))
      axis_l->Draw();
      if(axis_draw.at(3))
      axis_r->Draw();
      vector<TGaxis *> axises={axis_t,axis_b,axis_l,axis_r};
      return axises;
  }
  static TGaxis *LoadGaxis(double xmin, double ymin, double xmax, double ymax, double range_min, double range_max, TString opt = "")
{   
    double length = xmax - xmin;
    if (xmin == xmax)
        length = ymax - ymin;
    //int ndivision = 505;
    int ndivision = 510;
    if(length < 0.225) ndivision = 505;
    TGaxis *axis = new TGaxis(xmin, ymin, xmax, ymax, range_min, range_max, ndivision, opt);
    //axis->SetLineColor(kRed);
    //axis->SetLabelSize(axis->GetLabelSize()*1.2);
    axis->SetLabelFont(43);
    axis->SetLabelSize(38);
    axis->SetTickLength(0.015 / length);
    axis->SetLabelOffset(-0.002 / length);
    return axis;
}
static TLatex *DrawTLatex(double x,double y,TString str,int angle = 0,int textsize = 38,int alignment=12){
    TLatex *ytitler = new TLatex(x, y, str);
    // TPaveText *ytitler = new TPaveText(.05,.1,.95,.8);
    ytitler->SetTextAlign(alignment);
    ytitler->SetTextColor(1);
    ytitler->SetTextFont(43);
    ytitler->SetTextSize(textsize);
    ytitler->SetTextAngle(angle);
    ytitler->Draw();
    return ytitler;
}
  LoadTemplate Load;

private:
  void SetxyRanges() {
    if (rangex.size() == 0) {
      rangex.push_back(1);
      rangex.push_back(histsArray.at(0).at(0)->GetNbinsX());
    }
    if (histsLogx && histsArray.at(0).at(0)->GetBinLowEdge(rangex.at(0)) <= 0) {
      for (int i = 1; i <= histsArray.at(0).at(0)->GetNbinsX() + 1; i++) {
        if (histsArray.at(0).at(0)->GetBinLowEdge(i) > 0) {
          rangex.at(0) = i;
          break;
        }
      }
    }
    if(rangexnumber.size()==0){
      rangexnumber = {histsArray.at(0).at(0)->GetBinLowEdge(rangex.at(0)),
                    histsArray.at(0).at(0)->GetBinLowEdge(rangex.at(1) + 1)};
    }
    
    if (rangey.size() == 0) {
      rangey = Gethistrange(histsArray, rangex.at(0), rangex.at(1));
    }
    if (rangey.at(0) <= 0 && histsLogy) {
      cerr << "\033[1m"
           << "Warning: Non-positive number exist when Logy is token, Y ranges "
              "from 0.01 now!"
           << "\033[0m" << endl;
      cerr << "\033[1m"
           << "Warning: You can set Y ranges by SetYRange()!"
           << "\033[0m" << endl;
      rangey.at(0) = 0.01;
    }
    Formathistrange(histsArray, rangey);
    if (ratiosArray.size() > 0) {
      if (rangey_ratio.size() == 0) {
        rangey_ratio = Gethistrange(ratiosArray, rangex.at(0), rangex.at(1),1);
      }
      if (rangey_ratio.at(0) <= 0 && ratiosLogy) {
        cerr << "\033[1m"
             << "Warning: Non-positive number exist when Logy is token, Y "
                "ranges from 0.01 now!"
             << "\033[0m" << endl;
        cerr << "\033[1m"
             << "Warning: You can set Y ranges by SetYRangeRatio()!"
             << "\033[0m" << endl;
        rangey_ratio.at(0) = 0.01;
      }
      Formathistrange(ratiosArray, rangey_ratio);
    }
  }
};
