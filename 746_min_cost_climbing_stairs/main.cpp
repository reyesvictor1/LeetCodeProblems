#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        
        cost.push_back(0); // add
        int vectorSize = cost.size();

        // declaration phase
        std::vector<int> minCostVector = {cost[0], cost[1]};
        std::vector<int> climbingPossibilities = {1, 2};
        std::vector<int> temp;

        // iteration phase
        for (int i = 2; i < vectorSize; i++) {
            temp.clear();
            for (int climbingPossibility : climbingPossibilities) {
                int indexToCheck = i - climbingPossibility;
                if (indexToCheck < 0) continue; // out of range
                temp.push_back(indexToCheck);
            }
            if (temp.empty()) minCostVector.push_back(0);
            else {
                int minValue = INT_MAX;
                for (int num : temp) {
                    if (minCostVector[num] < minValue) minValue = minCostVector[num];
                }
                minCostVector.push_back(minValue + cost[i]);
            }
        }
        return minCostVector.back();
    }
};

int main() {
    // std::vector<int> input = {10, 15, 20};
    std::vector<int> input = {1,100,1,1,1,100,1,1,100,1};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.minCostClimbingStairs(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}