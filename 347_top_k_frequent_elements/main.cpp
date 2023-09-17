#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        
        std::vector<int> mostFrequentNums;

        // make an inventory of occurrences for each number in nums
        std::unordered_map<int, int> inventory;
        for (int num : nums) {
            inventory[num]++;
        }

        // find the max value contained in the unordered_map, take the key and erase it, repeat the process k times
        for (int i = 0; i < k; i++) {
            int maxValue = 0;
            int maxKey = -1;
            // iterate through all the map and find the max value
            for (const auto& pair : inventory) {
                if (pair.second > maxValue) {
                    maxKey = pair.first;
                    maxValue = pair.second;
                }
            }
            // take the key and erase it from the map
            mostFrequentNums.push_back(maxKey);
            inventory.erase(maxKey);
        }

        return mostFrequentNums;

    }
};

int main() {
    std::vector<int> input = {1, 1, 2, 2, 2, 2, 5, 5, 5, 7};
    int k = 2;
    Solution solution;
    std::vector<int> output = solution.topKFrequent(input, k);
    
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}