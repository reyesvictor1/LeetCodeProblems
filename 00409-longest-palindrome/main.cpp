#include <iostream>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(std::string s) {

        // create inventory <char, number of occurrences>
        std::unordered_map<char, int> inventory;
        for (char c : s) inventory[c]++;

        // add all even occurrences, add only the largest odd occurrence
        int palindromeLength = 0;
        int addOne = 0;
        for (const auto pair : inventory) {
            if (pair.second % 2) { // odd number of occurrences
                    palindromeLength += pair.second - 1;
                    addOne = 1;
            } else { // even number of occurrences
                palindromeLength += pair.second;
            }
        }
        palindromeLength += addOne;
        return palindromeLength;

    }
};

int main() {
    std::string input = "abccccdd";
    std::cout << "input:" << input << std::endl;

    Solution solution;
    int output = solution.longestPalindrome(input);
    std::cout << "output:" << output << std::endl;

    return 0;
}

