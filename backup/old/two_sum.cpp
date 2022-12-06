
// https://leetcode.com/problems/two-sum/
//
// 1. Two Sum
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
// Accepted
// 2,146,024
// Submissions
// 4,817,533

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <stdio.h>
#define debug(M,...) fprintf(stderr, "DEBUG: %s: %d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		// insert all numbers into hashtable
		map<int,int> hashtable;
		for (unsigned int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int comp = target - val;
            auto it = hashtable.find(comp);
            if (it != hashtable.end()) {
                vector<int> answer;
                answer.push_back(it->second);
                answer.push_back(i);
                return answer;
            }
            hashtable.insert( pair<int,int>(nums[i],i) );
		}
        debug("Not Found");
        throw;
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
        vector<int> answer = solution.twoSum(nums, target);
        for (auto it = answer.begin(); it != answer.end(); it++) {
            cout << *it << '\t';
        }
        cout << endl;
    }
}
