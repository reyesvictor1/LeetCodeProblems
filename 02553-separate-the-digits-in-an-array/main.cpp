#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> resultingVector;
        int value = 0;
        int singleDigit = 0;
        for (int i = 0; i < nums.size(); i++) {
            value = nums[i];
            std::string str = std::to_string(value);
            for (int j = 0; j < str.size(); j++) {
                // std::cout << typeid(str[j]).name() << std::endl;
                singleDigit = int(str[j]) - 48;
                // std::cout << typeid(singleDigit).name() << std::endl;
                resultingVector.push_back(singleDigit);
            }
        }
        return resultingVector;
    }
};

template <typename T>
void vectorPrinter(std::vector<T> myVector) {
    std::cout << "[";
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i];
        if (i != myVector.size()-1) std::cout << ",";  
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<int> input{13,25,83,77};
    vectorPrinter(input);
    Solution mySolution;
    std::vector<int> output = mySolution.separateDigits(input);
    vectorPrinter(output);
    return 0;
}