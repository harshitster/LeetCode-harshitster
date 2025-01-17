/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* prev = nullptr, *curr = head, *next = curr -> next;
        while(curr -> next) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
        }
        curr -> next = prev;
        head = curr;

        return head;
    }
};

// Revised - 01/16/2025