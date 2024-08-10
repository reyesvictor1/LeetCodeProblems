#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        
        // make inventory of all the elements in nums
        std::unordered_map<int, int> inventory;
        for (int num : nums) inventory[num]++;

        // sum all keys which have a value of one (only one occurrence)
        int total = 0;
        for (const auto &pair : inventory) {
            if (pair.second == 1) total += pair.first;
        }
        return total;

    }
};

int main() {
    std::vector<int> input = {1, 2, 3, 4, 4, 5};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.sumOfUnique(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}