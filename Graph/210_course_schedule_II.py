class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        for course, pre in prerequisites:
            graph[course].append(pre)

        state = [0] * numCourses
        order = []
        completed = set()

        def dfs(course):
            if state[course] == 1:
                return False
            if state[course] == 2:
                if course not in completed:
                    order.append(course)
                    completed.add(course)

            state[course] = 1

            for pre in graph[course]:
                if not dfs(pre):
                    return False

            state[course] = 2
            if course not in completed:
                order.append(course)
                completed.add(course)

            return True

        for source in range(numCourses):
            if not dfs(source):
                return []

        return order