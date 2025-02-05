class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = {i: set() for i in range(numCourses)}
        for p, q in prerequisites:
            graph[p].add(q)

        def dfs(node, visited, preqs):
            visited.add(node)

            for n in graph[node]:
                preqs[node].add(n)
                if n not in visited:
                    dfs(n, visited, preqs)
                preqs[node] |= preqs[n]

        preqs = {i : set() for i in range(numCourses)}
        visited = set()
        for i in range(numCourses):
            if i not in visited:
                dfs(i, visited, preqs)

        res = []
        for u, v in queries:
            if u in preqs and v in preqs[u]:
                res.append(True)
            else:
                res.append(False)

        return res