#include <iostream>
#include <string>

class Solution {
public:
    bool isSameAfterReversals(int num) {
        
        // convert num to string
        std::string originalStr = std::to_string(num);
        if (originalStr.size() == 1) return true; // only one digit number

        // reverse string
        std::string reversed1 = reverseString(originalStr);

        // remove any leading zeros
        int idx = 0;
        while (reversed1[idx] == '0') {
            reversed1.erase(reversed1.begin() + idx);
        }

        // reverse string again
        std::string reversed2 = reverseString(reversed1);

        // convert string to num
        int reversedInt = std::stoi(reversed2);
        return reversedInt == num;

    }

private:
    std::string reverseString(std::string &str) {
        std::string reversed;
        for (int i = str.size() - 1; i >= 0; i--) {
            reversed += str[i];
        }
        return reversed;
    }

};

int main() {
    int input;
    std::cout << "input: ";
    std::cin >> input;

    Solution solution;
    int output = solution.isSameAfterReversals(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}