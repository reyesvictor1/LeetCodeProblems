#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {

        // if triangle has one single level, return its value
        int tSize =  triangle.size();
        if (tSize <= 1) return triangle[0][0];

        // APPROACH: what's the minimum possible sum for the current element?
        // the triangle is composed of levels, where level n has n elements
        // level 1 is at the top of the triangle
        // if element is at position 0 or n - 1: there is only one possible path
        // else: there are two possible paths, choose the smallest one
        for (int level = 1; level < tSize; level++) {
            for (int idx = 0; idx < triangle[level].size(); idx++) {

                int min, pathA, pathB = 0;
                
                if (idx > 0 && idx < triangle[level].size() - 1) {
                    pathA = triangle[level - 1][idx - 1];
                    pathB = triangle[level - 1][idx];
                    min = pathA < pathB ? pathA : pathB;
                } else if (idx == 0) {
                    pathB = triangle[level - 1][idx];
                    min = pathB;
                } else {
                    pathA = triangle[level - 1][idx - 1];
                    min = pathA;
                }
                triangle[level][idx] += min; // update element in triangle
            }
        }

        // the minimum path sum is the smallest element of the bottom level
        int minPathSum = triangle[tSize - 1][0];
        for (int i = 0; i < triangle[tSize - 1].size(); i++) {
            int currentValue = triangle[tSize - 1][i];
            if (currentValue < minPathSum)
                minPathSum = currentValue;
        }
        return minPathSum;
    }
};

int main() {
    std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    for (std::vector<int> level : triangle) {
        for (int num : level)
            std::cout << num << " ";
        std::cout << std::endl;
    }
    
    Solution solution;
    int output = solution.minimumTotal(triangle);
    std::cout << "output: " << output << std::endl;

    return 0;
}