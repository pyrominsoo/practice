/*
404. Sum of Left Leaves
Easy

755

84

Favorite

Share
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Accepted
139,884
Submissions
281,578
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return sumLeft(root->left,true) + sumLeft(root->right,false);
        }
    }
    int sumLeft(TreeNode* root, bool leftchild) {
        if (root == NULL) {
            return 0;
        } else if (!root->left && !root->right) {
            return (leftchild)? root->val : 0;
        } else {
            return sumLeft(root->left, true) + sumLeft(root->right,false);
        }
    }
};
