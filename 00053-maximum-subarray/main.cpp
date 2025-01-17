#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        
        // Kadane's algorithm
        int maxSum = nums[0];
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // task 1: update max sum
            maxSum = std::max(maxSum, nums[i] + currentSum);

            // task 2: update current sum
            currentSum += nums[i];
            currentSum = std::max(0, currentSum);
        }
        
        return maxSum;
    }
};

int main() {
    std::vector<int> input = {-2,1,-3,4,-1,2,1,-5,4}; // answer = 6
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.maxSubArray(input);
    std::cout << "output: " << output << std::endl;
    
    return 0;
}