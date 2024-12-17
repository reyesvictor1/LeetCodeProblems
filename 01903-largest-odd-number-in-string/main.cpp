#include <iostream>
#include <string>

class Solution {
public:
    std::string largestOddNumber(std::string num) {
        
        int length = num.size();
        // traverse the string from right to left, stop when first odd number is found
        for (int i = length - 1; i >= 0; i--) {
            int digit = num[i] - '0'; // get digit value
            if (digit % 2)
                return num.substr(0, i + 1); // return substring
        }
        return std::string();
    }
};

int main() {
    std::string input;
    std::cout << "input: ";
    std::cin >> input;

    Solution solution;
    std::string output = solution.largestOddNumber(input);

    std::cout << "output: " << output << std::endl;

    return 0;
}