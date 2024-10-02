#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> collisions;
        std::vector<int> remainingAsteroids;
        bool keepChecking = false;

        for (int incomingAsteroid : asteroids) {

            do {
                // if stack is empty, then push the asteroid
                if (collisions.empty()) {
                    collisions.push(incomingAsteroid);
                    keepChecking = false;
                    continue;
                }

                // if stack is not empty, check the collision result
                int topAsteroid = collisions.top();

                // case 1: both asteroids traveling in the same direction
                if ((topAsteroid > 0 && incomingAsteroid > 0) || (topAsteroid < 0 && incomingAsteroid < 0))
                    collisions.push(incomingAsteroid);

                // case 2: top asteroid traveling left, incoming asteroid traveling right (no collision)
                else if (topAsteroid < 0 && incomingAsteroid > 0)
                    collisions.push(incomingAsteroid);

                // case 3: collision, both asteroids get destroyed
                else if (topAsteroid == -incomingAsteroid)
                    collisions.pop();

                // case 4: collision, top asteroid gets destroyed by incoming asteroid
                else if (abs(topAsteroid) < abs(incomingAsteroid)) {
                    collisions.pop();
                    keepChecking = true;
                    continue;
                }

                // case 5: collision, incoming asteroid gets destroyed by top asteroid, stop checking 
                keepChecking = false;

            } while (keepChecking);
            
        }

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

        return remainingAsteroids;
    }
};

int main() {
    std::vector<int> input = {-2,-2,1,-2};
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