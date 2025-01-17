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
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;

        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        stack<ListNode*> s;
        fast = slow -> next;
        slow -> next = nullptr;
        while(fast) {
            s.push(fast);
            fast = fast -> next;
        }

        slow = head;
        while(!s.empty()) {
            ListNode* node = s.top();
            s.pop();

            node -> next = slow -> next;
            slow -> next = node;
            slow = node -> next;
        }
    }
};

// Revised - 01/16/2025