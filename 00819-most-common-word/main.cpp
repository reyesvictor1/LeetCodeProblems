#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        // APPROACH:
        // 1.- create inventory of all words (all in lowercase)
        // 2.- iterate through all keys of the inventory
        // 3.- keep updating the most common word, only if word is not banned
        std::unordered_map<std::string, int> inventory;
        std::string currentWord = "";
        std::string punctuationSigns = "!?',;. ";
        for (char c : paragraph) {

            // check whether char is a punctuation sign
            if (punctuationSigns.find(c) != std::string::npos) {
                if (currentWord.size() > 0) inventory[currentWord]++; // word has finished, add it to the inventory
                currentWord = "";
                continue;
            }

            // correction to lowercase
            if (c >= 'A' && c <= 'Z')
                c = c + 'a' - 'A';

            // append char to current word
            currentWord = currentWord + c;
        }

        if (currentWord.size() > 0) inventory[currentWord]++; // handle last word if needed

        // iterate trough inventory, looking for the most common word
        std::string mostCommon = "";
        int mostOccurrences = 0;
        for (const auto &pair : inventory) {
            bool isBanned = false;
            std::string word = pair.first;
            int wordOccurrences = pair.second;

            // check that word is not in the banned list
            for (std::string b : banned) {
                if (word == b) {
                    isBanned = true;
                    break;
                }
            }
            if (isBanned) continue;

            // word is not banned, check if it is the most common word until now
            if (wordOccurrences > mostOccurrences) {
                mostOccurrences = wordOccurrences;
                mostCommon = word;
            }
        }

        return mostCommon;
    }
};

int main() {
    std::string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    std::cout << "paragraph: " << paragraph << std::endl;

    std::vector<std::string> banned = {"hit"};
    std::cout << "banned: ";
    for (std::string b : banned) {
        std::cout << b << " ";
    }
    std::cout << std::endl;

    Solution solution;
    std::string output = solution.mostCommonWord(paragraph, banned);
    std::cout << "output: " << output << std::endl;

    return 0;
}