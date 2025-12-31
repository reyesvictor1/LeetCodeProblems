#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        // APPROACH: two pointers
        int leftIdx = 0;
        int rightIdx = height.size() - 1;
        int maxArea = 0;
        
        while (leftIdx < rightIdx) {
            // calculate the current area
            int leftHeight = height[leftIdx];
            int rightHeight = height[rightIdx];
            int relativeDistance = rightIdx - leftIdx;
            int minHeight = std::min(leftHeight, rightHeight);
            int currentArea = relativeDistance * minHeight;
            maxArea = std::max(currentArea, maxArea); // update max area
            
            // decide which pointer (index) to move: keep the highest line
            if (leftHeight > rightHeight)
                rightIdx--;
            else leftIdx++;
        }
        return maxArea;
    }
};

int main() {
    std::vector<int> input = {1,8,6,2,5,4,8,3,7};
    std::cout << "input: [ ";
    for (int num : input) std::cout << num << " ";
    std::cout << "]" << std::endl;

    Solution solution;
    int output = solution.maxArea(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}