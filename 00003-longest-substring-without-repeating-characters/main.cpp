#include <iostream>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string str) {

        std::unordered_set<char> inventory;
        int maxSubstringLength = 0;
        int currentSubstringLength = 0;
        for (size_t offset = 0; offset < str.size(); offset++) {
            currentSubstringLength = 0;
            inventory.clear();
            for (size_t i = offset; i < str.size(); i++) {
                if (!inventory.count(str[i])) {
                    inventory.insert(str[i]);
                    currentSubstringLength++;
                    if ((i == str.size() - 1) && (currentSubstringLength > maxSubstringLength))
                        maxSubstringLength = currentSubstringLength;
                } else {
                    if (currentSubstringLength > maxSubstringLength)
                    maxSubstringLength = currentSubstringLength;
                    break;
                }
            }
        }
        return maxSubstringLength;
    }
};

int main() {

    std::string input = "thisisvictor";
    std::cout << "input: " << input << std::endl;

    Solution solution;
    int output = solution.lengthOfLongestSubstring(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}