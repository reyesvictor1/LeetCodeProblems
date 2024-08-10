#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {

        // most efficient solution: using XOR
        int result = 0;
        for (int num : nums) result = result ^ num;
        return result;

        // another solution: it works, but using extra space
        // most efficient solution: using XOR
        // std::unordered_map<int, int> inventory;
        // for (int num : nums) {
        //     inventory[num]++;
        // }
        // for (const auto& pair : inventory) {
        //     if (pair.second < 2) return pair.first;
        // }
        // return 0;
    }
};

int main() {
    std::vector<int> input = {4, 1, 2, 1, 2};
    Solution solution;
    int output = solution.singleNumber(input);

    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "output: " << output << std::endl;

    return 0;
}