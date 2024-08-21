#include <iostream>
#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {

        /** 
        * @brief Solution using the Two Pointers algorithm.  
        */
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {

            // if blank space is found or end of the sentence has been reached
            if (s[i] == ' ' || i == s.size() - 1) {
                
                // decrement right index (only if it is not end of the sentence)
                if (i != s.size() - 1) right--;

                // reverse the current word
                while (left < right) { 
                    std::swap(s[left], s[right]);
                    left++;
                    right--;
                }

                // set new position of left and right, starting at the next word
                left = i + 1;
                right = i + 1;
            } else {
                right++;
            }     
        }
        return s;
    }
};

int main() {
    std::string str = "Let's take LeetCode contest";
    std::cout << "input: " << str << std::endl;

    Solution solution;
    std::string output = solution.reverseWords(str);
    std::cout << "output: " << output  << std::endl;

    return 0;
}