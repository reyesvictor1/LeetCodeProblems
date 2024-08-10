#include <iostream>
#include <stack>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {

        // create a stack for each string:
        // each time a char is found, insert it to the stack
        // each time # is found, remove top element from stack
        std::stack<char> stack_s;
        for (char c : s) {
            if (c != '#') stack_s.push(c);
            else if (!stack_s.empty()) stack_s.pop();
        }

        std::stack<char> stack_t;
        for (char c : t) {
            if (c != '#') stack_t.push(c);
            else if (!stack_t.empty()) stack_t.pop();
        }

        // compare both stacks
        if (stack_s.size() != stack_t.size()) return false;
        while (!stack_s.empty()) {
            if (stack_s.top() != stack_t.top()) return false;
            else {
                stack_s.pop();
                stack_t.pop();
            }
        }
        return true;
    }
};

int main() {

    std::string s = "ab#c";
    std::string t = "ad#c";
    std::cout << "s: " << s << std::endl;
    std::cout << "t: " << t << std::endl;
    Solution solution;
    bool output = solution.backspaceCompare(s, t);
    std::cout << "output: " << output << std::endl;
    
    return 0;
}