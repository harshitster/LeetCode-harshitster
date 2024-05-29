class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        self.max_gold = 0
        self.r, self.c = len(grid), len(grid[0])
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        def dfs(i, j, path_gold):
            gold = grid[i][j]
            path_gold += gold
            self.max_gold = max(self.max_gold, path_gold)

            grid[i][j] = 0

            for di, dj in self.directions:
                I, J = i + di, j + dj
                if 0 <= I < self.r and 0 <= J < self.c and grid[I][J] != 0:
                    dfs(I, J, path_gold)

            grid[i][j] = gold

        for i in range(self.r):
            for j in range(self.c):
                if grid[i][j] != 0:
                    dfs(i, j, 0)

        return self.max_gold