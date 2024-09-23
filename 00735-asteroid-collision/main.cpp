#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> collisions;
        std::vector<int> remainingAsteroids;
        for (int asteroid : asteroids) {

            // if collisions is empty, then push the asteroid
            if (collisions.empty()) {
                collisions.push(asteroid);
                continue;
            }
            
            int topAsteroid = collisions.top();

            

            // collision is expected
            bool bothAsteroidsDestroyed = false;
            while (!collisions.empty()) {
                topAsteroid = collisions.top();

                // both asteroids travel in the same direction
                if ((topAsteroid > 0 && asteroid > 0) || (topAsteroid < 0 && asteroid < 0)) { 
                    collisions.push(asteroid);
                    break;
                }

                if (abs(topAsteroid) > abs(asteroid)) break; // incoming asteroid is destroyed
                if (abs(topAsteroid) < abs(asteroid)) collisions.pop(); // top asteroid is destroyed
                if (abs(topAsteroid) == abs(asteroid)) { // both asteroids are destroyed
                    collisions.pop();
                    bothAsteroidsDestroyed = true;
                    break;
                } 
            }

            // incoming asteroid destroyed all other asteroids, push it to the vector
            if (collisions.empty() && !bothAsteroidsDestroyed) collisions.push(asteroid);

            // convert stack into vector
            while (!collisions.empty()) {
                remainingAsteroids.push_back(collisions.top());
                collisions.pop();
            }

            // reverse the vector, using "two pointers" algorithm
            int left = 0;
            int right = remainingAsteroids.size() - 1;
            while (left < right) {
                int temp = remainingAsteroids[left];
                remainingAsteroids[left] = remainingAsteroids[right];
                remainingAsteroids[right] = temp;
                left++;
                right--;
            }
        }
        return remainingAsteroids;
    }
};

int main() {
    std::vector<int> input = {10,2,-5};
    std::cout << "input: [";
    for (int num : input) std::cout << num << " ";
    std::cout << "]" << std::endl;

    Solution solution;
    std::vector<int> output = solution.asteroidCollision(input);
    std::cout << "output: [";
    for (int num : output) std::cout << num << " ";
    std::cout << "]" << std::endl;

    return 0;
}