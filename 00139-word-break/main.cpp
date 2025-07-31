#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        
        // APPROACH: Dynamic Programming (tabulation)
        std::vector<bool> dpVector(s.size() + 1, false); // initialize the dp vector, fill it with "false" values

        // first value is "true", because there is always a way to create/construct an empty string
        dpVector[0] = true;

        // idx is the current letter index
        // iterate through the entire dp vector
        // checking if a substring starting from idx can be built with the words of the dictionary
        for (int idx = 0; idx < dpVector.size(); idx++) {
            
            if (!dpVector[idx])
                continue;

            for (std::string word : wordDict) {
                int wordSize = word.size();
                if (idx + wordSize > dpVector.size()) // guard clause: prevent manipulation of indices out of range
                    continue;
                std::string strToCheck = s.substr(idx, wordSize);
                if (strToCheck == word) // if the target string s contains the word, update the vector
                    dpVector[idx + wordSize] = true;
            }
        }

        return dpVector[dpVector.size() - 1]; // final verdict is the value of the last index of the dp vector
    }
};

int main() {
    // TEST 1: should return "true"
    // std::string s = "leetcode";
    // std::vector<std::string> wordDict = {"leet","code"};

    // TEST 2: should return "false"
    std::string s = "catsandog";
    std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};

    std::cout << "s: " << s << std::endl;
    std::cout << "wordDict: [ ";
    for (std::string word : wordDict) std::cout << word << " ";
    std::cout << "]" << std::endl;
    
    Solution solution;
    bool output = solution.wordBreak(s, wordDict);
    std::cout << "output: " << (output ? "true" : " false") << std::endl;

    return 0;
}