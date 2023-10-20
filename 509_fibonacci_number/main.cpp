#include <iostream>
#include <vector>

class Solution {
public:
    int fib(int n) {

        // dynamic programming approach
        std::vector<int> fiboNums;
        
        fiboNums.push_back(0);
        fiboNums.push_back(1);

        for (int i = 2; i <= n; i++) {
            fiboNums.push_back(fiboNums[i - 1] + fiboNums[i - 2]);
        }

        return fiboNums[n];
    }
};

int main() {

    int input;
    std::cout << "input: ";
    std::cin >> input;
    Solution solution;
    int output = solution.fib(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}