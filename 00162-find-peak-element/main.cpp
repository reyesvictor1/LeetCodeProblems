#include <iostream>
#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {

        if (nums.size() < 2) return 0;

        for (int idx = 0; idx < nums.size(); idx++) {

            int currentValue = nums[idx];

            // corner case: checking first element
            if (idx == 0) {
                if (currentValue > nums[idx + 1])
                    return idx; // return first index
                else continue;
            }
            
            // corner case: checking last element
            if (idx == nums.size() - 1) {
                if (currentValue > nums[idx - 1])
                    return idx; // return last index
                else continue;
            }
            
            // check normal cases
            if (nums[idx - 1] < currentValue && currentValue > nums[idx + 1])
                return idx;
        }

        return 0;

    }
};

int main() {
    std::vector<int> input = {1,2,3,1};
    std::cout << "input: [ ";
    for (int num : input) std::cout << num << " ";
    std::cout << "]" << std::endl;

    Solution solution;
    int output = solution.findPeakElement(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}