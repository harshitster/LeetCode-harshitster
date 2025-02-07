class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        stack = []

        for i in range(len(s)):
            if ord('A') <= ord(s[i]) <= ord('z'):
                continue
            else:
                if s[i] == '(':
                    stack.append(i)
                else:
                    if stack and s[stack[-1]] == '(':
                        stack.pop()
                    else:
                        stack.append(i)

        for index in stack:
            s[index] = ""

        return "".join(s)