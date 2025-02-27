class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        map = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'] 
        }

        out = []
        n = len(digits)

        if n == 0:
            return out

        def backtrack(i, part):
            if i == n:
                out.append(part)
                return

            for c in map[digits[i]]:
                part += c
                backtrack(i + 1, part)
                part = part[:-1]

        backtrack(0, "")
        return out

# revised - 02/26/2025