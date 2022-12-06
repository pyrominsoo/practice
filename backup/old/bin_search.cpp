/*
https://leetcode.com/problems/binary-search/

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].
Accepted
72,228
Submissions
146,151
*/

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include <stdio.h>
#define debug(M,...) fprintf(stderr, "DEBUG: %s: %d: " M "\n", __FILE__,__LINE__,##__VA_ARGS__)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search_recur(nums, target, 0, nums.size());
    }
    int search_recur(vector<int>& nums, int target, int begin, int end) {
        // Check base case, nums.size() == 0 or 1
        int length = end - begin;
        if (length <= 0) {
            debug("Not found");
            return -1;
        } else {
            // Select middle element from nums, elem
            int middle = begin + length / 2; 
            // Compare elem against target
            int elem = nums[middle];
            debug("middle = %d", middle);
            debug("elem = %d", elem);

            // If matched, return index
            if (elem == target) {
                debug("[Found]");
                return middle;
            } else if (elem > target) {
            // if elem > target, search left
                debug("[Search Left]");
                return search_recur(nums, target, begin, middle);
            } else {
            // if elem < taret, search right
                debug("[Search Right]");
                return search_recur(nums, target, middle+1, end);
            }
        }
    }
};

int main(void) {
    ifstream inputfile;
    inputfile.open("input.txt");
    int array_size;
    while (inputfile >> array_size) {
        vector<int> nums;
        while (array_size--) {
            int new_val;
            inputfile >> new_val;
            cout << new_val << '\t';
            nums.push_back(new_val);
        }
        cout << endl;
        int target;
        inputfile >> target;
        cout << target << endl;
        Solution solution;
        cout << solution.search(nums, target) << endl;

    }

    return 0;
}
