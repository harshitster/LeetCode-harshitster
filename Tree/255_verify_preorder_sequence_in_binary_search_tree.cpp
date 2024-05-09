class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int min_num = INT_MIN;

        for(int num: preorder) {
            while(!s.empty() && s.top() < num) {
                min_num = s.top();
                s.pop();
            }

            if(min_num >= num) return false;

            s.push(num);
        }

        return true;
    }
};