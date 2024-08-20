// gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "TFile.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "include/AdvancedDataInfo.h"
#include "include/CMSJetsAndDaughters.h"
#include "include/Draw_Template.h"
#include "include/Hists.h"
#include "include/JetBranch.h"
#include "include/JetObservable.h"
#include "include/LoadData.h"
#include "include/ParticleInfo.h"
#include "include/Process_bar.h"
#include "include/RecoPlane.h"
#include "include/SampleAnalyzer.h"
#include "include/SaveData.h"
#include "include/TreeEvents.h"
#include "vector"
#include <getopt.h>
// g++ generate_sample_CMSMC.cpp -I/home/zlin/.local/include
// -I/home/zlin/app/IFNPlugin -L/home/zlin/app/IFNPlugin -L/home/zlin/.local/lib
// -lRecursiveTools -lIFNPlugin  `root-config --cflags --ldflags --glibs`
// `fastjet-config --cxxflags --libs --plugins`   -o generate_sample_CMSMC ;
// ./generate_sample_CMSMC
class EventsAnalyzer : public SampleAnalyzer<CMSJetsAndDaughters>
{
public:
    struct BranchVectors
    {
        std::vector<double> *Pt = new std::vector<double>;
        std::vector<double> *Eta = new std::vector<double>;
        std::vector<double> *Phi = new std::vector<double>;
        std::vector<double> *Energy = new std::vector<double>;
        std::vector<int> *PdgId = new std::vector<int>;
        std::vector<int> *Charge = new std::vector<int>;
        std::vector<double> *JetPt = new std::vector<double>;
        std::vector<double> *JetEta = new std::vector<double>;
        std::vector<double> *JetPhi = new std::vector<double>;
        std::vector<double> *JetE = new std::vector<double>;
        std::vector<int> *JetId = new std::vector<int>;
    };
    TreeEvents treeEvents;
    BranchVectors RecoBranches;
    BranchVectors GenBranches;
    vector<BranchVectors> Branches;
    vector<string> prefixs;
    string inputFolder;
    double NextPassedNumber;
    EventsAnalyzer(string _inputFolder) { inputFolder = _inputFolder; }
    void initialize() override
    {
        // t->Add("/home/public/Datasets/newherwig/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL16/Chunk*.root/jetInfos/JetsAndDaughters");
        // t->Add("/home/public/Datasets/newherwig/QCD_Pt-15to7000_Flat_herwig7-RunIISummer19UL16-preVFP/Chunk*.root/jetInfos/JetsAndDaughters");
        t->Add((TString)inputFolder + "/Chunk*.root/jetInfos/JetsAndDaughters");
        prefixs = {"Gen","Reco"};
        for (auto prefix : prefixs)
        {
            std::vector<std::string> branch_names = {
                "pt1", "eta1", "phi1", "e1", "ntracks1", "nparticles1", "pt2", "eta2", "phi2", "e2", "ntracks2",
                "nparticles2", "pt3", "eta3", "phi3", "e3", "ntracks3", "nparticles3", "pt4", "eta4", "phi4",
                "e4", "ntracks4", "nparticles4", "z1", "kt1", "theta1", "deltaR1", "eec1", "z2", "kt2", "theta2",
                "deltaR2", "eec2", "n1x", "n1y", "n1z", "n2x", "n2y", "n2z", "isqq", "isgg", "phi", "jpt", "jeta",
                "jphi", "je", "jes_scale", "particle1_pt", "particle1_eta", "particle1_phi", "particle1_e",
                "particle1_charge", "particle1_pid", "particle1_jetid", "particle2_pt", "particle2_eta",
                "particle2_phi", "particle2_e", "particle2_charge", "particle2_pid", "particle2_jetid",
                "particle3_pt", "particle3_eta", "particle3_phi", "particle3_e", "particle3_charge",
                "particle3_pid", "particle3_jetid", "particle4_pt", "particle4_eta", "particle4_phi",
                "particle4_e", "particle4_charge", "particle4_pid", "particle4_jetid"};
            for (auto &branch_name : branch_names)
            {
                if (branch_name == "isqq" || branch_name == "isgg" || branch_name == "ntracks1" ||
                    branch_name == "ntracks2" || branch_name == "ntracks3" || branch_name == "ntracks4" ||
                    branch_name == "nparticles1" || branch_name == "nparticles2" || branch_name == "nparticles3" ||
                    branch_name == "nparticles4" || branch_name == "particle1_pid" ||
                    branch_name == "particle1_jetid" || branch_name == "particle2_pid" ||
                    branch_name == "particle2_jetid" || branch_name == "particle3_pid" ||
                    branch_name == "particle3_jetid" || branch_name == "particle4_pid" ||
                    branch_name == "particle4_jetid")
                {
                    treeEvents.addBranches(prefix + branch_name + "/vI");
                }
                else
                {
                    treeEvents.addBranches(prefix + branch_name + "/vD");
                }
            }
        }
        treeEvents.addBranches("NextPassedNumber/D");
        treeEvents.addBranches("PassPileUpRm/I");
        treeEvents.addBranches("GeneratorWeight/D");
        treeEvents.addBranches("TriggerBits/vI");
        treeEvents.addBranches("TriggerPrescales/vD");
        treeEvents.addBranches("RecoJetMatching/vI");
        treeEvents.addBranches("GenJetMatching/vI");
    }
    void BranchAlias()
    {
        if (Branches.size() != 0)
            return;
        GenBranches.Charge = events->GenDaughterCharge;
        GenBranches.PdgId = events->GenDaughterPdgId;
        GenBranches.Pt = events->GenDaughterPt;
        GenBranches.Eta = events->GenDaughterEta;
        GenBranches.Phi = events->GenDaughterPhi;
        GenBranches.Energy = events->GenDaughterEnergy;
        GenBranches.JetPt = events->GenJetPt;
        GenBranches.JetEta = events->GenJetEta;
        GenBranches.JetPhi = events->GenJetPhi;
        GenBranches.JetE = events->GenJetEnergy;
        GenBranches.JetId = events->GenDaughterJetId;

        RecoBranches.Charge = events->RecoDaughterCharge;
        RecoBranches.PdgId = events->RecoDaughterPdgId;
        RecoBranches.Pt = events->RecoDaughterPt;
        RecoBranches.Eta = events->RecoDaughterEta;
        RecoBranches.Phi = events->RecoDaughterPhi;
        RecoBranches.Energy = events->RecoDaughterEnergy;
        RecoBranches.JetPt = events->RecoJetPt;
        RecoBranches.JetEta = events->RecoJetEta;
        RecoBranches.JetPhi = events->RecoJetPhi;
        RecoBranches.JetE = events->RecoJetEnergy;
        RecoBranches.JetId = events->RecoDaughterJetId;
        Branches = {GenBranches, RecoBranches};
    }
    void analyze() override
    {
        BranchAlias();
        treeEvents.BeginEvent();
        for(int i=0;i<events->RecoJetMatching->size();i++){
            treeEvents.push_back("RecoJetMatching",events->RecoJetMatching->at(i));
        }
        for(int i=0;i<events->GenJetMatching->size();i++){
            treeEvents.push_back("GenJetMatching",events->GenJetMatching->at(i));
        }
        treeEvents.assign("NextPassedNumber", events->NextPassedNumber);
        treeEvents.assign("GeneratorWeight", events->GeneratorWeight);
        treeEvents.assign("PassPileUpRm", passpileuprm());
        for(int i=0;i<events->TriggerBits->size();i++){
            int triggerbits=events->TriggerBits->at(i);
            treeEvents.push_back("TriggerBits",triggerbits);
            treeEvents.push_back("TriggerPrescales",events->TriggerPrescales->at(i));
        }
        int branchindex = 0;
        
        for (auto &Branch : Branches)
        {
            int jetnum = Branch.JetPt->size();
            int daughternum = Branch.JetId->size();
            vector<vector<ParticleInfo>> daughtersjets(jetnum, vector<ParticleInfo>());
            for (int i = 0; i < daughternum; i++)
            {
                int jetid = Branch.JetId->at(i);
                if(Branch.Pt->at(i)<=1) continue;
                daughtersjets.at(jetid).push_back(ParticleInfo(Branch.PdgId->at(i),
                                                               Branch.Charge->at(i),
                                                               Branch.Pt->at(i),
                                                               Branch.Eta->at(i),
                                                               Branch.Phi->at(i),
                                                               Branch.Energy->at(i)));
                TLorentzVector p;
                p.SetPtEtaPhiE(Branch.Pt->at(i), Branch.Eta->at(i), Branch.Phi->at(i), Branch.Energy->at(i));
            }
            for (int i = 0; i < daughtersjets.size(); i++)
            {
                auto daughtersjet = daughtersjets.at(i);
                auto planes = RecoPlane::JetConstituents(daughtersjet);
                planes.first.initJet.SetPtEtaPhiE( Branch.JetPt->at(i) * 1.0,Branch.JetEta->at(i) * 1.0,
                Branch.JetPhi->at(i) * 1.0,Branch.JetE->at(i) * 1.0);
                RecoPlane::SavePlanes(planes, treeEvents, i, prefixs.at(branchindex), "");
                double jes_scale = Branch.JetPt->at(i) * 1.0 / planes.first.initJet.Pt();
                treeEvents.push_back(prefixs.at(branchindex) + "jes_scale", jes_scale);
            }
            branchindex++;
        }
        
    }
    int passpileuprm()
    {
        int ispasspileuprm = 1;
        double genht = 0;
        for (int iparton = 0; iparton < events->GenPartonPt->size(); iparton++)
            genht += events->GenPartonPt->at(iparton);
        if (events->RecoJetPt->size() > 0)
        {
            if ((!events->RecoPassDijet && !events->GenPassDijet) || events->PileupMaxPtHat / genht > 1 ||
                events->RecoJetPt->at(0) / genht > 1)
            {
                ispasspileuprm = 0;
            }
        }
        return ispasspileuprm;
    }
};

int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv);
    EventsAnalyzer analyzer(options.inputFolder);
    CommonTool::processAndSaveData(options, analyzer);
    return 0;
}