// 1044. Longest Duplicate Substring
// Hard
//
// 99
//
// 81
//
// Favorite
//
// Share
// Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
//
// Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)
//
//  
//
// Example 1:
//
// Input: "banana"
// Output: "ana"
// Example 2:
//
// Input: "abcd"
// Output: ""
//  
//
// Note:
//
// 2 <= S.length <= 10^5
// S consists of lowercase English letters.
// Accepted
// 3,235
// Submissions
// 13,887

#include <string>
#include <iostream>


using namespace std;

#include <stdio.h>
#define debug(M,...) fprintf(stderr, "DEBUG: %s: %d: " M "\n", __FILE__, __LINE__,##__VA_ARGS__)

class Solution {
public:
    string longestDupSubstring(string S) {
        int size = S.length();
        bool table[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                table[i][j] = true;
            }
        }
        int num_true = size * size;
        int last_i = 0;
        int last_len = 0;

        for (int len = 1; len < size; len++) {
            debug("len = %d", len);
            for (int i = 0; i <= size - len; i++) {
                debug("i = %d", i);
                for (int j = i+1; j <= size - len; j++) {
                    debug("j = %d", j);
                    if (table[i][j]) {
                        string sub1 = S.substr(i,len);
                        string sub2 = S.substr(j,len);
                        if (sub1 != sub2) {
                            if (num_true == 1) {
                                debug("[Last false]");
                                return S.substr(last_i,last_len);
                            } else {
                                num_true--;
                                table[i][j] = false;
                            }
                        } else {
                            debug("[Match found]");
                            last_i = i;
                            last_len = len;
                        }
                    }
                }
            }
        }
        debug("[End reached]");
        return S.substr(last_i,last_len);
    }
};


int main(void) {
    string input;
    Solution solution;
    while (true) {
        cin >> input;
        cout << solution.longestDupSubstring(input) << endl;
    }
    return 0;
}
