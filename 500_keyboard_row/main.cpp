#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<std::string> findWords(std::vector<std::string> &words)
    {
        std::vector<std::string> outputVector;
        std::string row1 = "qwertyuiopQWERTYUIOP";
        std::string row2 = "asdfghjklASDFGHJKL";
        std::string row3 = "zxcvbnmZXCVBNM";
        std::vector<std::unordered_set<char>> rows(3);
        for (char c : row1)
            rows[0].insert(c);
        for (char c : row2)
            rows[1].insert(c);
        for (char c : row3)
            rows[2].insert(c);
        for (std::string word : words)
        {
            bool canBeTyped = false;
            for (int i = 0; i < rows.size(); i++)
            {
                for (int j = 0; j < word.size(); j++)
                {
                    if (!rows[i].count(word[j]))
                        break; // cannot be typed with this row, change to next row
                    else if (j == word.size() - 1)
                        canBeTyped = true;
                }
                if (canBeTyped)
                {
                    outputVector.push_back(word);
                    break;
                }
            }
        }
        return outputVector;
    }
};

int main()
{
    std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};
    std::cout << "input: [ ";
    for (std::string word : words)
        std::cout << word << " ";
    std::cout << "]" << std::endl;

    Solution solution;
    std::vector<std::string> output = solution.findWords(words);
    std::cout << "output: [ ";
    for (std::string word : output)
        std::cout << word << " ";
    std::cout << "]" << std::endl;

    return 0;
}