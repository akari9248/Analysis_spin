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
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <algorithm>
#include <cassert>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>
using namespace fastjet;
using namespace std;

class EventsAnalyzer : public SampleAnalyzer<EmptyTree>{
public:
    struct BranchVectors
    {
        std::vector<double> *Pt = new std::vector<double>;
        std::vector<double> *Eta = new std::vector<double>;
        std::vector<double> *Phi = new std::vector<double>;
        std::vector<double> *Energy = new std::vector<double>;
        std::vector<int> *PdgId = new std::vector<int>;
        std::vector<double> *Charge = new std::vector<double>;
    };
    TreeEvents treeEvents;
    BranchVectors PartonBranches;
    BranchVectors HadronBranches;
    vector<BranchVectors> Branches;
    vector<string> suffixs;
    string inputFolder;
    CommonTool::Options options;

    EventsAnalyzer(CommonTool::Options _options) { options = _options; }
    void initialize() override
    {
        for (int i = 1; i <= 100; ++i)
        {
          t->Add((TString)options.inputFolder +
                     Form("chunk%d/*.root/JetsAndDaughters",
                 i));
          t->Add(Form(
              (TString)options.inputFolder +
              "Chunk%d/Part_pt450_-1_Ak8.root/JetsAndDaughters",
              i));
        }
        suffixs = {"_Parton", "_Hadron"};
        for (auto suffix : suffixs)
        {
            std::vector<std::string> branch_names = {
                "pt1", "eta1", "phi1", "e1", "ntracks1", "nparticles1","flavour1",
                "pt2", "eta2", "phi2", "e2", "ntracks2", "nparticles2","flavour2",
                "pt3", "eta3", "phi3", "e3", "ntracks3", "nparticles3","flavour3",
                "pt4", "eta4", "phi4", "e4", "ntracks4", "nparticles4","flavour4",
                "pt5", "eta5", "phi5", "e5", "ntracks5", "nparticles5","flavour5",
                "pt6", "eta6", "phi6", "e6", "ntracks6", "nparticles6","flavour6",
                "z1", "kt1", "theta1", "deltaR1", "eec1", 
                "z2", "kt2", "theta2","deltaR2", "eec2",
                "z3", "kt3", "theta3","deltaR3", "eec3", 
                "n1x", "n1y","n1z", "n2x", "n2y", "n2z", "n3x", "n3y", "n3z", 
                "isqq", "isgg", "isqq2", "isgg2", "phi", "thirdphi", 
                "jpt", "jeta","jphi", "je", "jes_scale", 
                "particle1_pt", "particle1_eta", "particle1_phi", "particle1_e","particle1_charge", "particle1_pid", "particle1_jetid", 
                "particle2_pt", "particle2_eta","particle2_phi", "particle2_e", "particle2_charge", "particle2_pid", "particle2_jetid",
                "particle3_pt", "particle3_eta", "particle3_phi", "particle3_e", "particle3_charge","particle3_pid", "particle3_jetid", 
                "particle4_pt", "particle4_eta", "particle4_phi", "particle4_e", "particle4_charge", "particle4_pid", "particle4_jetid",
                "particle5_pt", "particle5_eta", "particle5_phi", "particle5_e","particle5_charge", "particle5_pid", "particle5_jetid", 
                "particle6_pt", "particle6_eta","particle6_phi", "particle6_e", "particle6_charge", "particle6_pid", "particle6_jetid",};
            for (auto &branch_name : branch_names)
            {
                if (branch_name == "isqq" || branch_name == "isgg" || branch_name == "isqq2" || branch_name == "isgg2" ||
                    branch_name == "ntracks1" ||branch_name == "ntracks2" || branch_name == "ntracks3" || branch_name == "ntracks4" || 
                    branch_name == "ntracks5" ||branch_name == "ntracks6" || 
                    branch_name == "nparticles1" || branch_name == "nparticles2" || branch_name == "nparticles3" || branch_name == "nparticles4" || 
                    branch_name == "nparticles5" || branch_name == "nparticles6" || 
                    branch_name == "flavour1" || branch_name == "flavour2" || branch_name == "flavour3" || branch_name == "flavour4" || 
                    branch_name == "flavour5" || branch_name == "flavour6" || 
                    branch_name == "particle1_pid" || branch_name == "particle1_jetid" || 
                    branch_name == "particle2_pid" || branch_name == "particle2_jetid" || 
                    branch_name == "particle3_pid" || branch_name == "particle3_jetid" || 
                    branch_name == "particle4_pid" || branch_name == "particle4_jetid" ||
                    branch_name == "particle5_pid" || branch_name == "particle5_jetid" ||
                    branch_name == "particle6_pid" || branch_name == "particle6_jetid")
                {
                    treeEvents.addBranches( branch_name+suffix + "/vI");
                }
                else
                {
                    treeEvents.addBranches( branch_name+suffix + "/vD");
                }
            }
        }
        treeEvents.addBranches("match2/vI");
        treeEvents.addBranches("match3/vI");
        treeEvents.addBranches("PassPileUpRm/I");
        treeEvents.addBranches("GeneratorWeight/D");
        BranchAssignment();
    }
    void BranchAssignment()
    {
        t->SetBranchAddress("Pt_Parton" , &PartonBranches.Pt);
        t->SetBranchAddress("Eta_Parton",  &PartonBranches.Eta);
        t->SetBranchAddress("Phi_Parton",  &PartonBranches.Phi);
        t->SetBranchAddress("Energy_Parton", &PartonBranches.Energy);
        t->SetBranchAddress("PdgId_Parton", &PartonBranches.PdgId);
        t->SetBranchAddress("Charge_Parton", &PartonBranches.Charge);

        t->SetBranchAddress("Pt_Hadron" , &HadronBranches.Pt);
        t->SetBranchAddress("Eta_Hadron",  &HadronBranches.Eta);
        t->SetBranchAddress("Phi_Hadron",  &HadronBranches.Phi);
        t->SetBranchAddress("Energy_Hadron", &HadronBranches.Energy);
        t->SetBranchAddress("PdgId_Hadron", &HadronBranches.PdgId);
        t->SetBranchAddress("Charge_Hadron", &HadronBranches.Charge);

        Branches = {PartonBranches, HadronBranches};
    }
    void analyze() override
    {
        treeEvents.BeginEvent();
        treeEvents.assign("GeneratorWeight", 1.0);
        treeEvents.assign("PassPileUpRm",1);
        int branchindex = 0;
        vector<std::vector<JetBranch::threeplanes>> Parton_planes(1,std::vector<JetBranch::threeplanes>());
        vector<std::vector<JetBranch::threeplanes>> Hadron_planes(1,std::vector<JetBranch::threeplanes>());
        std::vector<std::vector<std::vector<JetBranch::threeplanes>>> planes_arr = {Parton_planes, Hadron_planes};
        for (auto &branchvector : Branches)
        {
            std::vector<PseudoJet> particles;
            std::vector<ParticleInfo> particlesinfo;
            for (size_t i = 0; i < branchvector.Pt->size(); ++i) {
                TLorentzVector p;
                p.SetPtEtaPhiE(branchvector.Pt->at(i), branchvector.Eta->at(i),
                                branchvector.Phi->at(i), branchvector.Energy->at(i));
                PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
                int pdgid = branchvector.PdgId->at(i);
                int charge=branchvector.Charge->at(i);
                ParticleInfo particleInfo(pdgid, charge,branchvector.Pt->at(i), branchvector.Eta->at(i),
                                branchvector.Phi->at(i), branchvector.Energy->at(i));
                particlesinfo.push_back(particleInfo);
                particle.set_user_index(i);
                particle.set_user_info(new FlavHistory(branchvector.PdgId->at(i)));
                particles.push_back(particle);
            }
            JetDefinition jet_def(antikt_algorithm, 0.4); 
            ClusterSequence cs(particles, jet_def);
            std::vector<PseudoJet> jets = cs.inclusive_jets(30); 

            auto new_end =
                std::remove_if(jets.begin(), jets.end(), [](const PseudoJet &jet) {
                return std::abs(jet.eta()) > 2.5;
                });
            jets.erase(new_end, jets.end());
            int jetnum=jets.size();
            vector<vector<ParticleInfo>> daughtersjets(jetnum, vector<ParticleInfo>());
            for (int i = 0; i < jetnum; i++)
            {
                for(auto &particle : jets.at(i).constituents()){
                    int user_index = particle.user_index();
                    daughtersjets.at(i).push_back(particlesinfo.at(user_index));
                    TLorentzVector p;
                    p.SetPtEtaPhiE(particle.pt(), particle.eta(), particle.phi(), particle.e());
                }
            }
            for (int i = 0; i < daughtersjets.size(); i++)
            {
                auto daughtersjet = daughtersjets.at(i);
                auto planes = RecoPlane::JetConstituents_threeplanes(daughtersjet);
                AssignFlavour(planes);
                planes_arr.at(branchindex).at(0).push_back(planes);
            }
            branchindex++;
        }
        auto match = JetBranch::matchPlanes(planes_arr.at(1),planes_arr.at(0),"second", 0.5);
        branchindex=0;
        for(auto &branchvector : Branches){
            for (int i = 0; i < planes_arr.at(branchindex).at(0).size(); i++)
            {
                auto planes = planes_arr.at(branchindex).at(0).at(i);
                RecoPlane::SavePlanes(planes, treeEvents, i, "", suffixs.at(branchindex));
                double jes_scale = 1;
                treeEvents.push_back("jes_scale"+suffixs.at(branchindex), jes_scale);
            }
            branchindex++;
        }
        for(auto &match_info:match.first.at(0)){
            treeEvents.push_back("match2", match_info);
        }
        for(auto &match_info:match.second.at(0)){
            treeEvents.push_back("match3", match_info);
        }
    }
    void AssignFlavour(JetBranch::threeplanes &planes)
    {
        int pdgid11 = JetBranch::GetIFNFlavour(planes.first.harder);
        int pdgid12 = JetBranch::GetIFNFlavour(planes.first.softer);
        int pdgid21 = JetBranch::GetIFNFlavour(planes.second.harder);
        int pdgid22 = JetBranch::GetIFNFlavour(planes.second.softer);
        int pdgid31 = JetBranch::GetIFNFlavour(planes.third.harder);
        int pdgid32 = JetBranch::GetIFNFlavour(planes.third.softer);
        
        bool isqq = JetBranch::isqq(pdgid21, pdgid22, pdgid12);
        bool isgg = JetBranch::isgg(pdgid21, pdgid22, pdgid12);

        bool isqq2 = JetBranch::isqq(pdgid31, pdgid32, pdgid11);
        bool isgg2 = JetBranch::isgg(pdgid31, pdgid32, pdgid11);

        planes.first.isqq = JetBranch::isqq(pdgid11, pdgid12);
        planes.first.isgg = JetBranch::isgg(pdgid11, pdgid12);
        planes.second.isqq = JetBranch::isqq(pdgid21, pdgid22);
        planes.second.isgg = JetBranch::isgg(pdgid21, pdgid22);
        planes.third.isqq = JetBranch::isqq(pdgid31, pdgid32);
        planes.third.isgg = JetBranch::isgg(pdgid31, pdgid32);

        planes.first.harder_flav= pdgid11;
        planes.first.softer_flav= pdgid12;
        planes.second.harder_flav= pdgid21;
        planes.second.softer_flav= pdgid22;
        planes.third.harder_flav= pdgid31;
        planes.third.softer_flav= pdgid32;
    }
};
int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv);
    EventsAnalyzer analyzer(options);
    CommonTool::processAndSaveData(options, analyzer);
    return 0;
}