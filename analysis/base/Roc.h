#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "/storage/shuangyuan/code/headfile/plotratio_beta.h"
// #include "Base_CMSMC.h"
#include "Base_PrivateMC_predict.h"
#include "Base_PrivateMC_train.h"

/*
  需要注意的事情：
  1. 请根据你的label设置，在Base_PrivateMC_train.h中修改相应的istrue和ifalse的判断
     主要是qq的部分，是选择了qq还是qq&q0
  2. 所有的Set*函数都要在Add*之前运行
*/

class ROC
{
public:
  ROC()
  {
    cc_roc = new TCanvas("cc_roc", "ROC Canvas", 800, 800);
    cc_chisquare = new TCanvas("cc_chisquare", "ChiSquare Canvas", 800, 800);
    cc_ratio = new TCanvas("cc_ratio1", "Ratio1 Canvas", 800, 800);
    cc_events = new TCanvas("cc_events1", "Events1 Canvas", 800, 800);
    cc_truefrac = new TCanvas("cc_truefrac", "Truefrac Canvas", 800, 800);
    std::vector<TCanvas *> canvas = {cc_roc, cc_chisquare, cc_ratio, cc_events, cc_truefrac};
    for (int i = 0; i < canvas.size(); i++)
    {
      canvas.at(i)->SetLeftMargin(0.12);
      canvas.at(i)->SetRightMargin(0.05);
      canvas.at(i)->SetTopMargin(0.05);
    }

    g = new TGraph();
    g_chi = new TGraph();
    g_ratio = new TGraph();
    g_event = new TGraph();
    g_truefrac = new TGraph();
    std::vector<TGraph *> graphs = {g, g_chi, g_ratio, g_event, g_truefrac};
    std::vector<TString> graph_names = {"roc", "chi2", "ratio", "event", "true_frac"};
    for (int i = 0; i < graphs.size(); i++)
    {
      graphs.at(i)->SetName(graph_names.at(i));
      graphs.at(i)->SetLineColor(kBlue);
      graphs.at(i)->SetMarkerColor(kBlue);
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

  void SetEntries(int analyze_entries)
  {
    entries = analyze_entries;
  }

  void SetWeight(std::vector<double> input_weights)
  {
    weights = input_weights;
  }

  void SetTPR(TString input_TPR)
  {
    TPR = input_TPR;
  }

  void SetFPR(TString input_FPR)
  {
    FPR = input_FPR;
  }

  void SetValidate(TString input_validate)
  {
    validate = input_validate;
  }

  void AddPrivateMC_train(TString input_path)
  {
    privateMC_train_herwig_off_path = input_path;
    Base_PrivateMC_train train(privateMC_train_herwig_off_path);
    train.SetTPR(TPR);
    train.SetFPR(FPR);
    train.SetValidate(validate);
    hists_private_train_herwig_off = train.GetBaseHist(entries);
  }

  void AddPrivateMC_predict_herwig_on(TString input_path)
  {
    std::cout << "Analyzing Private Herwig on predict sample ......" << std::endl;
    privateMC_predict_herwig_on_path = input_path;
    Base_PrivateMC_predict predict(privateMC_predict_herwig_on_path);
    predict.SetTPR(TPR);
    predict.SetWeight(weights);
    hists_private_predict_herwig_on = predict.GetBaseHist(entries);
  }

  void AddPrivateMC_predict_pythia(TString input_path_off, TString input_path_on)
  {
    std::cout << "Analyzing Private Pythia predict sample ......" << std::endl;
    privateMC_predict_pythia_off_path = input_path_off;
    Base_PrivateMC_predict predict1(privateMC_predict_pythia_off_path);
    predict1.SetTPR(TPR);
    predict1.SetWeight(weights);
    hists_private_predict_pythia_off = predict1.GetBaseHist(entries);

    privateMC_predict_pythia_on_path = input_path_on;
    Base_PrivateMC_predict predict2(privateMC_predict_pythia_on_path);
    predict2.SetTPR(TPR);
    predict2.SetWeight(weights);
    hists_private_predict_pythia_on = predict2.GetBaseHist(entries);
  }

  // void AddCMSMC(TString input_path)
  // {
  //   CMSMC_path = input_path;
  //   Base_CMSMC cms(CMSMC_path);
  //   cms.SetTPR(TPR);
  //   cms.SetWeight(weights);
  //   hists_cmsmc = cms.GetBaseHist();
  // }

  void DrawROC(TString outputfolder = ".")
  {
    if (privateMC_train_herwig_off_path == "")
    {
      std::cerr << "Error: privateMC_train_path is empty. Cannot draw ROC curve." << std::endl;
      return;
    }
    int bins = hists_private_train_herwig_off.true_distribute->GetNbinsX();
    int zero = 0;
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = hists_private_train_herwig_off.true_distribute->GetXaxis()->GetBinLowEdge(i);
      double true_rate = hists_private_train_herwig_off.true_distribute->Integral(i, bins);
      double false_rate = hists_private_train_herwig_off.false_distribute->Integral(i, bins);
      g->SetPoint(i - 1, false_rate, true_rate);
      // std::cout << i << " " << false_rate << " " << true_rate << std::endl;
    }

    cc_roc->cd();
    g->GetXaxis()->SetLimits(0, 1);
    g->GetYaxis()->SetRangeUser(0, 1);
    if (TPR == "qq")
    {
      g->GetYaxis()->SetTitle("True qq rate");
      if (FPR == "no qq" || FPR == "un qq" || FPR == "noqq" || FPR == "unqq")
        g->GetXaxis()->SetTitle("False qq rate");
      if (FPR == "gg")
        g->GetXaxis()->SetTitle("True gg rate");
    }
    if (TPR == "gg")
    {
      g->GetYaxis()->SetTitle("True gg rate");
      if (FPR == "no gg" || FPR == "un gg" || FPR == "nogg" || FPR == "ungg")
        g->GetXaxis()->SetTitle("False gg rate");
      if (FPR == "qq")
        g->GetXaxis()->SetTitle("True qq rate");
    }
    g->Draw("AL");

    TLine *line = new TLine(0, 0, 1, 1);
    line->SetLineColor(kBlack);
    line->SetLineWidth(2);
    line->SetLineStyle(2);
    line->Draw("same");

    double auc = CalculateArea(g);
    TPaveText *paveText1 = new TPaveText(0.45, 0.05, 0.99, 0.3);
    paveText1->AddText(TString::Format("AUC = %.4f", auc));
    paveText1->SetBorderSize(0);
    paveText1->SetFillColor(0);
    paveText1->SetTextFont(42);
    paveText1->SetTextSize(0.04);
    paveText1->SetTextAlign(12);
    paveText1->Draw("same");

    cc_roc->SaveAs(outputfolder + "/roc_" + TPR + "_" + FPR + "_" + validate + ".pdf");
  }

  void DrawChi2(TString outputfolder = ".", TString generator = "herwig")
  {
    TH2D *phi_score_off, *phi_score_on;
    if (generator == "herwig")
    {
      phi_score_off = hists_private_train_herwig_off.phi_score;
      phi_score_on = hists_private_predict_herwig_on.phi_score;
    }
    else if (generator == "pythia")
    {
      phi_score_off = hists_private_predict_pythia_off.phi_score;
      phi_score_on = hists_private_predict_pythia_on.phi_score;
    }
    else
    {
      std::cerr << "Error: Do not support the input generator." << std::endl;
      return;
    }

    int bins = phi_score_off->GetYaxis()->GetNbins();
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = phi_score_off->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_off = phi_score_off->ProjectionX("phi_off", i, bins);
      TH1D *phi_on = phi_score_on->ProjectionX("phi_on", i, bins);

      std::vector<TH1D *> phis = {phi_off, phi_on};
      Plots::Histdispose hists;
      hists.normalize(phis);

      std::vector<double> chi2s = hists.chi_square(phis);
      g_chi->SetPoint(i - 1, scorecut, chi2s.at(0));
      if (chi2s.at(0) > max_chi2)
      {
        max_chi2 = chi2s.at(0);
        max_chi2_scorecut = scorecut;
        max_chi2_bin = i;
      }

      delete phi_off, phi_on;
    }
    cc_chisquare->cd();
    g_chi->GetYaxis()->SetTitle("Chi square");
    g_chi->GetXaxis()->SetTitle("Score cut");
    g_chi->Draw();

    TPaveText *paveText2 = new TPaveText(0.5, 0.8, 0.8, 0.95, "NDC");
    paveText2->AddText(TString::Format("max chi2 = %.4f", max_chi2));
    paveText2->AddText(TString::Format("max chi2 scorecut = %.4f", max_chi2_scorecut));
    paveText2->SetBorderSize(0);
    paveText2->SetFillColor(0);
    paveText2->SetFillStyle(0);
    paveText2->SetTextFont(42);
    paveText2->SetTextSize(0.035);
    paveText2->SetTextAlign(12);
    paveText2->Draw("same");

    cc_chisquare->SaveAs(outputfolder + "/chi2_" + TPR + "_" + generator + ".pdf");

    TH1D *phi_off = phi_score_off->ProjectionX("phi_off", max_chi2_bin, bins);
    TH1D *phi_on = phi_score_on->ProjectionX("phi_on", max_chi2_bin, bins);

    std::vector<TH1D *> phis = {phi_off, phi_on};
    Plots::Histdispose hists;
    hists.normalize(phis);

    Plots::Plotratio plot(phis);
    plot.Draw();
    plot.AddPave({TPR, TString::Format("score cut = %.4f", max_chi2_scorecut)});
    plot.AddLegend({"spin off", "spin on"});
    plot.SetXRatioTitle("#varphi");
    plot.Write(outputfolder + "/chi2_max_" + TPR + "_" + generator + ".pdf");
  }

