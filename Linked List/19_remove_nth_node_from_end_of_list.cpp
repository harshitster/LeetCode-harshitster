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
    private:
        ListNode* helper(ListNode* head, int* n) {
            if(head == nullptr) return nullptr;
    
            head -> next = helper(head -> next, n);
            (*n) -= 1;
    
            if(*n == 0) return head -> next;
            return head;
        }
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            return helper(head, &n);
        }
    };

// Revised - 02/26/2025