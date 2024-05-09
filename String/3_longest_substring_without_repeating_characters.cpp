class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128, 0);
        int left = 0, max_len = 0, counter = 0;

        for(int right = 0; right < s.size(); right += 1) {
            if(map[s[right]] > 0) counter += 1;
            map[s[right]] = map[s[right]] + 1;

            while(counter > 0) {
                if(map[s[left]] > 1) {
                    counter -= 1;
                }
                map[s[left]] = map[s[left]] - 1;
                left += 1;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
