#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int staircaseTop) {

        std::vector<int> stepsVector = {1}; // set initial step to one for adding purposes
        std::vector<int> climbingPossibilities = { 1, 2 }; // you can climb either 1 step or 2 steps
        std::vector<int> temp;

        for (int i = 1; i <= staircaseTop; i++) {

            // iterate through all the possibilites
            temp.clear();
            for (int climbingPossibility : climbingPossibilities) {
                int indexToCheck = i - climbingPossibility;
                if (indexToCheck < 0) continue; // index is out of range
                if (indexToCheck > 0 && stepsVector[indexToCheck] == 0) continue; // impossible to reach current step with that climbing possibility
                temp.push_back(indexToCheck);
            }

            // evaluate results of current iteration
            if (temp.empty()) stepsVector.push_back(0); // impossible to reach step i with the available climbing possibilites
            else {
                int sumOfPossibilites = 0;
                for (int index : temp) {
                    sumOfPossibilites += stepsVector[index];
                }
                stepsVector.push_back(sumOfPossibilites);
            }

        }

        // get final result, which is the last element of the vector
        int result = stepsVector[staircaseTop];
        if (!result) return -1; // impossible to reach the top with available climbing possibilites
        else return result;
    }
};

int main() {
    int numOfSteps;
    std::cout << "Number of steps: ";
    std::cin >> numOfSteps;

    Solution solution;
    int output = solution.climbStairs(numOfSteps);
    std::cout << "You can reach the top in " << output << " diffent ways." << std::endl;

    return 0;
}