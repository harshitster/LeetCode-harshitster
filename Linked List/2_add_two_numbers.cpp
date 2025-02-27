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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* temp1 = l1, *temp2 = l2;
            ListNode* prev = nullptr;
            int c = 0;
    
            while(temp1 && temp2) {
                int sum = temp1 -> val + temp2 -> val + c;
                int val = sum % 10;
                c = sum / 10;
    
                temp1 -> val = val;
                prev = temp1;
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
    
            if(temp2) {
                prev -> next = temp2;
                temp1 = temp2;
            } 
    
            while(temp1 && c) {
                int sum = temp1 -> val + c;
                int val = sum % 10;
                c = sum / 10;
                
                temp1 -> val = val;
                prev = temp1;
                temp1 = temp1 -> next;
            }
    
            if(c) prev -> next = new ListNode(1);
    
            return l1;
        }
    };

// revised - 02/26/2025