class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9

        r = [set() for _ in range(n)]
        c = [set() for _ in range(n)]
        b = [set() for _ in range(n)]

        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue

                if board[i][j] in r[i]:
                    return False
                r[i].add(board[i][j])

                if board[i][j] in c[j]:
                    return False
                c[j].add(board[i][j])

                bi = 3 * (i // 3) + (j // 3)
                if board[i][j] in b[bi]:
                    return False
                b[bi].add(board[i][j])

        return True