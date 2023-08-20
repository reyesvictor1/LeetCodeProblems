#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int firstIndex, secondIndex, total;
        bool solved = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    total = nums[i] + nums[j]; 
                    if (total == target) {
                        firstIndex = i;
                        secondIndex = j;
                        solved = true;
                        break;
                    }                 
                }
            }
            if (solved) break;
        }
        result.push_back(firstIndex);   
        result.push_back(secondIndex); 
        return result;  
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
    std::vector<int> input{1,3,4,5,8};
    int target = 11;
    std::cout <<  "target: " << target << std::endl;
    vectorPrinter(input);
    Solution mySolution;
    std::vector<int> output = mySolution.twoSum(input, target);
    vectorPrinter(output);
    return 0;
}