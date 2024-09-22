class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1

        graph = {i: [] for i in range(n)}
        for c in connections:
            graph[c[0]].append(c[1])
            graph[c[1]].append(c[0])

        components = 0
        visited = set()

        def dfs(source):    
            visited.add(source)

            for ne in graph[source]:
                if ne not in visited:
                    dfs(ne)

        for i in range(n):
            if i not in visited:
                components += 1
                dfs(i)

        return components - 1