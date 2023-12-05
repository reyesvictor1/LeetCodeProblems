#include <iostream>
#include <stack>

class Solution {
public:
    std::string removeStars(std::string input) {
        
        // traverse the string, pushing each letter into the stack
        // whenever a star * shows up, do not push the star * and pop() the top element of the stack
        std::stack<char> charStack;
        for (int idx = 0; idx < input.size(); idx++) {
            if (input[idx] == '*') charStack.pop();
            else charStack.push(input[idx]);
        }

        // // make a string with the remaining elements from the stack
        int strSize =  charStack.size();
        std::string output(strSize, ' '); // preallocate the string size
        while (!charStack.empty()) {
            output[strSize - 1] = charStack.top(); // elements must be inserted backwards
            charStack.pop();
            strSize--;
        }
        return output;
    }
};

int main() {
    std::string input = "leet**cod*e";
    std::cout << "input: " << input << std::endl;

    Solution solution;
    std::string output = solution.removeStars(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}