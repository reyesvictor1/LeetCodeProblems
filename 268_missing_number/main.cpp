#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::unordered_set<int> numSet;
        for (int num : nums) numSet.insert(num);
        for (int i = 0; i <= nums.size(); i++) {
            if (!numSet.count(i)) return i;
        }
        return -1;
    }
};

int main() {

    std::vector<int> input = {3,0,1};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.missingNumber(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}