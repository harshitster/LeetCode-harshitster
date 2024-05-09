class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        hashmap = {}
        rows, cols = len(matrix), len(matrix[0])

        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    if (i, None) not in hashmap:
                        hashmap[(i, None)] = 1
                    if (None, j) not in hashmap:
                        hashmap[(None, j)] = 1

        for r, c in hashmap.keys():
            if c is None:
                for i in range(cols):
                    matrix[r][i] = 0
            else:
                for i in range(rows):
                    matrix[i][c] = 0