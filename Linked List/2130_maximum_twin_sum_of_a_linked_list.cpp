/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        stack<ListNode*> s;

        while(fast && fast -> next) {
            s.push(slow);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        int max_sum = INT_MIN;

        while(!s.empty() && slow) {
            max_sum = max(max_sum, s.top() -> val + slow -> val);
            s.pop();
            slow = slow -> next;
        }

        return max_sum;
    }
};