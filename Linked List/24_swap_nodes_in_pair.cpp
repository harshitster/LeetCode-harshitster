class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* curr = head,* next = head -> next,* prev = nullptr;
        while(curr && next) {
            curr -> next = next -> next;
            next -> next = curr;
            if(prev == nullptr) head = next;
            else prev -> next = next;

            prev = curr;
            curr = curr -> next;
            if(curr) next = curr -> next;
        }

        return head;
    }
};