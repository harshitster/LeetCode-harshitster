class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = {}
        for n1, n2 in edges:
            if n1 not in graph:
                graph[n1] = [n2]
            else:
                graph[n1].append(n2)

            if n2 not in graph:
                graph[n2] = [n1]
            else:
                graph[n2].append(n1)

        for i in range(n):
            if i not in graph:
                graph[i] = []

        def dfs(source):
            visited.add(source)

            for n in graph[source]:
                if n not in visited:
                    dfs(n)

        visited = set()
        components = 0
        for i in range(n):
            if i not in visited:
                components += 1
                dfs(i)

        return components