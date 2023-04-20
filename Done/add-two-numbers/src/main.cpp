
#include <iostream>
#include <sstream>

#include "list.h"
#include "solution.h"
#include <vector>

std::vector<int> parseIntVec(std::string str) {
    std::vector<int> result;
    std::istringstream ss(str);
    std::string token;

    while (std::getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }

    return result;
}

int main(void) {
    int num_input;
    std::cin >> num_input;
    std::cin.ignore();

    Solution solution;
    while (num_input--) {
        std::string str;
        std::cin >> str;
        std::cin.ignore();
        ListNode* l1 = makeListFromVec(parseIntVec(str));
        std::cin >> str;
        std::cin.ignore();
        ListNode* l2 = makeListFromVec(parseIntVec(str));

        ListNode* answer = solution.addTwoNumbers(l1,l2);

        printList(answer);
    }
    return 0;
}
