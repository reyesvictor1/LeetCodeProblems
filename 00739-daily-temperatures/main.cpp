#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> daysUntilWarmer;
        for (int i = 0; i < temperatures.size(); i++) {
            int currentTemperature = temperatures[i];
            int daysWaiting = 0;
            for (int j = i + 1; j < temperatures.size(); j++) {
                daysWaiting++;
                if (currentTemperature < temperatures[j]) break;
                if (j == temperatures.size() - 1) daysWaiting = 0;
            }
            daysUntilWarmer.push_back(daysWaiting);
        }
        return daysUntilWarmer;
    }
};

int main() {
    std::vector<int> input = {73,74,75,71,69,72,76,73};
    std::cout << "input: ["; 
    for (int num : input) std::cout << num << " ";
    std::cout << "]" << std::endl;

    Solution solution;
    std::vector<int> output = solution.dailyTemperatures(input);
    std::cout << "output: ["; 
    for (int num : output) std::cout << num << " ";
    std::cout << "]" << std::endl;

    return 0;
}
