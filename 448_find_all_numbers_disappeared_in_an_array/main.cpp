#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        // get size of nums to determine the n range
        int nSize = nums.size();

        std::unordered_set<int> inventory;
        for (int num : nums) inventory.insert(num);

        std::vector<int> missingValues;
        for (int i = 1; i <= nSize; i++) {

            // check if i is not in inventory vector
            auto it = inventory.find(i);
            if (it != inventory.end()) continue; // inventory contains i
            missingValues.push_back(i);
        }
        return missingValues;
    }
};

int main() {
    std::vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<int> output = solution.findDisappearedNumbers(input);
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}