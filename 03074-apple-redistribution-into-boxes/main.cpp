#include <iostream>
#include <vector>

class Solution {
public:
    void quickSort(std::vector<int> &array, int startIdx, int endIdx) {
       
        if (startIdx >= endIdx) return; // base case

        int pivotIdx = partition(array, startIdx, endIdx);
        quickSort(array, startIdx, pivotIdx - 1);
        quickSort(array, pivotIdx + 1, endIdx);

    }
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        
        // sum total apples
        int applesToDistribute = 0;
        for (int pack : apple) applesToDistribute += pack;

        // sort capacity boxes in descending order
        quickSort(capacity, 0, capacity.size() - 1);

        // distribute total apples into boxes
        for (int i = 0; i < capacity.size(); i++) {
            if (applesToDistribute <= 0) return i;
            applesToDistribute -= capacity[i];
        }
        return capacity.size();

    }
private:
    int partition(std::vector<int> &array, int startIdx, int endIdx) {
        int pivotValue = array[endIdx]; // pivot will always be the last index
        int i = startIdx - 1; // i will always start at startIdx - 1
        
        /*
            use j to iterate through the array, and when the loop finishes:
            - all elements less than the pivot value should be on the left side of the pivot
            - all elements greater than or equal to the pivot value should be on the right side of the pivot
        */
        for (int j = startIdx; j <= endIdx - 1; j++) {
            if (array[j] > pivotValue) { // "<" for ascending order, ">" for descending order
                i++;
                int temp = array[i];
                array[i] = array[j];  // variable swap
                array[j] = temp;
            }
        }
        i++;
        int temp = array[i];
        array[i] = array[endIdx];
        array[endIdx] = temp;
        
        return i; // i is the new pivot index
    }
};

int main() {
    std::vector<int> apple = {1,3,2};
    std::vector<int> capacity = {4,3,1,5,2};

    std::cout << "apple: ";
    for (int num : apple) std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "capacity: ";
    for (int num : capacity) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    int output = solution.minimumBoxes(apple, capacity);

    std::cout << "output: " << output << std::endl;

    return 0;
}