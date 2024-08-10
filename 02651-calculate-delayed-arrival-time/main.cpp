#include <iostream>

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        if (arrivalTime < 0 || delayedTime < 0) {
            std::cout << "Time cannot be negative" << std::endl;
            return 0;
        }
        int newArrivalTime = arrivalTime + delayedTime;
        return newArrivalTime % 24;
    }
};

int main() {

    int arrivalTime = 15;
    int delayedTime = 5;
    std::cout << "original arrival time: ";
    std::cin >> arrivalTime;
    std::cout << "delayed time: ";
    std::cin >> delayedTime;

    Solution solution;
    int newArrivalTime = solution.findDelayedArrivalTime(arrivalTime, delayedTime);
    std::cout << "new arrival time: " << newArrivalTime << std::endl;

    return 0;
}