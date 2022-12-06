
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
int getLevelDiff(Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d ", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d ",&n);
     struct Node *root = NULL;
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
   cout<<getLevelDiff(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
	queue < pair<Node*, int> > node_queue;
	int even_sum = 0;
	int odd_sum = 0;
	if (root) {
		node_queue.push( make_pair(root, 1) );
		while (!node_queue.empty()) {
            Node* curr_node = node_queue.front().first;
            int curr_depth = node_queue.front().second;
            node_queue.pop();
            
            if (curr_depth % 2 == 0) {
                even_sum += curr_node->data;
            } else {
                odd_sum += curr_node->data;
            }
            
            if (curr_node->left) {
                node_queue.push( make_pair(curr_node->left, curr_depth+1) );
            }
            if (curr_node->right) {
                node_queue.push( make_pair(curr_node->right, curr_depth+1) );
            }
		}
        return odd_sum - even_sum;
	} else {
		return 0;
	}
}

