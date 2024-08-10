#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {

        // convert vector to set
        std::set<int> numSet;
        for (int num : nums) numSet.insert(num);

        // traverse the set counting the consecutive numbers
        int maxCount = 0;
        int currentCount = 0;
        int lastNum = *numSet.begin() - 1;
        for (int num : numSet) {
            if (lastNum + 1 == num) currentCount++;
            else {
                if (currentCount > maxCount) maxCount = currentCount;
                currentCount = 1;
            }
            lastNum = num;
        }
        if (currentCount > maxCount) maxCount = currentCount;

        return maxCount;
    } 
};

int main() {
    std::vector<int> input = {100, 4, 200, 1, 3, 2};
    // std::vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    // std::vector<int> input = {9,1,4,7,3,-1,0,5,8,-1,6};
    std::cout << "input: ";
    for (int num : input) std::cout << num  << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.longestConsecutive(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}