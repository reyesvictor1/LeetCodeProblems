#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;
        bool intMinAppeared = false;

        for (int i = 0; i < nums.size(); i++) {

            int value = nums[i];
            if (value == INT_MIN) intMinAppeared = true;

            if (value > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = value;
            } else if (value > secondMax) {
                if (value == firstMax) continue;
                thirdMax = secondMax;
                secondMax = value;
            } else if (value > thirdMax) {
                if (value == secondMax) continue;
                thirdMax = value;
            }
        }
        
        if (intMinAppeared) {
            if (firstMax == INT_MIN) return firstMax;
            if (secondMax == INT_MIN) return firstMax;
            if (thirdMax == INT_MIN) return thirdMax;
        }
        return thirdMax > INT_MIN ? thirdMax : firstMax;
    }
};

int main() {
    std::vector<int> input = {5,2,8,5,3,3,7,4,1,6}; // answer is 8,7,6
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int thirdMax = solution.thirdMax(input);
    std::cout << "output: " << thirdMax << std::endl;

    return 0;
}