class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        lastDay = days[-1]
        dp = [0] * (lastDay + 1)

        index = 0
        for i in range(1, lastDay + 1):
            if i < days[index]:
                dp[i] = dp[i - 1]
            else:
                dp[i] = min([
                    dp[i - 1] + costs[0],
                    dp[max(0, i - 7)] + costs[1],
                    dp[max(0, i - 30)] + costs[2]
                ])
                index += 1

        return dp[lastDay]