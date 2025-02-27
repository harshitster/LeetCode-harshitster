class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))

        minutes = 0
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        while len(q) > 0:
            size = len(q)

            for _ in range(size):
                i, j = q.popleft()
                for ni, nj in directions:
                    I, J = i + ni, j + nj
                    if 0 <= I < m and 0 <= J < n and grid[I][J] == 1:
                        q.append((I, J))
                        grid[I][J] = 2

            minutes += 1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1

        return max(minutes - 1, 0)
    
# revised - 02/26/2025