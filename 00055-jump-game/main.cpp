#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        
        // dynamic programming (tabulation)

        // pre-allocate the dp table
        int tSize = nums.size();
        std::vector<bool> table(tSize, false);

        // seed the first value: always reachable, so, it's always true
        table[0] = true;

        // fill the table
        for (int i = 0; i < tSize; i++) {
            if (!table[i]) break;
            int maxJump = nums[i];
            for (int j = 1; j <= maxJump; j++) {
                if (i + j < tSize) table[i + j] = true;
            }
        }

        // return the last index of table 
        return table[tSize - 1];
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