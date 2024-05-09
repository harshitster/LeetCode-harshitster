class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        cost.append(0)
        dp = {}

        def helper(dp, n):
            if n < 2:
                return cost[n]

            if n not in dp:
                dp[n] = cost[n] + min(helper(dp, n - 1), helper(dp, n - 2))

            return dp[n]

        return helper(dp, n)