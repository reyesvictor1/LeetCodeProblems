#include <iostream>
#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        // APPROACH: iterate through all cells of the grid
        // whenever a 1 appears, check its surroundings to sum the perimeter of that cell
        int totalPerimeter = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                
                if (grid[row][col] == 1) { // check surroundings of that cell
                    
                    // check above
                    if (row == 0) totalPerimeter++;
                    else if (grid[row - 1][col] == 0) totalPerimeter++;

                    // check below
                    if (row == grid.size() - 1) totalPerimeter++;
                    else if (grid[row + 1][col] == 0) totalPerimeter++;

                    // check left
                    if (col == 0) totalPerimeter++;
                    else if (grid[row][col - 1] == 0) totalPerimeter++;

                    // check right
                    if (col == grid[0].size() - 1) totalPerimeter++;
                    else if (grid[row][col + 1] == 0) totalPerimeter++;
                }
            }
        }
        return totalPerimeter;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    std::cout << "grid:" << std::endl;
    for (std::vector<int> row : grid) {
        for (int col : row) std::cout << col << " ";
        std::cout << std::endl;
    }

    Solution solution;
    int perimeter = solution.islandPerimeter(grid);
    std::cout << "perimeter: " << perimeter << std::endl;

    return 0;
}