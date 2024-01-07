#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> output;
        for (int i = 0; i < n; i++) {
            output.push_back(nums[i]);
            output.push_back(nums[i + n]);
        }
        return output;
    }
};

int main() {
    
    std::vector<int> input = {2,5,1,3,4,7};
    int n = 3;
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<int> output = solution.shuffle(input, n);
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}