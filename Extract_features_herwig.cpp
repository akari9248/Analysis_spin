//gInterpreter->AddIncludePath("/home/zlin/.local/include");
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
class EventsAnalyzer : public SampleAnalyzer<AdvancedDataInfo> {
public:
    vector<TreeEvents> treeEvents;
    string flav="IFN";
    EventsAnalyzer(string _flav="IFN"){
        flav=_flav;
    }
    void initialize() override {
        treeEvents.resize(2);
        t->Add("/extdisk/zlin/Machine_learning/test/herwig_pt450_"+(TString)flav+"_May28/Chunk*.root/DataInfo");
        for (int i = 0; i < 2; i++) {
          treeEvents.at(i).addBranches("Nparticles_2/I");
          treeEvents.at(i).addBranches("Ntracks_2/I");
          treeEvents.at(i).addBranches("pTD_2/D");
          treeEvents.at(i).addBranches("sigma1_2/D");
          treeEvents.at(i).addBranches("sigma2_2/D");
          treeEvents.at(i).addBranches("sigma_2/D");
          treeEvents.at(i).addBranches("pt_2/D");
          treeEvents.at(i).addBranches("eta_2/D");
          treeEvents.at(i).addBranches("phi_2/D");
          treeEvents.at(i).addBranches("e_2/D");

          treeEvents.at(i).addBranches("Nparticles_3/I");
          treeEvents.at(i).addBranches("Ntracks_3/I");
          treeEvents.at(i).addBranches("pTD_3/D");
          treeEvents.at(i).addBranches("sigma1_3/D");
          treeEvents.at(i).addBranches("sigma2_3/D");
          treeEvents.at(i).addBranches("sigma_3/D");
          treeEvents.at(i).addBranches("pt_3/D");
          treeEvents.at(i).addBranches("eta_3/D");
          treeEvents.at(i).addBranches("phi_3/D");
          treeEvents.at(i).addBranches("e_3/D");

          treeEvents.at(i).addBranches("Nparticles_4/I");
          treeEvents.at(i).addBranches("Ntracks_4/I");
          treeEvents.at(i).addBranches("pTD_4/D");
          treeEvents.at(i).addBranches("sigma1_4/D");
          treeEvents.at(i).addBranches("sigma2_4/D");
          treeEvents.at(i).addBranches("sigma_4/D");
          treeEvents.at(i).addBranches("pt_4/D");
          treeEvents.at(i).addBranches("eta_4/D");
          treeEvents.at(i).addBranches("phi_4/D");
          treeEvents.at(i).addBranches("e_4/D");
          
          
          treeEvents.at(i).addBranches("z1/D");
          treeEvents.at(i).addBranches("z2/D");
          treeEvents.at(i).addBranches("DeltaR/D");
          treeEvents.at(i).addBranches("kt/D");
          treeEvents.at(i).addBranches("kt0/D");

          treeEvents.at(i).addBranches("Phi/D");
          treeEvents.at(i).addBranches("type/I");
          treeEvents.at(i).addBranches("match/I");

          treeEvents.at(i).addBranches("pt/D");
        }
    }
    void analyze() override {
        bool isoneGeVCut = true;
        int plane_num = events->pt3_Hadron->size();
        vector<ParticleInfo> jet2s(plane_num);
        vector<ParticleInfo> jet3s(plane_num);
        vector<ParticleInfo> jet4s(plane_num);
        vector<vector<ParticleInfo>> particles2(plane_num);
        vector<vector<ParticleInfo>> particles3(plane_num);
        vector<vector<ParticleInfo>> particles4(plane_num);
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

        int spin = events->spin;
        for(int i=0;i<plane_num;i++){
            if(events->jpt_Hadron->at(i)<450||events->jpt_Hadron->at(i)>600) continue;
            int isqq=events->isqq_Hadron->at(i);
            int isgg=events->isgg_Hadron->at(i);
            JetObservable JetObservable2(particles2.at(i));
            if(JetObservable2.jet_lorentzvector.Pt() >200||JetObservable2.jet_lorentzvector.Pt() <160) continue;
            JetObservable JetObservable3(particles3.at(i));
            JetObservable JetObservable4(particles4.at(i));
            
            auto width2 = JetObservable2.jetwidth();
            auto width3 = JetObservable3.jetwidth();
            auto width4 = JetObservable4.jetwidth();

            int type = events->isqq_Hadron->at(i) * 2 +
                                     events->isgg_Hadron->at(i);
            treeEvents.at(spin).BeginEvent();
            treeEvents.at(spin).assign("Nparticles_2",JetObservable2.Nparticles());
            treeEvents.at(spin).assign("Ntracks_2",JetObservable2.Ntracks());
            treeEvents.at(spin).assign("pTD_2",JetObservable2.pTD());
            treeEvents.at(spin).assign("sigma1_2",width2.sigma1);
            treeEvents.at(spin).assign("sigma2_2",width2.sigma2);
            treeEvents.at(spin).assign("sigma_2",width2.sigma);
            treeEvents.at(spin).assign("pt_2",jet2s.at(i).pt);
            treeEvents.at(spin).assign("eta_2",jet2s.at(i).eta);
            treeEvents.at(spin).assign("phi_2",jet2s.at(i).phi);
            treeEvents.at(spin).assign("e_2",jet2s.at(i).e);
            

            treeEvents.at(spin).assign("Nparticles_3",JetObservable3.Nparticles());
            treeEvents.at(spin).assign("Ntracks_3",JetObservable3.Ntracks());
            treeEvents.at(spin).assign("pTD_3",JetObservable3.pTD());
            treeEvents.at(spin).assign("sigma1_3",width3.sigma1);
            treeEvents.at(spin).assign("sigma2_3",width3.sigma2);
            treeEvents.at(spin).assign("sigma_3",width3.sigma);
            treeEvents.at(spin).assign("pt_3",jet3s.at(i).pt);
            treeEvents.at(spin).assign("eta_3",jet3s.at(i).eta);
            treeEvents.at(spin).assign("phi_3",jet3s.at(i).phi);
            treeEvents.at(spin).assign("e_3",jet3s.at(i).e);
            
            treeEvents.at(spin).assign("Nparticles_4",JetObservable4.Nparticles());
            treeEvents.at(spin).assign("Ntracks_4",JetObservable4.Ntracks());
            treeEvents.at(spin).assign("pTD_4",JetObservable4.pTD());
            treeEvents.at(spin).assign("sigma1_4",width4.sigma1);
            treeEvents.at(spin).assign("sigma2_4",width4.sigma2);
            treeEvents.at(spin).assign("sigma_4",width4.sigma);
            treeEvents.at(spin).assign("pt_4",jet4s.at(i).pt);
            treeEvents.at(spin).assign("eta_4",jet4s.at(i).eta);
            treeEvents.at(spin).assign("phi_4",jet4s.at(i).phi);
            treeEvents.at(spin).assign("e_4",jet4s.at(i).e);

            treeEvents.at(spin).assign("pt",events->jpt_Hadron->at(i));
            treeEvents.at(spin).assign("z1",events->z1_Hadron->at(i));
            treeEvents.at(spin).assign("z2",events->z2_Hadron->at(i));
            treeEvents.at(spin).assign("DeltaR",events->deltaR2_Hadron->at(i));
            treeEvents.at(spin).assign("kt",events->kt2_Hadron->at(i));
            treeEvents.at(spin).assign("kt0",events->kt1_Hadron->at(i));

            treeEvents.at(spin).assign("Phi",events->phi_Hadron->at(i));
            treeEvents.at(spin).assign("type",type);
            treeEvents.at(spin).assign("match",events->match->at(i));
        }
    }
};
// void Draw_plots_mini2(){
int main(int argc, char *argv[]) {
    std::string flav = "IFN";

    int opt;
    int chunki = 0;  

    while ((opt = getopt(argc, argv, "f:i:")) != -1) {
        switch (opt) {
        case 'f':
        flav = optarg;
        break;
        case 'i':
        chunki = atoi(optarg);  // 将参数转换为整数
        break;
        default:
        cerr << "Usage: " << argv[0] << " [-f flavour] [-i inputInt]" << endl;
        return 1;
        }
    }
    int nchunks = 100;

    for(int i=0;i<nchunks;i++){
        if(i!=chunki&&chunki!=-1) continue;
        double begin = i *1.0/nchunks;
        double events_frac = 1.0/nchunks;
        EventsAnalyzer analyzer(flav);
        analyzer.run_frac(events_frac,begin);
        SaveData::writeTreeEventsToRoot(analyzer.treeEvents.at(0),
                                    "/extdisk/zlin/Machine_learning/test/herwig_features2_May28_pt450/j2pt160_200/Features_Spinoff"+std::to_string(i+100)+".root", true);
        SaveData::writeTreeEventsToRoot(analyzer.treeEvents.at(1),
                                    "/extdisk/zlin/Machine_learning/test/herwig_features2_May28_pt450/j2pt160_200/Features_Spinon"+std::to_string(i+100)+".root", true);
    }
   
    return 0;
}    