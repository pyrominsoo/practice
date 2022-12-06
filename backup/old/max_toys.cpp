#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {

    // Receive the number of test cases
    int num_testcase;
    std::cin >> num_testcase;
    // For each test case,
    while (num_testcase--) {
        int N, K;
        // receive N and K
        std::cin >> N >> K;
        // Receive N values into a vector
        std::vector<int> toys;
        for (int i = 0; i < N; i++) {
            int input;
            std::cin >> input;
            toys.push_back(input);
        }
        // Sort the vector
        std::sort(toys.begin(),toys.end());

        // Count from the smallest element until the accumulated sum exceeds K
        std::vector<int>::const_iterator it;
        int sum = 0;
        int count = 0;
        for (it = toys.begin(); it != toys.end(); ++it) {
            sum += *it;
            if (sum > K) {
                break;
            }
            count++;
        }
        // Return the count of toys
        std::cout << count << std::endl;
    }

    return 0;
}
