class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if grid[m - 1][n - 1] == 1 or grid[0][0] == 1:
            return -1
        queue = []
        queue.append((0, 0, 1))
        min_cost = float('inf')
        directions = [(0, 1), (1, 0), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        visited = set()
        visited.add((0, 0))

        while len(queue) > 0:
            size = len(queue)

            for _ in range(size):
                i, j, cost = queue.pop(0)
                if i == m - 1 and j == n - 1:
                    min_cost = min(min_cost, cost)
                    continue

                for ni, nj in directions:
                    I, J = i + ni, j + nj
                    if 0 <= I < m and 0 <= J < n and (I, J) not in visited and grid[I][J] == 0:
                        visited.add((I, J))
                        queue.append((I, J, cost + 1))

        return min_cost if min_cost != float('inf') else -1