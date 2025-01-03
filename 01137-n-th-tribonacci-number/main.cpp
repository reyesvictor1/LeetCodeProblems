#include <iostream>
#include <vector>

class Solution {
public:
    int tribonacci(int n) {

        // dynamic programming approach
        std::vector<int> triboNums = {0, 1, 1};

        for (int i = 3; i <= n; i++) {
            int x = triboNums[i - 1] + triboNums[i - 2] + triboNums[i - 3];
            triboNums.push_back(x);
        }
        
        return triboNums[n];
    }
};

int main() {
    int n;
    std::cout << "n: ";
    std::cin >> n;

    Solution solution;
    int output = solution.tribonacci(n);
    std::cout << "output: " << output << std::endl;

    return 0;
}