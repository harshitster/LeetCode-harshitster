class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            set<char> st;
            int left = 0, longest = 0;
    
            for(int right = 0; right < s.size(); right += 1) {
                while(st.find(s[right]) != st.end()) st.erase(s[left++]);
    
                st.insert(s[right]);
                longest = max(longest, right - left + 1);
            }
    
            return longest;
        }
    };

// revised - 02/26/2025