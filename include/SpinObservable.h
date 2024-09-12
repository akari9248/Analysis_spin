#pragma once
#include "ParticleInfo.h"
#include <iostream>
#include <string>
#include <vector>
#include "TLorentzVector.h"
using namespace std;
class SpinObservable
{
public:
  struct PlaneTheta{
    double dphi12_X;
    double theta;
    double theta2;
  };
  TLorentzVector j1, j2, j3, j4,j1_sort,j2_sort,j3_sort,j4_sort;
  SpinObservable(TLorentzVector _j1, TLorentzVector _j2, TLorentzVector _j3, TLorentzVector _j4)
  {
    j1 = _j1;
    j2 = _j2;
    j3 = _j3;
    j4 = _j4;
    j1_sort = (_j1.Pt() > _j2.Pt()) ? _j1 : _j2;
    j2_sort = (_j1.Pt() > _j2.Pt()) ? _j2 : _j1;
    j3_sort = (_j3.Pt() > _j4.Pt()) ? _j3 : _j4;
    j4_sort = (_j3.Pt() > _j4.Pt()) ? _j4 : _j3;
  }
  SpinObservable(vector<ParticleInfo> _p1, vector<ParticleInfo> _p2, vector<ParticleInfo> _p3, vector<ParticleInfo> _p4)
  {
    for(auto &particle:_p1){
      TLorentzVector p;
      p.SetPtEtaPhiE(particle.pt,particle.eta,particle.phi,particle.e);
      j1+=p;
    }
    for(auto &particle:_p2){
      TLorentzVector p;
      p.SetPtEtaPhiE(particle.pt,particle.eta,particle.phi,particle.e);
      j2+=p;
    }
    for(auto &particle:_p3){
      TLorentzVector p;
      p.SetPtEtaPhiE(particle.pt,particle.eta,particle.phi,particle.e);
      j3+=p;
    }
    for(auto &particle:_p4){
      TLorentzVector p;
      p.SetPtEtaPhiE(particle.pt,particle.eta,particle.phi,particle.e);
      j4+=p;
    }
  }
  // Asume X -> j1 j2,  j2->j3 j4
  PlaneTheta GetPlaneTheta()
  {
    TLorentzVector t1, t2, t21, t22, X;
    t1=j1;
    t21=j3;
    t22=j4;
    t2 = t21 + t22;
    X = t1 + t2;

    TVector3 boostp2 = -(t2.BoostVector());
    TVector3 boostX = -(X.BoostVector());

    TLorentzVector t21_p2(t21);
    t21_p2.Boost(boostp2);
    TLorentzVector t22_p2(t22);
    t22_p2.Boost(boostp2);
    TLorentzVector t1_p2(t1);
    t1_p2.Boost(boostp2);

    TLorentzVector t2_pX(t2);
    t2_pX.Boost(boostX);
    TLorentzVector t1_pX(t1);
    t1_pX.Boost(boostX);
    TLorentzVector t21_X(t21);
    t21_X.Boost(boostX);
    TLorentzVector t22_X(t22);
    t22_X.Boost(boostX);
    PlaneTheta planetheta;
    // phi12

    TVector3 tmp1 = t2_pX.Vect().Cross(X.Vect());
    TVector3 tmp2;
    int i =rand();
    if (i % 2 == 0)
      tmp2 =  t22_X.Vect().Cross(t21_X.Vect()); // p2
    else
      tmp2 = t21_X.Vect().Cross(t22_X.Vect()); // p2
    planetheta.dphi12_X = acos(tmp1.Dot(tmp2) / tmp1.Mag() / tmp2.Mag());
    
    // theta*
    if (i % 2 == 0)
      planetheta.theta = acos(t1_pX.Vect().Dot(X.Vect()) / t1_pX.Vect().Mag() / X.Vect().Mag());
    else
      planetheta.theta = acos(t2_pX.Vect().Dot(X.Vect()) / t2_pX.Vect().Mag() / X.Vect().Mag());
    // theta2
    if (i % 2 == 0)
      planetheta.theta2 = acos(t1_p2.Vect().Dot(t21_p2.Vect()) / t1_p2.Vect().Mag() / t21_p2.Vect().Mag());
    else
      planetheta.theta2 = acos(t1_p2.Vect().Dot(t22_p2.Vect()) / t1_p2.Vect().Mag() / t22_p2.Vect().Mag());
    return planetheta;
  }
  // Asume X -> t1 t2 -> j1 j2 j3 j4
  PlaneTheta GetPlaneTheta2()
  {
    TLorentzVector t1, t2, t21, t22, X,t11,t12;
    t1=j1+j2;
    t11=j1;
    t12=j2;
    t21=j3;
    t22=j4;
    t2 = t21 + t22;
    X = t1 + t2;

    TVector3 boostp2 = -(t2.BoostVector());
    TVector3 boostX = -(X.BoostVector());

    
    TLorentzVector t21_p2(t21);
    t21_p2.Boost(boostp2);
    TLorentzVector t22_p2(t22);
    t22_p2.Boost(boostp2);
    TLorentzVector t1_p2(t1);
    t1_p2.Boost(boostp2);

    TLorentzVector t2_pX(t2);
    t2_pX.Boost(boostX);
    TLorentzVector t1_pX(t1);
    t1_pX.Boost(boostX);
    TLorentzVector t11_X(t11);
    t11_X.Boost(boostX);
    TLorentzVector t12_X(t12);
    t12_X.Boost(boostX);
    TLorentzVector t21_X(t21);
    t21_X.Boost(boostX);
    TLorentzVector t22_X(t22);
    t22_X.Boost(boostX);
    PlaneTheta planetheta;
    // phi12

    TVector3 tmp1 = t11_X.Vect().Cross(t12_X.Vect());
    TVector3 tmp2;
    int i =rand();
    if (i % 2 == 0)
      tmp2 =  t22_X.Vect().Cross(t21_X.Vect()); // p2
    else
      tmp2 = t21_X.Vect().Cross(t22_X.Vect()); // p2
    planetheta.dphi12_X = acos(tmp1.Dot(tmp2) / tmp1.Mag() / tmp2.Mag());
    
    // theta*
    if (i % 2 == 0)
      planetheta.theta = acos(t1_pX.Vect().Dot(X.Vect()) / t1_pX.Vect().Mag() / X.Vect().Mag());
    else
      planetheta.theta = acos(t2_pX.Vect().Dot(X.Vect()) / t2_pX.Vect().Mag() / X.Vect().Mag());
    // theta2
    if (i % 2 == 0)
      planetheta.theta2 = acos(t1_p2.Vect().Dot(t21_p2.Vect()) / t1_p2.Vect().Mag() / t21_p2.Vect().Mag());
    else
      planetheta.theta2 = acos(t1_p2.Vect().Dot(t22_p2.Vect()) / t1_p2.Vect().Mag() / t22_p2.Vect().Mag());
    return planetheta;
  }
  double GetPhi(){
    auto n1 = j1_sort.Vect().Cross(j2_sort.Vect());
    auto n2 = j3_sort.Vect().Cross(j4_sort.Vect());
    n1 = n1.Unit();
    n2 = n2.Unit();
    double cos_angle = abs(n1.Dot(n2));
    if ((n1.Cross(n2)).Dot(j3_sort.Vect()) < 0) {
      cos_angle = -1.0 * cos_angle;
    }
    double angle_radians = TMath::ACos(cos_angle);
    return angle_radians;
  }
};