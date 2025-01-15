#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        // APPROACH: imagine a plot of price against time
        // follow the stock market strategy: "buy low, sell high"
        // sum all the increasing slopes: that's the maximum profit
        int cumulativeProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int priceCurrentDay = prices[i];
            int priceNextDay = prices[i + 1];
            if (priceNextDay > priceCurrentDay)
                cumulativeProfit += priceNextDay - priceCurrentDay;
        }
        return cumulativeProfit;
    }
};

int main() {
    std::vector<int> input = {7,1,5,3,6,4};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.maxProfit(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}