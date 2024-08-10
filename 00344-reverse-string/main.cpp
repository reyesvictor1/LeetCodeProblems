#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        
        // solution A: time complexity O(n)
        std::reverse(s.begin(), s.end());

        // solution B: time complexity O(n)
        // int n = s.size();
        // int low = 0, high = n-1;       
        // while(low <= high){
        //     swap(s[low], s[high]);
        //     low++; high--;
        // }

        // solution C: traditional, but uses extra space and does not modify the array in-place, time complexity O(n)
        // std::vector<char> reversedString;
        // reversedString.reserve(s.size()); // memory preallocation, could improve performance
        // for (size_t idx = s.size() - 1; idx !=0; idx--) {
        //     reversedString.push_back(s[idx]);
        // }
        // return reversedString; // would return a vector<char>

        return;
    }
};

int main() {

    std::vector<char> input = {'v', 'i', 'c', 't', 'o', 'r'};
    std::cout << "input: ";
    for (char c : input) std::cout << c;
    std::cout << std::endl;

    Solution solution;
    solution.reverseString(input);
    std::cout << "output: ";
    for (char c : input) std::cout << c;
    std::cout << std::endl;

    return 0;
}