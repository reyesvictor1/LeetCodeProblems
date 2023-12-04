#include <iostream>
#include <vector>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        
        if (points.empty()) return 0;
        
        int totalTime = 0;
        std::vector<int> pointA = points[0];

        for (int idx = 1; idx < points.size(); idx++) {

            std::vector<int> pointB = points[idx];

            // compute the difference in distance for each axis
            int deltaX = abs(pointB[0] - pointA[0]);
            int deltaY = abs(pointB[1] - pointA[1]);

            // get the minimum difference value (which will be the diagonal time to travel)
            int diagonal = std::min(deltaX, deltaY);

            // substract minimum distance from maximum distance: this will be the vertical/horizontal time to travel
            int notDiagonal = abs(diagonal - std::max(deltaX, deltaY));

            // increment total time
            totalTime += diagonal + notDiagonal;

            // current point will become point A
            pointA = points[idx];
        }
        return totalTime;

    }
}; 

int main() {

    std::vector<std::vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    std::cout << "points: " << std::endl;
    for (std::vector<int> point : points) {
        std::cout << "[" << point[0] << "," << point[1] << "]" << std::endl;
    }
    Solution solution;
    int output = solution.minTimeToVisitAllPoints(points);
    std::cout << "output: " << output << std::endl;

    return 0;

}