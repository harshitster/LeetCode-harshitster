class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        m, n = len(matrix), len(matrix[0])
        for i in range(m // 2):
            for j in range(n):
                matrix[i][j], matrix[m - i - 1][j] = matrix[m - i - 1][j], matrix[i][j]


        for i in range(m):
            for j in range(i, n):
                if i == j:
                    continue
                else:
                    matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

# revised - 02/19/2025