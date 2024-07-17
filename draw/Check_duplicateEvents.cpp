#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "../include/Hists.h"
#include "../include/Process_bar.h"
#include "../include/Draw_Template.h"
#include <getopt.h>
#include "TDirectory.h"
#include "../include/CMSJetsAndDaughters.h"
void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void Check_duplicateEvents(){
    TChain * tchain = new TChain();

    tchain->Add("/home/public/Datasets/newherwig/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL16-preVFP/Chunk*.root/jetInfos/JetsAndDaughters");
    //tchain->Add("/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/CMS_herwig/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL18/Chunk*.root/jetInfos/JetsAndDaughters");
    
    CMSJetsAndDaughters events(tchain);
    for(int i=0;i<100000;i++){
        tchain->GetEntry(i);
        if(abs(events.GenJetPt->at(0)-541.843)<0.001){//16 preVFP
            cout<<events.LumiID<<" "<<events.EventID<<" "<<events.GenJetPt->at(0)<<" "<<events.GenJetEta->at(0)<<" "<<events.GenJetPhi->at(0)<<" "<<events.GenJetEnergy->at(0)<<" "<<events.RecoJetPt->at(0)<<" "<<events.RecoJetEta->at(0)<<" "<<events.RecoJetPhi->at(0)<<" "<<events.RecoJetEnergy->at(0)<<endl;
        }
        if(abs(events.GenJetPt->at(0)-505.989)<0.001){
            cout<<events.LumiID<<" "<<events.EventID<<" "<<events.GenJetPt->at(0)<<" "<<events.GenJetEta->at(0)<<" "<<events.GenJetPhi->at(0)<<" "<<events.GenJetEnergy->at(0)<<" "<<events.RecoJetPt->at(0)<<" "<<events.RecoJetEta->at(0)<<" "<<events.RecoJetPhi->at(0)<<" "<<events.RecoJetEnergy->at(0)<<endl;
        }
        
        //cout<<events.GenJetPt->at(0)<<" "<<events.GenJetEta->at(0)<<" "<<events.GenJetPhi->at(0)<<" "<<events.GenJetEnergy->at(0)<<endl;
    }
}
