class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode *curr = head, *next = head -> next, *prev = nullptr;
        while(next) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
        }
        curr -> next = prev;
        head = curr;
         
        return head;
    }
};