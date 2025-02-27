class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        out = []

        def backtrack(left, right, part):
            if left == n and right == n:
                out.append(part)
                return

            if left < n:
                part += '('
                backtrack(left + 1, right, part)
                part = part[:-1]

            if right < left:
                part += ')'
                backtrack(left, right + 1, part)
                part = part[:-1]

        backtrack(0, 0, "")
        return out

# revised - 02/26/2025