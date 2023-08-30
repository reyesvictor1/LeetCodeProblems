#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if (target <= nums[i]) return i;
        return nums.size();
    }
};

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 4;
    Solution solution;
    int result = solution.searchInsert(nums, target);

    std::cout << "input: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "target: " << target << std::endl;
    std::cout << "result: " << result << std::endl;
}