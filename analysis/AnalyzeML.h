#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "draw/Draw.h"
#include "hists/GetChi2.h"
#include "hists/GetChi2Data.h"
#include "hists/GetChi2Nui.h"
#include "hists/GetChi2NuiData.h"
#include "hists/GetChi2Reweight.h"
#include "hists/GetFraction.h"
#include "hists/GetRatio.h"
#include "hists/GetRoc.h"

class AnalysisML
{
public:
  void DrawRoc(TH1D *input_true, TH1D *input_false, TString flavour, TString suffix, TString outputfolder)
  {
    GetRoc roc(input_true, input_false);
    TGraph graph_roc = roc.GetROC();
    double auc = roc.CalculateArea(&graph_roc);
    Draw draw_roc({&graph_roc});
    draw_roc.DrawGraph();
    draw_roc.SetXYTitle("False " + flavour + " rate", "True " + flavour + " rate");
    draw_roc.AddPave({TString::Format("AUC = %.4f", auc)}, 0.5, 0.1, 0.9, 0.3);
    draw_roc.SetYRange(0, 1);
    draw_roc.AddLine(0, 0, 1, 1);
    draw_roc.Write(outputfolder + "/roc_" + flavour + suffix + ".pdf");
  }

  void DrawChi2(TH2D *pythia_phi_score_off, TH2D *pythia_phi_score_on,
                TH2D *herwig_phi_score_off, TH2D *herwig_phi_score_on,
                TString flavour, TString suffix, TString outputfolder)
  {
    GetChi2 chi2_pythia(pythia_phi_score_off, pythia_phi_score_on);
    TGraph graph_pythia = chi2_pythia.Chi2_scan();
    std::vector<TH1D *> phis_pythia = chi2_pythia.Chi2_max();
    std::vector<TString> paves_pythia = chi2_pythia.Chi2_pave("pythia");
    Plots::Plotratio plot1(phis_pythia);
    plot1.Draw();
    plot1.SetXRatioTitle("#varphi");
    plot1.AddChisquare();
    plot1.Write(outputfolder + "/chi2_max_pythia_" + flavour + suffix + ".pdf");

    GetChi2 chi2_herwig(herwig_phi_score_off, herwig_phi_score_on);
    TGraph graph_herwig = chi2_herwig.Chi2_scan();
    std::vector<TH1D *> phis_herwig = chi2_herwig.Chi2_max();
    std::vector<TString> paves_herwig = chi2_herwig.Chi2_pave("herwig");
    Plots::Plotratio plot2(phis_herwig);
    plot2.Draw();
    plot2.SetXRatioTitle("#varphi");
    plot2.AddChisquare();
    plot2.Write(outputfolder + "/chi2_max_herwig_" + flavour + suffix + ".pdf");

    GetChi2Nui chi2_off(herwig_phi_score_off, herwig_phi_score_on, pythia_phi_score_off, pythia_phi_score_on);
    TGraph graph_off = chi2_off.Chi2_scan("off");
    chi2_off.Chi2_max(outputfolder + "/chi2_nuisance_max_off_" + flavour + suffix + ".root", "off");
    std::vector<TString> paves_off = chi2_off.Chi2_pave("nuisance off");

    GetChi2Nui chi2_on(herwig_phi_score_off, herwig_phi_score_on, pythia_phi_score_off, pythia_phi_score_on);
    TGraph graph_on = chi2_on.Chi2_scan("on");
    chi2_on.Chi2_max(outputfolder + "/chi2_nuisance_max_on_" + flavour + suffix + ".root", "on");
    std::vector<TString> paves_on = chi2_on.Chi2_pave("nuisance on");

    Draw draw({&graph_herwig, &graph_pythia, &graph_off, &graph_on});
    draw.DrawGraph();
    draw.SetXYTitle("Score cut", "Chi2");
    draw.AddLegend({"Private herwig", "Private pythia", "nuisance off", "nuisance on"}, 0.68, 0.8, 0.92, 0.92);
    // draw.AddPave({paves_herwig.at(0), paves_herwig.at(1), paves_herwig.at(2),
    //               paves_pythia.at(0), paves_pythia.at(1), paves_pythia.at(2),
    //               paves_off.at(0), paves_off.at(1), paves_off.at(2),
    //               paves_on.at(0), paves_on.at(1), paves_on.at(2)},
    //              0.66, 0.3, 0.9, 0.6, 0.025);
    draw.AddPave({paves_herwig.at(0), paves_herwig.at(2), paves_pythia.at(0), paves_pythia.at(2),
                  paves_off.at(0), paves_off.at(2), paves_on.at(0), paves_on.at(2)},
                 0.7, 0.4, 0.92, 0.6, 0.025);
    draw.Write(outputfolder + "/chi2_scan_" + flavour + suffix + ".pdf");
  }

