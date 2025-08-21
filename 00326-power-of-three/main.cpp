#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        // base case n < 1: zero and negative numbers are not power of three
        // so, return false, which propagates through the call stack
        if (n < 1) return false;

        // base case n == 1: 3^0 = 1, return true, which propagates through the call stack
        if (n == 1) return true;

        // if not divisible by three, return false, which propagates through the call stack
        if (n % 3) return false; 

        return isPowerOfThree(n / 3);
    }
};

int main() {
    int input;
    std::cout << "Enter any integer: ";
    std::cin >> input;

    Solution solution;
    bool output = solution.isPowerOfThree(input);
    std::cout << "Is power of three: " << (output ? "true" : "false") << std::endl;

    return 0;
}