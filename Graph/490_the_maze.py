class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        n, m = len(maze), len(maze[0])
        visited = [[False] * m for _ in range(n)]

        def isValid(i, j):
            return i >= 0 and i < n and j >= 0 and j < m and maze[i][j] != 1
        
        def dfs(i, j):
            if visited[i][j] or not isValid(i, j):
                return False
            if i == destination[0] and j == destination[1]:
                return True

            visited[i][j] = True
            
            for di, dj in directions:
                ni, nj = i, j
                while isValid(ni, nj):
                    ni, nj = ni + di, nj + dj
                if dfs(ni - di, nj - dj):
                    return True

            return False

        return dfs(start[0], start[1])