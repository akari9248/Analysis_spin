#pragma once
#include "ParticleInfo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class JetObservable {
  ParticleInfo jet;
  vector<ParticleInfo> particles;
public:
  TLorentzVector jet_lorentzvector;
  struct Jetwidth {
    double sigma1;
    double sigma2;
    double sigma;

    Jetwidth(double _sigma1, double _sigma2, double _sigma)
        : sigma1(_sigma1), sigma2(_sigma2), sigma(_sigma) {}
  };
  JetObservable(ParticleInfo _jet, vector<ParticleInfo> _particles) {
    jet = _jet;
    particles = _particles;
    for(auto &particle:particles){
      TLorentzVector p;
      p.SetPtEtaPhiE(particle.pt,particle.eta,particle.phi,particle.e);
      jet_lorentzvector+=p;
    }
  }
  JetObservable(vector<ParticleInfo> _particles) {
    particles = _particles;
    for(auto &particle:particles){
      TLorentzVector p;
      p.SetPtEtaPhiE(particle.pt,particle.eta,particle.phi,particle.e);
      jet_lorentzvector+=p;
    }
  }
  int Ntracks() {
    int ntracks = 0;
    for (auto particle : particles) {
      if (particle.charge != 0)
        ntracks++;
    }
    return ntracks;
  }
  int Nparticles() { return particles.size(); }
  double pTD() {
    double pt2_sum = 0;
    double pt_sum = 0;
    for (auto particle : particles) {
      pt2_sum += particle.pt * particle.pt;
      pt_sum += particle.pt;
    }
    return sqrt(pt2_sum) / pt_sum;
  }
  Jetwidth jetwidth() {
    double M11 = 0;
    double M22 = 0;
    double M12 = 0;
    double M21 = 0;
    double pt2_sum = 0;
    // TLorentzVector jet_lorentzvector;
    // jet_lorentzvector.SetPtEtaPhiE(jet.pt, jet.eta, jet.phi, jet.e);

    for (auto particle : particles) {
      TLorentzVector particle_lorentzvector;
      particle_lorentzvector.SetPtEtaPhiE(particle.pt, particle.eta,
                                          particle.phi, particle.e);

      double deltaphi = particle_lorentzvector.DeltaPhi(jet_lorentzvector);
      double deltaeta =
          abs(particle_lorentzvector.Eta() - jet_lorentzvector.Eta());

      M11 += particle.pt * particle.pt * deltaeta * deltaeta;
      M22 += particle.pt * particle.pt * deltaphi * deltaphi;
      M12 += -particle.pt * particle.pt * deltaeta * deltaphi;
      M21 += -particle.pt * particle.pt * deltaeta * deltaphi;

      pt2_sum += particle.pt * particle.pt;
    }
    double lambda1 =
        (M11 + M22 + sqrt((M11 - M22) * (M11 - M22) + 4 * M21 * M12)) / 2.0;
    double lambda2 =
        (M11 + M22 - sqrt((M11 - M22) * (M11 - M22) + 4 * M21 * M12)) / 2.0;
    double sigma1 = sqrt(lambda1 / pt2_sum);
    double sigma2 = sqrt(lambda2 / pt2_sum);
    double sigma = sqrt(sigma1 * sigma1 + sigma2 * sigma2);
    return Jetwidth(sigma1, sigma2, sigma);
  }
  static int determineType(int flavour1, int flavour2)
  {
    if (flavour2 == 21 && flavour1 == 21)
    {
      return 1;
    }
    if (flavour1 != 0 && flavour1 != 21 && flavour2 != 0 && flavour2 != 21)
    {
      return 2;
    }
    if (flavour1 != 0 && flavour1 != 21 && flavour2 == 21)
    {
      return 3;
    }
    if (flavour2 != 0 && flavour2 != 21 && flavour1 == 21)
    {
      return 3;
    }
    if (flavour1 != 0 && flavour1 != 21 && flavour2 == 0)
    {
      return 4;
    }
    if (flavour2 != 0 && flavour2 != 21 && flavour1 == 0)
    {
      return 4;
    }
    if (flavour1 == 21 && flavour2 == 0)
    {
      return 5;
    }
    if (flavour2 == 21 && flavour1 == 0)
    {
      return 5;
    }
    return 0;
  }
};