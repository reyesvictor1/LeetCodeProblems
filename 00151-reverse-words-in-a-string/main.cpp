#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string reverseWords(std::string str) {

        // create a vector of strings
        std::vector<std::string> words;

        // iterate through all characters of the string
        bool takingWord = false;
        std::string word;
        for (char c : str) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                takingWord = true;
                word += c;
            } else {
                if (takingWord) { // the current word is finished
                    words.push_back(word);
                    takingWord = false;
                    word = "";
                }
            }
        }
        if (takingWord) words.push_back(word);

        // create reversed string
        std::string reversedStr;
        for (auto it = words.rbegin(); it != words.rend(); ++it) {
            reversedStr += *it;
            if (it != std::prev(words.rend())) reversedStr += " "; // insert whitespace after word (except for last word)
        }
        return reversedStr;
    }
};

int main() {
    std::string input = "   this  is  a good   example   ";
    Solution solution;
    std::string output = solution.reverseWords(input);

    std::cout << "input: " << input << std::endl;
    std::cout << "output: " << output << std::endl;

    return 0;
}