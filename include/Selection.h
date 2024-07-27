#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include "SaveData.h"
class Selection {
public:
    using Condition = std::function<bool()>;
    std::string name;
    std::vector<std::function<bool()>> conditions;

    Selection(const std::string& _name) : name(_name) {}
    void AddCondition(const std::function<bool()>& condition) {
        conditions.push_back(condition);
    }
    Selection() {}

    bool Evaluate() const {
        bool result = true;
        for (const auto& condition : conditions) {
            result = result&&condition();
        }
        return result;
    }
    std::string GetName() const {
        return name;
    }
    template <typename Func, typename... Args>
    static Condition make_condition(Func&& func, Args&&... args) {
        return [=]() { return func(args...); };
    }
    template <typename T, typename U>
    static bool isWithinRange(const T& value, const std::vector<U>& range) {
        if (range.size() != 2) {
            throw std::invalid_argument("Range vector must have exactly 2 elements.");
        }
        if (range[1] == static_cast<U>(-1)) {
            return value >= range[0];
        }
        return value >= range[0] && value <= range[1];
    }
};