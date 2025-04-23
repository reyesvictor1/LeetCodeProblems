#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool judgeCircle(std::string moves) {

        // APPROACH: the robot will return to the origin if and only if
        // the number of 'U's is equal to the number of 'D's AND
        // the number of 'L's is equal to the number of 'R's

        std::unordered_map<char, int> inventory; // <letter, occurrences>
        for (char c : moves) inventory[c]++;

        return (inventory['U'] == inventory['D'] && inventory['L'] == inventory['R']);
    }
};

int main() {
    std::string moves;
    std::cout << "Enter the robot moves: ";
    std::cin >> moves;

    Solution solution;
    bool output = solution.judgeCircle(moves);
    std::cout << "Robot returns to origin: " << output << std::endl;

    return 0;
}