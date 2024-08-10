#include <iostream>
#include <string>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string outputStr;
        for (char c : address) {
            if (c == '.') outputStr += "[.]";
            else outputStr += c;
        }
        return outputStr;
    }
};

int main() {
    std::string input;
    std::cout << "address: ";
    std::cin >> input;

    Solution solution;
    std::string output = solution.defangIPaddr(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}