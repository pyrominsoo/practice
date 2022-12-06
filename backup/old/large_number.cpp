#include <iostream>

int main(void) {

    // Corner case: When S == 0, impossible unless N == 1
    // When S >= 1, always possible

    // for making the largest number, MSBs should be as large as possible.
    // Because there is zero, there is no need to consider smaller digits when assining a digit

    // Take care of corner case
    // Initialize S
    // Iterate over N digits, from left to right
        // Assign the largest digit that does not go over the remaining S
        // Subtract the digit from S
    // Print the number


    int num_testcase;
    std::cin >> num_testcase;
    while (num_testcase--) {
        int N, S;
        std::cin >> N >> S;
        
        if (S == 0) {
            if (N == 1) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        } else if (S > (9 * N) ) {
            std::cout << -1 << std::endl;
        } else {
            for (int i = 0; i < N; i++) {
                int digit;
                if (S >= 9) {
                    digit = 9;    
                } else {
                    digit = S;
                }
                S -= digit;
                std::cout << digit;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
