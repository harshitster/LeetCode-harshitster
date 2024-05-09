class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int left = 0, right = 0, counter = 0, max_len = INT_MIN;

        while(right < s.size()) {
            if(map[s[right]] == 0) counter += 1;
            map[s[right]] += 1;
            right += 1;

            while(counter > 2) {
                if(map[s[left]] == 1) counter -= 1;
                map[s[left]] -= 1;
                left += 1;
            }

            max_len = max(max_len, right - left);
        }

        return max_len;
    }
};