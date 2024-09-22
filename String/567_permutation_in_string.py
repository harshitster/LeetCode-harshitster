class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_map = {}
        for c in s1:
            if c not in s1_map:
                s1_map[c] = 1
            else:
                s1_map[c] += 1
        
        left = 0
        s2_map = {}
        length = 0
        target = len(s1)

        for right in range(len(s2)):
            if s2[right] in s1_map:
                if s2[right] in s2_map:
                    while s2_map[s2[right]] == s1_map[s2[right]]:
                        s2_map[s2[left]] -= 1
                        left += 1
                        length -= 1
                    s2_map[s2[right]] += 1
                else:
                    s2_map[s2[right]] = 1
                length += 1
            else:
                length = 0
                s2_map = {}
                left = right + 1

            if length == target:
                return True

        return False