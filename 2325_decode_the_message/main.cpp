#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::string decodeMessage(std::string key, std::string message) {

        // create the decoding table using the key
        std::unordered_map<char, char> decodingTable;
        char currentAlphabetLetter = 'a';
        for (char c : key) {
            // if char is not white space and char is still not a key of the decoding table
            if (c != ' ' && !decodingTable[c]) { 
                decodingTable[c] = currentAlphabetLetter; // insert key with corresponding alphabet letter
                currentAlphabetLetter++; // increase alphabet letter
            }
        }

        // decode the message using the decoding table
        std::string decodedMessage;
        for (char c : message) {
            if (c == ' ')
                decodedMessage += ' ';
            else
                decodedMessage += decodingTable[c];
        }
        return decodedMessage;
    }
};

int main() {
    std::string key = "the quick brown fox jumps over the lazy dog";
    std::string message = "vkbs bs t suepuv";
    std::cout << "key: " << key << std::endl;
    std::cout << "message: " << message << std::endl;

    Solution solution;
    std::string output = solution.decodeMessage(key, message);
    std::cout << "output: " << output << std::endl;

    return 0;
}