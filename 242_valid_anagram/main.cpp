#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string stringA, std::string stringB) {
        
        // get the number of occurrences for each letter of stringA (inventory of letters)
        std::unordered_map<char, int> letterInventory;
        for (char c : stringB) {
            letterInventory[c]++; // increment value for the key[c], or insert it if not in the map
        }
        for (char c : stringA) {
            if (!letterInventory[c]) return false; // if key[c] does not exist or its value is zero, the process is finished
            letterInventory[c]--; // the key[c] exists, decrement its value
        }
        return true;

        // print the inventory
        // for (const auto& pair : letterInventory) {
        //     std::cout << pair.first << " : " << pair.second << std::endl;
        // }
    }
};

int main() {
    std::string stringA;
    std::string stringB;

    std::cout << "String A: ";
    std::cin >> stringA;
    std::cout << "String B: ";
    std::cin >> stringB;

    Solution solution;
    std::cout << solution.isAnagram(stringA, stringB);

    return 0;
}