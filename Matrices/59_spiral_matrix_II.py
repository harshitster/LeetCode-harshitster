class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        up, down = 0, n - 1
        left, right = 0, n - 1
        num = 1
        limit = n * n + 1

        grid = [[0 for _ in range(n)] for _ in range(n)]

        while num < limit:
            for i in range(left, right + 1):
                grid[up][i] = num
                num += 1
            up += 1

            for i in range(up, down + 1):
                grid[i][right] = num
                num += 1
            right -= 1

            if up <= down:
                for i in range(right, left - 1, -1):
                    grid[down][i] = num
                    num += 1
                down -= 1

            if left <= right:
                for i in range(down, up - 1, -1):
                    grid[i][left] = num
                    num += 1
                left += 1

        return grid