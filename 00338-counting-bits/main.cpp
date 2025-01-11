#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {

        // APPROACH: dynamic programming
        // by checking out the binary representation of the numbers from 0 to 9
        // we can notice a pattern in the number of 1's:
        //
        // |  n  | bits   | number of 1's 
        // |-----|--------|------------------------
        // |  0  |  0000  |    0 
        // |  1  |  0001  |    1
        // |  2  |  0010  |    1   =  1 + dp[n - 2]
        // |  3  |  0011  |    2   =  1 + dp[n - 2]
        // |  4  |  0100  |    1   =  1 + dp[n - 4]
        // |  5  |  0101  |    2   =  1 + dp[n - 4]
        // |  6  |  0110  |    2   =  1 + dp[n - 4]
        // |  7  |  0111  |    3   =  1 + dp[n - 4]
        // |  8  |  1000  |    1   =  1 + dp[n - 8]
        // |  9  |  1001  |    2   =  1 + dp[n - 8]
        
        std::vector<int> table(n + 1, 0);
        int offset = 2;

        // edge case, n = 0
        if (n == 0) return table;  

        // seed value of index 1
        table[1] = 1;
        
        // fill table
        for (int i = 2; i < table.size(); i++) {
            if (i == offset * 2) offset = offset * 2;
            table[i] = table[i - offset] + 1;
        }

        return table;
    }
};

int main() {
    int n;
    std::cout << "n: ";
    std::cin >> n;

    Solution solution;
    std::vector<int> output = solution.countBits(n);
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}