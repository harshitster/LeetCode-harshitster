class Solution {
private:
    int listSize(ListNode* head) {
        int size = 0;
        while(head) {
            size += 1;
            head = head -> next;
        }

        return size;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head,* next = head -> next,* prev = nullptr;

        while(next) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
        }
        curr -> next = prev;
        head = curr;

        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        int size = listSize(head);
        if(size <= 1) return true;

        ListNode* slow = head,* fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = slow;
        if(size % 2 == 1) temp2 = temp2 -> next;

        temp2 = reverseList(temp2);

        while(temp1 != slow && temp2 && temp1 -> val == temp2 -> val) {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        if(temp1 == slow && temp2 == nullptr) return true;

        return false;
    }
};