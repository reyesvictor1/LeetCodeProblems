#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string str) {
        str = strip(str);
        std::cout << "str-" << str << "-" << std::endl;
        size_t last_blank = str.find_last_of(" ");
        std::cout << "last_blank: " << last_blank << std::endl;
        if (last_blank != std::string::npos) { // at least two words
            str = str.substr(last_blank + 1); // return only the last word
            std::cout << "entered here" << std::endl;
        }
         std::cout << "str: " << str << std::endl;
        return str.length();
    }
    
    std::string strip(std::string str) {
        
        size_t first = str.find_first_not_of(" ");
        if (first == std::string::npos) { // no matches found
            // the string is all blank spaces
            str.clear();
        } else {
            size_t last = str.find_last_not_of(" ");
            str = str.substr(first, last - first + 1);
        }
        return str;
    }
};

int main() {
    std::string str;
    std::cout << "Enter the string: ";
    std::getline (std::cin, str);
    
    Solution solution;
    int result = solution.lengthOfLastWord(str);
    std::cout << result << std::endl;

    return 0;
}