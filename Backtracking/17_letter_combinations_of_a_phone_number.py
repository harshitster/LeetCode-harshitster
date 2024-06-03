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

        output = []
        n = len(digits)
        if n == 0:
            return output

        def backtrack(start_index, elements):
            if start_index == n:
                output.append(elements)
                return

            for l in map[digits[start_index]]:
                elements += l
                backtrack(start_index + 1, elements)
                elements = elements[:-1]

        backtrack(0, '')
        return output