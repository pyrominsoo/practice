#include <cstdint>
#include <iostream>
#include "solution.h"

int main(void) {
    int num_input;
    std::cin >> num_input;
    std::cin.ignore();

    Solution solution;
    while (num_input--) {
        uint32_t n;
        std::cin >> n;
        std::cin.ignore();

        std::cout << solution.hammingWeight(n) << std::endl;
    }
    return 0;
}
