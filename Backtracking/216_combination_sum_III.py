class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        output = []

        def backtrack(start, elements, length, s):
            if s > n:
                return
            if length == k:
                if s == n:
                    output.append(list(elements))
                return

            for i in range(start, 10):
                elements.append(i)
                backtrack(i + 1, elements, length + 1, s + i)
                elements.pop()

        backtrack(1, [], 0, 0)
        return output