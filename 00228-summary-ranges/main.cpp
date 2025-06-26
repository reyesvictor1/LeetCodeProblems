#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        
        std::vector<std::string> rangesVector;

        // corner cases
        if (nums.size() == 0) return rangesVector;
        if (nums.size() == 1) {
            rangesVector.push_back(std::to_string(nums[0]));
            return rangesVector;
        };

        int firstOfRange = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int currentValue = nums[i];
            int previousValue = nums[i - 1];
            bool isLastNum = i == nums.size() - 1;
            if (previousValue + 1 != currentValue) { // the range has ended
                std::string newRange = std::to_string(firstOfRange);
                if (previousValue != firstOfRange) newRange += "->" + std::to_string(previousValue);
                rangesVector.push_back(newRange);
                firstOfRange = currentValue; 
                // range has already ended, and current number is the last of the list
                if (isLastNum) rangesVector.push_back(std::to_string(currentValue));
            }
            else if (isLastNum) { // range has not ended, but current number is the last of the list
                std::string newRange = std::to_string(firstOfRange);
                if (currentValue != firstOfRange) newRange += "->" + std::to_string(currentValue);
                rangesVector.push_back(newRange);
            }
        }

        return rangesVector;
    }
};

int main() {
    std::vector<int> input = {0,2,3,4,6,7,8,9,15};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<std::string> output = solution.summaryRanges(input);
    std::cout << "output: ";
    for (std::string str : output) std::cout << str << ", ";
    std::cout << std::endl;

    return 0;
}