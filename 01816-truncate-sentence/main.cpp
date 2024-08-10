#include <iostream>

class Solution {
public:
    std::string truncateSentence(std::string str, int k) {
        std::string outputString;
        int blankSpacesFound = 0;
        for (size_t idx = 0; idx < str.size(); idx++) {
            if (str[idx] == ' ') blankSpacesFound++;
            if (blankSpacesFound == k) break;
            outputString += str[idx];
        }
        return outputString;
    }
};

int main() {
    std::string input = "What is the solution to this problem";
    int k = 4;
    std::cout << "input: " << input << std::endl;
    std::cout << "k: " << k << std::endl;

    Solution solution;
    std::string output = solution.truncateSentence(input, k);
    std::cout << "output: " << output << std::endl;

    return 0;
}