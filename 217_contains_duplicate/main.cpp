#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> checkedNums;
        for (int num : nums) {
            if (checkedNums.count(num) > 0)
            return true;
            checkedNums.insert(num);
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