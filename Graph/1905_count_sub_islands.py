class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        def isValid(i, j):
            return i < m and j < n and i >= 0 and j >= 0 and grid2[i][j] == 1

        def dfs(i, j):
            grid2[i][j] = -1
            is_sub_island = True

            if grid1[i][j] == 0:
                is_sub_island = False

            for di, dj in directions:
                I = i + di
                J = j + dj
                if(isValid(I, J)):
                    if not dfs(I, J):
                        is_sub_island = False

            return is_sub_island

        count = 0
        for i in range(m):
            for j in range(n):
                if(grid2[i][j] == 1):
                    if dfs(i, j):
                        count += 1

        return count