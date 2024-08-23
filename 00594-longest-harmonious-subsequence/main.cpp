#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {

        // create an inventory of nums
        std::unordered_map<int, int> inventory; // <num, occurrences>
        for (int num : nums) inventory[num]++;

        // for each key x of the map, check if key x+1 exists, and sum both occurrences
        int longestSubsequence = 0;
        for (const auto &pair : inventory) {
            int x = pair.first;
            int currentSubsequence = 0;
            if (inventory.find(x + 1) != inventory.end()) {
                currentSubsequence = inventory[x] + inventory[x + 1];
                if (currentSubsequence > longestSubsequence)
                    longestSubsequence = currentSubsequence;
            }
        }
        return longestSubsequence;
    }
};

int main() {
    std::vector<int> input = {1,3,2,2,5,2,3,7};
    std::cout << "input: [ ";
    for (int num : input) std::cout << num << " ";
    std::cout << "]" << std::endl;

    Solution solution;
    int output = solution.findLHS(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}