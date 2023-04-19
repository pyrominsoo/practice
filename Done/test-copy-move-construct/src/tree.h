#ifndef CLASS_TREE_H
#define CLASS_TREE_H

#include <iostream>

class TreeNode {
  public:

    TreeNode(int val = 0, TreeNode* next = nullptr) {
        this->val = val;
        this->next = next;
        std::cout << "Constructor called: " << this->val << " at " << this << "\n";
    }


    TreeNode(const TreeNode& obj) {
        this->val = obj.val;
        std::cout << "Copy constructor called:" << this->val << " at " << this << "\n";
    }

    TreeNode(TreeNode&& obj) : val{ obj.val } {
        next = nullptr;
        std::cout << "Move constructor called:" << val << "\n";
    }

    ~TreeNode() {
        std::cout << "Destructor called: " << val << " at " << this << "\n";
    }

  private:
    int val;
    TreeNode* next;
};



#endif // CLASS_TREE_H