  void DrawRatio(TH2D *pythia_phi_score_off, TH2D *pythia_phi_score_on,
                 TH2D *herwig_phi_score_off, TH2D *herwig_phi_score_on,
                 TString flavour, TString suffix, TString outputfolder)
  {
    GetRatio ratio1(pythia_phi_score_off, pythia_phi_score_on);
    TGraph graph1 = ratio1.Ratio_scan();
    GetRatio ratio2(herwig_phi_score_off, herwig_phi_score_on);
    TGraph graph2 = ratio2.Ratio_scan();

    Draw draw({&graph2, &graph1});
    draw.DrawGraph();
    draw.SetAutoRange();
    draw.SetXYTitle("Score cut", "Ratio amplitude");
    draw.AddLegend({"herwig", "pythia"}, 0.7, 0.8, 0.9, 0.88);
    // draw.AddLine(0, 0, 1, 0);
    draw.Write(outputfolder + "/ratio_" + flavour + suffix + ".pdf");
  }

  void DrawFrac(TH2D *pythia_phi_score_off, TH2D *pythia_phi_score_on,
                TH2D *herwig_phi_score_off, TH2D *herwig_phi_score_on,
                TString flavour, TString suffix, TString outputfolder)
  {
    GetFraction frac1(pythia_phi_score_off, pythia_phi_score_on);
    TGraph graph1 = frac1.Fraction_scan();
    GetFraction frac2(herwig_phi_score_off, herwig_phi_score_on);
    TGraph graph2 = frac2.Fraction_scan();

    Draw draw({&graph2, &graph1});
    draw.DrawGraph();
    draw.SetXYTitle("Score cut", "Events fraction");
    draw.SetYRange(0, 1);
    draw.AddLegend({"herwig", "pythia"}, 0.7, 0.8, 0.9, 0.88);
    draw.AddLine(0, 0, 1, 0);
    draw.Write(outputfolder + "/fraction_" + flavour + suffix + ".pdf");
  }

  void DrawModel(TH2D *pythia_phi_score_off, TH2D *pythia_phi_score_on,
                 TH2D *herwig_phi_score_off, TH2D *herwig_phi_score_on,
                 TString flavour, TString suffix, TString outputfolder)
  {
    GetChi2 chi2_model_off(herwig_phi_score_off, pythia_phi_score_off);
    TGraph graph_model_off = chi2_model_off.Chi2_scan();
    GetChi2 chi2_model_on(herwig_phi_score_on, pythia_phi_score_on);
    TGraph graph_model_on = chi2_model_on.Chi2_scan();
    Draw draw_model({&graph_model_off, &graph_model_on});
    draw_model.DrawGraph();
    draw_model.SetXYTitle("Score cut", "Chi2");
    draw_model.AddPave({"Herwig & Pythia", "difference"}, 0.7, 0.3, 0.9, 0.4);
    draw_model.AddLegend({"spin off", "spin on"}, 0.7, 0.7, 0.9, 0.8);
    draw_model.Write(outputfolder + "/chi2_model_" + flavour + suffix + ".pdf");

    GetRatio ratio_model_off(herwig_phi_score_off, pythia_phi_score_off);
    TGraph graph_ratio_off = ratio_model_off.Ratio_scan();
    GetRatio ratio_model_on(herwig_phi_score_on, pythia_phi_score_on);
    TGraph graph_ratio_on = ratio_model_on.Ratio_scan();
    Draw draw_ratio({&graph_ratio_off, &graph_ratio_on});
    draw_ratio.DrawGraph();
    draw_ratio.SetXYTitle("Score cut", "Ratio amplitude");
    draw_ratio.AddPave({"Herwig & Pythia", "difference"}, 0.7, 0.3, 0.9, 0.4);
    draw_ratio.AddLegend({"spin off", "spin on"}, 0.7, 0.7, 0.9, 0.8);
    draw_ratio.Write(outputfolder + "/ratio_model_" + flavour + suffix + ".pdf");
  }

