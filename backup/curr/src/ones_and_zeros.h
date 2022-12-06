/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

#include <utility>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
  
        vector<pair<int,int>> counts;
        int a;
        int b;
        int total_a = 0;
        int total_b = 0;
        // process substrings into integer numbers
        for (auto str : strs) {
            a = std::count(str.begin(),str.end(),'0');
            b = str.size() - a;
            total_a += a;
            total_b += b;
            counts.push_back({a,b});
        }

        // finding the best combination of these counts is more or less brute force, 
        // but recording the score of combinations would definitely save some computation.
        // I think it's clear that the possibilities should be traversed by the number of selections, as it provides a clear point
        // of stopping.
        // I think going from the min number towards max is better because the computations are simpler.

        unordered_map<vector<int>,pair<int,int>> dp;

        int num_sel;
        for (num_sel = 1; num_sel <= strs.size(); num_sel++) {
            if (findGoodSel(dp, counts, num_sel, m, n)) {
                break;
            }
        }
        return num_sel;

    }
        
    int findMax(vector<pair<int,int>> counts, int m, int n)
    bool findGoodSel(unordered_map
};
