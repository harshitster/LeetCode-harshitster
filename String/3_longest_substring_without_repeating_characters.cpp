class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int left = 0, length = 0, max_len = 0;

        for(int right = 0; right < s.size(); right += 1) {
            while(left < right && st.find(s[right]) != st.end()) {
                st.erase(s[left++]);
                length -= 1;
            }

            st.insert(s[right]);
            length += 1;
            max_len = max(max_len, length);
        }

        return max_len;
    }
};

// revised - 01/25/2025