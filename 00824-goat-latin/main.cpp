#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string toGoatLatin(std::string sentence) {

        // make a vector of the words
        std::vector<std::string> words;
        std::string currentWord;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] != ' ')
                currentWord += sentence[i];
            else {
                words.push_back(currentWord);
                currentWord = "";
            }
        }
        words.push_back(currentWord);

        // process each word of the vector
        std::string translation;
        int currentIndex = 1;
        for (std::string &word : words) {
            char firstLetter = word.front();
            int length = word.size();

            if (!isVowel(firstLetter)) {
                word = word.substr(1);
                word += firstLetter;
            }
            word += "ma";

            // add "a"s given the current index
            for (int j = 0; j < currentIndex; j++)
                word += "a";

            // append processed word to translation
            translation += word + " ";
            currentIndex++;
        }
        
        translation.pop_back(); // remove trailing space
        return translation;
    }

private:
    bool isVowel(char c) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else return false;
    }
};

int main() {
    std::string input = "I speak Goat Latin";
    std::cout << "input: " << input << std::endl;

    Solution solution;
    std::string output = solution.toGoatLatin(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}