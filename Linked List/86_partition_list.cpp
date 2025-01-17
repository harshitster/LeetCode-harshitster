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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;

        ListNode* temp = head, *prev = nullptr;
        ListNode* head2 = nullptr, *temp2 = nullptr;

        while(temp) {
            if(temp -> val >= x) {
                if(head2 == nullptr) head2 = temp;
                else temp2 -> next = temp;
                temp2 = temp;

                if(prev == nullptr) {
                    head = temp -> next;
                    temp = head;
                } else {
                    prev -> next = temp -> next;
                    temp = prev -> next;
                }
                temp2 -> next = nullptr;
            } else {
                prev = temp;
                temp = temp -> next;
            }
        }

        if(prev == nullptr) head = head2;
        else prev -> next = head2;

        return head;
    }
};