class Solution {
private:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* curr = start,* prev = end -> next,* next = nullptr;

        while(curr != end) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        curr -> next = prev;
        return curr;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == nullptr) return head;
        
        ListNode* prev = nullptr,* start = head,* end = nullptr;
        int count = 1;

        while(count < left) {
            prev = start;
            start = start -> next;
            count += 1;
        }
        end = start;
        while(count < right) {
            end = end -> next;
            count += 1;
        }

        start = reverse(start, end);
        if(prev == nullptr) head = start;
        else prev -> next = start;

        return head;
    }
};