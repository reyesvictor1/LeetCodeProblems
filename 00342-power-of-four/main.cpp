#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int n) {
        // base case n < 1: zero and negative numbers are not power of four
        // so, return false, which propagates through the call stack
        if (n < 1) return false;

        // base case n == 1: 4^0 = 1, return true, which propagates through the call stack
        if (n == 1) return true;

        // if not divisible by four, return false, which propagates through the call stack
        if (n % 4) return false;

        return isPowerOfFour(n / 4);
    }
};

int main() {
    int input;
    std::cout << "Enter any integer: ";
    std::cin >> input;

    Solution solution;
    bool output = solution.isPowerOfFour(input);
    std::cout << "Is power of four: " << (output ? "true" : "false") << std::endl;

    return 0;
}