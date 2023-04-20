#ifndef PRACTICE_LIST_H
#define PRACTICE_LIST_H

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode* makeListFromVec(const std::vector<int>& vec) {
    if (vec.size() == 0) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    ListNode* currNode = head;

    for (int i = 1; i < vec.size(); ++i) {
        currNode->next = new ListNode(vec[i]);
        currNode = currNode->next;
    }
    return head;
}

inline void printList(ListNode* head) {
    std::cout << head->val;
    while (head->next != nullptr) {
        head = head->next;
        std::cout << ",";
        std::cout << head->val;
    }
    std::cout << std::endl;
}


#endif //PRACTICE_LIST_H
