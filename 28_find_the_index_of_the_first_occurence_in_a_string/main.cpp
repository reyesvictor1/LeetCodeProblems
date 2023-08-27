#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int found = haystack.find(needle);
        if (found != std::string::npos) return found; // returns the position of the first index
        else return -1;
    }
};

int main () {
    std::string haystack = "sadbutsad";
    std::string needle = "sad";

    Solution solution;
    std::cout << solution.strStr(haystack, needle) << std::endl;

    return 0;
}