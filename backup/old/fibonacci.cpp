
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        else return dp(N);
    }
    int dp(int N) {
        vector<int> table(N+1,0);
        table[0] = 0;
        table[1] = 1;
        for (int i = 2; i <= N; i++) {
            table[i] = table[i-1] + table[i-2];

        }
        return table[N];
    }
};

int main(void) {
    ifstream inputfile;
    inputfile.open("input.txt");
    int N;
    Solution solution;
    while (inputfile >> N) {
        cout << solution.fib(N) << endl;
    }
}
