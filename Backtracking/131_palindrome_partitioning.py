class Solution:
    def partition(self, s: str) -> List[List[str]]:
        memo = {}
        n = len(s)

        def is_palindrome(s):
            return s == s[::-1]

        def backtrack(start):
            if start in memo:
                return memo[start]

            if start >= n:
                return [[]]

            res = []
            for end in range(start, n):
                substring = s[start:end + 1]
                if is_palindrome(substring):
                    for suffix in backtrack(end + 1):
                        res.append([substring] + suffix)

            memo[start] = res
            return res

        return backtrack(0)


# revised - 02/25/2025