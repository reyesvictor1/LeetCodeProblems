#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        // unordered associative containers implement unsorted (hashed) data structures that can be quickly searched
        // O(1) average, O(n) worst-case complexity

        // convert each vector to unordered_set, which has unique keys
        std::unordered_set<int> set1;
        std::unordered_set<int> set2;
        for (int num : nums1) set1.insert(num);
        for (int num : nums2) set2.insert(num);

        // iterate through each set looking for the different elements
        std::vector<int> numsIn1ButNotIn2;
        std::vector<int> numsIn2ButNotIn1;
        for (int num : set1) if (set2.find(num) == set2.end()) numsIn1ButNotIn2.push_back(num);
        for (int num : set2) if (set1.find(num) == set1.end()) numsIn2ButNotIn1.push_back(num);

        // return the result
        std::vector<std::vector<int>> result = { numsIn1ButNotIn2, numsIn2ButNotIn1 };
        return result;
    }
};

int main() {

    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};
    std::cout << "nums1: ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "nums2: ";
    for (int num : nums2) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<std::vector<int>> output = solution.findDifference(nums1, nums2);

    std::cout << "output[0]: ";
    for (int num : output[0]) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "output[1]: ";
    for (int num : output[1]) std::cout << num << " ";
    std::cout << std::endl;

    return 0;

}