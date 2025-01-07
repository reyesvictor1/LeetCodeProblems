#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {

        // corner case: if array has only one element, return it
        if (nums.size() == 1) return nums[0];

        // APPROACH: dynamic programming (tabulation)
        // create a table
        // each index of table will contain the maximum possible amount that can be robbed until such index
        // the maximum possible amount is the maximum between:
        //  a) value at nums[n] + value at table[n - 2] // since one house must be skipped
        //  b) value at table[n - 1]  // the max amount until the previous house
        // determine the maximum amount and set it at table[n]

        // preallocate the DP table
        std::vector<int> table(nums.size(), 0);
        table[0] = nums[0]; // seed the first value
        table[1] = nums[0] > nums[1] ? nums[0] : nums[1]; // seed the second value

        // fill the table with the max amounts
        for (int i = 2; i < table.size(); i++) {
           int optionA = nums[i] + table[i - 2];
           int optionB = table[i - 1];
           int maxAmount = optionA > optionB ? optionA : optionB;
           table[i] = maxAmount;
        }

        // the maximum possible amount is the value at the last index
        return table[table.size() - 1];

    }
};

int main() {
    std::vector<int> input = {2,7,9,3,1};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.rob(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}