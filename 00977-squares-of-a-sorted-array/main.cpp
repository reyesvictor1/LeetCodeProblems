#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {

        // create a new vector with all the squares
        std::vector<int> squares;
        for (int num : nums) {
            int square = num * num;
            squares.push_back(square);
        }

        // sort and return the new vector
        quickSort(squares, 0, squares.size() - 1);
        return squares;

    }

    void quickSort(std::vector<int> &array, int startIdx, int endIdx) {

        if (startIdx >= endIdx) return; // base case

        int partitionIdx = partition(array, startIdx, endIdx);
        quickSort(array, startIdx, partitionIdx - 1);
        quickSort(array, partitionIdx + 1, endIdx);

    }
private:
    int partition(std::vector<int> &array, int startIdx, int endIdx) {
        int pivotValue = array[endIdx];
        int i = startIdx - 1;
        for (int j = startIdx; j <= endIdx -1; j++) {
            if (array[j] < pivotValue) {
                i++;
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
        i++;
        int temp = array[endIdx];
        array[endIdx] = array[i];
        array[i] = temp;
        return i;
    }
};

int main() {
    std::vector<int> input = {-7,-3,2,3,11};
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::vector<int> output = solution.sortedSquares(input);
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}