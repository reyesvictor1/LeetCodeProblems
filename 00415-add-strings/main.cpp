#include <iostream>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {

        std::string result;

        int largestSize = num1.size() > num2.size() ? num1.size() : num2.size();
        int idxNum1 = num1.size() - 1;
        int idxNum2 = num2.size() - 1;
        int overflow = 0;
        for (int i = 0; i < largestSize; i++) {
            
            int d1 = 0;
            int d2 = 0;

            if (idxNum1 >= 0) {
                char c1 = num1[idxNum1];
                d1 = c1 - '0';
            }

            if (idxNum2 >= 0) {
                char c2 = num2[idxNum2];
                d2 = c2 - '0';
            }

            // perform addition
            int sum = d1 + d2 + overflow;

            // reset overflow
            if (overflow) overflow = 0;
            
            // check if overflow occurs
            if (sum > 9) {
                sum -= 10;
                overflow = 1;
            }

            char charDigit = '0' + sum;
            result += charDigit;

            // decrement indexes
            idxNum1--;
            idxNum2--;
        }

        // check if still has overflow
        if (overflow)
            result += '1';

        // reverse string result
        int i = 0;
        int j = result.size() - 1;
        while (i < j) {
            char temp = result[i];
            result[i] = result[j];
            result[j] = temp;
            i++;
            j--;
        }

        return result;
    }
};

int main() {
    std::string num1 = "11";
    std::string num2 = "123";
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    Solution solution;
    std::string addition = solution.addStrings(num1, num2);
    std::cout << "addition: " << addition << std::endl;

    return 0;
}