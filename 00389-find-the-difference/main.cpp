#include <iostream>
#include <unordered_map>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {

        std::unordered_map<char, int> inventory_s;
        std::unordered_map<char, int> inventory_t;
        
        for (char c : s) inventory_s[c]++;

        for (char c : t) {
            inventory_t[c]++;
            if (inventory_t[c] > inventory_s[c]) return c;
        }
        return ' ';
    }
};

int main() {
    std::string s = "abcd";
    std::string t = "badce";
    std::cout << "s: " << s << std::endl;
    std::cout << "t: " << t << std::endl;

    Solution solution;
    char output = solution.findTheDifference(s, t);
    std::cout << "output: " <<  output << std::endl;

    return 0;
}