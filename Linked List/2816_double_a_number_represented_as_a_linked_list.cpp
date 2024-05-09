class Solution {
private:
    ListNode* helper(ListNode* head, int* c) {
        if(head == nullptr) return nullptr;

        helper(head -> next, c);
        int val = head -> val * 2 + *c;
        head -> val = val % 10;
        *c = val / 10;

        return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if(head == nullptr) return nullptr;

        int c = 0;
        helper(head, &c);
        if(c == 1) head = new ListNode(1, head);

        return head;
    }
};