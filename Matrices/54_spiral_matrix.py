class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows, cols = len(matrix), len(matrix[0])
        up, left = 0, 0
        down, right = rows - 1, cols - 1
        res = []
        n = rows * cols

        while len(res) < n:
            for i in range(left, right + 1):
                res.append(matrix[up][i])
            up += 1

            for i in range(up, down + 1):
                res.append(matrix[i][right])
            right -= 1

            if len(res) < n:
                for i in range(right, left - 1, -1):
                    res.append(matrix[down][i])
                down -= 1

            if len(res) < n:
                for i in range(down, up - 1, -1):
                    res.append(matrix[i][left])
                left += 1

        return res