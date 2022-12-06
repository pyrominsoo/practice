#include<bits/stdc++.h>
#include<sstream>

using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
bool isIsomorphic(Node *root1,Node *root2);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int m=n;
        Node *root1=NULL;
        Node *root2=NULL;
        while(n-->0){
            int a1,a2;
            cin>>a1>>a2;
            char lr;
            scanf(" %c",&lr);
            if(root1==NULL){
                root1=newNode(a1);
                switch(lr){
                    case 'L':root1->left=newNode(a2);
                    break;
                    case 'R':root1->right=newNode(a2);
                    break;
                }
            }
            else{
                insert(root1,a1,a2,lr);
            }
        }
        while(m-->0){
            int a1,a2;
            cin>>a1>>a2;
            char lr;
            scanf(" %c",&lr);
            if(root2==NULL){
                root2=newNode(a1);
                switch(lr){
                    case 'L':root2->left=newNode(a2);
                    break;
                    case 'R':root2->right=newNode(a2);
                    break;
                }
            }
            else{
                insert(root2,a1,a2,lr);
            }
        }
        /*inorder(root1);
        cout<<endl;
        inorder(root2);*/
        if(isIsomorphic(root1,root2)){
            cout<<"Yes ";
        }
        else{
            cout<<"No ";
        }
    }
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
bool isIsomorphic(Node *root1,Node *root2)
{
	if (root1 == NULL) {
        if (root2 == NULL) {
            return true;
        } else {
            return false;
        }
    } else if (root2 == NULL) {
        return false;
    } else {
        stringstream buffer;
        queue<Node*> node_queue;

        // Traverse the trees, breadth-first, smaller child first
        node_queue.push(root1);
        while (!node_queue.empty()) {
            Node* node = node_queue.front();
            node_queue.pop();
            buffer << node->data << " ";
            if (node->left && node->right) {
                if (node->left->data > node->right->data) {
                    node_queue.push(node->right);
                    node_queue.push(node->left);
                } 
                node_queue.push(node->left);
                node_queue.push(node->right);
            } else if (node->left) {
                node_queue.push(node->left);
            } else if (node->right) {
                node_queue.push(node->right);
            } 
        }
        string string1 = buffer.str();
        buffer.str("");
        buffer.clear();

        node_queue.push(root2);
        while (!node_queue.empty()) {
            Node* node = node_queue.front();
            node_queue.pop();
            buffer << node->data << " ";
            if (node->left && node->right) {
                if (node->left->data > node->right->data) {
                    node_queue.push(node->right);
                    node_queue.push(node->left);
                } else {
                    node_queue.push(node->left);
                    node_queue.push(node->right);
                }
            } else if (node->left) {
                node_queue.push(node->left);
            } else if (node->right) {
                node_queue.push(node->right);
            } 
        }
        string string2 = buffer.str();

        if (string1 == string2) {
            return true;
        } else {
            return false;
        }
    }
}

