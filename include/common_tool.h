#pragma once
#include <iostream>
#include <string>
#include <vector>
class CommonTool {
    public:
  template <typename T>
  std::vector<T> static concatenate(const std::vector<T> &v1,
                             const std::vector<T> &v2) {
    std::vector<T> result;
    result.reserve(v1.size() + v2.size()); // 预先分配足够的空间以提高效率
    result.insert(result.end(), v1.begin(),
                  v1.end()); // 插入第一个 vector 的所有元素
    result.insert(result.end(), v2.begin(),
                  v2.end()); // 插入第二个 vector 的所有元素
    return result;
  }
  template <typename T>
    static void concatenateToFirstVect(std::vector<T>& v1, const std::vector<T>& v2) {
            v1.insert(v1.end(), v2.begin(), v2.end());
  }
};