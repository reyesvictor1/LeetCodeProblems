#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {

        std::vector<std::vector<int>> triangle;

        for (int level = 0; level < numRows; level++) {
            std::vector<int> currentLevel;
            if (level == 0) currentLevel = {1};
            else if (level == 1) currentLevel = {1, 1};
            else {
                currentLevel.push_back(1);
                for (int idx = 1; idx < level; idx++) {
                    int a = triangle[level - 1][idx - 1];
                    int b = triangle[level - 1][idx];
                    currentLevel.push_back(a + b);        
                }
                currentLevel.push_back(1);
            }

            triangle.push_back(currentLevel);
        }

        return triangle;
    }
};

int main() {
    int numRows = 0;
    std::cout << "numRows: ";
    std::cin >> numRows;

    Solution solution;
    std::vector<std::vector<int>> triangle = solution.generate(numRows);
    for (std::vector<int> level : triangle) {
        for (int element : level)
            std::cout << element << " ";
        std::cout << std::endl;
    }

    return 0;
}