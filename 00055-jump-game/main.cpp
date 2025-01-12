#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        
        // APPROACH: greedy
        // what's the farthest possible index I can reach?
        // update this index as you iterate through the nums array
        // if you reach an index greater than the farthest reachable index, then you cannot reach the end

        // NOTE: dynamic programming approach (tabulation) also works, but it's slower because:
        // - it has a nested loop, resulting in O(n²) time complexity in the worst case
        // - redundant updates: each index in table is updated multiple times as the outer loop progresses
        // - use DP approach only if you need to track all reachable indices and not just
        //   whether the last index is reachable

        int farthestIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthestIdx) return false; // current index is beyond the farthest reachable index
            farthestIdx = std::max(farthestIdx, i + nums[i]); // update farthest index
        }
        return true; // all indices were reachable, so, last index is reachable
    }
};

int main() {
    std::vector<int> input = {5, 2, 0, 0, 0, 1, 4};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    bool output = solution.canJump(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}