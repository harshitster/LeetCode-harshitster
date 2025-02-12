class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        for course, pre in prerequisites:
            graph[course].append(pre)

        state = [0] * numCourses
        out = []
        def dfs(course):
            if state[course] == 1:
                return False
            if state[course] == 2: 
                return True

            state[course] = 1

            for prereq in graph[course]:
                if not dfs(prereq):
                    return False

            state[course] = 2
            out.append(course)
            return True

        for i in range(numCourses):
            if not dfs(i):
                return []

        return out
    
# revised - 02/11/2025