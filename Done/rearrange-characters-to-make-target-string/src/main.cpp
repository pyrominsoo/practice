#include <cstdint>
#include <iostream>
#include "solution.h"

int main(void) {
    int num_input;
    std::cin >> num_input;
    std::cin.ignore();

    Solution solution;
    while (num_input--) {
        std::string s, target;
        std::cin >> s;
        std::cin.ignore();
        std::cin >> target;
        std::cin.ignore();

        std::cout << solution.rearrangeCharacters(s,target) << std::endl;
    }
    return 0;
}
