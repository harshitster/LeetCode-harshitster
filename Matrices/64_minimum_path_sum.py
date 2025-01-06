class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                if i == rows - 1 and j == cols - 1:
                    continue
                elif i == rows - 1:
                    grid[i][j] += grid[i][j + 1]
                elif j == cols - 1:
                    grid[i][j] += grid[i + 1][j]
                else:
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1])

        return grid[0][0]
    
# Revised - 01/06/2025