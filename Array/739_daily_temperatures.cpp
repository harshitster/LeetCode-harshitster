class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> res(n);

        for(int i = 0; i < n; i += 1) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int index = s.top();
                s.pop();

                res[index] = (i - index);
            }
            s.push(i);
        }

        return res;
    }
};
