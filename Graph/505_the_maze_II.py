class Solution:
    def minDistance(self, distance, visited, n, m):
        indices = (-1, -1)
        min_val = float('inf')

        for i in range(n):
            for j in range(m):
                if distance[i][j] < min_val and visited[i][j] == False:
                    min_val = distance[i][j]
                    indices = (i, j)

        return indices

    def dijkstra(self, maze, distance, visited, n, m):
        directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        while True:
            u = self.minDistance(distance, visited, n, m)
            if u[0] == -1:
                break

            visited[u[0]][u[1]] = True

            for di, dj in directions:
                ni, nj = u[0] + di, u[1] + dj
                running_distance = 0
                while 0 <= ni < n and 0 <= nj < m and maze[ni][nj] == 0:
                    running_distance += 1
                    ni += di
                    nj += dj

                if distance[ni - di][nj - dj] > distance[u[0]][u[1]] + running_distance:
                    distance[ni - di][nj - dj] = distance[u[0]][u[1]] + running_distance


    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        n, m = len(maze), len(maze[0])
        distance = [[float('inf')] * m for _ in range(n)]
        visited = [[False] * m for _ in range(n)]
        distance[start[0]][start[1]] = 0

        self.dijkstra(maze, distance, visited, n, m)

        return distance[destination[0]][destination[1]] if distance[destination[0]][destination[1]] != float('inf') else -1\
        

# Needs improvement using A-star Algorithm