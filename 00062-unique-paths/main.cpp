#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // dynamic programming approach: tabulation

        // allocate the table
        int rows = m + 1;
        int cols = n + 1;
        std::vector<std::vector<int>> table(rows, std::vector<int>(cols, 0));
        
        // seed the base case: there is 1 way to reach the starting cell (1, 1)
        table[1][1] = 1;

        // fill up the table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int currentValue = table[i][j];
                if (i + 1 < rows) // if next row is within bounds
                    table[i + 1][j] += currentValue; // propagate value to the cell below
                if (j + 1 < cols) // if next column is within bounds
                    table[i][j + 1] += currentValue; // propagate value to the cell to the right
            }
        }

        // the value at [m][n] contains the total number of unique paths
        return table[m][n];
    }
};

int main() {
    int m, n;
    std::cout << "m: ";
    std::cin >> m;
    std::cout << "n: ";
    std::cin >> n;

    Solution solution;
    int output = solution.uniquePaths(m, n);
    std::cout << "output: " << output << std::endl;

    return 0;
}