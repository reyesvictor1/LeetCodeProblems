#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {

        bool hasZeroesBefore = false;
        int lastIndexNonZero = -1;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] == 0) {
                hasZeroesBefore = true;
                continue;
            }
            if (hasZeroesBefore) {
                std::swap(nums[lastIndexNonZero + 1], nums[idx]); 
            }
            lastIndexNonZero++;
        }
    }
};

int main() {

    std::vector<int> nums = {0, 3, 5, 0, 12};
    
    std::cout << "input: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    solution.moveZeroes(nums);
    std::cout << "output: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}