#pragma once
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <TFile.h>
#include <TDirectory.h>
#include <TString.h>

// MetaData class declaration
class MetaData {
public:
    MetaData() = default;

    MetaData(const std::string& name) : name(name) {}

    void AddParameter(const std::string& key, const std::string& value) {
        parameterMap[key].push_back(value);
    }
    template <typename T, typename = std::enable_if_t<std::is_member_function_pointer<decltype(&T::GetName)>::value>>
    void AddParameter(const T& keyObj, const std::string& value) {
        std::string key = keyObj.GetName();
        parameterMap[key].push_back(value);
    }
    void AddParameter(const std::string& key, const std::vector<std::string>& values) {
        parameterMap[key].insert(parameterMap[key].end(), values.begin(), values.end());
    }

    const std::string& GetName() const {
        return name;
    }

    const std::map<std::string, std::vector<std::string>>& GetParameterMap() const {
        return parameterMap;
    }

    std::string GetParametersAsString() const {
        std::ostringstream os;
        for (const auto& pair : parameterMap) {
            os<< pair.first << ": \n";
            for (const auto& value : pair.second) {
                os << "     "<< value << " \n";
            }
        }
        return os.str();
    }

    void Clear() {
        name.clear();
        parameterMap.clear();
    }

private:
    std::string name;
    std::map<std::string, std::vector<std::string>> parameterMap;
};

// MetaDataManager class declaration
class MetaDataManager {
public:
    MetaDataManager() = default;
    ~MetaDataManager() = default;
    std::string RemovePrefix(const std::string &str, const std::string &prefix = "./")
    {
        if (str.compare(0, prefix.size(), prefix) == 0)
        {
            return str.substr(prefix.size());
        }
        return str;
    }
    MetaData* CreateMetaData(const std::string& name) {
        std::string cleanName = RemovePrefix(name);
        metaDataList.emplace_back(cleanName);
        return &metaDataList.back();
    }

    void SaveToRootFile(const std::string& fileName) {
        TFile file(fileName.c_str(), "UPDATE");
        if (file.IsZombie()) {
            std::cerr << "Error: Could not open the file." << std::endl;
            return;
        }

        TDirectory* dir = file.GetDirectory("MetaData");
        if (!dir) {
            dir = file.mkdir("MetaData");
        }
        dir->cd();

        for (auto& md : metaDataList) {
            std::string dirName = md.GetName();
            TDirectory* metaDir = dir->GetDirectory(dirName.c_str());
            if (!metaDir) {
                metaDir = dir->mkdir(dirName.c_str());
            }
            metaDir->cd();

            for (const auto& param : md.GetParameterMap()) {
                std::string paramDirName = param.first;
                TDirectory* paramDir = metaDir->GetDirectory(paramDirName.c_str());
                if (!paramDir) {
                    paramDir = metaDir->mkdir(paramDirName.c_str());
                }
                if (paramDir) {
                    paramDir->cd();
                } else {
                    std::cerr << "Error: Could not create or access directory " << paramDirName << std::endl;
                    continue;
                }

                int valueIndex = 0;
                for (const auto& value : param.second) {
                    TString tValue(value.c_str());
                    std::string valueName = value;
                    paramDir->WriteObject(&tValue, valueName.c_str());
                }
            }
        }

        file.Close();
    }

    void LoadFromRootFile(const std::string& fileName) {
        TFile file(fileName.c_str(), "READ");
        if (file.IsZombie()) {
            std::cerr << "Error: Could not open the file." << std::endl;
            return;
        }

        TDirectory* dir = file.GetDirectory("MetaData");
        if (!dir) {
            std::cerr << "Error: Could not find MetaData in file." << std::endl;
            return;
        }

        TList* keys = dir->GetListOfKeys();
        TIter next(keys);
        TObject* key;

        metaDataList.clear();
        while ((key = next())) {
            TDirectory* metaDir = dir->GetDirectory(key->GetName());
            if (!metaDir) continue;

            MetaData metaData(key->GetName());

            TList* paramKeys = metaDir->GetListOfKeys();
            TIter nextParam(paramKeys);
            TObject* paramKey;
            while ((paramKey = nextParam())) {
                TDirectory* paramDir = metaDir->GetDirectory(paramKey->GetName());
                if (!paramDir) continue;

                TList* valueKeys = paramDir->GetListOfKeys();
                TIter nextValue(valueKeys);
                TObject* valueKey;
                std::vector<std::string> values;
                while ((valueKey = nextValue())) {
                    if (valueKey->GetName()) {
                        values.push_back(valueKey->GetName());
                    }
                }

                metaData.AddParameter(paramKey->GetName(), values);
            }

            metaDataList.push_back(metaData);
        }

        file.Close();
    }

    std::string GetMetaDataAsString() const {
        std::ostringstream os;
        for (const auto& metaData : metaDataList) {
            os << "MetaData: " << metaData.GetName() << "\n";
            os << metaData.GetParametersAsString();
        }
        return os.str();
    }

private:
    std::vector<MetaData> metaDataList;
};