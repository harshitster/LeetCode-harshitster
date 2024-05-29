class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr,* curr = head;

        while(curr) {
            if(curr -> val == val) {
                if(prev == nullptr) head = curr -> next;
                else prev -> next = curr -> next;
                
                curr -> next = nullptr;
                delete curr;

                if(prev == nullptr) curr = head;
                else curr = prev -> next;
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }

        return head;
    }
};