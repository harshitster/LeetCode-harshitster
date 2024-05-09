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
    ListNode* rotateRight(ListNode* head, int k) {
        int list_size = size(head);
        if(list_size == 0) return nullptr;

        k = k % list_size;
        if(k == 0) return head;
        k = list_size - k + 1;

        ListNode *curr = head, *prev = nullptr;
        int count = 1;
        while(curr && count < k) {
            count += 1;
            prev = curr;
            curr = curr -> next;
        }
        while(curr -> next) {
            curr = curr -> next;
        }

        curr -> next = head;
        head = prev -> next;
        prev -> next = nullptr;
        
        return head;
    }
};