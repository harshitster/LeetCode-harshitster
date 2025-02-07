class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        r = [0] * rows
        c = [0] * cols

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    r[i] += 1
                    c[j] += 1

        total = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1 and (r[i] > 1 or c[j] > 1):
                    total += 1

        return total