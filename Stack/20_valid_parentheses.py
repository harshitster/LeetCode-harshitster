class Solution:
    def isValid(self, s: str) -> bool:
        hashmap = {
            ")": "(",
            "}": "{",
            "]": "["
        }

        stack = []

        for c in s:
            if c not in hashmap:
                stack.append(c)
            else:
                if not stack or stack[-1] != hashmap[c]:
                    return False
                else:
                    stack.pop()

        return True if len(stack) == 0 else False
    
# revised - 01/27/2025