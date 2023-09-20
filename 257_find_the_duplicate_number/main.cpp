#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        
        // create a map containing the already checked nums
        std::unordered_map<int, int> inventory;
        for (int num : nums) {
            if (inventory[num]) return num; // if num already exists, then it is the duplicated
            inventory[num] = 1; // insert the key for num
        }
        return 1;
    }
};

int main() {
    std::vector<int> input = {3, 1, 3, 4, 2};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.findDuplicate(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}