#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int numUniqueEmails(std::vector<std::string>& emails) {

        // create inventory of local names and domain names
        std::unordered_map<std::string, std::unordered_set<std::string>> inventory;
        for (std::string email : emails) {
            std::string localName;
            int atPosition = 0;
            bool plusFound = false;
            for (int idx = 0; idx < email.size(); idx++) {
                if (email[idx] == '.') continue;
                if (email[idx] == '+') plusFound = true;
                if (email[idx] == '@') {
                    atPosition = idx;
                    break;
                };
                if (!plusFound) localName += email[idx];
            }
            std::string domainName = email.substr(atPosition + 1);
            inventory[localName].insert(domainName);
        }
    
        // count unique addresses
        int count = 0;
        for (const auto &pair : inventory) {
            count += pair.second.size();
        }
        return count;
    }
};

int main() {
    std::vector<std::string> emails = { "test.email+alex@leetcode.com",
                                        "test.e.mail+bob.cathy@leetcode.com",
                                        "testemail+david@lee.tcode.com"};
    for (std::string email : emails) std::cout << email << std::endl;

    Solution solution;
    int output = solution.numUniqueEmails(emails);
    std::cout << "output:" << output << std::endl;

    return 0;
}