class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        dp = {0: 1, 1: 10}

        def helper(n):
            if n in dp:
                return dp[n]

            ways = 9
            factor = 9
            for i in range(1, n):
                ways *= factor
                factor -= 1

            dp[n] = ways + helper(n - 1)
            return dp[n]

        return helper(n)