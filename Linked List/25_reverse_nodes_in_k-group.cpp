class Solution {
private:
    void reverse(ListNode** start, ListNode** end) {
        ListNode* curr = *start,* next = nullptr,* prev = (*end) -> next;
        
        while(curr != *end) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        curr -> next = prev;
        
        ListNode* temp = *start;
        *start = *end;
        *end = temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;

        ListNode* start = head,* end = head,* prev = nullptr;
        int count = 1;

        while(end) {
            if(count % k == 0) {
                reverse(&start, &end);
                if(count == k) head = start;
                else prev -> next = start;
                prev = end;
                start = end -> next;
            }

            count += 1;
            end = end -> next;
        }

        return head;
    }
};