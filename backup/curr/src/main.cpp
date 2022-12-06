#include <vector>
#include <iostream>

#include "ones_and_zeros.h"
#include "InputHandler.h"

using namespace std;


int main(void) {
    InputHandler handler;
    handler.readStringsFromFile();
  
    Solution solution;
    int answer;
    answer = solution.findMaxForm(handler.getStrs(),6,6);
    cout << answer << endl;
        
    return 0;
}
