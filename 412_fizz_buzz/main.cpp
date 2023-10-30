#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {

        // solution A: first approach, 4 ms
        std::vector<std::string> outputVector;
        for (int idx = 1; idx <= n; idx++) {
            if (!(idx % 3) && !(idx % 5)) outputVector.push_back("FizzBuzz");
            else if (!(idx % 3)) outputVector.push_back("Fizz");
            else if (!(idx % 5)) outputVector.push_back("Buzz");
            else outputVector.push_back(std::to_string(idx));
        }
        return outputVector;

        // solution B: taken from the solutions section, 0 ms
        // std::vector<std::string> res(n);
        // for(int i = 1;i <= n; i++) {
        //     res[i - 1] = std::to_string(i);
        // }
        // for(int i = 2;i < n; i += 3) {
        //     res[i] = "Fizz";
        // }
        // for(int i = 4;i < n; i += 5) {
        //     res[i] = "Buzz";
        // }
        // for(int i = 14;i < n; i += 15) {
        //     res[i] = "FizzBuzz";
        // }
        // return res;
    }
};

int main() {
    int n;
    std::cout << "input: ";
    std::cin >> n;

    Solution solution;
    std::vector<std::string> output = solution.fizzBuzz(n);
    std::cout << "output: ";
    for (std::string str : output) std::cout << str <<  " ";
    std::cout << std::endl;

    return 0;
}