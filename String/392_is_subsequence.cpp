class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, s_xlen = s.size();
        for(int j = 0; j < t.size(); j += 1) {
            if(s[i] == t[j]) i += 1;
        }

        return i == s_len;
    }
};