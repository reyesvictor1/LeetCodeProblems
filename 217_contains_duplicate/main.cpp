#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (std::count(nums.begin(), nums.end(), *it) > 1)
            return true;
        }
        return false;
    } 
};

int main() {
    std::vector<int> input = {1, 2, 3, 5};
    Solution solution;
    bool output = solution.containsDuplicate(input);

    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "contains duplicate: " << output << std::endl;
}