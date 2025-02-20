class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[rows - 1][cols - 1] == 1 or obstacleGrid[0][0] == 1:
            return 0
        grid = [[0] * cols] * rows
        grid[rows - 1][cols - 1] = 1

        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                if i == rows - 1 and j == cols - 1:
                    continue
                if obstacleGrid[i][j] == 1:
                    grid[i][j] = 0
                else:
                    if i == rows - 1:
                        grid[i][j] = grid[i][j + 1]
                    elif j == cols - 1:
                        grid[i][j] = grid[i + 1][j]
                    else:
                        grid[i][j] = grid[i + 1][j] + grid[i][j + 1]

        return grid[0][0]
    
# revised - 02/19/2025