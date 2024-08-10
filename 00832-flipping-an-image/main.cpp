#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        
        // reverse each row (flip horizontally)
        for (std::vector<int> &row : image) {
            std::reverse(row.begin(), row.end());
        }

        // invert the image
        for (std::vector<int> &row : image) {
            for (int &pixel : row) {
                pixel = !pixel;
            }
        }
        
        return image;
    }
};

int main() {

    std::vector<std::vector<int>> input = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    std::cout << "input:" << std::endl;
    for (std::vector<int> &row : input) {
        for (int num : row) { std::cout << num << " "; }
        std::cout << std::endl;
    }

    Solution solution;
    std::vector<std::vector<int>> output = solution.flipAndInvertImage(input);
    std::cout << "output:" << std::endl;
    for (std::vector<int> &row : output) {
        for (int num : row) { std::cout << num << " "; }
        std::cout << std::endl;
    }

    return 0;
}