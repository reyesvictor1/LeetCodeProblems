#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs, int k) {
        
        // traverse the logs vector to make an inventory (userID : set of minutes when userID had activity)
        std::unordered_map<int, std::unordered_set<int>> inventory;
        for (std::vector<int> log : logs) {
            int userID = log[0];
            int minuteOfActivity = log[1];
            inventory[userID].insert(minuteOfActivity);
        }

        // count how many minutes each user was active (get size of set)
        std::vector<int> UAMstatistics(k); // preallocate vector of size k
        for (const auto pair : inventory) {
            int userUAM = pair.second.size();
            if (userUAM <= UAMstatistics.size()) UAMstatistics[userUAM - 1]++;
        }
        return UAMstatistics;
    }
};

int main() {
    std::vector<std::vector<int>>logs = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    int k = 5;
    std::cout << "logs: " << std::endl;
    for (std::vector<int> log : logs) std::cout << "[ " << log[0] << ", " << log[1] << " ]" << std::endl;

    Solution solution;
    std::vector<int> output = solution.findingUsersActiveMinutes(logs, k);
    std::cout << "output: ";
    for (int num : output) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}