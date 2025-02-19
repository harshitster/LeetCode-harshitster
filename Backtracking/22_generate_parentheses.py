class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        out = []
        size = 2 * n

        def backtrack(res, left, right, s):
            if s == size:
                out.append(res)
                return

            if left < n:
                res += "("
                backtrack(res, left + 1, right, s + 1)
                res = res[:-1]

            if right < left:
                res += ")"
                backtrack(res, left, right + 1, s + 1)
                res = res[:-1]

        backtrack("", 0, 0, 0)
        return out

# revised - 02/18/2025