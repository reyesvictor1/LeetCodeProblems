#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        std::vector<std::vector<int>> newImg = img;
        int rows = img.size();
        int cols = img[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                resetTotal();
                addToTotal(img[i][j]); // current pixel
                bool hasRowAbove = i > 0;
                bool hasRowBelow = i < rows - 1;
                bool hasColLeft = j > 0;
                bool hasColRight = j < cols -1;
                if (hasRowAbove) {
                    addToTotal(img[i - 1][j]); // top center
                    if (hasColLeft) addToTotal(img[i - 1][j - 1]); // top left corner
                    if (hasColRight) addToTotal(img[i - 1][j + 1]); // top right corner
                }
                if (hasRowBelow) {
                    addToTotal(img[i + 1][j]); // bottom center
                    if (hasColLeft) addToTotal(img[i + 1][j - 1]); // bottom left corner
                    if (hasColRight) addToTotal(img[i + 1][j + 1]); // bottom right corner
                }
                if (hasColLeft) addToTotal(img[i][j - 1]); // left center
                if (hasColRight) addToTotal(img[i][j + 1]); // right center

                newImg[i][j] = std::floor(m_total / m_pixelCounter);
            }
        }
        return newImg;
    }
private:
    int m_total = 0;
    int m_pixelCounter = 0;
    void addToTotal(int value) {
        m_total += value;
        m_pixelCounter++;
    }
    void resetTotal() {
        m_total = 0;
        m_pixelCounter = 0;
    }
};

int main() {
    std::vector<std::vector<int>> img = {{100,200,100},
                                         {200,50,200},
                                         {100,200,100}};
    std::cout << "input:" << std::endl;
    for (std::vector<int> row : img) {
        for (int col : row) std::cout << col << " ";
        std::cout << std::endl;
    }

    Solution solution;
    std::vector<std::vector<int>> newImg = solution.imageSmoother(img);

    std::cout << "output:" << std::endl;
    for (std::vector<int> row : newImg) {
        for (int col : row) std::cout << col << " ";
        std::cout << std::endl;
    }

    return 0;
}