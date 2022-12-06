/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

#include <stdio.h>
#define debug(M,...) fprintf(stderr, "DEBUG: %s: %d: " M "\n", __FILE__,__LINE__, ##__VA_ARGS__)


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // TODO : nums1 or nums2 could be empty
		// Find the number of elements in the left half of merged array
		unsigned int m = nums1.size();
		unsigned int n = nums2.size();
        unsigned int total = m + n;
        bool even = (total % 2 == 0);
		unsigned int num_left = (total + 1) / 2;    // include the median itself

        debug("m = %d", m);
        debug("n = %d", n);
        debug("total = %d", total);
        debug("even = %d", even);
        debug("num_left = %d", num_left);


		// Binary search of number of elements contributed by nums1, A
		// start by assuming A == B where B is the number of elements contributed by B
        unsigned int idx_nums1 = num_left / 2;
        unsigned int idx_nums2 = num_left - idx_nums1;
        if (idx_nums1 > m) {
            idx_nums1 = m;
            idx_nums2 = num_left - idx_nums1;
        };
        if (idx_nums2 > n) {
            idx_nums2 = n;
            idx_nums1 = num_left - idx_nums2;
        }
        debug("idx_nums1 = %d", idx_nums1);
        debug("idx_nums2 = %d", idx_nums2);

        unsigned int step = idx_nums1 / 2;
        if (step == 0) step++;
        while (true) {
            if (idx_nums1 == 0 || idx_nums2 == 0) {
                debug("[Reached 0]");
                vector<int>* target1;
                vector<int>* target2;
                int ans;
                int ans_nxt;
                bool nums1_target = (idx_nums1 == 0)? false : true;
                unsigned int target1_size = (nums1_target)? m : n;
                if (nums1_target) {
                    target1 = &nums1;
                    target2 = &nums2;
                } else {
                    target1 = &nums2;
                    target2 = &nums1;
                }
                if ((*target2).size() == 0) {
                    ans = (*target1)[num_left-1];
                    ans_nxt = even? (*target1)[num_left] : 0;
                } else if (num_left < target1_size) {
                    ans = (*target1)[num_left-1];
                    ans_nxt = even? min((*target1)[num_left],(*target2)[0]) : 0;
                } else if (num_left == target1_size) {
                    ans = (*target1)[num_left-1];
                    ans_nxt = even? (*target2)[0] : 0;
                } else {
                    ans = (*target2)[num_left-target1_size-1];
                    ans_nxt = even? (*target2)[num_left-target1_size] : 0;
                }
                if (even) {
                    debug("returning ans = %d, %d", ans, ans_nxt);
                    return (double)(ans + ans_nxt)/2.0;
                } else {
                    debug("returning ans = %d", ans);
                    return (double)ans;
                }
            } 
            int x = nums1[idx_nums1-1];
            int y = nums2[idx_nums2-1];
            // TODO what happens if x or y are the last elements?
            int x_nxt = (idx_nums1 >= m)? numeric_limits<int>::max() : nums1[idx_nums1];
            int y_nxt = (idx_nums2 >= n)? numeric_limits<int>::max() : nums2[idx_nums2];

            debug("x = %d", x); 
            debug("y = %d", y); 
            debug("x_nxt = %d", x_nxt); 
            debug("y_nxt = %d", y_nxt); 

            // compare them
            if (x == y) {
            // if they are the same, the assumption is correct
                debug("[Same]");
                // if total number of elem is even, then the median is (x + min(x',y'))/2
                // else (odd), then the median is x
                if (even) {
                    return (double)(x + min(x_nxt,y_nxt))/2.0;    
                } else {
                    return (double)x;    
                }
            } else {
                // let bigger value be f and smaller value g
                int f;
                int g_nxt;
                bool x_lt_y;
                if (x > y) {
                    debug("x > y");
                    f = x;
                    g_nxt = y_nxt;
                    x_lt_y = false;

                } else {
                    debug("x <= y");
                    f = y;
                    g_nxt = x_nxt;
                    x_lt_y = true;
                }
                if (f > g_nxt) {
                    debug("[Assumption incorrect]");
                // if f > g', the assumtion is incorrect, set next A and repeat
                    if (step == 0) step++;
                    if (x_lt_y) {
                    // if f == y, then we need to include more from nums1, A increases by binary search
                        idx_nums1 = idx_nums1 + step;
                    } else {
                    // if f == x, then we need to include more from nums2. A decreases by binary search
                        idx_nums1 = idx_nums1 - step;
                    }
                    step = step / 2;
                    idx_nums2 = num_left - idx_nums1;
                    if (idx_nums1 > m) {
                        idx_nums1 = m;
                        idx_nums2 = num_left - idx_nums1;
                    };
                    if (idx_nums2 > n) {
                        idx_nums2 = n;
                        idx_nums1 = num_left - idx_nums2;
                    }
                    debug("idx_nums1 = %d", idx_nums1);
                    debug("idx_nums2 = %d", idx_nums2);
                } else {
                    debug("[Assumption correct]");
                // if f <= g', the assumption is correct
                    // if total number of elem is even, then the median is (f + min(f',g'))/2
                    // else (odd), then the median is f
                    if (even) {
                        return (double)(f + min(x_nxt,y_nxt))/2.0;    
                    } else {
                        return (double)f;
                    }
                }
            }
        }
    }
}; 


int main(void) {
    ifstream inputfile;
    inputfile.open("input.txt");
    int num_case;
    inputfile >> num_case;
    while (num_case--) {
        int num_a, num_b;
        inputfile >> num_a;
        inputfile >> num_b;

        vector<int> nums1;
        vector<int> nums2;
        while (num_a--) {
            int new_val;
            inputfile >> new_val;
            cout << new_val << '\t';
            nums1.push_back(new_val);
        }
        cout << endl;
        while (num_b--) {
            int new_val;
            inputfile >> new_val;
            cout << new_val << '\t';
            nums2.push_back(new_val);
        }
        cout << endl;
        Solution solution;
        cout << solution.findMedianSortedArrays(nums1,nums2) << endl;
        cout << endl << endl;
    }
    return 0;
};
