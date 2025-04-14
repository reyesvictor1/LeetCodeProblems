#include <iostream>
#include <vector>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {

        // approach: iterate through the array and find the two lowest values
        int choco1 = prices[0];
        int choco2 = prices[1];

        for (int i = 2; i < prices.size(); i++) {
            int current = prices[i];
            if (current >= choco1 && current >= choco2) continue;

            // discard the max value out of choco1 and choco2
            if (choco1 < choco2) choco2 = current;
            else choco1 = current;
        }
        
        int amountToPay = choco1 + choco2;
        int diff = money - amountToPay;
        return diff < 0 ? money : diff; 
    }
};

int main() {
    std::vector<int> prices = {5, 4, 6, 8, 2, 5};
    int money = 20;
    std::cout << "money: " << money << std::endl;
    std::cout << "prices: ";
    for (int price : prices) std::cout << price << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.buyChoco(prices, money);
    std::cout << "output: " << output << std::endl;

    return 0;
}