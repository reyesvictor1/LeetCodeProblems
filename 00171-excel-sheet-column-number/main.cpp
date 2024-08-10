#include <iostream>
#include <cmath>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        
        int total = 0;
        int letterValue = 0;
        int power = 0;
        for (int idx = columnTitle.size() - 1; idx >= 0; idx--) {
            letterValue = columnTitle[idx] - 'A' + 1;
            total += letterValue * std::pow(26, power);
            // if (!power) total++; // POTENTIAL BUG, NEEDS TO BE CHECKED
            power++;
        }
        return total;
    }
};

int main() {

    std::string columnTitle;
    std::cout << "columnTitle: ";
    std::cin >> columnTitle;

    Solution solution;
    int output = solution.titleToNumber(columnTitle);
    std::cout << "output: " << output << std::endl;

    return 0;
}