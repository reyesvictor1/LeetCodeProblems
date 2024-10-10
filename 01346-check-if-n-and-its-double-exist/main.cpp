#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool checkIfExist(std::vector<int> &arr) {
        std::unordered_set<int> numSet;
        for (int num : arr) {

            // check if set already contains its double 
            int numDouble = 2 * num;
            if (numSet.count(numDouble))
                return true;

            // if even, check if set already contains its half 
            if (!(num % 2)) {
                int numHalf = num / 2;
                if (numSet.count(numHalf))
                    return true;
            }
            
            // insert num into set
            numSet.insert(num);
        }
        return false;
    }
};

int main() {
    std::vector<int> input = {10, 2, 5, 3};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    bool output = solution.checkIfExist(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}