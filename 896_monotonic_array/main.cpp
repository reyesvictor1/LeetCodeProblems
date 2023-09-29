#include <iostream>
#include <vector>

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {

        if (nums.size() <= 2) return true;

        int previous = nums[0];
        bool increasing = false;
        bool decreasing = false;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (!increasing && !decreasing) {
                if (nums[idx] == previous) continue;
                if (nums[idx] > previous) increasing = true;
                if (nums[idx] < previous) decreasing = true; 
            }
            if (increasing && nums[idx] < previous) return false;
            if (decreasing && nums[idx] > previous) return false;
            previous = nums[idx];
        }
        return true;
    }
};

int main() {

    std::vector<int> input = {1, 2, 2, 3, 5};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::cout << "output: " << solution.isMonotonic(input);
    
    return 0;

}