#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    std::string sortSentence(std::string s) {

        // populate the table as [index] = "substring"
        std::map<int, std::string> table;
        int idxStart = 0;
        int length = 0;
        for (int i = 0; i <= s.size(); i++) {

            // delimiter found, insert key and value in table
            if (s[i] == ' ' || i == s.size()) {
                int key = s[i - 1] - '0';
                std::string value = s.substr(idxStart, length - 1);
                table[key] = value;
                idxStart = i + 1; // set starting index for next substring
                length = 0; // reset length of next substring
            } else length++;

        }

        // create the new ordered string
        std::string outputStr;
        for (const auto &pair : table)
            outputStr += pair.second + " ";

        outputStr.pop_back(); // delete the extra blank space of the end
        return outputStr;
    }
};

int main() {

    std::string input = "is2 sentence4 This1 a3";
    std::cout << "input: " << input << std::endl;

    Solution solution;
    std::string output = solution.sortSentence(input);
    std::cout << "output: " << output << std::endl;

    return 0;

}