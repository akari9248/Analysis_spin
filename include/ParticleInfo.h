#pragma once
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include "fastjet/contrib/FlavInfo.hh"
#include "fastjet/contrib/IFNPlugin.hh"
#include "TLorentzVector.h"
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <cassert>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <random>
// 使用FastJet的命名空间
using namespace fastjet;
using namespace std;
using namespace fastjet::contrib;
class ParticleInfo : public PseudoJet::UserInfoBase{
  public:
  int pdgid,index;
  double charge;
  int chargeInt;
  double px,py,pz,e;
  double pt,eta,phi;
  // ParticleInfo(int pdgid_,int index_,double px_,double py_,double pz_,double e_){
  //   pdgid = pdgid_;
  //   index = index_;
  //   px = px_;
  //   py = py_;
  //   pz = pz_;
  //   e = e_;
  // }
  ParticleInfo(int pdgid_,double charge_,double pt_,double eta_,double phi_,double e_){
    pdgid = pdgid_;
    charge = charge_;
    pt = pt_;
    eta = eta_;
    phi = phi_;
    e = e_;
  }
  ParticleInfo(int pdgid_,int charge_,double pt_,double eta_,double phi_,double e_){
    pdgid = pdgid_;
    chargeInt = charge_;
    charge = charge_;
    pt = pt_;
    eta = eta_;
    phi = phi_;
    e = e_;
  }
  ParticleInfo(double pt_,double eta_,double phi_,double e_){
    pt = pt_;
    eta = eta_;
    phi = phi_;
    e = e_;
  }
  ParticleInfo(int pdgid_,int charge_){
    pdgid = pdgid_;
    charge = charge_;
    chargeInt = charge_;
  }
  ParticleInfo(){}
};
