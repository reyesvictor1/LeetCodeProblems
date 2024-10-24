#include <iostream>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {

        bool previousIdxHasFlower = false;
        for (int idx = 0; idx < flowerbed.size(); idx++) {

            // if no more flowers to place
            if (!n) break;

            // if current index already has a flower
            if (flowerbed[idx] == 1) {
                previousIdxHasFlower = true;
                continue;
            }

            // if previous index already has a flower
            if (previousIdxHasFlower) {
                previousIdxHasFlower = false;
                continue;
            }

            // current index has no flower, check next index
            int nextIdx = idx + 1;
            if (nextIdx < flowerbed.size()) {

                // if next index already has a flower
                if (flowerbed[nextIdx] == 1) continue;

                // next index has no flower, place flower in current index
                flowerbed[idx] = 1;
                n--;
                previousIdxHasFlower = true;
            } else {
                flowerbed[idx] = 1;
                n--; // limit reached, place flower there
            }
        }
        return !n;
    }
};

int main() {
    std::vector<int> input = {1,0,0,0,1};
    int n = 2;
    std::cout << "input: ";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "n: " << n << std::endl;

    Solution solution;
    bool output = solution.canPlaceFlowers(input, n);
    std::cout << "output: " << output << std::endl;

    return 0;
}