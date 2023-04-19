/*
https://leetcode.com/problems/excel-sheet-column-number/

171. Excel Sheet Column Number
Easy
4.1K
327
Companies
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701


Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
Accepted
589K
Submissions
949.3K
Acceptance Rate
62.0%
*/

#include <string>
#include <math.h>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int answer = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            answer *= 26;
            answer += columnTitle[i] - 'A' + 1;
        }
        return answer;
    }
};
