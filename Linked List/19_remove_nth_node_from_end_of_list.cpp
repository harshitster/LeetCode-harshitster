class Solution {
private:
    int size(ListNode* head) {
        int s = 0;
        while(head) {
            s += 1;
            head = head -> next;
        }
        return s;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;

        int k = size(head) - n + 1;
        int count = 1;

        ListNode *curr = head, *prev = nullptr;
        while(curr && count < k) {
            prev = curr;
            curr = curr -> next;
            count += 1;
        }

        if(prev) {
            prev -> next = curr -> next;
        } else {
            head = curr -> next;
        }
        curr -> next = nullptr;
        return head;
    }
};