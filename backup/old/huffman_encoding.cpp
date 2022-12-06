

#ifdef NDEBUG
#define debug(M,...)
#else
#include <stdio.h>
#define debug(M,...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
        __FILE__,__LINE__, ##__VA_ARGS__)
#endif

#include <iostream>
#include <queue>


struct HuffmanNode {
    char data;  // 0 represents internal nodes
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
};

class CompareNode {
    public:
        bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
            return lhs->freq > rhs->freq;
        }
};


class HuffmanTree {
    public:
        HuffmanTree(void);
        ~HuffmanTree(void);
        void recursive_del(HuffmanNode* node);
        void insert(char data, int freq);
        void build(void);
        void traverse(void);
    private:
        std::priority_queue< HuffmanNode*, std::vector<HuffmanNode*>, CompareNode > nodes;
        HuffmanNode* root;
};

HuffmanTree::HuffmanTree(void) {
    root = NULL;
}

HuffmanTree::~HuffmanTree(void) {
    if (root) {
        recursive_del(root);
    } else {
        while (!nodes.empty()) {
            delete nodes.top();
            nodes.pop();
        }
    }
}


void HuffmanTree::recursive_del(HuffmanNode* node) {
    if (node) {
        recursive_del(node->left);
        recursive_del(node->right);
        delete node;
    }
}

void HuffmanTree::insert(char data, int freq) {
    HuffmanNode* new_node = new HuffmanNode;
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    nodes.push(new_node);
}

void HuffmanTree::build(void) {
    if (root) {
        debug("Warning: root already present. Will overwrite.");
    }

    while (nodes.size() >= 2) {
        HuffmanNode* first = nodes.top();
        nodes.pop();
        HuffmanNode* second = nodes.top();
        nodes.pop();
        HuffmanNode* new_node = new HuffmanNode;
        new_node->data = 0;
        new_node->freq = first->freq + second->freq;
        new_node->left = first;  
        new_node->right = second;
        nodes.push(new_node); 
    }

    root = nodes.top();
    nodes.pop();
}

void visit_node(HuffmanNode* node, std::string code) {
    if (node) {
        if (node->left == NULL && node->right == NULL) {
            // leaf node
            std::cout << node->data << " " << code << std::endl;
        } else {
            // internal nodes always have two children
            visit_node(node->left, code + "0");
            visit_node(node->right, code + "1");
        }
    }
}


void HuffmanTree::traverse(void) {
    visit_node(root, "");
}



int main(void) {
    int num_case;
    std::cin >> num_case;
    while (num_case--) {
        std::string input_string;
        std::cin >> input_string;
        int input_size = input_string.size();
        int freq[input_size];
        for (int i = 0; i < input_size; i++) {
            std::cin >> freq[i]; 
        }

        HuffmanTree tree;
        for (int i = 0; i < input_size; i++) {
            tree.insert(input_string[i],freq[i]);    
        }
        tree.build();
        tree.traverse();
    };
    return 0;
}
