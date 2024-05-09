class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* curr = head,* prev = nullptr;
        int flag = 0;
        for(ListNode* next = head -> next; next != nullptr; next = next -> next) {
            if(next -> val == curr -> val) {
                flag = 1;
                continue;
            } else {
                if(next == curr -> next){
                    prev = curr;
                    curr = curr -> next;
                }
                else {
                    if(prev == nullptr) head = next;
                    else prev -> next = next;
                    curr = next;
                }
                flag = 0;
            }
        }

        if(flag == 1) {
            if(prev == nullptr) return nullptr;
            else prev -> next = nullptr;
        }

        return head;
    }
};