#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string str) {
        
        std::stack<char> myStack;

        for (char c : str) {
            switch (c)
            {
                // if its closing, check if top element of stack is its corresponding closing part
                case ')':
                    if (myStack.empty() || myStack.top() != '(') return false;
                    myStack.pop();
                    break;
                case ']':
                    if (myStack.empty() || myStack.top() != '[') return false;
                    myStack.pop();
                    break;
                case '}':
                    if (myStack.empty() || myStack.top() != '{') return false;
                    myStack.pop();
                    break;
                default:

                    // if its opening, push it into the stack
                    if (c == '(' ||  c == '[' || c == '{') myStack.push(c);
                    else {
                        std::cout << "Character '" << c << "' is not allowed." << std::endl;
                        return false;
                    }
            }
        }
        if (myStack.empty()) return true;
        else return false;
    }
};

int main() {

    std::string input;
    // input = "()[]{}";
    // std::cout << "input: "<< input << std::endl;
    std::cout << "input: ";
    std::cin >> input;
    
    Solution solution;
    bool output = solution.isValid(input);
    std::cout << "output: " << output << std::endl;
    
    return 0;
}