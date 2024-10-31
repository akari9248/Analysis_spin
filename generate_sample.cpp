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
#include "include/MetaDataManager.h"
#include "include/Selection.h"
#include "TLeaf.h"
using namespace fastjet;
using namespace std;

class EventsAnalyzer : public SampleAnalyzer<CMSJetsAndDaughters>{
public:
    struct BranchVectors
    {
        std::vector<double> *Pt = new std::vector<double>;
        std::vector<double> *Eta = new std::vector<double>;
        std::vector<double> *Phi = new std::vector<double>;
        std::vector<double> *Energy = new std::vector<double>;
        std::vector<int> *PdgId = new std::vector<int>;
        std::vector<int> *Charge = new std::vector<int>;
        std::vector<double> *Charge_d = new std::vector<double>;

        std::vector<int> *JetId = new std::vector<int>;
        std::vector<double> *JetPt = new std::vector<double>;
        std::vector<double> *JetEta = new std::vector<double>;
        std::vector<double> *JetPhi = new std::vector<double>;
        std::vector<double> *JetEnergy = new std::vector<double>;
        std::vector<int> *JetMatching = new std::vector<int>;
         
    };
    struct JetAndDaughters{
        TLorentzVector jet;
        std::vector<ParticleInfo> daughters;
    };
    struct PrefixAndSuffix{
        string prefix;
        string suffix;
        PrefixAndSuffix(const string& pref, const string& suff) 
        : prefix(pref), suffix(suff) {}
    };
    TreeEvents treeEvents;
    vector<BranchVectors> Branches;
    vector<string> prefixs;
    vector<string> suffixs;
    string inputFolder;
    CommonTool::Options options;
    MetaDataManager metadata;
    MetaData* md;
    Selection EventSelection;
    Selection JetSelection;
    Selection PlaneSelection;
    Selection ParticleSelection;
    Selection BranchSelection;
    string SampleType="PrivateMC";
    bool charge_d=false;
    vector<PrefixAndSuffix> level;
    std::pair<std::vector<std::vector<Int_t>>, std::vector<std::vector<Int_t>>> match;
    std::vector<std::vector<EventsAnalyzer::JetAndDaughters>>  levelsjetsdaughters;  
    std::vector<std::vector<std::vector<JetBranch::threeplanes>>> planes_arr;
    bool SaveParticles = false;
    Hists weightcut;
    Hists pileupweight;
    //todo: Add particle selection (1. Particle Energy scale )
    //todo: Add Jet selection (for systematic JES and JER )
    //todo: Save more eventsweight for systematic
    EventsAnalyzer(CommonTool::Options _options)
    {
        options = _options;
        md = metadata.CreateMetaData(options.executablefile);
        EventSelection = Selection("EventSelection");
        JetSelection = Selection("JetSelection");
        ParticleSelection = Selection("ParticleSelection");
        PlaneSelection = Selection("PlaneSelection");
        BranchSelection = Selection("BranchSelection");
        md->AddParameter("IO Paramter", "Input Folder = " + options.inputFolder);
        md->AddParameter("IO Paramter", "Output Folder = " + options.outputFolder);
    }
    void initialize() override
    {
        InitSampleType();
        InitAnalyzeBranch();
        InitEventSelection();
        InitJetSelection();
        InitParticleSelection();
        InitPlaneSelection();
        InitOutputBranch();
        InitBranchSelection();
    }
    void analyze() override
    {
        DeriveLevelsJetsDaughters();
        if (!EventSelection.Evaluate()) return;
        ParticleSelection.Evaluate();
        JetSelection.Evaluate();
        RecoSplitPlanes();
        PlaneSelection.Evaluate();
        MatchPlanes();
        treeEvents.BeginEvent();
        SavePlanes();
        BranchSelection.Evaluate();
    }
    void DeriveLevelsJetsDaughters(){
        levelsjetsdaughters.clear();
        for (auto &branchvector : Branches)
        {
            auto jetsdaughters = DeriveJetsDaughtersSampleType(branchvector);
            levelsjetsdaughters.push_back(jetsdaughters);
        }
    }
    void RecoSplitPlanes()
    {
        planes_arr = std::vector<std::vector<std::vector<JetBranch::threeplanes>>>(
            level.size(), vector<std::vector<JetBranch::threeplanes>>(
                              1, std::vector<JetBranch::threeplanes>()));
        for(int level=0;level<levelsjetsdaughters.size();level++)
        {
            auto jetsdaughters = levelsjetsdaughters.at(level);
            for (int i = 0; i < jetsdaughters.size(); i++)
            {
                auto jetdaughters = jetsdaughters.at(i).daughters;
                auto planes = RecoPlane::JetConstituents_threeplanes(jetdaughters);
                planes.first.initJet=jetsdaughters.at(i).jet;
                planes.second.initJet=jetsdaughters.at(i).jet;
                planes.third.initJet=jetsdaughters.at(i).jet;
                AssignFlavour(planes);
                planes_arr.at(level).at(0).push_back(planes);
            }
        }
        AssignMatchedThreePlanes();
    }
    void AssignMatchedThreePlanes(){
        if(SampleType == "CMSMCGen"){
            for(int level=0;level<planes_arr.size();level++)
            {
                for (int i = 0; i < planes_arr.at(level).at(0).size(); i++)
                {
                    int matchindex = Branches.at(level).JetMatching->at(i);
                    if(matchindex!=-1){
                        planes_arr.at(level).at(0).at(i).ismatched = true;
                        planes_arr.at(planes_arr.size() - level -1).at(0).at(matchindex).ismatched = true;
                        planes_arr.at(level).at(0).at(i).matchedthreeplanes = planes_arr.at(planes_arr.size() - level -1).at(0).at(matchindex).Getpseudothreeplanes();
                        
                    }else{
                        planes_arr.at(level).at(0).at(i).matchedthreeplanes = JetBranch::pseudothreeplanes();
                    }
                }
            }
        }
    }
    void MatchPlanes(){
        if(SampleType != "CMSData")
            match = JetBranch::matchPlanes(planes_arr.at(1),planes_arr.at(0),"second", 0.5);
    }
    void SavePlanes(){
        for(int levelindex=0;levelindex<level.size();levelindex++){
            for (int i = 0; i < planes_arr.at(levelindex).at(0).size(); i++)
            {
                auto planes = planes_arr.at(levelindex).at(0).at(i);
                RecoPlane::SavePlanes(planes, treeEvents, i, level.at(levelindex).prefix, level.at(levelindex).suffix,SaveParticles);
            }
        }
        treeEvents.assign("GeneratorWeight",1.0);
        if (SampleType != "CMSData")
        {
            for (int i = 0; i < match.first.at(0).size(); i++)
            {
                treeEvents.push_back("match2", match.first.at(0).at(i));
                treeEvents.push_back("match3", match.second.at(0).at(i));
            }
        }
        if (SampleType == "CMSMCGen")
        {
            for (int levelindex = 0; levelindex < level.size(); levelindex++)
            {
                if (level.at(levelindex).prefix == "Gen")
                {
                    for (auto &plane : planes_arr.at(levelindex).at(0))
                    {
                        treeEvents.push_back("MatchedRecoPhi", plane.matchedthreeplanes.deltaPhi);
                    }
                }
            }
        }
        if(options.inputFolder.find("JetHT") == std::string::npos){
            treeEvents.assign("GeneratorWeight",events->GeneratorWeight);
        }
    }
    std::vector<EventsAnalyzer::JetAndDaughters> DeriveJetsDaughtersSampleType(EventsAnalyzer::BranchVectors &branchvector)
    {
        if (SampleType == "PrivateMC") return ClusterJetsAndDaughters(branchvector);
        if (SampleType == "CMSMC" || SampleType == "CMSData"|| SampleType == "CMSMCGen") return ExtractJetsAndDaughters(branchvector);
        return {};
    }
    std::vector<EventsAnalyzer::JetAndDaughters> ExtractJetsAndDaughters(EventsAnalyzer::BranchVectors &branchvector){
        int jetnum = branchvector.JetPt->size();
        vector<JetAndDaughters> jetsdaughters(jetnum, JetAndDaughters());
        for (int i = 0; i < branchvector.JetId->size(); i++)
        {
            int jetid = branchvector.JetId->at(i);
            jetsdaughters.at(jetid).daughters.push_back(ParticleInfo(branchvector.PdgId->at(i),
                                                           branchvector.Charge->at(i),
                                                           branchvector.Pt->at(i),
                                                           branchvector.Eta->at(i),
                                                           branchvector.Phi->at(i),
                                                           branchvector.Energy->at(i)));
            // ***** Add temporary ecal un. hcal un. track un. and track eff 
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);
            jetsdaughters.at(jetid).daughters.back().SetDetectorUncertainty(
                (branchvector.Charge->at(i) != 0) ? 0.01 : 0,
                (branchvector.PdgId->at(i) == 22) ? 0.03 : 0,
                (branchvector.Charge->at(i) == 0 && branchvector.PdgId->at(i) != 22) ? 0.05 : 0,
                (dis(gen) < 0.03) ? 1.0 : 0.0
            );
            // *****                                          
            TLorentzVector p;
            p.SetPtEtaPhiE(branchvector.Pt->at(i), branchvector.Eta->at(i), branchvector.Phi->at(i), branchvector.Energy->at(i));
        }
        for (int i = 0; i < jetsdaughters.size(); i++)
        {
            jetsdaughters.at(i).jet.SetPtEtaPhiE(branchvector.JetPt->at(i), branchvector.JetEta->at(i), branchvector.JetPhi->at(i), branchvector.JetEnergy->at(i));
        }
        return jetsdaughters;
    }
    std::vector<EventsAnalyzer::JetAndDaughters> ClusterJetsAndDaughters(EventsAnalyzer::BranchVectors &branchvector){
        std::vector<PseudoJet> particles;
        std::vector<ParticleInfo> particlesinfo;
        for (size_t i = 0; i < branchvector.Pt->size(); ++i)
        {
            TLorentzVector p;
            p.SetPtEtaPhiE(branchvector.Pt->at(i), branchvector.Eta->at(i),
                           branchvector.Phi->at(i), branchvector.Energy->at(i));
            PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
            int pdgid = branchvector.PdgId->at(i);
            int charge;
            if (charge_d)
            {
                charge = branchvector.Charge_d->at(i);
            }
            else
            {
                charge = branchvector.Charge->at(i);
            }
            ParticleInfo particleInfo(pdgid, charge, branchvector.Pt->at(i), branchvector.Eta->at(i),
                                      branchvector.Phi->at(i), branchvector.Energy->at(i));
            particlesinfo.push_back(particleInfo);
            particle.set_user_index(i);
            particle.set_user_info(new FlavHistory(branchvector.PdgId->at(i)));
            particles.push_back(particle);
        }
        JetDefinition jet_def(antikt_algorithm, 0.4);
        ClusterSequence cs(particles, jet_def);
        auto csjets = cs.inclusive_jets(30);
        auto new_end =
            std::remove_if(csjets.begin(), csjets.end(), [](const PseudoJet &jet)
                           { return std::abs(jet.eta()) > 2.5; });
        csjets.erase(new_end, csjets.end());
        csjets = sorted_by_pt(csjets);
        int jetnum = csjets.size();
        vector<JetAndDaughters> jetsdaughters(jetnum, JetAndDaughters());
        for (int i = 0; i < jetnum; i++)
        {
            jetsdaughters.at(i).jet = PseudoJetToTLorentzVector(csjets.at(i));
            for (auto &particle : csjets.at(i).constituents())
            {
                int user_index = particle.user_index();
                jetsdaughters.at(i).daughters.push_back(particlesinfo.at(user_index));
                TLorentzVector p;
                p.SetPtEtaPhiE(particle.pt(), particle.eta(), particle.phi(), particle.e());
            }
        }
        return jetsdaughters;
    }
    void InitSampleType(){
        SampleType = options.SampleType;
        if(SampleType.empty()) {
            cerr<<"Sample type shoule be specified. e.g. PrivateMC, CMSMC , CMSMCGen, CMSData"<<endl;
            std::exit(EXIT_FAILURE);
        }
        md->AddParameter("Sample Type", SampleType);
        if (SampleType == "PrivateMC")
        {
            for (int i = 1; i <= 100; ++i)
            {
                t->Add((TString)options.inputFolder +
                       Form("chunk%d/*.root/JetsAndDaughters",
                            i));
            }
            prefixs = {""};
            suffixs = {"_Parton", "_Hadron"};
        }
        if (SampleType == "CMSMC" || SampleType == "CMSData" || SampleType == "CMSMCGen")
        {
           if(options.inputFolder.find("Run3") != std::string::npos||options.inputFolder.find("Run2022") != std::string::npos) t->Add((TString)options.inputFolder + "/Chunk*.root/JetsAndDaughters");
           else t->Add((TString)options.inputFolder + "/Chunk*.root/jetInfos/JetsAndDaughters");
           if(SampleType == "CMSMC"){
               prefixs = {"Gen","Reco"};
               suffixs = {""};
           }
           if(SampleType == "CMSMCGen"){
               prefixs = {"Gen","Reco"};
               suffixs = {""};
           }
           if((SampleType == "CMSData")){
               prefixs = {"Reco"};
               suffixs = {""};
           }
        }
        for (auto prefix : prefixs)
        {
            for (auto suffix : suffixs)
            {
                level.push_back(PrefixAndSuffix(prefix,suffix));
                md->AddParameter("Level", "prefix = " + prefix + " , suffix = " + suffix);
            }
        }

    }
    void InitOutputBranch(){
        for (auto prefix : prefixs){
            for (auto suffix : suffixs){
                std::vector<std::string> branch_names = {
                    "pt1", "eta1", "phi1", "e1", "ntracks1", "nparticles1","flavour1","pTD1","sigma11","sigma21","sigma1",
                    "pt2", "eta2", "phi2", "e2", "ntracks2", "nparticles2","flavour2","pTD2","sigma12","sigma22","sigma2",
                    "pt3", "eta3", "phi3", "e3", "ntracks3", "nparticles3","flavour3","pTD3","sigma13","sigma23","sigma3",
                    "pt4", "eta4", "phi4", "e4", "ntracks4", "nparticles4","flavour4","pTD4","sigma14","sigma24","sigma4",
                    "pt5", "eta5", "phi5", "e5", "ntracks5", "nparticles5","flavour5","pTD5","sigma15","sigma25","sigma5",
                    "pt6", "eta6", "phi6", "e6", "ntracks6", "nparticles6","flavour6","pTD6","sigma16","sigma26","sigma6",
                    "z1", "kt1", "theta1", "deltaR1", "eec1", 
                    "z2", "kt2", "theta2","deltaR2", "eec2",
                    "z3", "kt3", "theta3","deltaR3", "eec3", 
                    "n1x", "n1y","n1z", "n2x", "n2y", "n2z", "n3x", "n3y", "n3z", 
                    "type1", "type2", "type3", "Phi2", "Phi3",
                    "dPhi12_X2","Theta2","Theta22","dPhi12_X3","Theta3","Theta23",
                    "jpt", "jeta","jphi", "je"};
                if(SaveParticles){
                    std::vector<std::string> particles_branch_names = {
                        "particle1_pt", "particle1_eta", "particle1_phi", "particle1_e", "particle1_charge", "particle1_pid", "particle1_jetid",
                        "particle2_pt", "particle2_eta", "particle2_phi", "particle2_e", "particle2_charge", "particle2_pid", "particle2_jetid",
                        "particle3_pt", "particle3_eta", "particle3_phi", "particle3_e", "particle3_charge", "particle3_pid", "particle3_jetid",
                        "particle4_pt", "particle4_eta", "particle4_phi", "particle4_e", "particle4_charge", "particle4_pid", "particle4_jetid",
                        "particle5_pt", "particle5_eta", "particle5_phi", "particle5_e", "particle5_charge", "particle5_pid", "particle5_jetid",
                        "particle6_pt", "particle6_eta", "particle6_phi", "particle6_e", "particle6_charge", "particle6_pid", "particle6_jetid"};
                    branch_names.insert(branch_names.end(), particles_branch_names.begin(), particles_branch_names.end());
                }
                for (auto &branch_name : branch_names)
                {
                    if (branch_name == "type1" || branch_name == "type2" || branch_name == "type3" ||
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
                        treeEvents.addBranches(prefix+branch_name+suffix + "/vI");
                    }
                    else
                    {
                        treeEvents.addBranches(prefix+branch_name+suffix + "/vD");
                    }
                }
            }
        }
        treeEvents.addBranches("GeneratorWeight/D");
        if(SampleType != "CMSData"){
            treeEvents.addBranches("match2/vI");
            treeEvents.addBranches("match3/vI");
        }
        if(SampleType == "CMSMCGen"){
            treeEvents.addBranches("MatchedRecoPhi/vD");
        }
    
    }
    void InitAnalyzeBranch()
    {
        Branches.resize(prefixs.size() * suffixs.size());
        auto it = Branches.begin();                
        for (const auto &prefix : prefixs)
        {
            for (const auto &suffix : suffixs)
            {
                TString prefixTStr = (TString)prefix;
                TString suffixTStr = (TString)suffix;
                if(SampleType == "CMSMC" ||SampleType == "CMSData" ||SampleType == "CMSMCGen"){
                    t->SetBranchAddress(prefixTStr + "JetPt" + suffixTStr, &it->JetPt);
                    ApplyJetEnergyScale(prefixTStr,&it->JetPt);
                    t->SetBranchAddress(prefixTStr + "JetEta" + suffixTStr, &it->JetEta);
                    t->SetBranchAddress(prefixTStr + "JetPhi" + suffixTStr, &it->JetPhi);
                    t->SetBranchAddress(prefixTStr + "JetEnergy" + suffixTStr, &it->JetEnergy);
                    t->SetBranchAddress(prefixTStr + "JetMatching" + suffixTStr, &it->JetMatching);
                    t->SetBranchAddress(prefixTStr + "DaughterJetId" + suffixTStr, &it->JetId);
                    prefixTStr = (TString)prefix + "Daughter";
                    suffixTStr = (TString)suffix;
                    t->SetBranchAddress(prefixTStr + "Charge" + suffixTStr, &it->Charge);
                }
                t->SetBranchAddress(prefixTStr + "Pt" + suffixTStr, &it->Pt);
                t->SetBranchAddress(prefixTStr + "Eta" + suffixTStr, &it->Eta);
                t->SetBranchAddress(prefixTStr + "Phi" + suffixTStr, &it->Phi);
                t->SetBranchAddress(prefixTStr + "Energy" + suffixTStr, &it->Energy);
                t->SetBranchAddress(prefixTStr + "PdgId" + suffixTStr, &it->PdgId);
                if (SampleType == "PrivateMC")
                {
                    TBranch *branch = t->GetBranch(prefixTStr + "Charge" + suffixTStr);
                    if (branch)
                    {
                        TLeaf *leaf = branch->GetLeaf(branch->GetName());
                        if (leaf)
                        {
                            std::string typeName = leaf->GetTypeName(); 
                            if (typeName == "vector<double>" || typeName == "std::vector<double>" || typeName == "vector<Double_t>")
                            {
                                charge_d = true;
                                t->SetBranchAddress(prefixTStr + "Charge" + suffixTStr, &(it->Charge_d));
                                std::cout << "Branch " << prefixTStr + "Charge" + suffixTStr << " is of type vector<double>." << std::endl;
                            }else{
                                t->SetBranchAddress(prefixTStr + "Charge" + suffixTStr, &it->Charge);
                                std::cout << "Branch " << prefixTStr + "Charge" + suffixTStr << " is of type vector<int>." << std::endl;
                            }
                        }
                    }
                }
                
                ++it; 
            }
        }
    }
    void InitEventSelection()
    {
        if (SampleType == "PrivateMC")
        {
            AddSelection(
            EventSelection, "DiJet Selection",
            [this]
            {
                vector<TLorentzVector> jets;
                for(auto &jetdaughters:levelsjetsdaughters.at(1)) {
                    jets.push_back(jetdaughters.jet);
                }
                double pTCut = 30;
                double etaCut = 2.1;
                if (jets.size() < 2) return false;
                if (jets.at(0).Pt() < pTCut || abs(jets.at(0).Eta()) > etaCut) return false;
                if (jets.at(1).Pt() < pTCut || abs(jets.at(1).Eta()) > etaCut) return false;
                // the two leading jets must lie in opposite hemisphere
                auto dphi = jets.at(0).Phi() - jets.at(1).Phi();
                if ( dphi > M_PI ) dphi -= 2.0*M_PI;
                if ( dphi <= -M_PI ) dphi += 2.0*M_PI;
                auto dpt = jets.at(0).Pt() - jets.at(1).Pt();
                auto spt = jets.at(0).Pt() + jets.at(1).Pt();
                
                if (abs(dphi) > 2 && abs(dpt)/spt < 0.3) return true;
                return false;
            });
        }
        if(SampleType == "CMSMC"){
            AddSelection(
                   EventSelection, "Gen&&Reco DiJet Selection",
                   [this]
                   {
                       return this->events->GenPassDijet && this->events->RecoPassDijet;
                   });
            AddSelection(
                   EventSelection, "Pileup removal",
                   [this]
                   {
                       double genht = 0;
                       for (int iparton = 0; iparton < this->events->GenPartonPt->size(); iparton++)
                           genht += this->events->GenPartonPt->at(iparton);
                       if (this->Branches.at(1).JetPt->size() > 0)
                       {
                           if ( this->events->PileupMaxPtHat / genht > 1 ||
                               this->Branches.at(1).JetPt->at(0) / genht > 1)
                           {
                               return false;
                           }
                       }
                        return true;
                   });
        }
        if(SampleType == "CMSMCGen"){
            AddSelection(
                   EventSelection, "Gen DiJet Selection",
                   [this]
                   {
                       return this->events->GenPassDijet;
                   });
            AddSelection(
                   EventSelection, "Pileup removal",
                   [this]
                   {
                       double genht = 0;
                       for (int iparton = 0; iparton < this->events->GenPartonPt->size(); iparton++)
                           genht += this->events->GenPartonPt->at(iparton);
                       if (this->Branches.at(1).JetPt->size() > 0)
                       {
                           if ( this->events->PileupMaxPtHat / genht > 1 ||
                               this->Branches.at(1).JetPt->at(0) / genht > 1)
                           {
                               return false;
                           }
                       }
                       
                        return true;
                   });
        }
        if((SampleType == "CMSData")){
            AddSelection(
                   EventSelection, "Reco DiJet Selection",
                   [this]
                   {
                       return this->events->RecoPassDijet;
                   });
            AddSelection(
                   EventSelection, "HLT450 selection",
                   [this]
                   {
                       return this->events->TriggerBits->back();
                   });
        }
        if(options.inputFolder.find("Flat_herwig") != std::string::npos) {
            cout<<"Add events selection: Overweighted Events Removal"<<endl;
            weightcut=Hists("table/OverWeightedEventRemoval/GeneratorWeightcut.root");        
            AddSelection(
                EventSelection, "Overweighted Events Removal",
                [this]
                {
                    if (this->Branches.at(0).JetPt->size() > 0)
                    {
                        int bin =this->weightcut["GeneratorWeightCutSmoothHist"]->FindBin(this->Branches.at(0).JetPt->at(0));
                        if (this->events->GeneratorWeight > this->weightcut["GeneratorWeightCutSmoothHist"]->GetBinContent(bin))
                        {
                            return false;
                        }
                    }
                    return true;
                });
        }
        if(options.inputFolder.find("Flat_pythia") != std::string::npos) {
            cout<<"Add events selection: Overweighted Events Removal"<<endl;
            weightcut=Hists("table/OverWeightedEventRemoval/GeneratorWeightcut_pythia8.root");
            AddSelection(
                EventSelection, "Overweighted Events Removal",
                [this]
                {
                    if (this->Branches.at(0).JetPt->size() > 0)
                    {
                        int bin =this->weightcut["GeneratorWeightCutSmoothHist"]->FindBin(this->Branches.at(0).JetPt->at(0));
                        if (this->events->GeneratorWeight > this->weightcut["GeneratorWeightCutSmoothHist"]->GetBinContent(bin))
                        {
                            return false;
                        }
                    }
                    return true;
                });
        }
    }
    void InitJetSelection(){
        if(SampleType=="CMSMCGen") return;
        AddSelection(
            JetSelection, (std::string)TString::Format("JetPt = [ %d , %d ]", options.jinit_ptlow, options.jinit_pthigh),
            [this]
            {
                for (auto &jetsdaughters : this->levelsjetsdaughters)
                {
                    jetsdaughters.erase(
                        std::remove_if(jetsdaughters.begin(), jetsdaughters.end(),
                                       [this](const JetAndDaughters &jd)
                                       {
                                           return jd.jet.Pt() < this->options.jinit_ptlow || jd.jet.Pt() > this->options.jinit_pthigh;
                                       }),
                        jetsdaughters.end());
                }
                return true;
            });
        AddSelection(
            JetSelection, "JetEta = [ -2.1 , 2.1 ]",
            [this]
            {
                for (auto &jetsdaughters : this->levelsjetsdaughters) 
                {
                    jetsdaughters.erase(
                        std::remove_if(jetsdaughters.begin(), jetsdaughters.end(),
                                    [](const JetAndDaughters &jd) {
                                        return abs(jd.jet.Eta()) >=2.1;
                                    }),
                        jetsdaughters.end());
                }
                return true;
            });
    }
    void InitParticleSelection(){
        AddSelection(
            ParticleSelection, "Scale particle pt sum = jet pt",
            [this]
            {
                for (auto &jetsdaughters : this->levelsjetsdaughters)
                {
                    for(auto &jd:jetsdaughters){
                        TLorentzVector j0;
                        for(auto &dau:jd.daughters){
                            j0+=dau.lorentzvector;
                        }
                        double scale = jd.jet.Pt()*1.0/j0.Pt();
                        for(auto &dau:jd.daughters){
                            dau.ScaleGlobalEnergy(scale);
                        }
                    }
                }
                return true;
            });
        ApplyParticleEnergyScale();
        AddSelection(
            ParticleSelection, "Particle Pt >= 1 GeV",
            [this]
            {
                for (auto &jetsdaughters : this->levelsjetsdaughters)
                {
                    for(auto &jd:jetsdaughters){
                        jd.daughters.erase(
                        std::remove_if(jd.daughters.begin(), jd.daughters.end(),
                                       [this](const ParticleInfo &dau)
                                       {
                                           return dau.pt < 1 ;
                                       }),
                        jd.daughters.end());
                    }
                }
                return true;
            });
    }
    void InitPlaneSelection(){
        if(SampleType == "PrivateMC"||SampleType == "CMSMC"||SampleType == "CMSData")
        {
            AddSelection(
                PlaneSelection, (std::string)TString::Format("Plane2 JetPt = [ %d , %d ]", options.j2_ptlow, options.j2_pthigh),
                [this]
                {
                    for (auto &planes : this->planes_arr)
                    {
                        planes.at(0).erase(
                            std::remove_if(planes.at(0).begin(), planes.at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           {
                                               return threeplanes.first.softer.pt() > this->options.j2_pthigh ||
                                                      threeplanes.first.softer.pt() < this->options.j2_ptlow;
                                           }),
                            planes.at(0).end());
                    }
                    return true;
                });
            // AddSelection(
            //     PlaneSelection, "Plane2 and Plane3 Exist",
            //     [this]
            //     {
            //         for (auto &planes : this->planes_arr)
            //         {
            //             planes.at(0).erase(
            //                 std::remove_if(planes.at(0).begin(), planes.at(0).end(),
            //                                [](const JetBranch::threeplanes &threeplanes)
            //                                {
            //                                    return threeplanes.second.harder_nparticles == 0 ||
            //                                           threeplanes.second.softer_nparticles == 0 ||
            //                                           threeplanes.third.harder_nparticles == 0 ||
            //                                           threeplanes.third.softer_nparticles == 0;
            //                                }),
            //                 planes.at(0).end());
            //         }
            //         return true;
            //     });
            AddSelection(
                PlaneSelection, "Plane2 Exist",
                [this]
                {
                    for (auto &planes : this->planes_arr)
                    {
                        planes.at(0).erase(
                            std::remove_if(planes.at(0).begin(), planes.at(0).end(),
                                           [](const JetBranch::threeplanes &threeplanes)
                                           {
                                               return threeplanes.second.harder_nparticles == 0 ||
                                                      threeplanes.second.softer_nparticles == 0 ;
                                           }),
                            planes.at(0).end());
                    }
                    return true;
                });
        
        }
        if(SampleType == "CMSMCGen"){
            AddSelection(
            PlaneSelection, (std::string)TString::Format("Gen JetPt = [ %d , %d ]", options.jinit_ptlow, options.jinit_pthigh),
            [this]
            {
                for (int i=0;i<level.size();i++) 
                {
                    auto planes = &planes_arr.at(i);
                    if(level.at(i).prefix == "Gen") {
                        planes_arr.at(i).at(0).erase(
                            std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           {
                                               return threeplanes.first.initJet.Pt() < this->options.jinit_ptlow 
                                               || threeplanes.first.initJet.Pt() > this->options.jinit_pthigh;
                                           }),
                            planes_arr.at(i).at(0).end());
                    }else{
                        planes_arr.at(i).at(0).erase(
                            std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           {
                                               return threeplanes.matchedthreeplanes.first.initJet.Pt() < this->options.jinit_ptlow || 
                                                      threeplanes.matchedthreeplanes.first.initJet.Pt() > this->options.jinit_pthigh;
                                           }),
                            planes_arr.at(i).at(0).end());
                    }
                }
                return true;
            });
            AddSelection(
            PlaneSelection, "Gen Jet Eta = [ -2.1 , 2.1]",
            [this]
            {
                for (int i=0;i<level.size();i++) 
                {
                    auto planes = &planes_arr.at(i);
                    if(level.at(i).prefix == "Gen") {
                        planes_arr.at(i).at(0).erase(
                            std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           { return abs(threeplanes.first.initJet.Eta()) >= 2.1; }),
                            planes_arr.at(i).at(0).end());
                    }else{
                        planes_arr.at(i).at(0).erase(
                            std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           {
                                                return abs(threeplanes.matchedthreeplanes.first.initJet.Eta()) >= 2.1;
                                           }),
                            planes_arr.at(i).at(0).end());
                    }
                }
                return true;
            });
            AddSelection(
                PlaneSelection, (std::string)TString::Format("Gen Plane2 JetPt = [ %d , %d ]", options.j2_ptlow, options.j2_pthigh),
                [this]
                {
                    for (int i = 0; i < level.size(); i++)
                    {
                        auto planes = &planes_arr.at(i);

                        if (level.at(i).prefix == "Gen")
                        {
                            planes_arr.at(i).at(0).erase(
                                std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                               [this](const JetBranch::threeplanes &threeplanes)
                                               {
                                                   return threeplanes.first.softer.pt() < this->options.j2_ptlow || threeplanes.first.softer.pt() > this->options.j2_pthigh;
                                               }),
                                planes_arr.at(i).at(0).end());
                        }
                        else
                        {
                            planes_arr.at(i).at(0).erase(
                                std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                               [this](const JetBranch::threeplanes &threeplanes)
                                               {
                                                   return threeplanes.matchedthreeplanes.first.softer.pt() < this->options.j2_ptlow ||
                                                          threeplanes.matchedthreeplanes.first.softer.pt() > this->options.j2_pthigh;
                                               }),
                                planes_arr.at(i).at(0).end());
                        }
                    }
                    return true;
                });
            // AddSelection(
            // PlaneSelection, "Gen Plane2 and Plane3 Exist (Reco Jet must matched to Gen Jet)",
            // [this]
            // {
            //     for (int i=0;i<level.size();i++) 
            //     {
            //         auto planes = &planes_arr.at(i);
            //         if(level.at(i).prefix == "Gen") {
            //             planes_arr.at(i).at(0).erase(
            //                 std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
            //                                [this](const JetBranch::threeplanes &threeplanes)
            //                                {
            //                                    return !threeplanes.ismatched||
            //                                           threeplanes.second.harder_nparticles == 0 ||
            //                                           threeplanes.second.softer_nparticles == 0 ||
            //                                           threeplanes.third.harder_nparticles == 0 ||
            //                                           threeplanes.third.softer_nparticles == 0;
            //                                }),
            //                 planes_arr.at(i).at(0).end());
            //         }else{
            //             planes_arr.at(i).at(0).erase(
            //                 std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
            //                                [this](const JetBranch::threeplanes &threeplanes)
            //                                {
            //                                    return !threeplanes.ismatched||
            //                                           threeplanes.matchedthreeplanes.second.harder_nparticles == 0 ||
            //                                           threeplanes.matchedthreeplanes.second.softer_nparticles == 0 ||
            //                                           threeplanes.matchedthreeplanes.third.harder_nparticles == 0 ||
            //                                           threeplanes.matchedthreeplanes.third.softer_nparticles == 0;
            //                                }),
            //                 planes_arr.at(i).at(0).end());
            //         }
            //     }
            //     return true;
            // });
            AddSelection(
            PlaneSelection, "Gen Plane2 Exist (Reco Jet must matched to Gen Jet)",
            [this]
            {
                for (int i=0;i<level.size();i++) 
                {
                    auto planes = &planes_arr.at(i);
                    if(level.at(i).prefix == "Gen") {
                        planes_arr.at(i).at(0).erase(
                            std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           {
                                               return !threeplanes.ismatched||
                                                      threeplanes.second.harder_nparticles == 0 ||
                                                      threeplanes.second.softer_nparticles == 0 ;
                                           }),
                            planes_arr.at(i).at(0).end());
                    }else{
                        planes_arr.at(i).at(0).erase(
                            std::remove_if(planes_arr.at(i).at(0).begin(), planes_arr.at(i).at(0).end(),
                                           [this](const JetBranch::threeplanes &threeplanes)
                                           {
                                               return !threeplanes.ismatched||
                                                      threeplanes.matchedthreeplanes.second.harder_nparticles == 0 ||
                                                      threeplanes.matchedthreeplanes.second.softer_nparticles == 0 ;
                                           }),
                            planes_arr.at(i).at(0).end());
                    }
                }
                return true;
            });
        }
        
    }
    void InitBranchSelection(){
        if(SampleType.find("CMS") != std::string::npos) {
            treeEvents.addBranches("NumberTruePileup/D");
            treeEvents.addBranches("NumberPrimaryVertex/I");
            treeEvents.addBranches("NumberGoodVertex/I");
            AddSelection(
                BranchSelection, "Add pile up branch",
                [this]
                {
                    this->treeEvents.assign("NumberTruePileup",this->events->NumberTruePileup);
                    this->treeEvents.assign("NumberPrimaryVertex",this->events->NumberPrimaryVertex);
                    this->treeEvents.assign("NumberGoodVertex",this->events->NumberGoodVertex);
                    return true;
                });
        }
        if(options.inputFolder.find("Flat_pythia") != std::string::npos) {
            pileupweight = Hists("table/Pileup_reweighting/pileup_weight.root");
            treeEvents.addBranches("PileupWeight/D");
            AddSelection(
                BranchSelection, "Add pile up weight",
                [this]
                {
                    int bin = this->pileupweight["PileupReweight"]->FindBin(this->events->NumberTruePileup);
                    this->treeEvents.assign("PileupWeight",this->pileupweight["PileupReweight"]->GetBinContent(bin));
                    return true;
                });

        }
        ApplyPileupUncertainty();
    }
    void AddSelection(Selection &selection,const std::string& description, std::function<bool()> condition){
        selection.AddCondition(condition);
        md->AddParameter(selection, description);
    };
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
    void ApplyPileupUncertainty(){
        if(options.inputFolder.find("Flat_herwig") != std::string::npos) {
            pileupweight = Hists("table/Pileup_reweighting/pileup_weight_herwig.root");
            treeEvents.addBranches("PileupWeightNm/D");
            treeEvents.addBranches("PileupWeightUp/D");
            treeEvents.addBranches("PileupWeightDn/D");
            AddSelection(
                BranchSelection, "Add pile up weight Uncertainty: table/Pileup_reweighting/pileup_weight_herwig.root",
                [this]
                {
                    int bin = this->pileupweight["NominalWeight"]->FindBin(this->events->NumberTruePileup);
                    this->treeEvents.assign("PileupWeightNm",this->pileupweight["NominalWeight"]->GetBinContent(bin));
                    bin = this->pileupweight["UpWeight"]->FindBin(this->events->NumberTruePileup);
                    this->treeEvents.assign("PileupWeightUp",this->pileupweight["UpWeight"]->GetBinContent(bin));
                    bin = this->pileupweight["DnWeight"]->FindBin(this->events->NumberTruePileup);
                    this->treeEvents.assign("PileupWeightDn",this->pileupweight["DnWeight"]->GetBinContent(bin));
                    return true;
                });
        }
    }
    void ApplyParticleEnergyScale(){
        AddSelection(
            ParticleSelection, "Scale particle energy as " + options.jdEnergyUncertainty,
            [this]
            {
                for (auto &jetsdaughters : this->levelsjetsdaughters)
                {
                    for(auto &jd:jetsdaughters){
                        for(auto &dau:jd.daughters){
                            if(options.jdEnergyUncertainty.find("ChargedUp") != std::string::npos)
                                 dau.ScaleGlobalEnergy(1+dau.TrackerUncertainty);
                            if(options.jdEnergyUncertainty.find("ChargedDn") != std::string::npos)
                                 dau.ScaleGlobalEnergy(1-dau.TrackerUncertainty);
                            if(options.jdEnergyUncertainty.find("PhotonUp") != std::string::npos)
                                 dau.ScaleGlobalEnergy(1+dau.EcalUncertainty);
                            if(options.jdEnergyUncertainty.find("PhotonDn") != std::string::npos)
                                 dau.ScaleGlobalEnergy(1-dau.EcalUncertainty);
                            if(options.jdEnergyUncertainty.find("NeutralUp") != std::string::npos)
                                 dau.ScaleGlobalEnergy(1+dau.HcalUncertainty);
                            if(options.jdEnergyUncertainty.find("NeutralDn") != std::string::npos)
                                 dau.ScaleGlobalEnergy(1-dau.HcalUncertainty);
                        }
                        if (options.jdEnergyUncertainty.find("TrackEff") != std::string::npos)
                        {
                            jd.daughters.erase(
                                std::remove_if(jd.daughters.begin(), jd.daughters.end(),
                                               [&](const auto &dau)
                                               {
                                                   return dau.RandomDrop;
                                               }),
                                jd.daughters.end());
                        }
                        TLorentzVector j0;
                        for(auto &dau:jd.daughters){
                            j0+=dau.lorentzvector;
                        }
                        jd.jet = j0;
                    }
                }
                return true;
            });
    }
    void ApplyJetEnergyScale(TString prefixTStr, std::vector<double> **jetpt_vector)
    {
        if (prefixTStr == "Reco" &&
            (options.jdEnergyUncertainty.find("JESUp") != std::string::npos ||
             options.jdEnergyUncertainty.find("JESDn") != std::string::npos ||
             options.jdEnergyUncertainty.find("JERUp") != std::string::npos ||
             options.jdEnergyUncertainty.find("JERDn") != std::string::npos ||
             options.jdEnergyUncertainty.find("JERNm") != std::string::npos))
        {
            t->SetBranchAddress(prefixTStr + "JetPt" + options.jdEnergyUncertainty,jetpt_vector);
        }
    }
    TLorentzVector PseudoJetToTLorentzVector(const fastjet::PseudoJet &pj)
    {
        return TLorentzVector(pj.px(), pj.py(), pj.pz(), pj.e());
    }
};
int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv);
    EventsAnalyzer analyzer(options);
    CommonTool::processAndSaveDataWithMetaInfo(options, analyzer);
    return 0;
}

