#include <iostream>
#include <vector>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {

        int maxWealth = 0;
        int temp = 0;

        for (std::vector<int> account : accounts) {
            temp = 0;
            for (int balance : account) temp += balance;
            if (temp > maxWealth) maxWealth = temp;
        }

        return maxWealth;
    }
};

int main() {
    std::vector<std::vector<int>> accounts =   {{2,8,7},
                                                {7,1,3},
                                                {1,9,5}};
    for (std::vector<int> account : accounts) {
        std::cout << ">>> ";
        for (int balance : account) std::cout << balance << " ";
        std::cout << std::endl;
    }

    Solution solution;
    int richest = solution.maximumWealth(accounts);
    std::cout << "richest: " << richest << std::endl;

    return 0;
}
