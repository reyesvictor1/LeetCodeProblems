#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {

        std::stack<int> record;
        
        // perform the operation and push result to the record
        for (std::string str : operations) {
            if (str == "C") record.pop();
            else if (str == "D") {
                int x = record.top();
                record.push(x * 2);
            }
            else if (str == "+") {
                int x = record.top();
                record.pop();
                int y = record.top();
                record.push(x);
                int sum = x + y;
                record.push(sum);
            }
            else {
                int x = std::stoi(str);
                record.push(x);
            }
        }

        // sum all the elements of the record
        int total = 0;
        while (!record.empty()) {
            total += record.top();
            record.pop();
        }
        return total;
    }
};

int main() {
    std::vector<std::string> input = {"5","2","C","D","+"};
    std::cout << "input: [";
    for (std::string str : input) std::cout << str <<  " ,";
    std::cout << "]" << std::endl;

    Solution solution;
    int output = solution.calPoints(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}