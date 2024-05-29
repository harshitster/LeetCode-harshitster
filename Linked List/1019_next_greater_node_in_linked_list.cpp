class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        int n = 0;
        while(head) {
            n += 1;
            res.push_back(head -> val);
            head = head -> next;
        }

        stack<int> s;
        for(int i = 0; i < n; i += 1) {
            while(!s.empty() && res[s.top()] < res[i]) {
                int idx = s.top();
                s.pop();
                res[idx] = res[i];
            }
            s.push(i);
        }

        while(!s.empty()) {
            int idx = s.top();
            s.pop();
            res[idx] = 0;
        }

        return res;
    }
};