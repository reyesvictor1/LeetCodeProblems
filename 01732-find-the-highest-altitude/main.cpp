#include <iostream>
#include <vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        
        // compute a new vector with the real height of each point
        std::vector<int> heights;
        int currentHeight = 0;
        for (int idx = 0; idx < gain.size(); idx++) {
            int height = currentHeight + gain[idx];
            heights.push_back(height);
            currentHeight = height;
        }

        // get the maximum value of the vector
        int maxHeight = 0;
        for (int idx = 0; idx < heights.size(); idx++) {
            if (heights[idx] > maxHeight) maxHeight = heights[idx];
        }
        return maxHeight;

    }
};

int main() {
    std::vector<int> input = {-5, 1, 5, 0, -7};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.largestAltitude(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}