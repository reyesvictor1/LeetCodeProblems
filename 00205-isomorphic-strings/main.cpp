#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> correlationMap;
        std::unordered_set<char> mappedCharacters;
        for (int i = 0; i < s.size(); i++) {
            char charFromS = s[i];
            char charFromT = t[i];
            // check whether character has already been mapped
            auto it = correlationMap.find(charFromS);
            if (it != correlationMap.end()) { // key exists
                char equivalentChar = correlationMap[charFromS];
                if (equivalentChar != charFromT)
                    return false;
            } else { // key does not exist, insert it
                correlationMap[charFromS] = charFromT;
                // but also check if char from t has not been already mapped
                if (mappedCharacters.find(charFromT) != mappedCharacters.end())
                    return false; // char from t has already been mapped
                mappedCharacters.insert(charFromT);
            }
        }
        return true;
    }
};

int main() {
    std::string s = "badc";
    std::string t = "baba";

    std::cout << "s: " << s << std::endl;
    std::cout << "t: " << t << std::endl;

    Solution solution;
    bool output = solution.isIsomorphic(s, t);
    std::cout << "output: " << output << std::endl;

    return 0;
}