  void DrawRatio(TString outputfolder = ".", TString generator = "herwig")
  {
    TH2D *phi_score_off, *phi_score_on;
    if (generator == "herwig")
    {
      phi_score_off = hists_private_train_herwig_off.phi_score;
      phi_score_on = hists_private_predict_herwig_on.phi_score;
    }
    else if (generator == "pythia")
    {
      phi_score_off = hists_private_predict_pythia_off.phi_score;
      phi_score_on = hists_private_predict_pythia_on.phi_score;
    }
    else
    {
      std::cerr << "Error: Do not support the input generator." << std::endl;
      return;
    }
    int bins = phi_score_off->GetYaxis()->GetNbins();
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = phi_score_off->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_off = phi_score_off->ProjectionX("phi_off", i, bins);
      TH1D *phi_on = phi_score_on->ProjectionX("phi_on", i, bins);
      TH1D *ratio = (TH1D *)phi_on->Clone("ratio");
      ratio->Divide(phi_off);

      Plots::Histdispose hists;
      std::pair<double, double> minmax = hists.findGlobalMinMax({ratio});
      double ratio_value = (minmax.second - minmax.first) / 2.0;
      g_ratio->SetPoint(i - 1, scorecut, ratio_value);
      if (ratio_value > max_ratio)
      {
        max_ratio = ratio_value;
        max_ratio_scorecut = scorecut;
      }
      delete phi_off, phi_on, ratio;
    }
    cc_ratio->cd();
    g_ratio->GetYaxis()->SetTitle("Ratio");
    g_ratio->GetXaxis()->SetTitle("Score cut");
    g_ratio->Draw();

