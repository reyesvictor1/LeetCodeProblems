#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {

        // apply the Dutch National Flag solution
        int leftIdx = 0;
        int currentIdx = 0; // current index to check
        int rightIdx = nums.size() - 1;
        while (currentIdx <= rightIdx) {
            switch(nums[currentIdx]) {
                case 0:
                    nums[currentIdx] = nums[leftIdx];
                    nums[leftIdx] = 0;
                    currentIdx++;
                    leftIdx++;
                    break;
                case 1:
                    currentIdx++;
                    break;
                case 2:
                    nums[currentIdx] = nums[rightIdx];
                    nums[rightIdx] = 2;
                    rightIdx--; // decrement right index, keep the same current index
                    break;
            }
        }
    }
};

int main() {
    std::vector<int> nums = {2,0,2,1,1,0};
    std::cout << "input: [";
    for (int num : nums) std::cout << num;
    std::cout << "]" << std::endl;

    Solution solution;
    solution.sortColors(nums);
    std::cout << "input: [";
    for (int num : nums) std::cout << num;
    std::cout << "]" << std::endl;

    return 0;
}