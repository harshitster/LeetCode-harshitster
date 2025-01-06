class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]

        def helper(dp, n):
            if n < 0:
                return 0
            if n == 0: 
                return 1

            if dp[n] != 0:
                return dp[n]
            else:
                dp[n] = helper(dp, n - 1) + helper(dp, n - 2)

            return dp[n]

        return helper(dp, n)
    
# Revised - 01/06/2025