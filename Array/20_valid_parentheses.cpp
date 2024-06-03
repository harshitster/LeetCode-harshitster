class Solution {
private:
    unordered_map<char, char> map;
public:
    bool isValid(string s) {
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';
        stack<char> st;

        for(char c: s) {
            if(map.find(c) != map.end()) {
                if(st.empty()) return false;

                char top = st.top();
                st.pop();
                if(top != map[c]) return false; 
            } else st.push(c);
        }

        return st.empty();
    }
};