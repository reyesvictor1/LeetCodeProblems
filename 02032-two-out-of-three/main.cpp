#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<int> twoOutOfThree(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<int> &nums3) {
        // make an inventory of all elements
        std::unordered_map<int, int> inventory;
        std::unordered_set<int> tempSet;

        // create tempSet to avoid duplicate numbers in the same array
        for (int num : nums1) tempSet.insert(num);
        for (int num : tempSet) inventory[num]++;
        tempSet.clear();

        for (int num : nums2) tempSet.insert(num);
        for (int num : tempSet) inventory[num]++;
        tempSet.clear();

        for (int num : nums3) tempSet.insert(num);
        for (int num : tempSet) inventory[num]++;
        tempSet.clear();

        // elements of the inventory with 2 or more occurrences will be pushed into the output vector
        std::vector<int> output;
        for (const auto pair : inventory) {
            if (pair.second >= 2) output.push_back(pair.first);
        }
        return output;
    }
};

void printVector(std::vector<int> nums, std::string name) {
    std::cout << name << ": ";
    for (int num : nums) std::cout << num << " ";
    std::cout <<std::endl;
}

int main() {
    
    std::vector<int> nums1 = {6, 7, 8, 9};
    std::vector<int> nums2 = {8, 9};
    std::vector<int> nums3 = {9};
    printVector(nums1, "nums1");
    printVector(nums2, "nums2");
    printVector(nums3, "nums3");
    
    Solution solution;
    std::vector<int> output = solution.twoOutOfThree(nums1, nums2, nums3);
    printVector(output, "output");


    return 0;
}