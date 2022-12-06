

/*

https://leetcode.com/problems/valid-parentheses/


20. Valid Parentheses
Easy

3382

158

Favorite

Share
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
Accepted
703,577
Submissions
1,886,761
*/
#include <stack>
#include <string>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        map<char,char> table;
        table.insert( pair<char,char>(']','[') );
        table.insert( pair<char,char>('}','{') );
        table.insert( pair<char,char>(')','(') );
        stack<char> stack;
        for (auto it = s.begin(); it != s.end(); it++) {
            char next_char = (*it);
            if (next_char == ']' or next_char == '}' or next_char == ')') {
                if (stack.empty()) {
                    return false;
                }
                else if (table[next_char] == stack.top()) {
                    stack.pop();
                } 
                else {
                    return false;
                }
            } else {
                stack.push(next_char);
            }
        }
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }

    }
};

int main(void) {
    string s;
    Solution solution;
    while (true) {
        cin >> s;
        cout << solution.isValid(s) << endl;
    }
    return 0;
};
