#include <vector>
#include <iostream>
#include <queue>

int main(void) {

    int num_testcase;

    std::cin >> num_testcase;

    while (num_testcase--) {
        int N, K;
        std::cin >> N >> K;
        std::vector<int> whole;
        std::priority_queue<int, std::vector<int>, std::greater<int> > within_k;


        for (int i = 0; i < N; i++) {
            int input;
            std::cin >> input;
            whole.push_back(input);
        }
        for (int i = 0; i < K; i++) {
            within_k.push(whole[i]);
        }
        for (int i = K; i < N; i++) {
            whole[i-K] = within_k.top();
            within_k.pop();
            within_k.push(whole[i]);
        }
        for (int i = N-K; i < N; i++) {
            whole[i] = within_k.top();
            within_k.pop();
        }

        for (int i = 0; i < N; i++) {
            std::cout << whole[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
