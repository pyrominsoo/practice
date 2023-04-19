#ifndef CLASS_TREE_H
#define CLASS_TREE_H

#include "debug.h"
#include <iostream>
#include <queue>

class TreeNode {
  public:

    TreeNode(int val = 0, TreeNode* next = nullptr) {
        this->val = val;
        this->next = next;
        debug("TreeNode constructor", this, this->val, this->next);
    }

    TreeNode(const TreeNode& obj) {
        this->val = obj.val;
        debug("TreeNode copy constructor", this, this->val, this->next);
    }

    TreeNode(TreeNode&& obj) : val{ obj.val } {
        next = nullptr;
        debug("TreeNode move constructor", this, this->val, this->next);
    }

    ~TreeNode() {
        debug("TreeNode destructor", this, this->val, this->next);
    }

  private:
    int val;
    TreeNode* next;
};

class Tree {
  public:
    Tree(TreeNode* head = nullptr) {
        this->head = head;
    }

    Tree(const Tree& obj) {
        TreeNode* newHead = copyTree(obj);
        this->head = newHead;
    }

    Tree(Tree&& obj) : head{obj.head} {

    }

    ~Tree() {

    }

    TreeNode* copyTree(const Tree& src) {
        return nullptr;
    }

  private:
    TreeNode* head;
};




#endif // CLASS_TREE_H
