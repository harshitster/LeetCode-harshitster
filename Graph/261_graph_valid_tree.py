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