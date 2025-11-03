#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        // define Morse Code representation
        std::vector<std::string> morseAlphabet = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."};

        // APPROACH: iterate through all words
        // 1.- transform each word to Morse Code
        // 2.- insert the transformed word into a set (i.e. unordered_set)
        // 3.- since elements in sets are unique, the number of different transformations is just the size of the set
        std::unordered_set<std::string> transformations;
        for (std::string word : words) {
            std::string transformed;
            for (int i = 0; i < word.size(); i++) {
                transformed += morseAlphabet[word[i] - 'a'];
            }
            transformations.insert(transformed);
        }
        return transformations.size();
    } 
};

int main() {
    std::vector<std::string> words = {"gin","zen","gig","msg"};
    for (std::string word : words)
        std::cout << word << std::endl;

    Solution solution;
    int output = solution.uniqueMorseRepresentations(words);
    std::cout << "output: " << output << std::endl; 

    return 0;
}