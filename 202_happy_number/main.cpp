#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool isHappy(int num)
    {
        std::vector<int> checkedSums;
        while (num > 1) {
            // replace the number by the sum of the squares of its digits
            std::string numStr = std::to_string(num);
            int currentSum = 0;
            for (char digit : numStr) {
                int d = digit - '0';
                currentSum += d * d;
            }
            num = currentSum;

            // check if currentSum has not appeared previously, if yes, it means the process will cycle
            auto it = std::find(checkedSums.begin(), checkedSums.end(), currentSum);
            if (it != checkedSums.end()) return false; // currentSum has already appeared, stop the process
            checkedSums.push_back(currentSum);
        }
        return true;
    }
};

int main()
{
    int input;
    std::cout << "insert number: ";
    std::cin >> input;
    Solution solution;
    std::cout << "output: " << solution.isHappy(input) << std::endl;

    return 0;
}