class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_map = {}
        for c in p:
            if c not in p_map:
                p_map[c] = 1
            else:
                p_map[c] += 1
        
        s_map = {}
        left = 0
        length = 0
        target = len(p)
        res = []

        for right in range(len(s)):
            if s[right] in p_map:
                if s[right] in s_map:
                    while s_map[s[right]] == p_map[s[right]]:
                        s_map[s[left]] -= 1
                        left += 1
                        length -= 1
                    s_map[s[right]] += 1
                else:
                    s_map[s[right]] = 1
                length += 1
            else:
                left = right + 1
                s_map = {}
                length = 0

            if length == target:
                res.append(left)
                s_map[s[left]] -= 1
                if s_map[s[left]] == 0:
                    del s_map[s[left]]
                left += 1
                length -= 1

        return res