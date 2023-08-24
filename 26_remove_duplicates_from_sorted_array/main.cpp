#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        for (int num : nums) {
            auto it = std::find(nums.begin(), nums.end(), num);
            while (std::find(it + 1, nums.end(), num) != nums.end()) {
                nums.erase(it);
            }
        }
        std::cout << "OUTPUT: ";
        for (int num : nums) { std::cout << num << " "; }
        std::cout << std::endl;
        return nums.size();
    }
};

int main() {
    
    std::vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << "INPUT: ";
    for (int num : input) { std::cout << num << " "; }
    std::cout << std::endl;
    Solution solution;
    int result = solution.removeDuplicates(input);
    std::cout << result << std::endl;

    return 0;
}