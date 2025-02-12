class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hashmap = {}
        max_count, max_length = 0, 0

        left = 0
        for right in range(len(s)):
            hashmap[s[right]] = hashmap.get(s[right], 0) + 1
            max_count = max(max_count, hashmap[s[right]])

            if (right - left + 1) - max_count > k:
                hashmap[s[left]] -= 1
                left += 1
            else:
                max_length = max(max_length, right - left + 1)

        return max_length