    TPaveText *paveText3 = new TPaveText(0.5, 0.8, 0.8, 0.95, "NDC");
    paveText3->AddText(TString::Format("max ratio = %.4f", max_ratio));
    paveText3->AddText(TString::Format("max ratio scorecut = %.4f", max_ratio_scorecut));
    paveText3->SetBorderSize(0);
    paveText3->SetFillColor(0);
    paveText3->SetFillStyle(0);
    paveText3->SetTextFont(42);
    paveText3->SetTextSize(0.035);
    paveText3->SetTextAlign(12);
    paveText3->Draw("same");

    cc_ratio->SaveAs(outputfolder + "/ratio_" + TPR + "_" + generator + ".pdf");
  }

  void DrawFrac(TString outputfolder = ".", TString generator = "herwig")
  {
    TH2D *phi_score_off, *phi_score_on;
    if (generator == "herwig")
    {
      phi_score_off = hists_private_train_herwig_off.phi_score;
      phi_score_on = hists_private_predict_herwig_on.phi_score;
    }
    else if (generator == "pythia")
    {
      phi_score_off = hists_private_predict_pythia_off.phi_score;
      phi_score_on = hists_private_predict_pythia_on.phi_score;
    }
    else
    {
      std::cerr << "Error: Do not support the input generator." << std::endl;
      return;
    }
    int bins = phi_score_on->GetYaxis()->GetNbins();
    double events_sum = phi_score_on->GetEntries();
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = phi_score_on->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_on = phi_score_on->ProjectionX("phi_on", i, bins);
      double events_frac = phi_on->GetEntries() * 1.0 / events_sum;
      double true_rate = hists_private_train_herwig_off.true_distribute->Integral(i, bins);
      g_event->SetPoint(i - 1, scorecut, events_frac);
      g_truefrac->SetPoint(i - 1, scorecut, true_rate);
    }

    cc_events->cd();
    g_event->GetYaxis()->SetRangeUser(0, 1);
    // cc_events2->SetLogy();
    g_event->GetXaxis()->SetLimits(0, 1);
    g_event->GetYaxis()->SetTitle("Events fraction");
    g_event->GetXaxis()->SetTitle("Score cut");
    g_event->Draw();

    g_truefrac->GetYaxis()->SetRangeUser(0, 1);
    g_truefrac->GetXaxis()->SetLimits(0, 1);
    g_truefrac->SetLineColor(kRed);
    g_truefrac->SetMarkerColor(kRed);
    g_truefrac->Draw("same");

    TLegend *leg = new TLegend(0.55, 0.8, 0.88, 0.88);
    leg->AddEntry(g_event, "all events fraction", "lq");
    leg->AddEntry(g_truefrac, TPR + " fraction", "lq");
    leg->SetBorderSize(0);
    leg->SetFillColorAlpha(0, 0);
    leg->SetTextFont(42);
    leg->SetTextSize(0.04);
    leg->Draw("same");

    cc_events->SaveAs(outputfolder + "/fraction_" + TPR + "_" + generator + ".pdf");
  }

  void Write(TString outputfolder = ".")
  {
    hists_private_predict_herwig_on.phi_score->SetName("phi_score_predict");
    hists_private_predict_herwig_on.phi_score->SetTitle("phi_score_predict");
    hists_private_train_herwig_off.phi_score->SetName("phi_score_train");
    hists_private_train_herwig_off.phi_score->SetName("phi_score_train");
  }

