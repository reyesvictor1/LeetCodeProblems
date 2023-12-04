#include <iostream>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        
        // create set containing all jewels
        std::unordered_set<char> jewelsSet;
        for (char c : jewels) jewelsSet.insert(c);

        // look for jewels in stones
        int jewelsFound = 0;
        for (char c : stones) if (jewelsSet.count(c)) jewelsFound++;

        return jewelsFound;
    }
};

int main() {
    
    std::string jewels = "aA";
    std::string stones = "aAAbbbb";
    std::cout << "jewels: " << jewels << std::endl;
    std::cout << "stones: " << stones << std::endl;

    Solution solution;
    int output = solution.numJewelsInStones(jewels, stones);
    std::cout << "output: " << output << std::endl;

    return 0;
}