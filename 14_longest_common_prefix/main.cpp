#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = "";
        for (size_t idx = 0; idx < strs.size(); ++idx) {
            if (idx == 0) {
                prefix = strs[0];
                continue;
            }
            const std::string current = strs[idx];
            int j = 0;
            while (j < current.size() && j < prefix.size() && prefix[j] == current[j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};

int main() {
    std::vector<std::string> input = {"flower", "flow", "flight"};
    Solution solution;
    std::string output = solution.longestCommonPrefix(input);

    std::cout << "Input: ";
    for (std::string str : input) { std::cout << str << " "; }
    std::cout << "\nOutput: " << output << std::endl;

    return 0;
}