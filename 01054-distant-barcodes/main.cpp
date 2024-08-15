#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) {

        // create inventory of barcodes
        std::unordered_map<int, int> inventory; // <barcode, occurrences>
        for (int barcode : barcodes)
            inventory[barcode]++;

        // create new output vector
        int length = barcodes.size();
        std::vector<int> newBarcodes(length);

        // insert the barcodes by number of occurrences, but skipping one space in between
        int currentIdx = 0;
        for (int i = 0; i < length; i++) {

            // look for the value with the most occurrences
            int maxOccurrences = 0;
            int barcodeWithMostOccurrences;
            for (const auto &pair : inventory) {
                if (pair.second > maxOccurrences) {
                    maxOccurrences = pair.second;
                    barcodeWithMostOccurrences = pair.first;
                }
            }

            // insert barcodeWithMostOccurrences into the new barcodes vector, always skipping one space
            for (int j = 0; j < maxOccurrences; j++) {
                newBarcodes[currentIdx] = barcodeWithMostOccurrences;
                currentIdx += 2; // increment two
                if (currentIdx >= length) currentIdx = 1;
            }

            // for current barcodeWithMostOccurrences, set its number of occurrences to zero
            inventory[barcodeWithMostOccurrences] = 0;
        }

        return newBarcodes;
    }
};

int main()
{
    std::vector<int> barcodes = {1,1,1,1,2,2,3,3};
    std::cout << "barcodes: ";
    for (int barcode : barcodes)
        std::cout << barcode;
    std::cout << std::endl;

    Solution solution;
    std::vector<int> newBarcodes = solution.rearrangeBarcodes(barcodes);

    std::cout << "output: ";
    for (int barcode : newBarcodes)
        std::cout << barcode;
    std::cout << std::endl;

    return 0;
}