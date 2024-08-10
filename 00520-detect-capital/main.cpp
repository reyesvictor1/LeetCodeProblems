#include <iostream>

enum class WordType { OnlyFirstUpperCase, AllUpperCase, AllLowerCase };

class Solution {
public:
    bool detectCapitalUse(std::string str) {

        WordType word;
        for (int idx = 0; idx < str.size(); idx++) {
            char c = str[idx];
            if (c >= 'A' && c <= 'Z') {
                if (idx == 0) word = WordType::OnlyFirstUpperCase;
                else if (idx == 1 && word == WordType::OnlyFirstUpperCase) word = WordType::AllUpperCase;
                else if (idx > 1 && word == WordType::AllUpperCase) continue;
                else return false;
            }
            else if (c >= 'a' && c <= 'z') {
                if (idx == 0) word = WordType::AllLowerCase;
                else if (idx >= 1 && word != WordType::AllUpperCase) continue;
                else return false;
            }
            else {
                std::cout << "Invalid character " << str[idx] << " at position " << idx << std::endl;
                return false; // invalid character in string
            }
        }
        return true;
    }
};

int main() {

    std::string input;
    std::cout << "input: ";
    std::cin >> input;

    Solution solution;
    bool output = solution.detectCapitalUse(input);
    std::cout << "output: " << output << std::endl;

    return 0;

}