#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {

        // make inventory of all the occurrences
        std::unordered_map<int, int> inventory;
        for (int num : nums) inventory[num]++;
        
        // total = (n - 1) + (n - 2) + ... + 1
        // where n is the number of occurrences for each value, with at least 2 occurrences
        int total = 0;
        for (const auto pair : inventory) {
            if (pair.second > 1) {
                int value = pair.second - 1;
                int tempTotal = 0;
                for (int i = value; i > 0; i--) {
                    tempTotal += i;
                }
                total += tempTotal;
            }
        }
        return total;
    }
};

int main() {
    std::vector<int> input ={1,2,3,1,1,3};
    // std::vector<int> input ={1,1,1,1};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.numIdenticalPairs(input);
    std::cout << "output: " << output << std::endl;
    
    return 0;
}