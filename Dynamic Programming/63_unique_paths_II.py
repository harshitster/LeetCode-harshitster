class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[m - 1][n - 1] == 1:
            return 0
        obstacleGrid[m - 1][n - 1] = 1

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1 and j == n - 1:
                    continue
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = 0
                else:
                    if i != m - 1:
                        obstacleGrid[i][j] += obstacleGrid[i + 1][j]
                    if j != n - 1:
                        obstacleGrid[i][j] += obstacleGrid[i][j + 1]
        
        return obstacleGrid[0][0]

# Revised - 01/06/2025