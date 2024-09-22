class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n, k = len(costs), len(costs[0])
        dp = [0] * k
        
        for i in range(n):
            temp = [0] * k
            for j in range(k):
                temp[j] = costs[i][j] + min(dp[:j] + dp[j + 1:])
            dp = temp

        return min(dp)