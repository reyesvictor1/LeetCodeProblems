#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {

        // convert integer to string
        std::string A = std::to_string(x);

        // copy string and reverse the copy
        std::string B = A;
        std::reverse(B.begin(), B.end());

        // compare both strings
        for (size_t i = 0; i <= A.length() ; i++) {
            if (A[i] != B[i]) return false;
        }
        return true;
    }
};

int main() {

    int x = 121;  // outputs true
    int y = -121; // outputs false
    int z = 1;    // outputs true

    Solution solution;
    std::cout << x << " : " << solution.isPalindrome(x) << "\n";
    std::cout << y << " : " << solution.isPalindrome(y) << "\n";
    std::cout << z << " : " << solution.isPalindrome(z) << "\n";

    return 0;
}