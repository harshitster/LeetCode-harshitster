class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            set<char> st;
            int left = 0, length = 0, longest = 0;
    
            for(int right = 0; right < s.size(); right += 1) {
                while(st.find(s[right]) != st.end()) {
                    st.erase(s[left++]);
                    length -= 1;
                }
    
                st.insert(s[right]);
                length += 1;
                longest = max(longest, length);
            }
    
            return longest;
        }
    };

// revised - 02/18/2025