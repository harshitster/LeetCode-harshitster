class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        m, n = len(grid), len(grid[0])

        def dfs(i, j):
            grid[i][j] = "0"
            
            for ni, nj in directions:
                I, J = i + ni, j + nj

                if 0 <= I < m and 0 <= J < n and grid[I][J] == "1":
                    dfs(I, J)

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    dfs(i, j)
                    count += 1

        return count    
    
# Revised - 01/25/2025