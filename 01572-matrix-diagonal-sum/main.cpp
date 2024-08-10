#include <iostream>
#include <vector>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>> &mat) {

        int totalSum = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.size(); j++) {
                if (j == i || j == mat.size() - i - 1) totalSum += mat[i][j];
            }
        }
        return totalSum;
    }
};

int main() {

    std::vector<std::vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    Solution solution;
    int output = solution.diagonalSum(mat);
    std::cout << "output: " << output << std::endl;

    return 0;
}