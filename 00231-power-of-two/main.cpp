#include <iostream>
#include <set>
#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {

        // create a set including numbers power of two 
        std::set<long long> numSet;
        int x = 0;
        long long result = 0;
        while(result < n) {
            result = std::pow(2, x);
            numSet.insert(result);
            x++;
        }

        // numSet contains n, then n is a power of 2
        if (numSet.find(n) != numSet.end()) return true;

        // n is not a power of 2
        return false;
    }
};

int main() {
    int input;
    std::cout << "input: ";
    std::cin >> input;

    Solution solution;
    int output = solution.isPowerOfTwo(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}