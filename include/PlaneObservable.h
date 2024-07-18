#pragma once
#include "ParticleInfo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class PlaneObservable {
public:
  struct plane {
    TLorentzVector jet1;
    TLorentzVector jet2;
    TVector3 n;
    plane(double pt1, double eta1, double phi1,double e1,
          double pt2, double eta2, double phi2,double e2){
            jet1.SetPtEtaPhiE(pt1,eta1,phi1,e1);
            jet2.SetPtEtaPhiE(pt2,eta2,phi2,e2);
            GetPlaneVector();
    }
    plane(TLorentzVector _j1,
          TLorentzVector _j2){
            jet1=_j1;
            jet2=_j2;
            GetPlaneVector();
    }
    void GetPlaneVector() {
      n = jet1.Vect().Cross(jet2.Vect());
    }
  };
  static double DeltaPhi(plane plane1, plane plane2) {
    TVector3 n1 = plane1.n;
    TVector3 n2 = plane2.n;
    n1 = n1.Unit();
    n2 = n2.Unit();
    double cos_angle = abs(n1.Dot(n2));
    if ((n1.Cross(n2)).Dot(plane2.jet1.Vect()) < 0) {
      cos_angle = -1.0 * cos_angle;
    }
    double angle_radians = TMath::ACos(cos_angle);
    return angle_radians;
  }
};