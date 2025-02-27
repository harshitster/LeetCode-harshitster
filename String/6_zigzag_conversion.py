class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        n = len(s)
        grid = [["" for _ in range(n)] for _ in range(numRows)]
        i, j = 0, 0

        for idx in range(n):
            if i == 0:
                ni, nj = 1, 0
            elif i == numRows - 1:
                ni, nj = -1, 1

            grid[i][j] = s[idx]
            i, j = i + ni, j + nj

        res = ""
        for i in range(numRows):
            for j in range(n):
                if grid[i][j] != "":
                    res += grid[i][j]

        return res
