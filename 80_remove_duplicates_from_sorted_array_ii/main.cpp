#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {

        if (nums.empty()) return 0;
        
        int k = nums.size();
        int analyzedValue = nums.front();
        int repetitions = 1;
        int maxRepetitions = 2;
        int checkedElements = 0;

        for (int idx = 0; idx < nums.size(); idx++) {

            if (idx != 0) {
                if (analyzedValue == nums[idx]) {
                    repetitions++;
                    if (repetitions > maxRepetitions) {
                        nums.erase(nums.begin() + idx);
                        nums.push_back(0);
                        idx--;
                        k--;
                    }
                } else {
                    repetitions = 1;
                    analyzedValue = nums[idx];
                }
            }

            checkedElements++;
            if (checkedElements == nums.size()) break;

        }

        return k;
    }
};

int main() {

    std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    std::cout << "nums: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int k = solution.removeDuplicates(nums);
    std::cout << "k: " << k << std::endl;
    std::cout << "nums: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}