class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head,* fast = head;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
};

// Revised - 01/16/2025