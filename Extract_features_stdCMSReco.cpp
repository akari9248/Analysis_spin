// gInterpreter->AddIncludePath("/home/zlin/.local/include");
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
#include "include/AdvancedDataInfoCMS.h"
#include "include/Selection.h"
// #include "include/common_tool.h"
class EventsAnalyzer : public SampleAnalyzer<AdvancedDataInfoCMS>
{
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
    double NextPassedNumber;
    EventsAnalyzer(CommonTool::Options options) { 
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
    void initialize() override
    {
        t->Add((TString)inputFolder+"/Chunk*.root/DataInfo");

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

        treeEvents.addBranches("z1/D");
        treeEvents.addBranches("z2/D");
        treeEvents.addBranches("DeltaR/D");
        treeEvents.addBranches("kt/D");
        treeEvents.addBranches("kt0/D");

        treeEvents.addBranches("Phi/D");
        treeEvents.addBranches("type/I");

        treeEvents.addBranches("pt/D");
        treeEvents.addBranches("GeneratorWeight/D");
        treeEvents.addBranches("NextPassedNumber/D");
        NextPassedNumber=0;
    }
    void analyze() override
    {
        int plane_num = events->Recopt3->size();
        vector<ParticleInfo> jet2s(plane_num);
        vector<ParticleInfo> jet3s(plane_num);
        vector<ParticleInfo> jet4s(plane_num);
        vector<vector<ParticleInfo>> particles2(plane_num);
        vector<vector<ParticleInfo>> particles3(plane_num);
        vector<vector<ParticleInfo>> particles4(plane_num);
        for (int i = 0; i < plane_num; i++)
        {
            ParticleInfo particle(events->Recopt2->at(i),
                                  events->Recoeta2->at(i),
                                  events->Recophi2->at(i),
                                  events->Recoe2->at(i));

            jet2s.at(i) = particle;
        }
        for (int i = 0; i < plane_num; i++)
        {
            ParticleInfo particle(events->Recopt3->at(i),
                                  events->Recoeta3->at(i),
                                  events->Recophi3->at(i),
                                  events->Recoe3->at(i));

            jet3s.at(i) = particle;
        }
        for (int i = 0; i < plane_num; i++)
        {

            ParticleInfo particle(events->Recopt4->at(i),
                                  events->Recoeta4->at(i),
                                  events->Recophi4->at(i),
                                  events->Recoe4->at(i));
            jet4s.at(i) = particle;
        }
        for (int i = 0; i < events->Recoparticle2_jetid->size(); i++)
        {
            int jetid = events->Recoparticle2_jetid->at(i);
            ParticleInfo particle(events->Recoparticle2_pid->at(i),
                                  events->Recoparticle2_charge->at(i),
                                  events->Recoparticle2_pt->at(i),
                                  events->Recoparticle2_eta->at(i),
                                  events->Recoparticle2_phi->at(i),
                                  events->Recoparticle2_e->at(i));
            particles2.at(jetid).push_back(particle);
        }
        for (int i = 0; i < events->Recoparticle3_jetid->size(); i++)
        {
            int jetid = events->Recoparticle3_jetid->at(i);
            ParticleInfo particle(events->Recoparticle3_pid->at(i),
                                  events->Recoparticle3_charge->at(i),
                                  events->Recoparticle3_pt->at(i),
                                  events->Recoparticle3_eta->at(i),
                                  events->Recoparticle3_phi->at(i),
                                  events->Recoparticle3_e->at(i));
            particles3.at(jetid).push_back(particle);
        }
        for (int i = 0; i < events->Recoparticle4_jetid->size(); i++)
        {
            int jetid = events->Recoparticle4_jetid->at(i);
            ParticleInfo particle(events->Recoparticle4_pid->at(i),
                                  events->Recoparticle4_charge->at(i),
                                  events->Recoparticle4_pt->at(i),
                                  events->Recoparticle4_eta->at(i),
                                  events->Recoparticle4_phi->at(i),
                                  events->Recoparticle4_e->at(i));
            particles4.at(jetid).push_back(particle);
        }

        int spin = 0;
        int unit_NextPassedNumber = events->NextPassedNumber*1.0/plane_num;
        for (int i = 0; i < plane_num; i++)
        {
            NextPassedNumber+= unit_NextPassedNumber;
            double jesscale = events->Recojes_scale->at(i);
            if (!Selection::isWithinRange(events->Recojpt->at(i) * jesscale, jinit_range))
                continue;
            int isqq = events->Recoisqq->at(i);
            int isgg = events->Recoisgg->at(i);
            JetObservable JetObservable2(particles2.at(i));
            if (!Selection::isWithinRange(JetObservable2.jet_lorentzvector.Pt() * jesscale, j2_range))
                continue;
                
            auto width2 = JetObservable2.jetwidth();
            JetObservable JetObservable3(particles3.at(i));
            auto width3 = JetObservable3.jetwidth();
            JetObservable JetObservable4(particles4.at(i));
            auto width4 = JetObservable4.jetwidth();
            int type = 0;
            if (JetObservable3.Nparticles() == 0 || JetObservable4.Nparticles() == 0)
            {
                continue;
            }
            treeEvents.BeginEvent();
            treeEvents.assign("NextPassedNumber", NextPassedNumber);
            NextPassedNumber=0;
            treeEvents.assign("PassPileUpRm", events->PassPileUpRm);
            treeEvents.assign("GeneratorWeight", events->GeneratorWeight);
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

            treeEvents.assign("pt", events->Recojpt->at(i));
            treeEvents.assign("z1", events->Recoz1->at(i));
            treeEvents.assign("z2", events->Recoz2->at(i));
            treeEvents.assign("DeltaR", events->RecodeltaR2->at(i));
            treeEvents.assign("kt", events->Recokt2->at(i));
            treeEvents.assign("kt0", events->Recokt1->at(i));

            treeEvents.assign("Phi", events->Recophi->at(i));
            treeEvents.assign("type", type);
        }
    }
};

int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv);
    EventsAnalyzer analyzer(options);
    CommonTool::processAndSaveData(options, analyzer);
    return 0;
}