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
            c = sum / 10;
            int val = sum % 10;

            temp1 -> val = val;

            prev = temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        ListNode* temp = nullptr;
        if(temp1 != nullptr || temp2 != nullptr){
            if(temp1 == nullptr) {
                prev -> next = temp2;
                temp = temp2;
            }
            else temp = temp1;
        }

        while(temp && c == 1) {
            int sum = temp -> val + c;
            c = sum / 10;
            int val = sum % 10;

            prev = temp;
            temp -> val = val;
            temp = temp -> next;
        }

        if(c == 1) prev -> next = new ListNode(1);

        return l1;
    }
};

// # Revised - 01/15/2025