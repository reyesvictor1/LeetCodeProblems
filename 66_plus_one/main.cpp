#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        
        bool overflow = true;

        // iterate over the vector in reverse order
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it != 9) {
                *it += 1;
                overflow = false;
            }
            else {
                *it = 0;
            }
            if (!overflow) break;
        }

        // there is still overflow, then add a new digit at the beginning
        if (overflow) digits.insert(digits.begin(), 1);        
        
        // print final vector
        for (unsigned digit :  digits) {
            std::cout << digit << " ";
        }

        return digits;
    }
};

int main() {
    std::vector<int> digits{9,8,9};
    Solution solution;
    solution.plusOne(digits);
}