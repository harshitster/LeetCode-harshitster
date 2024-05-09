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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int listA_size = size(headA), listB_size = size(headB);
        int diff = abs(listA_size - listB_size);
        ListNode *temp = nullptr, *other = nullptr;

        if(listA_size >= listB_size) {
            temp = headA;
            other = headB;
        } else {
            temp = headB;
            other = headA;
        }

        while(diff > 0) {
            temp = temp -> next;
            diff -= 1;
        }

        while(temp && other) {
            if(temp == other) return temp;
            temp = temp -> next;
            other = other -> next;
        }

        return nullptr;
    }
};