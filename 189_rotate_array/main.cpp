#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        // get k modulus (in case k is greater than size of vector)   
        k = k % nums.size();

        // create a vector containing the nums last k elements
        std::vector<int> temp;
        for (int idx = nums.size() - 1; idx >= nums.size() - k; --idx) {
            temp.push_back(nums[idx]);           
        }

        // insert and remove the last k elements of nums
        for (int idx = 0; idx < k; ++idx) {
            nums.insert(nums.begin(), temp[idx]);
            nums.pop_back();
        }
    }
};


int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    std::cout << "input: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    solution.rotate(nums, k);
    std::cout << "output: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}