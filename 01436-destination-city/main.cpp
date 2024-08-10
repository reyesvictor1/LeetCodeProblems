#include <iostream>
#include <vector>
#include <unordered_map>

enum class CityType { Departure, Destination, Both};

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        
        // create a map of all the cities
        // each city will receive one value CityType (Departure, Destination, Both)
        std::unordered_map<std::string, CityType> cities;
        for (std::vector<std::string> path : paths) {

            std::string departure = path[0];
            std::string destination = path[1];

            // check departure city
            if (cities.count(departure)) {
                if (cities[departure] != CityType::Departure) cities[departure] = CityType::Both;
            } else {
                cities[departure] = CityType::Departure; // departure
            }
            
            // check destination city
            if (cities.count(destination)) {
                if (cities[destination] != CityType::Destination) cities[destination] = CityType::Both;
            } else {
                cities[destination] = CityType::Destination; // destination
            }
        }

        // traverse the map looking for the city which is destination only
        for (const auto &pair : cities) {
            if (pair.second == CityType::Destination) return pair.first;
        }

        std::string failed = "No destination found.";
        return failed;

    }
};

int main() {

    std::vector<std::vector<std::string>> paths = {
        {"London", "New York"},
        {"New York", "Lima"},
        {"Lima", "Sao Paulo"}
    };
    Solution solution;
    std::string output = solution.destCity(paths);
    std::cout << "output: " << output << std::endl;

    return 0;
}