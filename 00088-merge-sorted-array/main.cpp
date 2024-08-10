#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {

        // // solution A: using std::sort
        // for (int i = 0; i < nums2.size(); i++) {
        //     nums1[m] = nums2[i];
        //     m++;
        // }
        // std::sort(nums1.begin(), nums1.end());

        // solution B
        int currentIndex = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[currentIndex] = nums1[m - 1];
                m--;
            } else {
                nums1[currentIndex] = nums2[n - 1];
                n--;
            }
            currentIndex--;
        }

        while (n > 0) {
            nums1[currentIndex] = nums2[n - 1];
            n--;
            currentIndex--;
        }
    }
};

int main() {
    std::vector<int> nums1 = {2, 3, 9, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {1, 4, 6};
    int n = 3;

    std::cout << "nums1: ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "nums2: ";
    for (int num : nums2) std::cout << num << " ";
    std::cout << std::endl;
    
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    std::cout << "merged: ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}