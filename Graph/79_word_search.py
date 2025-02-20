class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def dfs(i, j, index):
            if index == len(word):
                return True

            c = board[i][j]
            board[i][j] = '$'
            for ni, nj in directions:
                I, J = i + ni, j + nj
                if 0 <= I < m and 0 <= J < n and board[I][J] == word[index]:
                    if dfs(I, J, index + 1):
                        return True

            board[i][j] = c
            return False


        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and dfs(i, j, 1):
                    return True

        return False
    
# revised - 02/19/2025