protected:
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
      area += dx * avgHeight;
    }
    double auc = std::abs(area);
    return auc;
  }
 
private:
  std::vector<double> weights = {1, 1, 1, 1};
  TString TPR = "qq";
  TString FPR = "noqq";
  TString validate = "all";
  TString privateMC_train_herwig_off_path = "";
  TString privateMC_predict_herwig_on_path = "";
  TString privateMC_predict_pythia_off_path = "";
  TString privateMC_predict_pythia_on_path = "";
  TString CMSMC_path = "";
  struct graphs_PrivateMC_train hists_private_train_herwig_off;
  struct graphs_PrivateMC_predict hists_private_predict_herwig_on, hists_private_predict_pythia_off, hists_private_predict_pythia_on;
  // struct graphs_CMSMC hists_cmsmc;

  TCanvas *cc_roc, *cc_chisquare, *cc_ratio, *cc_events, *cc_truefrac;
  TGraph *g, *g_chi, *g_ratio, *g_event, *g_truefrac;
  std::vector<double> true_rates, false_rates;
  double max_chi2 = -1.0;
  double max_ratio = -1.0;
  int max_chi2_bin = -1;
  double max_chi2_scorecut = -1.0;
  double max_ratio_scorecut = -1.0;
  int entries = -1;
};