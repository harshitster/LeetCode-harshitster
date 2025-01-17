class Solution {
private:
    ListNode* helper(ListNode* head, int* c) {
        if(head == nullptr) return nullptr;

        helper(head -> next, c);
        int val = head -> val + *c;
        head -> val = val % 10;
        *c = val / 10;

        return head;
    }
public:
    ListNode* plusOne(ListNode* head) {
        if(head == nullptr) return nullptr;

        int c = 1;
        helper(head, &c);
        if(c == 1) head = new ListNode(1, head);

        return head;
    }
};

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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp = head;
        while(temp) {
            s.push(temp);
            temp = temp -> next;
        }

        int c = 1;
        while(!s.empty() && c == 1) {
            temp = s.top();
            s.pop();

            int val = temp -> val + c;
            temp -> val = val % 10;
            c = val / 10;
        }

        if(c == 1) {
            temp = new ListNode(1, head);
            head = temp;
        }
        return head;
    }
};

// Revised - 01/16/2025