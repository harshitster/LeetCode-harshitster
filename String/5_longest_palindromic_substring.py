class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest, out = 0, ""

        for i in range(len(s)):
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > longest:
                    longest = r - l + 1
                    out = s[l: r + 1]
                l -= 1
                r += 1

            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > longest:
                    longest = r - l + 1
                    out = s[l: r + 1]
                l -= 1
                r += 1

        return out

# revised - 02/11/2025