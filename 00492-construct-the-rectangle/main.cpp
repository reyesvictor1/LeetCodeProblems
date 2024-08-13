#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        
        // variable initialization
        std::vector<int> dimensions;
        int width = sqrt(area);

        // decrease width value until a valid divisor is found
        while (area % width != 0) {
            width--;
        }

        // now that width is valid, calculate the length
        int length = area / width;

        // return the result
        dimensions.push_back(length);
        dimensions.push_back(width);
        return dimensions;
    }
};

int main() {
    int area;
    std::cout << "Enter the area: ";
    std::cin >> area;

    Solution solution;
    std::vector<int> output = solution.constructRectangle(area);
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
};