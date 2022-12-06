/*
3 Data structures
Easy Accuracy: 67.03% Submissions: 324 Points: 2

Given N operations. Each of type 1 or type 2 or type 3

Type 1: "1 x", insert number x in the priority queue (Greatest element on the top)
Type 2: "2 x", insert number x in the queue (First In First Out)
Type 3: "3 x", insert number x in the stack (First In Last Out)

The task is to print the elements in all three data structures from top to bottom. First print elements of the priority queue, then elements of the queue and then elements of the stack.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains a single integer N.
3. The next N lines contains any operation as mentioned above.


Output: For each test case, print the elements as mentioned above

Constraints:
1. 1 <= T <= 100
2. 1 <= N <= 104
3. 1 <= X <= 109

Example:
Input:
2
5
1 10
2 5
1 5
2 4
3 1
1
3 100

Output:
10 5 5 4 1
100
*/
