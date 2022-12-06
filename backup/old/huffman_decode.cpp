
#ifndef DEBUG
#define debug(M,...)
#else
#include <stdio.h>
#define debug(M,...) fprintf(stderr, "DEBUG: %s:%d: " M "\n",\
        __FILE__,__LINE__, ##__VA_ARGS__)
#endif


#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;
map<char, string> codes;
map<char, int> freq;
struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << " ";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}
void calcFreq(string str, int n)
{
	for (int i=0; i<(int)str.size(); i++)
		freq[str[i]]++;
}
// complete this function
string decodeHuffmanData(struct MinHeapNode* root, string binaryString);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        string encodedString, decodedString;
        calcFreq(str, str.length());
        HuffmanCodes(str.length());
        for (auto i: str)encodedString+=codes[i];
        //cout<<encodedString<<endl;
        decodedString = decodeHuffmanData(minHeap.top(), encodedString);
        cout << decodedString << endl;
    }
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of Huffman tree is as
struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
};
*/
// task is to complete this function
// function should return decoded string from 
// the given bianry encoded string
string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
	// init answer
	string ans = "";
	// Set the current node as root
	struct MinHeapNode* current = root;
	// Iterate over the string
	for (const char& c: binaryString) {
	    //	(As a starting point, root is guaranteed to be an internal node, if not, there's no point in encoding)
	    // 	If char == 0, follow left
        if (c == '0') current = current->left;
	    //	if char == 1, follow right
        else if (c == '1') current = current->right;
        else cout << "character other than 0 or 1: " << c << endl;
        if (current->left == NULL && current->right == NULL) {
	    //	if current node is a leaf
	    //		append the node's data to answer
	    //		reset current node to root
            ans += current->data;
            current = root;
        }
	}
    return ans;
}
