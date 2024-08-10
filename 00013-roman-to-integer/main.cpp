#include <iostream>

class Solution {
public:
    int romanToInt(std::string str) {
        
        int total = 0;
        bool skip = false;
        for (int idx = 0; idx < str.size(); idx++) {

            if (skip) {
                skip = false;
                continue;
            }

            switch (str[idx]) {
            case 'I':
                if (idx + 1 < str.size()) {
                    if (str[idx + 1] == 'V') { total += 4; skip = true;}
                    else if (str[idx + 1] == 'X') { total += 9; skip = true;}
                    else total += 1;
                } else {
                    total += 1;
                }
                break;
            case 'V':
                total += 5;
                break;
            case 'X':
                if (idx + 1 < str.size()) {
                    if (str[idx + 1] == 'L') { total += 40; skip = true;}
                    else if (str[idx + 1] == 'C') { total += 90; skip = true;}
                    else total += 10;
                } else {
                    total += 10;
                }
                break;
            case 'L':
                total += 50;
                break;
            case 'C':
                if (idx + 1 < str.size()) {
                    if (str[idx + 1] == 'D') { total += 400; skip = true;}
                    else if (str[idx + 1] == 'M') { total += 900; skip = true;}
                    else total += 100;
                } else {
                    total += 100;
                }
                break;
            case 'D':
                total += 500;
                break;
            case 'M':
                total += 1000;
                break;
            default:
                break;
            }
        }
        return total;
    }
};

int main() {

    std::string roman = "MCMXCVIII"; // 1998
    std::cout << "roman: " << roman << std::endl;

    Solution solution;
    int value = solution.romanToInt(roman);
    std::cout << "integer: " << value << std::endl;

    return 0;
}