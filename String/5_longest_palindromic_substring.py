class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest = 0
        res = ""
        n = len(s)

        def helper(l, r, n):
            nonlocal longest
            nonlocal res
            while l >= 0 and r < n and s[l] == s[r]:
                if (r - l + 1) > longest:
                    longest = r - l + 1
                    res = s[l:r + 1]
                l -= 1
                r += 1

        for i in range(n):
            helper(i, i, n)
            helper(i, i + 1, n)

        return res
    
# revised - 02/26/2025