#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        int removeElement(std::vector<int>& nums, int valueToRemove) {
            
            while (std::find(nums.begin(), nums.end(), valueToRemove) != nums.end()) {
                nums.erase(std::find(nums.begin(), nums.end(), valueToRemove));
            };

            std::cout << "Output: ";
            for (int num : nums) { std::cout << num << ", "; }
            std::cout << std::endl;
            
            return nums.size();
        }
};

int main() {
    std::vector<int> input = {0, 1, 2, 2, 3, 0, 4, 2};
    int valueToRemove = 2;

    std::cout << "Input: ";
    for (int num : input) { std::cout << num << ", "; }
    std::cout << std::endl;

    std::cout << "Value to remove: " << valueToRemove << std::endl;

    Solution solution;
    int result = solution.removeElement(input, valueToRemove);
     std::cout << "size: " << result << std::endl;

    return 0;
}