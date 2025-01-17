class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        graph = {i: [] for i in range(n)}
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)
        states = [0] * n

        def dfs(node, prev):
            if states[node] == 1:
                return False
            if states[node] == 2:
                return True
            
            states[node] = 1

            for n in graph[node]:
                if n != prev and not dfs(n, node):
                    return False

            states[node] = 2
            return True

        res = dfs(0, -1)
        if not res:
            return res

        for i in range(n):
            if states[i] != 2:
                return False

        return True
    
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        graph = {i: [] for i in range(n)}
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        def dfs(node, prev, visited):
            if node in visited:
                return False

            visited.add(node)
            for n in graph[node]:
                if n != prev:
                    res = dfs(n, node, visited)
                    if not res:
                        return False

            return True

        visited = set()
        res = dfs(0, -1, visited) and len(visited) == n

        return res
    
# Revised - 01/17/2025