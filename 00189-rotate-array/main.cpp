#include <iostream>
#include <vector>
#include <algorithm>

class SolutionA { // time limit exceeded
public:
    void rotate(std::vector<int>& nums, int k) {
        // get k modulus (in case k is greater than size of vector)   
        k = k % nums.size();

        for (int idx = 0; idx < k; ++idx) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }  
    }
};

class SolutionB { // taken from other submissions 
public:
    void rotate(std::vector<int>& nums, int k) {
        // get k modulus (in case k is greater than size of vector)
        k = k % nums.size();
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end() - k);
        std::reverse(nums.begin(), nums.end());
    }
};


int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    std::cout << "input: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    SolutionB solution;
    solution.rotate(nums, k);
    std::cout << "output: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}