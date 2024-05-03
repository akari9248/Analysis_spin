#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

class ParticleChargeInfo {
private:
    std::unordered_map<int, int> pdgid_charge_map;

public:
    ParticleChargeInfo(const std::string& filename = "tabel/particle_charge.csv") {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int pdgid, charge;
            if (iss >> pdgid >> charge) {
                pdgid_charge_map[pdgid] = charge;
            }
        }

        file.close();
    }

    int getChargeThreetimes(int pdgid) const {
        int anti = 1;
        if(pdgid<0) anti =-1;
        pdgid = pdgid * anti;
        auto it = pdgid_charge_map.find(pdgid);
        if (it != pdgid_charge_map.end()) {
            return it->second * anti;
        }
        return 448; // 如果找不到对应的pdgid,返回0作为默认值
    }
};