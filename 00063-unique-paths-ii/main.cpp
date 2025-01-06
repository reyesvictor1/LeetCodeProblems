#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        
        // dynamic programming approach: tabulation

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        // if the start or end cell has an obstacle, no paths are possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1) 
            return 0;

        // allocate the table
        std::vector<std::vector<int>> table(rows, std::vector<int>(cols, 0));

        // seed the base case: there is 1 way to reach the starting cell (1, 1)
        table[0][0] = 1;

        // fill the table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // skip if current cell has an obstacle
                if (obstacleGrid[i][j] == 1) continue;

                int currentValue = table[i][j];
                if (i + 1 < rows) // if next row is within bounds
                    table[i + 1][j] += currentValue; // propagate value to the cell below
                if (j + 1 < cols) // if next column is within bounds
                    table[i][j + 1] += currentValue; // propagate value to the cell to the right
            }
        }

        // the value at the [last row][last col] is the total number of unique paths
        return table[rows - 1][cols - 1];
    }
};

int main() {
    std::vector<std::vector<int>> obstacleGrid = {
                                                    {0,0,0},
                                                    {0,1,0},
                                                    {0,0,0}
                                                };
    for (std::vector<int> row : obstacleGrid) {
        for (int num : row) std::cout << num << " ";
        std::cout << std::endl;
    }

    Solution solution;
    int output = solution.uniquePathsWithObstacles(obstacleGrid);
    std::cout << "output: " << output << std::endl;

    return 0;
}