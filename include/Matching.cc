#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <unordered_map>
#include <vector>
#include "TLorentzVector.h"
#include "JetBranch.h"
using namespace std;
class Matching {
 private:
  static std::vector<int> matchSrcAndDst(
      std::vector<TLorentzVector> src,
      std::vector<TLorentzVector> dst,
      double drCut, std::function<bool(unsigned, unsigned)> isContinue) {
    std::vector<int> results(src.size(), -1);
    std::vector<bool> flags(dst.size(), false);
    for (unsigned isrc = 0; isrc < src.size(); isrc++) {
      auto matches = std::vector<int>{};
      for (unsigned idst = 0; idst < dst.size(); idst++) {
        if (flags[idst]) continue;
        if (isContinue(isrc, idst)) continue;
        double dr = src.at(isrc).DeltaR(dst.at(idst));
        if (dr > drCut) continue;
        if (results[isrc] == -1) {
          // do matching when all conditions passed
          results[isrc] = idst;
          flags[idst] = true;
          matches.push_back(idst);
          continue;
        }
        // assign double match status to -2, and store them in map
        matches.push_back(idst);
        results[isrc] = -2;  // -2 means double match situation
        // remember to restore these ptc in flags to false
        for (auto m : matches) flags[m] = false;
      }
      // then handle this isrc if it's double match
      if (matches.size() <= 1) continue;
      double min = 999999999.9;
      int nearest = -1;
      for (unsigned i = 0; i < matches.size(); i++) {
        int idst = matches.at(i);
        // we need nearest pt particle
        double diff = abs(src.at(isrc).Pt() - dst.at(idst).Pt());
        if (diff > min) continue;
        nearest = idst;
        min = diff;
      }
      results[isrc] = nearest;
      flags[nearest] = true;
    }
    // sanity checking
    for (auto v : results) {
      // there should be no double match after we handle them
      if (v == -2) {
        cout << "double matching jet still there" <<endl;
      }
    }
    return results;
  }
  std::vector<int> matchSrcAndDstDaughter(
      std::vector<TLorentzVector> src, std::vector<int> srcJetIds,
      std::vector<double> srcPts, std::vector<int> srcCharges,
      std::vector<int> srcMatchJets, std::vector<TLorentzVector> dst,
      std::vector<int> dstJetIds, std::vector<double> dstPts,
      std::vector<int> dstCharges) {
    std::vector<int> results(src.size(), -1);
    std::vector<bool> flags(dst.size(), false);
    for (unsigned isrc = 0; isrc < src.size(); isrc++) {
      int srcJetId = srcJetIds.at(isrc);
      int matchJetId = srcMatchJets.at(srcJetId);
      if (matchJetId < 0) continue;

      double min = 999999999.9;
      int id = -1;
      for (unsigned idst = 0; idst < dst.size(); idst++) {
        if (matchJetId != dstJetIds.at(idst)) continue;
        if (srcCharges.at(isrc) == 0 && dstCharges.at(idst) != 0) continue;
        if (srcCharges.at(isrc) != 0 && dstCharges.at(idst) == 0) continue;
        if (flags[idst]) continue;

        double drCut;
        double daunum = 0;
        for (unsigned i = 0; i < src.size(); i++) {
          if (srcJetIds.at(i) == srcJetId) {
            daunum += 1;
          }
        }
        drCut = sqrt(0.16 / 10 / sqrt(daunum));
        double dr = src.at(isrc).DeltaR(dst.at(idst));
        if (dr > drCut) continue;

        double diff = abs(srcPts.at(isrc) - dstPts.at(idst));
        //&& diff < (srcPts.at(isrc) + dstPts.at(idst))
        if (diff < min) {
          min = diff;
          id = idst;
        }
      }
      if (id != -1) {
        results[isrc] = id;
        flags[id] = true;
      }
    }
    // sanity checking
    for (auto v : results) {
      // there should be no double match after we handle them
      if (v == -2) {
        cout << "double matching jet still there" <<endl;;
      }
    }
    return results;
  }

 public:
  static std::vector<int> matchJet(std::vector<TLorentzVector> &src,
                            std::vector<TLorentzVector> &dst,
                             double drCut = 0.2) {
    return matchSrcAndDst(src, dst, drCut,
                          [](unsigned isrc, unsigned idst) { return false; });
  }
  
  std::vector<int> matchDaughter(
      std::vector<TLorentzVector> src, std::vector<int> srcJetIds,
      std::vector<int> srcCharges, std::vector<double> srcPts,
      std::vector<int> srcMatchJets, std::vector<TLorentzVector> dst,
      std::vector<int> dstJetIds, std::vector<int> dstCharges,
      std::vector<double> dstPts, double drCut = 0.05) {
    // sanity checking
    if (src.size() != srcJetIds.size()) {
      cout << "dims of src p4 and jetid not equal!"<<endl;
    }
    if (dst.size() != dstJetIds.size()) {
      cout << "dims of dst p4 and jetid not equal!"<<endl;
    }
    return matchSrcAndDstDaughter(src, srcJetIds, srcPts, srcCharges,
                                  srcMatchJets, dst, dstJetIds, dstPts,
                                  dstCharges);
  }

  std::vector<int> copyMatchInfo(int size, std::vector<int> infos) {
    std::vector<int> results(size, -1);
    for (unsigned i = 0; i < infos.size(); i++) {
      if (infos.at(i) < 0) continue;
      results.at(infos.at(i)) = i;
    }

    return results;
  }
};
