class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        output = []

        def backtrack(start, elements, size):
            if size == k:
                output.append(elements[:])
                return

            for i in range(start, n + 1):
                elements.append(i)
                backtrack(i + 1, elements, size + 1)
                elements.pop()

        backtrack(1, [], 0)
        return output