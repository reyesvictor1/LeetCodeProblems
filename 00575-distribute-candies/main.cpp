#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        
        std::unordered_set<int> uniques;
        for (int candy : candyType) uniques.insert(candy);

        int halfSize = candyType.size() * 0.5;
        int maxNum = uniques.size() > halfSize ? halfSize : uniques.size();

        return maxNum;
    }
};

int main() {

    std::vector<int> input = {1,1,1,2,4,4,5,5,5,5};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.distributeCandies(input);
    std::cout << "output:" << output << std::endl;

    return 0;
}