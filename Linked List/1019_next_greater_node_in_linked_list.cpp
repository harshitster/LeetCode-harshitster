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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> out;
        int n = 0;
        ListNode* temp = head;

        while(temp) {
            out.push_back(temp -> val);
            n += 1;
            temp = temp -> next;
        }

        stack<int> s;
        for(int i = 0; i < n; i += 1) {
            while(!s.empty() && out[s.top()] < out[i]) {
                int idx = s.top();
                s.pop();
                out[idx] = out[i]; 
            }
            s.push(i);
        }

        while(!s.empty()) {
            int idx = s.top();
            s.pop();
            out[idx] = 0;
        }
        
        return out;
    }
};

// Revised - 01/16/2025