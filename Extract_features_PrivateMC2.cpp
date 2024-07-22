//gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "include/common_tool.h"
#include "include/AdvancedDataInfo.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include "include/Draw_Template.h"
#include "include/JetBranch.h"
#include "include/ParticleInfo.h"
#include "include/JetObservable.h"
#include <getopt.h>
#include "include/TreeEvents.h"
#include "vector"
#include "include/SaveData.h"
#include "include/AdvancedDataInfo.h"
#include "include/Selection.h"
#include "include/SpinObservable.h"
class EventsAnalyzer : public SampleAnalyzer<AdvancedDataInfo> {
public:
    TreeEvents treeEvents;
    string inputFolder;
    int jinit_ptlow;
    int jinit_pthigh;
    int j0_ptlow;
    int j0_pthigh;
    int j2_ptlow;
    int j2_pthigh;
    vector<int> jinit_range;
    vector<int> j0_range;
    vector<int> j2_range;
    CommonTool::Options options;
    double NextPassedNumber;
    EventsAnalyzer(CommonTool::Options _options) { 
        options=_options;
        inputFolder = options.inputFolder; 
        jinit_ptlow = options.jinit_ptlow;
        jinit_pthigh = options.jinit_pthigh;
        j0_ptlow = options.j0_ptlow;
        j0_pthigh = options.j0_pthigh;
        j2_ptlow = options.j2_ptlow;
        j2_pthigh = options.j2_pthigh;
        jinit_range={jinit_ptlow, jinit_pthigh};
        j0_range={j0_ptlow, j0_pthigh};
        j2_range={j2_ptlow, j2_pthigh};
    }
    void initialize() override {
        
        t->Add((TString)inputFolder+"/Chunk*.root/DataInfo");
        
        treeEvents.addBranches("Nparticles_1/I");
        treeEvents.addBranches("Ntracks_1/I");
        treeEvents.addBranches("pTD_1/D");
        treeEvents.addBranches("sigma1_1/D");
        treeEvents.addBranches("sigma2_1/D");
        treeEvents.addBranches("sigma_1/D");
        treeEvents.addBranches("pt_1/D");
        treeEvents.addBranches("eta_1/D");
        treeEvents.addBranches("phi_1/D");
        treeEvents.addBranches("e_1/D");

        treeEvents.addBranches("PassPileUpRm/I");
        treeEvents.addBranches("Nparticles_2/I");
        treeEvents.addBranches("Ntracks_2/I");
        treeEvents.addBranches("pTD_2/D");
        treeEvents.addBranches("sigma1_2/D");
        treeEvents.addBranches("sigma2_2/D");
        treeEvents.addBranches("sigma_2/D");
        treeEvents.addBranches("pt_2/D");
        treeEvents.addBranches("eta_2/D");
        treeEvents.addBranches("phi_2/D");
        treeEvents.addBranches("e_2/D");

        treeEvents.addBranches("Nparticles_3/I");
        treeEvents.addBranches("Ntracks_3/I");
        treeEvents.addBranches("pTD_3/D");
        treeEvents.addBranches("sigma1_3/D");
        treeEvents.addBranches("sigma2_3/D");
        treeEvents.addBranches("sigma_3/D");
        treeEvents.addBranches("pt_3/D");
        treeEvents.addBranches("eta_3/D");
        treeEvents.addBranches("phi_3/D");
        treeEvents.addBranches("e_3/D");

        treeEvents.addBranches("Nparticles_4/I");
        treeEvents.addBranches("Ntracks_4/I");
        treeEvents.addBranches("pTD_4/D");
        treeEvents.addBranches("sigma1_4/D");
        treeEvents.addBranches("sigma2_4/D");
        treeEvents.addBranches("sigma_4/D");
        treeEvents.addBranches("pt_4/D");
        treeEvents.addBranches("eta_4/D");
        treeEvents.addBranches("phi_4/D");
        treeEvents.addBranches("e_4/D");

        treeEvents.addBranches("Nparticles_5/I");
        treeEvents.addBranches("Ntracks_5/I");
        treeEvents.addBranches("pTD_5/D");
        treeEvents.addBranches("sigma1_5/D");
        treeEvents.addBranches("sigma2_5/D");
        treeEvents.addBranches("sigma_5/D");
        treeEvents.addBranches("pt_5/D");
        treeEvents.addBranches("eta_5/D");
        treeEvents.addBranches("phi_5/D");
        treeEvents.addBranches("e_5/D");

        treeEvents.addBranches("Nparticles_6/I");
        treeEvents.addBranches("Ntracks_6/I");
        treeEvents.addBranches("pTD_6/D");
        treeEvents.addBranches("sigma1_6/D");
        treeEvents.addBranches("sigma2_6/D");
        treeEvents.addBranches("sigma_6/D");
        treeEvents.addBranches("pt_6/D");
        treeEvents.addBranches("eta_6/D");
        treeEvents.addBranches("phi_6/D");
        treeEvents.addBranches("e_6/D");

        treeEvents.addBranches("z1/D");
        treeEvents.addBranches("z2/D");
        treeEvents.addBranches("z3/D");
        treeEvents.addBranches("DeltaR/D");
        treeEvents.addBranches("DeltaR3/D");
        treeEvents.addBranches("kt/D");
        treeEvents.addBranches("kt0/D");
        treeEvents.addBranches("kt3/D");

        treeEvents.addBranches("Phi/D");
        treeEvents.addBranches("Phi3/D");
        treeEvents.addBranches("type/I");
        treeEvents.addBranches("type3/I");
        treeEvents.addBranches("match/I");
         treeEvents.addBranches("match3/I");

        treeEvents.addBranches("pt/D");
        treeEvents.addBranches("GeneratorWeight/D");
        treeEvents.addBranches("NextPassedNumber/D");

        treeEvents.addBranches("dphi12_X/D");
        treeEvents.addBranches("theta/D");
        treeEvents.addBranches("theta2/D");
        treeEvents.addBranches("dphi12_X3/D");
        treeEvents.addBranches("theta3/D");
        treeEvents.addBranches("theta23/D");
        NextPassedNumber=0;
        
    }
    void analyze() override {
        // int spin = events->spin;
        // if(spin!=options.spin) return;
        bool isoneGeVCut = options.OneGeVCut==1;
        int plane_num = events->pt3_Hadron->size();
        vector<ParticleInfo> jet1s(plane_num);
        vector<ParticleInfo> jet2s(plane_num);
        vector<ParticleInfo> jet3s(plane_num);
        vector<ParticleInfo> jet4s(plane_num);
        vector<ParticleInfo> jet5s(plane_num);
        vector<ParticleInfo> jet6s(plane_num);
        vector<vector<ParticleInfo>> particles1(plane_num);
        vector<vector<ParticleInfo>> particles2(plane_num);
        vector<vector<ParticleInfo>> particles3(plane_num);
        vector<vector<ParticleInfo>> particles4(plane_num);
        vector<vector<ParticleInfo>> particles5(plane_num);
        vector<vector<ParticleInfo>> particles6(plane_num);
        for(int i=0;i<plane_num;i++){
           ParticleInfo particle( events->pt1_Hadron->at(i),
                                  events->eta1_Hadron->at(i),
                                  events->phi1_Hadron->at(i),
                                  events->e1_Hadron->at(i));
                                  
            jet1s.at(i)=particle;
        }
        for(int i=0;i<plane_num;i++){
           ParticleInfo particle( events->pt2_Hadron->at(i),
                                  events->eta2_Hadron->at(i),
                                  events->phi2_Hadron->at(i),
                                  events->e2_Hadron->at(i));
                                  
            jet2s.at(i)=particle;
        }
        for(int i=0;i<plane_num;i++){
           ParticleInfo particle( events->pt3_Hadron->at(i),
                                  events->eta3_Hadron->at(i),
                                  events->phi3_Hadron->at(i),
                                  events->e3_Hadron->at(i));
                                  
            jet3s.at(i)=particle;
        }
        for(int i=0;i<plane_num;i++){
           ParticleInfo particle( events->pt4_Hadron->at(i),
                                  events->eta4_Hadron->at(i),
                                  events->phi4_Hadron->at(i),
                                  events->e4_Hadron->at(i));
            jet4s.at(i)=particle;
        }
        for(int i=0;i<plane_num;i++){
           ParticleInfo particle( events->pt5_Hadron->at(i),
                                  events->eta5_Hadron->at(i),
                                  events->phi5_Hadron->at(i),
                                  events->e5_Hadron->at(i));
                                  
            jet5s.at(i)=particle;
        }
        for(int i=0;i<plane_num;i++){
           ParticleInfo particle( events->pt6_Hadron->at(i),
                                  events->eta6_Hadron->at(i),
                                  events->phi6_Hadron->at(i),
                                  events->e6_Hadron->at(i));
            jet6s.at(i)=particle;
        }
        for(int i=0;i<events->particle1_jetid_Hadron->size();i++){
            int jetid = events->particle1_jetid_Hadron->at(i);
            if(isoneGeVCut&&events->particle1_pt_Hadron->at(i)<1) continue;
            ParticleInfo particle(events->particle1_pid_Hadron->at(i),
                                  events->particle1_charge_Hadron->at(i),
                                  events->particle1_pt_Hadron->at(i),
                                  events->particle1_eta_Hadron->at(i),
                                  events->particle1_phi_Hadron->at(i),
                                  events->particle1_e_Hadron->at(i));
            particles1.at(jetid).push_back(particle);
        }
        for(int i=0;i<events->particle2_jetid_Hadron->size();i++){
            int jetid = events->particle2_jetid_Hadron->at(i);
            if(isoneGeVCut&&events->particle2_pt_Hadron->at(i)<1) continue;
            ParticleInfo particle(events->particle2_pid_Hadron->at(i),
                                  events->particle2_charge_Hadron->at(i),
                                  events->particle2_pt_Hadron->at(i),
                                  events->particle2_eta_Hadron->at(i),
                                  events->particle2_phi_Hadron->at(i),
                                  events->particle2_e_Hadron->at(i));
            particles2.at(jetid).push_back(particle);
        }
        for(int i=0;i<events->particle3_jetid_Hadron->size();i++){
            int jetid = events->particle3_jetid_Hadron->at(i);
            if(isoneGeVCut&&events->particle3_pt_Hadron->at(i)<1) continue;
            ParticleInfo particle(events->particle3_pid_Hadron->at(i),
                                  events->particle3_charge_Hadron->at(i),
                                  events->particle3_pt_Hadron->at(i),
                                  events->particle3_eta_Hadron->at(i),
                                  events->particle3_phi_Hadron->at(i),
                                  events->particle3_e_Hadron->at(i));
            particles3.at(jetid).push_back(particle);
        }
        for(int i=0;i<events->particle4_jetid_Hadron->size();i++){
            int jetid = events->particle4_jetid_Hadron->at(i);
            if(isoneGeVCut&&events->particle4_pt_Hadron->at(i)<1) continue;
            ParticleInfo particle(events->particle4_pid_Hadron->at(i),
                                  events->particle4_charge_Hadron->at(i),
                                  events->particle4_pt_Hadron->at(i),
                                  events->particle4_eta_Hadron->at(i),
                                  events->particle4_phi_Hadron->at(i),
                                  events->particle4_e_Hadron->at(i));
            particles4.at(jetid).push_back(particle);
        }
        for(int i=0;i<events->particle5_jetid_Hadron->size();i++){
            int jetid = events->particle5_jetid_Hadron->at(i);
            if(isoneGeVCut&&events->particle5_pt_Hadron->at(i)<1) continue;
            ParticleInfo particle(events->particle5_pid_Hadron->at(i),
                                  events->particle5_charge_Hadron->at(i),
                                  events->particle5_pt_Hadron->at(i),
                                  events->particle5_eta_Hadron->at(i),
                                  events->particle5_phi_Hadron->at(i),
                                  events->particle5_e_Hadron->at(i));
            particles5.at(jetid).push_back(particle);
        }

        for(int i=0;i<events->particle6_jetid_Hadron->size();i++){
            int jetid = events->particle6_jetid_Hadron->at(i);
            if(isoneGeVCut&&events->particle6_pt_Hadron->at(i)<1) continue;
            ParticleInfo particle(events->particle6_pid_Hadron->at(i),
                                  events->particle6_charge_Hadron->at(i),
                                  events->particle6_pt_Hadron->at(i),
                                  events->particle6_eta_Hadron->at(i),
                                  events->particle6_phi_Hadron->at(i),
                                  events->particle6_e_Hadron->at(i));
            particles6.at(jetid).push_back(particle);
        }

        
        double unit_NextPassedNumber = 1.0/plane_num;
        for (int i = 0; i < plane_num; i++)
        {
            NextPassedNumber+= unit_NextPassedNumber;
            double jesscale = 1;
            if (!Selection::isWithinRange(events->jpt_Hadron->at(i) * jesscale, jinit_range))
                continue;
            int isqq = events->isqq_Hadron->at(i);
            int isgg = events->isgg_Hadron->at(i);
            int isqq2 = events->isqq2_Hadron->at(i);
            int isgg2 = events->isgg2_Hadron->at(i);
            JetObservable JetObservable2(particles2.at(i));
            if (!Selection::isWithinRange(JetObservable2.jet_lorentzvector.Pt() * jesscale, j2_range))
                continue;
            auto width2 = JetObservable2.jetwidth();
            JetObservable JetObservable1(particles1.at(i));
            auto width1 = JetObservable1.jetwidth();
            JetObservable JetObservable3(particles3.at(i));
            auto width3 = JetObservable3.jetwidth();
            JetObservable JetObservable4(particles4.at(i));
            auto width4 = JetObservable4.jetwidth();
            JetObservable JetObservable5(particles5.at(i));
            auto width5 = JetObservable5.jetwidth();
            JetObservable JetObservable6(particles6.at(i));
            auto width6 = JetObservable6.jetwidth();
            if (JetObservable3.Nparticles() == 0 || JetObservable4.Nparticles() == 0 ||JetObservable5.Nparticles()==0||JetObservable6.Nparticles()==0)
            {
                continue;
            }
            
            int type = determineType(events->flavour3_Hadron->at(i), events->flavour4_Hadron->at(i));
            int type3 = determineType(events->flavour5_Hadron->at(i), events->flavour6_Hadron->at(i));

            if(type==0 && type3==0 ) continue;
            if(events->kt2_Hadron->at(i)<2 || events->kt3_Hadron->at(i)<2 ) continue;
            SpinObservable spinobservable(particles1.at(i),particles2.at(i),particles3.at(i),particles4.at(i));
            auto planetheta=spinobservable.GetPlaneTheta();
            SpinObservable spinobservable3(particles1.at(i),particles2.at(i),particles5.at(i),particles6.at(i));
            auto planetheta3=spinobservable3.GetPlaneTheta();

            treeEvents.BeginEvent();
            treeEvents.assign("NextPassedNumber", NextPassedNumber);
            NextPassedNumber=0;
            treeEvents.assign("PassPileUpRm", 1);
            treeEvents.assign("GeneratorWeight", 1.0);
            treeEvents.assign("Nparticles_1", JetObservable1.Nparticles());
            treeEvents.assign("Ntracks_1", JetObservable1.Ntracks());
            treeEvents.assign("pTD_1", JetObservable1.pTD());
            treeEvents.assign("sigma1_1", width1.sigma1);
            treeEvents.assign("sigma2_1", width1.sigma2);
            treeEvents.assign("sigma_1", width1.sigma);
            treeEvents.assign("pt_1", jet1s.at(i).pt*jesscale);
            treeEvents.assign("eta_1", jet1s.at(i).eta);
            treeEvents.assign("phi_1", jet1s.at(i).phi);
            treeEvents.assign("e_1", jet1s.at(i).e*jesscale);
            treeEvents.assign("Nparticles_2", JetObservable2.Nparticles());
            treeEvents.assign("Ntracks_2", JetObservable2.Ntracks());
            treeEvents.assign("pTD_2", JetObservable2.pTD());
            treeEvents.assign("sigma1_2", width2.sigma1);
            treeEvents.assign("sigma2_2", width2.sigma2);
            treeEvents.assign("sigma_2", width2.sigma);
            treeEvents.assign("pt_2", jet2s.at(i).pt);
            treeEvents.assign("eta_2", jet2s.at(i).eta);
            treeEvents.assign("phi_2", jet2s.at(i).phi);
            treeEvents.assign("e_2", jet2s.at(i).e);

            treeEvents.assign("Nparticles_3", JetObservable3.Nparticles());
            treeEvents.assign("Ntracks_3", JetObservable3.Ntracks());
            treeEvents.assign("pTD_3", JetObservable3.pTD());
            treeEvents.assign("sigma1_3", width3.sigma1);
            treeEvents.assign("sigma2_3", width3.sigma2);
            treeEvents.assign("sigma_3", width3.sigma);
            treeEvents.assign("pt_3", jet3s.at(i).pt);
            treeEvents.assign("eta_3", jet3s.at(i).eta);
            treeEvents.assign("phi_3", jet3s.at(i).phi);
            treeEvents.assign("e_3", jet3s.at(i).e);
            treeEvents.assign("Nparticles_4", JetObservable4.Nparticles());
            treeEvents.assign("Ntracks_4", JetObservable4.Ntracks());
            treeEvents.assign("pTD_4", JetObservable4.pTD());
            treeEvents.assign("sigma1_4", width4.sigma1);
            treeEvents.assign("sigma2_4", width4.sigma2);
            treeEvents.assign("sigma_4", width4.sigma);
            treeEvents.assign("pt_4", jet4s.at(i).pt);
            treeEvents.assign("eta_4", jet4s.at(i).eta);
            treeEvents.assign("phi_4", jet4s.at(i).phi);
            treeEvents.assign("e_4", jet4s.at(i).e);

            treeEvents.assign("Nparticles_5", JetObservable5.Nparticles());
            treeEvents.assign("Ntracks_5", JetObservable5.Ntracks());
            treeEvents.assign("pTD_5", JetObservable5.pTD());
            treeEvents.assign("sigma1_5", width5.sigma1);
            treeEvents.assign("sigma2_5", width5.sigma2);
            treeEvents.assign("sigma_5", width5.sigma);
            treeEvents.assign("pt_5", jet5s.at(i).pt);
            treeEvents.assign("eta_5", jet5s.at(i).eta);
            treeEvents.assign("phi_5", jet5s.at(i).phi);
            treeEvents.assign("e_5", jet5s.at(i).e);
            treeEvents.assign("Nparticles_6", JetObservable6.Nparticles());
            treeEvents.assign("Ntracks_6", JetObservable6.Ntracks());
            treeEvents.assign("pTD_6", JetObservable6.pTD());
            treeEvents.assign("sigma1_6", width6.sigma1);
            treeEvents.assign("sigma2_6", width6.sigma2);
            treeEvents.assign("sigma_6", width6.sigma);
            treeEvents.assign("pt_6", jet6s.at(i).pt);
            treeEvents.assign("eta_6", jet6s.at(i).eta);
            treeEvents.assign("phi_6", jet6s.at(i).phi);
            treeEvents.assign("e_6", jet6s.at(i).e);

            treeEvents.assign("pt", events->jpt_Hadron->at(i));
            treeEvents.assign("z1", events->z1_Hadron->at(i));
            treeEvents.assign("z2", events->z2_Hadron->at(i));
            treeEvents.assign("z3", events->z3_Hadron->at(i));

            treeEvents.assign("DeltaR", events->deltaR2_Hadron->at(i));
            treeEvents.assign("DeltaR3", events->deltaR3_Hadron->at(i));
            treeEvents.assign("kt", events->kt2_Hadron->at(i));
            treeEvents.assign("kt0", events->kt1_Hadron->at(i));
            treeEvents.assign("kt3", events->kt3_Hadron->at(i));
            treeEvents.assign("Phi",events->phi_Hadron->at(i));
            treeEvents.assign("Phi3",events->thirdphi_Hadron->at(i));
            treeEvents.assign("type",type);
            treeEvents.assign("type3",type3);
            treeEvents.assign("match",events->match->at(i));
            treeEvents.assign("match3",events->match3->at(i));
            treeEvents.assign("dphi12_X",planetheta.dphi12_X);
            treeEvents.assign("theta",planetheta.theta);
            treeEvents.assign("theta2",planetheta.theta2);

            treeEvents.assign("dphi12_X3",planetheta3.dphi12_X);
            treeEvents.assign("theta3",planetheta3.theta);
            treeEvents.assign("theta23",planetheta3.theta2);
        }
    }
    int determineType(int flavour1, int flavour2) {
        if (flavour2 == 21 && flavour1 == 21) {
            return 1;
        }
        if (flavour1 != 0 && flavour1 != 21 && flavour2 != 0 && flavour2 != 21) {
            return 2;
        }

        if (flavour1 != 0 && flavour1 != 21 && flavour2 == 21) {
            return 3;
        }
        if (flavour2 != 0 && flavour2 != 21 && flavour1 == 21) {
            return 3;
        }
        if (flavour1 != 0 && flavour1 != 21 && flavour2 == 0) {
            return 4;
        }
        if (flavour2 != 0 && flavour2 != 21 && flavour1 == 0) {
            return 4;
        }
        if (flavour1 == 21 && flavour2 == 0) {
            return 5;
        }
        if (flavour2 == 21 && flavour1 == 0) {
            return 5;
        }
        return 0; 
    }
};
// void Draw_plots_mini2(){
int main(int argc, char *argv[]) {
    CommonTool::Options options = CommonTool::parseArguments(argc, argv);
    EventsAnalyzer analyzer(options);
    CommonTool::processAndSaveData(options, analyzer);
    return 0;
}    