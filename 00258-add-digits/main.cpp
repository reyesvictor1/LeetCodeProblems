#include <iostream>
#include <string>

class Solution {
public:
    int addDigits(int num) {
        
        if (num < 10) return num; // if num is a single digit, the addition is finished

        // convert integer to string
        std::string str = std::to_string(num);
        int strSize = str.size();

        while (strSize > 1) {
            // iterate through all the digits (adding them)
            int total = 0;
            for (char c : str) { 
                total += c - '0';
            }
            num = total;
            
            // convert integer to string
            str = std::to_string(num);
            strSize = str.size();
        }
        return num;
    }
};

int main() {
    int input = 957;
    Solution solution;
    int output = solution.addDigits(input);
    std::cout << "input: " << input << std::endl;
    std::cout << "output: " << output << std::endl;
    return 0;
}