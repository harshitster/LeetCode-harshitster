class Solution:
    def longestPalindrome(self, s: str) -> int:
        hashset = set()
        res = 0
        size = 0

        for c in s:
            if c in hashset:
                hashset.remove(c)
                res += 2
                size -= 1
            else:
                hashset.add(c)
                size += 1

        if size == 0:
            return res
        return res + 1
