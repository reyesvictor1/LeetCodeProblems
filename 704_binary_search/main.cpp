#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        
        // set low and high indexes
        int lowIndex = 0;
        int highIndex = nums.size() - 1;

        // perform binary search algorithm
        while (lowIndex <= highIndex) {
           int middleIndex =  lowIndex + ((highIndex - lowIndex) / 2);
           int value = nums[middleIndex];

           if (value < target) lowIndex = middleIndex + 1; // adjust the lower boundary
           else if (value > target) highIndex = middleIndex - 1; // adjust the upper boundary
           else return middleIndex; //target was found
        }
        return -1; // target not found
    }
};

int main() {
    std::vector<int> input = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "target: " << target << std::endl;

    Solution solution;
    int output = solution.search(input, target);
    if (output < 0) std::cout << target << " not found" << std::endl;
    else std::cout << target << " found at index " << output << std::endl;

    return 0;
}