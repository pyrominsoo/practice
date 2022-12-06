#include <vector>
#include <iostream>
#include <fstream>
#include "InputHandler.h"

using namespace std;

vector<int>& InputHandler::acceptInt(int size) {
    while (size--) {
        int temp;    
        cin >> temp;
        input_vec.push_back(temp);
    }
    return input_vec;
}

vector<vector<int>>& InputHandler::formatGrid(int m, int n) {
    grid.resize(m);
    for (int j = 0; j < m; j++) {
        grid[j].resize(n);
        for (int i = 0; i < n; i++) {
            grid[j][i] = input_vec[j*n + i];
        }
    }
    return grid;
}

void InputHandler::printGrid(void) {
    for (auto it : grid) {
        for (auto j : it) {
            cout << j;
        }
        cout << endl;
    }
}

vector<int>& InputHandler::readFile(void) {
    ifstream inputfile("input.txt");
    char nextchar;
    int num;
    if (inputfile.is_open()) {
        while (inputfile.get(nextchar)) {
            if (isdigit(nextchar)) {
                num = nextchar - '0';
                input_vec.push_back(num);
            }
        }
    }
    else {
        cout << "Error: " << __FUNCTION__ << ": failed to open input.txt" << endl;
    }
   
    return input_vec;
}

vector<string>& InputHandler::acceptStrings(int size) {
    while (size--) {
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }
    return strs;
}

vector<string>& InputHandler::readStringsFromFile(void) {
    ifstream inputfile("input.txt");
    string line;
    if (inputfile.is_open()) {
        while (getline(inputfile,line)) {
            strs.push_back(line);
        }
    }
    else {
        cout << "Error: " << __FUNCTION__ << ": failed to open input.txt" << endl;
    }
   
    return strs;
}
