#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        // for each day, what's the most possible profit I can make?
        // ANSWER: keep track of the lowest value that appeared before
        int minPrice = prices[0]; // initialize min price as the first price
        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) maxProfit = profit;
        }
        return maxProfit;
    }
};

int main() {
    std::vector<int> input = {7, 1, 5, 3, 6, 4};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.maxProfit(input);
    std::cout << "output: " << output << std::endl;
    
    return 0;
}