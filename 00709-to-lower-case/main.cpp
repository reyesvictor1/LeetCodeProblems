#include <iostream>
#include <cctype> // used for approach B

class Solution {
public:
    std::string toLowerCase(std::string str) {
        for (char& c : str) {

            // approach A
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';

            // approach B
            // if (c >= 'A' && c <= 'Z') c = std::tolower(c);

        }
        return str;
    }
};


int main() {

    std::string input = "HeLLo WorlD";
    Solution solution;
    std::string output = solution.toLowerCase(input);
    std::cout << "input: " << input << std::endl;
    std::cout << "output: " << output << std::endl;

    return 0;
}