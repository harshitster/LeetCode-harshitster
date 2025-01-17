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
    int length(ListNode* head) {
        int length = 0;
        while(head) {
            length += 1;
            head = head -> next;
        }
        return length;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(len == 0) return nullptr;

        n = len - n + 1;
        int i = 1;

        ListNode* temp = head, *prev = nullptr;
        while(temp && i != n) {
            i += 1;
            prev = temp;
            temp = temp -> next;
        }

        if(prev == nullptr) {
            head = temp -> next;
        } else {
            prev -> next = temp -> next;
        }

        return head;
    }
};

// Revised - 01/15/2025