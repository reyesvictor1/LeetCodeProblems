#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        
        // if there is only one element, the last index is reached
        if (nums.size() == 1) return true;

        // the idea is to iterate in reverse though the vector from the second-to-last index
        // wherever a zero is found, the jump distance needed increases by one
        // the next time a non zero number is found:
        //      if the number is greater than or equal to the jump distance needed, reset the jump distance needed
        //      if the number is less than the jump distance needed, increase the jump distance needed by one
        // in the end, the jump distance needed must be one, otherwise the jump to the last index is impossible

        int jumpDistanceNeeded = 1;
        for (int idx = nums.size() - 2; idx >= 0; idx--) {
            if (nums[idx]) {
                if (nums[idx] >= jumpDistanceNeeded) jumpDistanceNeeded = 1;
                else jumpDistanceNeeded++;
            }
            else if (!nums[idx]) jumpDistanceNeeded++;
        }
        if (jumpDistanceNeeded == 1) return true;
        else return false;

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