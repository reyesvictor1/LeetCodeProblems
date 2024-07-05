#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int> &nums) {

        std::unordered_map<int, int> inventory;
        for (int num : nums)
            inventory[num]++;

        std::vector<int> result;
        for (const auto &pair : inventory)
            if (pair.second == 1)
                result.push_back(pair.first);

        return result;
    }
};

int main() {
    std::vector<int> input = {1, 2, 1, 3, 2, 5};
    std::cout << "input: ";
    for (int num : input)
        std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<int> output = solution.singleNumber(input);
    std::cout << "output: ";
    for (int num : output)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}