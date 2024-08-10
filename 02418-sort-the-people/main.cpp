#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {

        std::vector<std::string> sortedPeople;
        
        // find max height and its corresponding index
        std::unordered_set<int> usedIndexes;
        for (int j = 0; j < names.size(); j++) {
            
            int maxValue = 0; // reset value
            int maxIndex = 0; // reset index

            for (int idx = 0; idx < heights.size(); idx++) {

                // check if idx is not an already used index, if yes then continue
                if (usedIndexes.count(idx)) continue;

                if (heights[idx] > maxValue) {
                    maxValue = heights[idx];
                    maxIndex = idx;
                }
            }
            sortedPeople.push_back(names[maxIndex]);
            usedIndexes.insert(maxIndex); // add index to the usedIndexes set
        }
        return sortedPeople;
    }
};

int main() {

    std::vector<std::string> names = {"Mary", "John", "Emma"};
    std::vector<int> heights = {180, 165, 170};
    std::cout << "names: ";
    for (std::string name : names) std::cout << name << " ";
    std::cout << std::endl;
    std::cout << "heights: ";
    for (int height : heights) std::cout << height << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<std::string> sortedPeople = solution.sortPeople(names, heights);
    std::cout << "sorted: ";
    for (std::string name : sortedPeople) std::cout << name << " ";
    std::cout << std::endl;

    return 0;
}