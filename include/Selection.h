#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include "SaveData.h"
class Selection {
public:
    template <typename T, typename U>
    static bool isWithinRange(const T& value, const std::vector<U>& range) {
        if (range.size() != 2) {
            throw std::invalid_argument("Range vector must have exactly 2 elements.");
        }
        
        // 如果右边界为 -1，则只检查左边界
        if (range[1] == static_cast<U>(-1)) {
            return value >= range[0];
        }

        // 否则检查完整的范围
        return value >= range[0] && value <= range[1];
    }
};