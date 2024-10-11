class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        q = deque()
        n, m = len(mat), len(mat[0])
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.append((i, j))
                else:
                    mat[i][j] = -1

        while q:
            x, y = q.popleft()
            for dx, dy in directions:
                X, Y = x + dx, y + dy
                if X >= 0 and X < n and Y >= 0 and Y < m and mat[X][Y] == -1:
                    mat[X][Y] = mat[x][y] + 1
                    q.append((X, Y))

        return mat