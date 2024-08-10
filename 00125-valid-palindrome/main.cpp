#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string str) {

        // create a new string based on str, but containing only alphanumeric characters
        std::string alphaString;
        for (char c : str) {
            if (c >= 'a' && c <= 'z') alphaString.push_back(c);
            if (c >= 'A' && c <= 'Z') alphaString.push_back(c - 'A' + 'a');
            if (c >= '0' && c <= '9') alphaString.push_back(c);
        }

        // create a duplicate of the string, but reversed
        std::string reversedAlphaString;
        for (int idx = alphaString.length() - 1; idx >= 0; idx--) {
            reversedAlphaString.push_back(alphaString[idx]);
        }

        std::cout << "->" << alphaString << "<-" << std::endl;
        std::cout << "->" << reversedAlphaString << "<-" << std::endl;

        // compared both strings
        for (int idx = 0; idx < alphaString.length(); idx++) {
            if (alphaString[idx] != reversedAlphaString[idx]) return false;
        }
        return true;
    }
};


int main() {
    std::string input = "A man, a plan, a canal: Panama";
    Solution solution;
    
    std::cout << "input: " << input << std::endl;
    std::cout << solution.isPalindrome(input) << std::endl;

    return 0;
}