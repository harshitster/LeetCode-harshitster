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