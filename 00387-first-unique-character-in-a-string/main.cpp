#include <iostream>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string str) {
        
        // make inventory of all characters
        std::unordered_map<char, int> inventory;
        for (char c : str) inventory[c]++;

        // find first occurrence of a unique character
        for (int i = 0; i < str.size(); i++) {
            char currentChar = str[i];
            if (inventory[currentChar] == 1) return i;
        }

        // no unique characters in string
        return -1;

    }
};

int main() {

    std::string input = "loveleetcode";
    std::cout << "input:" << input << std::endl;

    Solution solution;
    int output = solution.firstUniqChar(input);
    std::cout << "output:" << output << std::endl;
    
    return 0;
}