class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        rows, cols = len(grid), len(grid[0])

        def isValid(i, j):
            return i >= 0 and i < rows and j >= 0 and j < cols and grid[i][j] == 1

        def dfs(i, j, area):
            area = 1
            grid[i][j] = 0

            for di, dj in directions:
                I = i + di
                J = j + dj
                if isValid(I, J):
                    area += dfs(I, J, area + 1)

            return area

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    max_area = max(max_area, dfs(i, j, 0))

        return max_area