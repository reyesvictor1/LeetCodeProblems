#include <iostream>
#include <string>

class Solution {
public:
    int maximum69Number (int num) {
        std::string strNum = std::to_string(num);
        bool digitChanged = false;
        for (int idx = 0; idx < strNum.size(); idx++) {
            if (strNum[idx] == '6') {
                strNum[idx] = '9';
                digitChanged = true;
                break;
            }
        }
        return std::stoi(strNum);
    }
};

int main() {
    int input;
    std::cout << "insert number onsisting only of digits 6 and 9: ";
    std::cin >> input;

    Solution solution;
    int output = solution.maximum69Number(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}