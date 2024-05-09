class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;

        ListNode *slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) break;
        }
        
        if(fast == nullptr || fast -> next == nullptr) return nullptr;

        while(true) {
            if(slow == head) break;
            slow = slow -> next;
            head = head -> next;
        }

        return head;
    }
};