  void DrawChi2Data(TH2D *pythia_phi_score_off, TH2D *pythia_phi_score_on,
                    TH2D *herwig_phi_score_off, TH2D *herwig_phi_score_on,
                    TH2D *data_phi_score, TString flavour, TString suffix, TString outputfolder)
  {
    GetChi2Data chi2_pythia(pythia_phi_score_off, pythia_phi_score_on, data_phi_score);
    TGraph graph_pythia = chi2_pythia.Chi2_scan();
    std::vector<TH1D *> phis_pythia = chi2_pythia.Chi2_max();
    std::vector<TString> paves_pythia = chi2_pythia.Chi2_pave("pythia");
    Plots::Plotratio plot1(phis_pythia);
    plot1.Draw();
    plot1.SetXRatioTitle("#varphi");
    plot1.AddChisquare();
    plot1.Write(outputfolder + "/chi2data_max_pythia_" + flavour + suffix + ".pdf");

    GetChi2Data chi2_herwig(herwig_phi_score_off, herwig_phi_score_on, data_phi_score);
    TGraph graph_herwig = chi2_herwig.Chi2_scan();
    std::vector<TH1D *> phis_herwig = chi2_herwig.Chi2_max();
    std::vector<TString> paves_herwig = chi2_herwig.Chi2_pave("herwig");
    Plots::Plotratio plot2(phis_herwig);
    plot2.Draw();
    plot2.SetXRatioTitle("#varphi");
    plot2.AddChisquare();
    plot2.Write(outputfolder + "/chi2data_max_herwig_" + flavour + suffix + ".pdf");

    GetChi2NuiData chi2_off(herwig_phi_score_off, herwig_phi_score_on, pythia_phi_score_off, pythia_phi_score_on, data_phi_score);
    TGraph graph_off = chi2_off.Chi2_scan("off");
    chi2_off.Chi2_max(outputfolder + "/chi2data_nuisance_max_off_" + flavour + suffix + ".root", "off");
    std::vector<TString> paves_off = chi2_off.Chi2_pave("nuisance off");

    GetChi2NuiData chi2_on(herwig_phi_score_off, herwig_phi_score_on, pythia_phi_score_off, pythia_phi_score_on, data_phi_score);
    TGraph graph_on = chi2_on.Chi2_scan("on");
    chi2_on.Chi2_max(outputfolder + "/chi2data_nuisance_max_on_" + flavour + suffix + ".root", "on");
    std::vector<TString> paves_on = chi2_on.Chi2_pave("nuisance on");

    Draw draw({&graph_herwig, &graph_pythia, &graph_off, &graph_on});
    draw.DrawGraph();
    draw.SetXYTitle("Score cut", "Chi2");
    draw.AddLegend({"Private herwig", "Private pythia", "nuisance off", "nuisance on"}, 0.68, 0.8, 0.92, 0.92);
    // draw.AddPave({paves_herwig.at(0), paves_herwig.at(1), paves_herwig.at(2),
    //               paves_pythia.at(0), paves_pythia.at(1), paves_pythia.at(2),
    //               paves_off.at(0), paves_off.at(1), paves_off.at(2),
    //               paves_on.at(0), paves_on.at(1), paves_on.at(2)},
    //              0.66, 0.3, 0.9, 0.6, 0.025);
    draw.AddPave({paves_herwig.at(0), paves_herwig.at(2), paves_pythia.at(0), paves_pythia.at(2),
                  paves_off.at(0), paves_off.at(2), paves_on.at(0), paves_on.at(2)},
                 0.7, 0.4, 0.92, 0.6, 0.025);
    draw.Write(outputfolder + "/chi2data_scan_" + flavour + suffix + ".pdf");
  }

  void DrawReweight(TH2D *CMS_MC, TString CMS_MC_reweight_path, TH2D *data_phi_score,
                    TString flavour, TString suffix, TString outputfolder)
  {
    GetChi2Reweight chi2(CMS_MC, CMS_MC_reweight_path);
    TGraph graph = chi2.Chi2_scan();
    Draw draw({&graph});
    draw.DrawGraph();
    draw.Write(outputfolder + "/chi2data_CMSMC_scan_" + flavour + suffix + ".pdf");
  }
};