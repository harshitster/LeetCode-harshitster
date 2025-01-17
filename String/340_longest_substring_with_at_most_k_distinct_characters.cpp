class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int left = 0, max_length = 0;

        for(int right = 0; right < s.size(); right += 1) {
            if(map.find(s[right]) == map.end()) {
                map[s[right]] = 1;
                k -= 1;   
            }
            else map[s[right]] += 1;

            while(k < 0) {
                map[s[left]] -= 1;
                if(map[s[left]] == 0) {
                    map.erase(s[left]);
                    k += 1;
                }
                left += 1;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    } 
};