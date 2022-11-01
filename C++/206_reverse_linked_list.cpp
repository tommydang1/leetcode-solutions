#include "header.hpp"

// Iterative
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *prev, *cur, *next;
        prev = NULL;
        cur = head;
        next = head;

        while (next->next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        next->next = prev;

        return next;
    }
};

// Recursive
// Time: O(n)
// Space: O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* rest = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};