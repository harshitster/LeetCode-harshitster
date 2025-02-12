class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = []
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j))

        minutes = 0
        while queue:
            size = len(queue)

            for _ in range(size):
                i, j = queue.pop(0)
                for ni, nj in directions:
                    I, J = i + ni, j + nj
                    if 0 <= I < m and 0 <= J < n and grid[I][J] == 1:
                        grid[I][J] = 2
                        queue.append((I, J))

            minutes += 1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1

        return max(minutes - 1, 0)
    
# revised - 02/11/2025