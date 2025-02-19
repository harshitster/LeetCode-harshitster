class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = {i: set() for i in range(numCourses)}
        for u, v in prerequisites:
            graph[u].add(v)

        def dfs(node, visited, preqs):
            visited.add(node)

            for n in graph[node]:
                preqs[node].add(n)
                if n not in visited:
                    dfs(n, visited, preqs)
                preqs[node] |= preqs[n]

        preqs = {i: set() for i in range(numCourses)}
        visited = set()

        for i in range(numCourses):
            if i not in visited:
                dfs(i, visited, preqs)

        out = []
        for u, v in queries:
            if v in preqs[u]:
                out.append(True)
            else:
                out.append(False)

        return out

# revised - 02/18/2025