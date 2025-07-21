#include <iostream>
#include <vector>

class Solution {
public:
    bool validMountainArray(std::vector<int>& arr) {
        if (arr.size() < 3) return false; // array must have at least 3 elements

        bool ascending = true;
        for (int i = 1; i < arr.size(); i++) {

            int previousValue = arr[i - 1];
            int currentValue = arr[i];
            if (currentValue == previousValue) return false;

            if (ascending) {
                if (currentValue > previousValue) continue;
                if (currentValue < previousValue) {
                    ascending = false;
                    if (i == 1) return false; // array never increased
                }
            } else {
                if (currentValue < previousValue) continue;
                return false;
            }
        }
        if (ascending) return false; // array never decreased
        return true; 

    }
};

int main() {
    std::vector<int> input = {0,2,3,4,5,2,1,0};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    bool output = solution.validMountainArray(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}