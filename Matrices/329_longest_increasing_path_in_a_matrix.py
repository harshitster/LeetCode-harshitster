class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        def dfs(i, j):
            dp[i][j] = 1

            for di, dj in directions:
                ni, nj = i + di, j + dj
                if ni >= 0 and ni < n and nj >= 0 and nj < m and matrix[ni][nj] > matrix[i][j]:
                    if dp[ni][nj] != 0:
                        dp[i][j] = max(dp[i][j], 1 + dp[ni][nj])
                    else:
                        dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj))

            return dp[i][j]

        longest_path = 1
        for i in range(n):
            for j in range(m):
                if dp[i][j] == 0:
                    longest_path = max(longest_path, dfs(i, j))
                else:
                    longest_path = max(longest_path, dp[i][j])

        return longest_path