#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        
        // base case: if amount is zero, return 0
        if (!amount) return 0;

        // apply dynamic programming approach
        std::vector<int> minCoinsVector = {0}; // first element is zero
        std::vector<int> temp;
        for (int i = 1; i <= amount; i++) {
            temp.clear();
            // for each iteration, check the minimum coins for each coin
            for (int coin : coins) {
                int indexToCheck = i - coin;
                if (indexToCheck < 0) continue; // index is out of range
                if (indexToCheck > 0 && minCoinsVector[indexToCheck] == 0) continue; // index in range but its value is zero,
                // means it is not possible to reach the amount using that coin denomination
                temp.push_back(minCoinsVector[indexToCheck]);
            }
            // check temp vector
            if (temp.empty()) minCoinsVector.push_back(0); // impossible to reach i with the available coin denominations
            else {
                // check which is the minimum value
                int minValue = i;
                for (int j = 0; j < temp.size(); j++) {
                    if (temp[j] < minValue) minValue = temp[j];
                }
                minCoinsVector.push_back(minValue + 1);
            }    
        }

        int result = minCoinsVector[amount];
        if (!result) return -1; // impossible to reach the amount with the available coin denominations
        else return result;
    }
};

int main() {

    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << "coins: ";
    for (int coin : coins) std::cout << coin << " ";
    std::cout << std::endl;
    std::cout << "amount: " << amount << std::endl;

    Solution solution;
    int output = solution.coinChange(coins, amount);
    std::cout << "output: " << output << std::endl;

    return 0;

}