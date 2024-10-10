class Solution:
    def integerReplacement(self, n: int) -> int:
        dp = {}
        dp[1] = 0

        def helper(n):
            if n in dp:
                return dp[n]

            if n % 2 == 0:
                dp[n] = helper(n // 2) + 1
            else:
                dp[n] = min(helper(n - 1), helper(n + 1)) + 1

            return dp[n]

        return helper(n)