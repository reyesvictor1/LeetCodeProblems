#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {

        // create word inventory for characters of magazine
        std::unordered_map<char, int> inventory;
        for (char c : magazine) inventory[c]++;

        // construct the ransomNote with characters of the inventory
        for (char c : ransomNote) {
            if (!inventory[c]) return false; // inventory does not contain char, cannot construct ransmNote
            inventory[c]--;
        }
        return true;
    }
};

int main() {
    std::string ransomNote = "help";
    std::string magazine = "padelsh";

    Solution solution;
    std::cout << "ransomNote: " << ransomNote << std::endl;
    std::cout << "magazine: " << magazine << std::endl;
    std::cout << solution.canConstruct(ransomNote, magazine) << std::endl;

    return 0;
}