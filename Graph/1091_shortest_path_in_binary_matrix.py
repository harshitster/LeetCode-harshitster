class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        if(grid[0][0] == 1 or grid[m - 1][n - 1] == 1):
            return -1

        directions = [(0, 1), (1, 0), (-1, 0), (0, -1), (1, 1), (-1, 1), (1, -1), (-1, -1)]
        queue = [(0, 0)]
        visited = set()
        visited.add((0, 0))

        shortest = float('inf')
        path = 1
        while len(queue) > 0:
            size = len(queue)

            for _ in range(size):
                i, j = queue.pop(0)
                if i == m - 1 and j == n - 1:
                    return path

                for ni, nj in directions:
                    I, J = i + ni, j + nj
                    if 0 <= I < m and 0 <= J < n and (I, J) not in visited and grid[I][J] == 0:
                        visited.add((I, J))
                        queue.append((I, J))

            path += 1

        return -1
    
# revised - 02/25/2025