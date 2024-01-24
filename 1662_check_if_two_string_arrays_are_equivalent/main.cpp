#include <iostream>
#include <vector>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string> &stringVectorA, std::vector<std::string> &stringVectorB) {

        std::string A;
        std::string B;

        for (std::string str : stringVectorA) A += str;
        for (std::string str : stringVectorB) B += str;

        if (A.size() != B.size()) return false;

        for (int idx = 0; idx < A.size(); idx++) {
            if (A[idx] != B[idx]) return false;
        }

        return true;
    }   
};

int main() {
    std::vector<std::string> stringVectorA{"ab", "c"};
    std::vector<std::string> stringVectorB{"a", "bc"};

    std::cout << "vector A: ";
    for (std::string str : stringVectorA) std::cout << str << " ";
    std::cout << std::endl;

    std::cout << "vector B: ";
    for (std::string str : stringVectorB) std::cout << str << " ";
    std::cout << std::endl;

    Solution solution;
    bool output = solution.arrayStringsAreEqual(stringVectorA, stringVectorB);
    std::cout << "output: " << output << std::endl;

    return 0;
}