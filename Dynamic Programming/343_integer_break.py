class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1

        dp = {}

        def helper(n):
            if n <= 3:
                return n
            if n in dp:
                return dp[n]

            ans = n
            for i in range(1, n):
                ans = max(ans, i * helper(n - i))

            dp[n] = ans
            return dp[n]

        return helper(n)