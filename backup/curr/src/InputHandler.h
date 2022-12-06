#include <vector>
#include <iostream>

using namespace std;


class InputHandler {
public:
    
    InputHandler() = default;

    vector<int>& acceptInt(int size);

    void printInputVec(void) {
        for (auto it : input_vec) {
            cout << it << endl;
        }
    }

    vector<int>& getInputVec(void) {
        return input_vec;
    }

    vector<vector<int>>& formatGrid(int m, int n);

    void printGrid(void);


    vector<vector<int>>& getGrid(void) {
        return grid;
    }

    vector<int>& readFile(void);

    vector<string>& acceptStrings(int size);
    
    vector<string>& readStringsFromFile(void);

    vector<string>& getStrs(void) {
        return strs;
    }
private:
    vector<int> input_vec;
    vector<vector<int>> grid;
    vector<string> strs;
};

