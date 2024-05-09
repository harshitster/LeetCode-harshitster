class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode *curr = head -> next, *prev = head;
        int val = prev -> val;

        while(curr) {
            while(curr && curr -> val == val) {
                prev -> next = curr -> next;
                curr -> next = nullptr;
                curr = prev -> next;
            }

            if(curr) {
                val = curr -> val;
                prev = curr;
                curr = curr -> next;
            }
        }

        return head;
    }
};