class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        output = []
        size = 2 * n

        def backtrack(elements, left, right, e_size):
            if e_size == size:
                output.append(elements)
                return

            if left < n:
                elements += '('
                backtrack(elements, left + 1, right, e_size + 1)
                elements = elements[:-1]
            
            if right < left:
                elements += ')'
                backtrack(elements, left, right + 1, e_size + 1)
                elements = elements[:-1]

        backtrack('', 0, 0, 0)
        return output