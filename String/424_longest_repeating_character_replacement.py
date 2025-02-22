class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hashmap = {}
        max_len, max_count = 0, 0
        left = 0

        for right in range(len(s)):
            hashmap[s[right]] = hashmap.get(s[right], 0) + 1
            max_count = max(max_count, hashmap[s[right]])

            if (right - left + 1) - max_count > k:
                hashmap[s[left]] -= 1
                left += 1
            else:
                max_len = max(max_len, right - left + 1)

        return max_len
    
# revised - 02/21/2025