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
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
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
     leftView(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
 */
// A wrapper over leftViewUtil()
void traverse(queue< pair<Node*,int> >& node_queue, map<int,int>& leftview);
void leftView(Node *root)
{
    map<int,int> leftview;
    queue< pair<Node*,int> > node_queue;
    
    if (root) {
        node_queue.push( make_pair(root,0) ) ;
        traverse(node_queue, leftview);
        for (map<int,int>::const_iterator it = leftview.begin(); it != leftview.end(); it++) {
            cout << it->second << " ";
        }
    } 
}

void traverse(queue< pair<Node*,int> >& node_queue, map<int,int>& leftview) {
    while (!node_queue.empty()) {
        Node* curr_node = node_queue.front().first;
        int curr_vd = node_queue.front().second;
        node_queue.pop();
        leftview[curr_vd] = curr_node->data;
        if (curr_node->right) {
            node_queue.push( make_pair(curr_node->right, curr_vd+1) );
        }
        if (curr_node->left) {
            node_queue.push( make_pair(curr_node->left, curr_vd+1) );
        }
    }
}    



