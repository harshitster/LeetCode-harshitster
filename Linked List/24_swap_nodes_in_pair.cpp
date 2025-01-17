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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* temp1 = head, *temp2 = head -> next, *prev = nullptr;

        while(temp2) {
            temp1 -> next = temp2 -> next;
            temp2 -> next = temp1;
            if(prev) prev -> next = temp2;
            else head = temp2;

            prev = temp1;
            temp1 = temp1 -> next;
            if(temp1) temp2 = temp1 -> next;
            else temp2 = nullptr;
        }

        return head;
    }
};

// Revised - 01/15/2025