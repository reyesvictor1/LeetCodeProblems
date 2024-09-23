#include <iostream>
#include <vector>

class Solution {
public:
    int findPoisonedDuration(std::vector<int> &timeSeries, int duration) {
        
        int poisonedDuration = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            int endCurrentPoisonTime = timeSeries[i] + duration - 1;
            int nextStartingPosionTime = timeSeries[i + 1];
            if (endCurrentPoisonTime < nextStartingPosionTime) 
                poisonedDuration += duration;
            else {
                int t = timeSeries[i + 1] - timeSeries[i];
                poisonedDuration += t;
            }
        }
        poisonedDuration += duration; // add duration for the final element of the timeSeries
        return poisonedDuration;
    }
};

int main() {
    std::vector<int> timeSeries = {1, 4};
    int duration = 2;

    std::cout << "timeSeries: [ ";
    for (int num : timeSeries) std::cout << num << " ";
    std::cout << "]" << std::endl;
    std::cout << "duration:" << duration << std::endl;

    Solution solution;
    int output = solution.findPoisonedDuration(timeSeries, duration);
    std::cout << "output:" << output << std::endl;

    return 0;
}