class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        for p in prerequisites:
            graph[p[0]].append(p[1])

        states = [0] * numCourses
        def dfs(course, out):
            if states[course] == 2:
                return True
            elif states[course] == 1:
                return False

            states[course] = 1

            for p in graph[course]:
                res = dfs(p, out)
                if not res:
                    return False

            states[course] = 2
            out.append(course)
            return True

        out = []
        for i in range(numCourses):
            dfs(i, out)

        return out if len(out) == numCourses else []
    
# Revised - 01/17/2025