class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        stack<ListNode*> s;
        for(ListNode* curr = head; curr; curr = curr -> next) {
            while(!s.empty() && s.top() -> val < curr -> val) {
                ListNode* temp = s.top();
                s.pop();
                temp -> val = -1;
            }
            s.push(curr);
        }

        ListNode* prev = nullptr;
        for(ListNode* curr = head; curr; curr = curr -> next) {
            if(curr -> val == -1) {
                if(prev == nullptr) head = curr -> next;
                else prev -> next = curr -> next;
            } else prev = curr;
        }

        return head;
        
    }
};

// Can be optimized