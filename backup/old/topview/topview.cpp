#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void topView(Node *root);
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
     topView(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Structure of binary tree
/*struct Node
struct Node
{
    int data, hd;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void traverse(queue< pair<Node*,int> >& node_queue, map<int,int>& top_view);


// The goal: for each horizontal position, output the top node
// Initialize the map where an int value is stored for each horizontal distance index
// Traverse the graph, breath-first so that the higher nodes will write first and the values will not be overwritten.
//		at each node, check if the horizontal distance has a value, if not write data
// Printout the map inorder
void topView(Node *root)
{
	if (root) {
        map<int, int> top_view;
        queue< pair<Node*,int> > node_queue; // first: node pointer, second: hd
        pair<Node*,int> curr_node;
        curr_node.first = root;
        curr_node.second = 0;
        node_queue.push(curr_node);
        traverse(node_queue, top_view);
	}
    else {
        return;
    }
}

void traverse(queue< pair<Node*,int> >& node_queue, map<int,int>& top_view) {
    while (!node_queue.empty()) {
        Node* curr_node = node_queue.front().first;
        int curr_hd = node_queue.front().second;
        node_queue.pop();

        if (top_view.find(curr_hd) == top_view.end()) {
            top_view[curr_hd] = curr_node->data; 
            cout << curr_node-> data << " ";
        }

        // visit left with one less HD
        if (curr_node->left) {
           pair<Node*, int> new_visit;
           new_visit.first = curr_node->left;
           new_visit.second = curr_hd - 1;
           node_queue.push(new_visit);
        }
        // visit right with one more HD
        if (curr_node->right) {
           pair<Node*, int> new_visit;
           new_visit.first = curr_node->right;
           new_visit.second = curr_hd + 1;
           node_queue.push(new_visit);
        }
    }
}


