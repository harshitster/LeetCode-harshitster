class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        dp = [[0 for _ in range(n2 + 1)] for _ in range(n1 + 1)]

        for i in range(n1 + 1):
            for j in range(n2 + 1):
                if i == 0 and j == 0: 
                    dp[i][j] = 0
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] + 1
                elif i == 0:
                    dp[i][j] = dp[i][j - 1] + 1
                else:
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (1 if word1[i - 1] != word2[j - 1] else 0))

        return dp[n1][n2]