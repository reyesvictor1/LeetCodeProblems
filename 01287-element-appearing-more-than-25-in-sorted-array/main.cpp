#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        int thresh25 = arr.size() / 4;
        std::unordered_map<int, int> inventory;
        for (int num : arr) {
            inventory[num]++;
            if (inventory[num] > thresh25) return num;
        }
        return -1;
    }
};

int main() {

    std::vector<int> input = {1,2,2,6,6,6,6,7,10};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.findSpecialInteger(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}