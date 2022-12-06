// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
// Method that prints the bottom view.
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     bottomView(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
// Method that prints the bottom view.
void visit(Node *node, map<int,int>& bot_view, int hd);
void bottomView(Node *root)
{
    // THe goal: for each horizontal position, output the most bottom node
    // Initialize the map where an int value is stored for each horizontal distance index
    // Traverse the graph, preorder so that deeper nodes will overwrite the int values stored
    //      at each node, write data into the appropriate horizontal distance
    // Printout the map, from the least HD to largest HD


    // if root is not NULL
    if (root) {
        map<int,int> bot_view;
        visit(root, bot_view, 0);
        for (map<int,int>::const_iterator it = bot_view.begin(); \
            it != bot_view.end(); ++it ) {
            cout << it->second << " ";
        }
    } else {
        return;

    }
}

void visit(Node *node, map<int,int>& bot_view, int hd) {
    // write the data onto the map
    bot_view[hd] = node->data;

    // visit left with one less HD
    if (node->left) {
       visit(node->left, bot_view, hd - 1);
    }
    // visit right with one more HD
    if (node->right) {
        visit(node->right, bot_view, hd + 1);
    }
}
