#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        
        // make a copy of the vector
        std::vector<int> heightsCopy = heights;

        // sort the vector
        std::sort(heights.begin(), heights.end());

        // compare both the original and the sorted vector, counting all the discrepancies
        int discrepancies = 0;
        for (int idx = 0; idx < heights.size(); idx++) {
            if (heights[idx] != heightsCopy[idx]) discrepancies++;
        }
        return discrepancies;
    }
};

int main() {

    std::vector<int> input = {1, 1, 4, 2, 1, 3};
    std::cout << "heights: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.heightChecker(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}