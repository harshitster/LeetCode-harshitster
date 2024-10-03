class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        MOD = 10**9 + 7

        def dfs(i, j):
            if dp[i][j] != 0:
                return dp[i][j]

            for di, dj in directions:
                ni, nj = i + di, j + dj
                if ni >= 0 and ni < n and nj >= 0 and nj < m and grid[i][j] < grid[ni][nj]:
                    if dp[ni][nj] != 0:
                        dp[i][j] += dp[ni][nj] + 1
                    else:
                        dp[i][j] += dfs(ni, nj) + 1

            return dp[i][j]

        count = 0
        for i in range(n):
            for j in range(m):
                count = (count + dfs(i, j)) % MOD

        return count + ((n * m) % MOD)