class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])

        oneRow = []
        for i in range(m):
            ones = 0
            for j in range(n):
                if grid[i][j] == 1:
                    ones += 1
            oneRow.append(ones)

        oneCol = []
        for j in range(n):
            ones = 0
            for i in range(m):
                if grid[i][j] == 1:
                    ones += 1
            oneCol.append(ones)

        for i in range(m):
            for j in range(n):
                grid[i][j] = oneRow[i] + oneCol[j] - (m - oneRow[i]) - (n - oneCol[j])
        
        return grid