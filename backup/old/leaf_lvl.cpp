
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
bool check(Node* node);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << check(root) << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*You are required to complete this method*/
struct LevelCheck {
    bool valid;
    int level;
    LevelCheck(bool val, int lvl) {
        valid = val;
        level = lvl; 
    }
};
bool check(Node *root)
{
    //Your code here
    if (root) {
        LevelCheck level(false,0);
        stack< pair<Node*,int> > node_stack;
        node_stack.push( make_pair(root, 0) );
        while (!node_stack.empty()) {
            Node* curr_node = node_stack.top().first;
            int curr_depth = node_stack.top().second;
            node_stack.pop();
            if (curr_node->left == NULL && curr_node->right == NULL) {
                // leaf node
                if (level.valid) {
                    if (level.level != curr_depth) {
                        return false;
                    } 
                } else {
                    level.valid = true;
                    level.level = curr_depth;
                }
            } 
            if (curr_node->left) {
                node_stack.push( make_pair(curr_node->left, curr_depth+1) );
            } 
            if (curr_node->right) {
                node_stack.push( make_pair(curr_node->right, curr_depth+1) );
            }
        }
        return true;
    } else {
        return true;
    }
}

