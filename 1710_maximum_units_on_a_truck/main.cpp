#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {

        // create inventory <numberOfUnitsPerBox, numberOfBoxes>
        std::set<int> unitsPerBox_set;
        std::unordered_map<int, int> inventory;
        for (std::vector<int> boxType : boxTypes) {
            unitsPerBox_set.insert(boxType[1]);
            inventory[boxType[1]] += boxType[0];
        }

        // convert the set back to vector
        std::vector<int> unitsPerBox;
        for (int boxType : unitsPerBox_set)
            unitsPerBox.push_back(boxType);

        // truck's loading process
        int totalUnitsLoaded = 0;
        int remainingSpace = truckSize;
        for (int i = unitsPerBox.size() - 1; i >= 0; i--) {
            if (remainingSpace <= 0) return totalUnitsLoaded;
            
            int unitsInThisBoxType = unitsPerBox[i];
            int availableBoxes = inventory[unitsInThisBoxType];

            // load the truck
            if (availableBoxes > remainingSpace) {
                totalUnitsLoaded += remainingSpace * unitsInThisBoxType;
                remainingSpace = 0;
                return totalUnitsLoaded;
            } else {
                totalUnitsLoaded += availableBoxes * unitsInThisBoxType;
                remainingSpace -= availableBoxes;
            }
        }
        return totalUnitsLoaded;
    }
};

int main() {

    std::vector<std::vector<int>> boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;
    std::cout << "boxTypes: [";
    for (std::vector<int> boxType : boxTypes)
        std::cout << "[" << boxType[0] << "," << boxType[1] << "]";
    std::cout << "]" << std::endl;
    std::cout << "truckSize: " << truckSize << std::endl;

    Solution solution;
    int output = solution.maximumUnits(boxTypes, truckSize);
    std::cout << "output: " << output << std::endl;

    return 0;
}