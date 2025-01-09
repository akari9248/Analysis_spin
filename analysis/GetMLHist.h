#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "base/Base_PrivateMC_train.h"
#include "base/Base_PrivateMC_predict.h"
#include "base/Base_CMSMC.h"
#include "base/Base_CMSData.h"

class GetMLHists
{
public:
  // GetMLHists() {}

  void SetWeight(std::vector<double> input_weights_qq, std::vector<double> input_weights_gg)
  {
    weights_qq = input_weights_qq;
    weights_gg = input_weights_gg;
  }

  void SetEntries(int input)
  {
    entries = input;
  }

  graphs_PrivateMC_train GetHists_PrivateMC_train_herwig_off(TString input_path)
  {
    std::cout << "Analyzing Private herwig off train sample ......" << std::endl;
    PrivateMC_herwig_off_path = input_path;
    Base_PrivateMC_train train(PrivateMC_herwig_off_path);
    train.SetWeight(weights_qq, weights_gg);
    hists_PrivateMC_train_herwig_off = train.GetBaseHist(entries);
    return hists_PrivateMC_train_herwig_off;
  }

  graphs_PrivateMC_predict GetHists_PrivateMC_predict_herwig_on(TString input_path)
  {
    std::cout << "Analyzing Private herwig on predict sample ......" << std::endl;
    PrivateMC_herwig_on_path = input_path;
    Base_PrivateMC_predict predict(PrivateMC_herwig_on_path);
    predict.SetWeight(weights_qq, weights_gg);
    hists_PrivateMC_predict_herwig_on = predict.GetBaseHist(entries);
    return hists_PrivateMC_predict_herwig_on;
  }

  graphs_PrivateMC_predict GetHists_PrivateMC_predict_pythia_off(TString input_path)
  {
    std::cout << "Analyzing Private pythia off predict sample ......" << std::endl;
    PrivateMC_pythia_off_path = input_path;
    Base_PrivateMC_predict predict(PrivateMC_pythia_off_path);
    predict.SetWeight(weights_qq, weights_gg);
    hists_PrivateMC_predict_pythia_off = predict.GetBaseHist(entries);
    return hists_PrivateMC_predict_pythia_off;
  }

  graphs_PrivateMC_predict GetHists_PrivateMC_predict_pythia_on(TString input_path)
  {
    std::cout << "Analyzing Private pythia on predict sample ......" << std::endl;
    PrivateMC_pythia_on_path = input_path;
    Base_PrivateMC_predict predict(PrivateMC_pythia_on_path);
    predict.SetWeight(weights_qq, weights_gg);
    hists_PrivateMC_predict_pythia_on = predict.GetBaseHist(entries);
    return hists_PrivateMC_predict_pythia_on;
  }

  graphs_CMSMC GetHists_CMSMC_predict_herwig(TString input_path)
  {
    std::cout << "Analyzing CMS herwig predict sample ......" << std::endl;
    CMSMC_herwig_path = input_path;
    Base_CMSMC cmsmc(CMSMC_herwig_path);
    cmsmc.SetWeight(weights_qq, weights_gg);
    hists_CMSMC_herwig = cmsmc.GetBaseHist(entries);
    return hists_CMSMC_herwig;
  }

  graphs_CMSMC GetHists_CMSMC_predict_pythia(TString input_path)
  {
    std::cout << "Analyzing CMS pythia predict sample ......" << std::endl;
    CMSMC_pythia_path = input_path;
    Base_CMSMC cmsmc(CMSMC_pythia_path);
    cmsmc.SetWeight(weights_qq, weights_gg);
    hists_CMSMC_pythia = cmsmc.GetBaseHist(entries);
    return hists_CMSMC_pythia;
  }

  graphs_CMSData GetHists_CMSData_predict(TString input_path)
  {
    std::cout << "Analyzing CMS data sample ......" << std::endl;
    CMSData_path = input_path;
    Base_CMSData cmsdata(CMSData_path);
    cmsdata.SetWeight(weights_qq, weights_gg);
    hists_CMSData = cmsdata.GetBaseHist(entries);
    return hists_CMSData;
  }

private:
  graphs_PrivateMC_predict hists_PrivateMC_predict_herwig_on, hists_PrivateMC_predict_pythia_on, hists_PrivateMC_predict_pythia_off;
  graphs_PrivateMC_train hists_PrivateMC_train_herwig_off;
  graphs_CMSMC hists_CMSMC_pythia, hists_CMSMC_herwig;
  graphs_CMSData hists_CMSData;

  TString PrivateMC_herwig_on_path = "";
  TString PrivateMC_herwig_off_path = "";
  TString PrivateMC_pythia_on_path = "";
  TString PrivateMC_pythia_off_path = "";
  TString CMSMC_herwig_path = "";
  TString CMSMC_pythia_path = "";
  TString CMSData_path = "";

  std::vector<double> weights_qq = {1, 1, 1, 1};
  std::vector<double> weights_gg = {1, 1, 1, 1};
  int entries = -1;
};