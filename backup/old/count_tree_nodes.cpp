
/*
222. Count Complete Tree Nodes
Medium

1224

154

Favorite

Share
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
Accepted
145,658
Submissions
393,084
*/



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
		if (root == NULL) {
			return 0;
		} else {
            return 1 + countNodes(root->left) + countNodes(root->right);
		}
    }
};



