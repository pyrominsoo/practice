#include <iostream>
#include "solution.h"

int main(void) {
    int num_input;
    std::cin >> num_input;
    std::cin.ignore();

    Solution solution;
    while (num_input--) {
        std::string columnTitle;
        std::cin >> columnTitle;
        std::cin.ignore();

        std::cout << solution.titleToNumber(columnTitle) << std::endl;
    }
    return 0;
}
