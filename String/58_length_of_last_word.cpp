class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char> st;
        int i = 0, n = s.size();

        while(i < n) {
            if(s[i] != ' ') {
                while(!st.empty()) st.pop();
                while(i < n && s[i] != ' ') 
                    st.push(s[i++]);
            } else i += 1;
        }

        return st.size();
    }
};