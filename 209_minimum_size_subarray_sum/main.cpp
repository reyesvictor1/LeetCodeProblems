#include  <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        
        // apply sliding window technique
        int leftIndex = 0;
        int rightIndex = 0;
        int minSubarrayLength = nums.size() + 1;
        int totalSum = 0;

        while (rightIndex < nums.size()) {
            totalSum = totalSum + nums[rightIndex];
            while (totalSum >= target) {
                minSubarrayLength = std::min(rightIndex - leftIndex + 1, minSubarrayLength);
                totalSum = totalSum - nums[leftIndex];
                leftIndex++;
            }
            rightIndex++;
        }

        if (minSubarrayLength == nums.size() + 1) return 0;
        return minSubarrayLength;
    }
};

int main() {
    int target = 11;
    std::vector<int> input = {1,1,1,1,1,1,1,1};
    std::cout <<  "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.minSubArrayLen(target, input);
    std::cout << "output: " << output << std::endl;

    return 0;
}