class Solution:
    def firstUniqChar(self, s: str) -> int:
        hashmap = {}
        for i in range(len(s)):
            hashmap[s[i]] = hashmap.get(s[i], 0) + 1

        for i in range(len(s)):
            if hashmap[s[i]] == 1:
                return i

        return -1