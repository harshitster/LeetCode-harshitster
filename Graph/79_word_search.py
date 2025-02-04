class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.rows, self.cols = len(board), len(board[0])
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        self.word_length = len(word)

        def dfs(i, j, idx):
            if word[idx] != board[i][j]:
                return False
            if idx + 1 == self.word_length:
                return True

            c = board[i][j]
            board[i][j] = '$'
            for di, dj in self.directions:
                I, J = i + di, j + dj
                if I >= 0 and I < self.rows and J >= 0 and J < self.cols:
                    if dfs(I, J, idx + 1):
                        return True
            board[i][j] = c        

            return False

        for i in range(self.rows):
            for j in range(self.cols):
                if dfs(i, j, 0):
                    return True

        return False
    
# revised - 02/03/2025