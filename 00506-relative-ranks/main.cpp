#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        // sort array in descending order
        std::vector<int> sortedScores = score;
        quickSort(sortedScores, 0, sortedScores.size() - 1);

        // create a hash map of ranks based on the sorted array
        std::unordered_map<int, int> rankingMap; // <score, rank>
        int currentPlace = 1;
        for (int s : sortedScores) {
            rankingMap[s] = currentPlace;
            currentPlace++;
        }

        // for each element in score, look for its corresponding rank in the hash map
        std::vector<std::string> rankingVector;
        for (int s : score) {
            int place = rankingMap[s];
            std::string placeStr;
            switch (place)
            {
            case 1:
                placeStr = "Gold Medal";
                break;
            case 2:
                placeStr = "Silver Medal";
                break;
            case 3:
                placeStr = "Bronze Medal";
                break;
            
            default:
                placeStr = std::to_string(place);
                break;
            }
            rankingVector.push_back(placeStr);
        }

        return rankingVector;

    }
private:
    void quickSort(std::vector<int> &array, int startIdx, int endIdx) {
        if (startIdx >= endIdx) return; // base case

        int pivotIdx = partition(array, startIdx, endIdx);
        quickSort(array, startIdx, pivotIdx - 1);
        quickSort(array, pivotIdx + 1, endIdx);

    }

    int partition(std::vector<int> &array, int startIdx, int endIdx) {
        int pivotValue = array[endIdx]; // pivot value will always be value of last index
        int i = startIdx - 1; // i will always start at startIdx - 1

        for (int j = startIdx; j <= endIdx - 1; j++) {
            if (array[j] > pivotValue) {
                // swap i with j
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // final swap of i with endIdx
        i++;
        int temp = array[i];
        array[i] = array[endIdx];
        array[endIdx] = temp;

        return i;  // i is the new pivot
    }
};

int main() {
    std::vector<int> scores = {10,3,8,9,4};
    std::cout << "scores: ";
    for (int num : scores) std::cout << num << ", ";
    std::cout << std::endl;

    Solution solution;
    std::vector<std::string> ranks = solution.findRelativeRanks(scores);
    std::cout << "ranks: ";
    for (std::string str : ranks) std::cout << str << ", ";
    std::cout << std::endl;

    return 0;
}