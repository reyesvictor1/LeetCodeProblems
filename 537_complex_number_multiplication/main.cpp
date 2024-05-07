#include <iostream>
#include <string>

class Solution
{
public:
    std::string complexNumberMultiply(std::string num1, std::string num2)
    {

        std::string A, B, C, D;
        int a, b, c, d;

        // extract values from num1
        for (int i = 0; i < num1.size(); i++)
        {
            if (num1[i] == '+')
                break;
            A += num1[i];
        }
        for (int i = A.size() + 1; i < num1.size() - 1; i++)
            B += num1[i];

        // extract values from num2
        for (int i = 0; i < num2.size(); i++)
        {
            if (num2[i] == '+')
                break;
            C += num2[i];
        }
        for (int i = C.size() + 1; i < num2.size() - 1; i++)
            D += num2[i];

        // convert coefficients from string to int
        a = std::stoi(A);
        b = std::stoi(B);
        c = std::stoi(C);
        d = std::stoi(D);

        // do math
        int real = (a * c) - (b * d);
        int imaginary = (a * d) + (b * c);

        // concatenate the results
        std::string result = std::to_string(real) + "+" + std::to_string(imaginary) + "i";
        return result;
    }
};

int main()
{
    std::string num1 = "2+1i";
    std::string num2 = "3+5i";
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    Solution solution;
    std::string output = solution.complexNumberMultiply(num1, num2);
    std::cout << "output: " << output << std::endl;

    return 0;
}