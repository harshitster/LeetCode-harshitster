class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = {i: [] for i in range(n)}
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        def dfs(node, visited):
            visited.add(node)

            for n in graph[node]:
                if n not in visited:
                    dfs(n, visited)

        visited = set()
        count = 0
        for i in range(n):
            if i not in visited:
                dfs(i, visited)
                count += 1

        return count
    
# Revised - 01/17/2025