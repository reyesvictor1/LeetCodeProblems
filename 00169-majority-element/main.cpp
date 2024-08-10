#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {

        int halfSize = nums.size() / 2;

        // create map that will store each num and its corresponding number of occurrences
        // in a C++ map, there is no need to check if the key already exists, since:
        // A) if a key already exists, the value associated with that key will be updated
        // B) if the key does not exist, a new key-value pair will be added to the map
        std::map<int, int> occurrencesMap; 

        for (const int& num : nums) {
            occurrencesMap[num]++; // increment value of key [num]
            if (occurrencesMap[num] > halfSize) return num;
        }
        return 0;
    }
};

int main() {
    std::vector<int> input = {9, 9, 2, 2, 2, 9, 9};
    Solution solution;
    int output = solution.majorityElement(input);

    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "output: " << output << std::endl;

    return 0;
}