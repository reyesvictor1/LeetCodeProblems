#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        
        // create a map of bills according to their value (cash register)
        std::unordered_map<int, int> cashRegister;
        for (int bill : bills) {
            switch (bill) {
                case 5:
                    cashRegister[5]++;
                    break;
                case 10:
                    if (cashRegister[5] > 0) {
                        cashRegister[5]--;
                        cashRegister[10]++;
                        break;
                    }
                    return false;
                case 20: // first try to give a $10 bill if posible
                    if (cashRegister[10] > 0 && cashRegister[5] > 0) {
                        cashRegister[10]--;
                        cashRegister[5]--;
                        break;
                    } else if (cashRegister[5] >= 3) {
                        cashRegister[5] -= 3;
                        break;
                    }
                    return false;
                default:
                    std::cout << "Invalid bill: " << bill << std::endl;
                    return false;
            }  
        }
        return true;
    }
};

int main() {
    std::vector<int> bills = {5, 5, 5, 10, 20};
    std::cout << "bills: ";
    for (int num : bills) std::cout << num << " ";
    std::cout << std::endl;

    Solution solution;
    std::cout << solution.lemonadeChange(bills);

    return 0;
}