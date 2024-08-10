#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        // make ordered set to get unique ordered values
        std::set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }

        // check for the first missing positive
        // (std::set only allows element access via iterators)
        std::set<int>::iterator it;
        it = numSet.find(1);
        int idx = 1;
        for (it; it != numSet.end(); it++) {
            if (*it != idx) return idx;
            idx++;
        }
        return idx;
    }
};

int main() {
    std::vector<int>input = {3, 4, -1, 1, 2, 8};
    std::cout << "set: ";
        for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.firstMissingPositive(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}