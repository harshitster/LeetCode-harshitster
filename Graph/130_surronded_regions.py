class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def dfs(i, j):
            board[i][j] = "T"

            for ni, nj in directions:
                I, J = i + ni, j + nj
                if 0 <= I < m and 0 <= J < n and board[I][J] == "O":
                    dfs(I, J)

        for i in range(m):
            for j in range(n):
                if board[i][j] == "O" and (i in [0, m - 1] or j in [0, n - 1]):
                    dfs(i, j)

        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    board[i][j] = "X"
                elif board[i][j] == "T":
                    board[i][j] = "O"