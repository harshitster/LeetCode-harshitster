class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* odd_dummy = new ListNode(-1, head);
        ListNode* even_dummy = new ListNode(-1, head -> next);

        ListNode* odd = odd_dummy -> next,* even = even_dummy -> next;
        ListNode* odd_prev = nullptr,* even_prev = nullptr;
        int flag = 1;

        while(odd && even) {
            if(flag == 1) {
                odd -> next = even -> next;
                odd_prev = odd;
                odd = odd -> next;
                flag = 0;
            } else {
                even -> next = odd -> next;
                even_prev = even;
                even = even -> next;
                flag = 1;
            }
        }

        if(odd_prev) while(odd_prev -> next) odd_prev = odd_prev -> next;
        if(even_prev) {
            while(even_prev -> next) even_prev = even_prev -> next;
            even_prev -> next = nullptr;
        }

        head = odd_dummy -> next;
        odd_prev -> next = even_dummy -> next;

        return head;
    }
};