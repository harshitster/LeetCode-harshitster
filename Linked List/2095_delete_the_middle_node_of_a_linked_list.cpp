class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = nullptr,* slow = head,* fast = head;
        
        while(fast != nullptr && fast -> next != nullptr) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if(prev) prev -> next = slow -> next;
        else head = slow -> next;
        return head;
    }
};