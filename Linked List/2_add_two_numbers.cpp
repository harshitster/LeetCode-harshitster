class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;

        ListNode* curr1 = l1,* curr2 = l2,* prev = nullptr;
        int c = 0, sum, val;
        while(curr1 && curr2) {
            sum = curr1 -> val + curr2 -> val + c;
            val = sum % 10;
            c = sum / 10;

            curr1 -> val = val;

            prev = curr1;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }

        if(curr2) {
            prev -> next = curr2;
            curr1 = curr2;
        }

        while(c == 1) {
            if(curr1 == nullptr) {
                prev -> next = new ListNode(1);
                return l1;
            } 

            sum = curr1 -> val + c;
            val = sum % 10;
            c = sum / 10;

            curr1 -> val = val;

            prev = curr1;
            curr1 = curr1 -> next;
        }

        return l1;
    }
};