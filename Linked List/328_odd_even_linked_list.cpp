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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        
        ListNode* temp1 = head, *prev1 = nullptr;
        ListNode* temp2 = nullptr, *prev2 = nullptr;

        int even = 0;
        while(temp1) {
            if(even) {
                if(temp2 == nullptr) {
                    temp2 = temp1;
                    prev2 = temp2;
                } else {
                    prev2 -> next = temp1;
                    prev2 = prev2 -> next;
                }
                prev1 -> next = temp1 -> next;
                temp1 = prev1 -> next;
                prev2 -> next = nullptr;
            } else {
                prev1 = temp1;
                temp1 = temp1 -> next;
            }
            even = 1 - even;
        }

        prev1 -> next = temp2;
        return head;
    }
};

// revised - 01/28/2025