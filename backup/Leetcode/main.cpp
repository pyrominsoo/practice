#include <vector>
#include <iostream>

using namespace std;

class Solution;

class InputHandler {
public:
    
    InputHandler() = default;

    vector<int>& acceptInt(int size) {
        while (size--) {
            int temp;    
            cin >> temp;
            input_vec.push_back(temp);
        }
        return input_vec;
    }

    void printInputVec(void) {
        for (auto it : input_vec) {
            cout << it << endl;
        }
    }

    vector<vector<int>>& formatGrid(int m, int n) {
        grid.resize(m);
        for (int j = 0; j < m; j++) {
            grid[j].resize(n);
            for (int i = 0; i < n; i++) {
                grid[j][i] = input_vec[j*n + i];
            }
        }
        return grid;
    }

    void printGrid(void) {
        for (auto it : grid) {
            for (auto j : it) {
                cout << j << endl;
            }
        }
    }

private:
    vector<int> input_vec;
    vector<vector<int>> grid;
};

int main(void) {
    InputHandler handler;
    handler.acceptInt(4);
    handler.printInputVec();
    handler.formatGrid(2,2);
    handler.printGrid();
    return 0;
}
