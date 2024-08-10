#include <iostream>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int fullBottles = numBottles;
        int emptyBottles = 0;
        int totalBottles = fullBottles + emptyBottles;
        int totalDrink = fullBottles;

        while(totalBottles >= numExchange) {
            fullBottles = totalBottles / numExchange;
            emptyBottles = totalBottles % numExchange;
            totalBottles = fullBottles + emptyBottles;
            totalDrink += fullBottles;
        }
        return totalDrink;
    }
};

int main() {
    int numBottles;
    int numExchange;
    std::cout << "numBottles: ";
    std::cin >> numBottles;
    std::cout <<"numExchange: ";
    std::cin >> numExchange;

    Solution solution;
    int output = solution.numWaterBottles(numBottles, numExchange);
    std::cout << "output: " << output << std::endl;

    return 0;
}