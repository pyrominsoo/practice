#ifndef CLASS_TREE_H
#define CLASS_TREE_H

#include "debug.h"
#include <iostream>

class TreeNode {
  public:

    TreeNode(int val = 0, TreeNode* next = nullptr) {
        this->val = val;
        this->next = next;
        dstr("TreeNode constructor");
        debug(this, this->val, this->next);
    }

    TreeNode(const TreeNode& obj) {
        this->val = obj.val;
        dstr("TreeNode copy constructor");
        debug(this, this->val, this->next);
    }

    TreeNode(TreeNode&& obj) : val{ obj.val } {
        next = nullptr;
        dstr("TreeNode move constructor");
        debug(this, this->val, this->next);
    }

    ~TreeNode() {
        dstr("TreeNode destructor");
        debug(this, this->val, this->next);
    }

  private:
    int val;
    TreeNode* next;
};



#endif // CLASS_TREE_H
