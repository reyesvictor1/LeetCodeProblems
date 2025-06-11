#include <iostream>
#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int maxConsecutive = 0;
        int currentConsecutive = 0;
        for (int num : nums) {
            if (num == 0) {
                currentConsecutive = 0;
            } else {
                currentConsecutive++;
                if (currentConsecutive > maxConsecutive)
                maxConsecutive = currentConsecutive;
            }
        }
        return maxConsecutive;
    }
};

int main() {
    std::vector<int> input = {1,1,0,1,1,1};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.findMaxConsecutiveOnes(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}