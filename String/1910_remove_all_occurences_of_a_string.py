class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        stack_length = 0
        part_length = len(part)

        for i in range(len(s)):
            stack.append(s[i])
            stack_length += 1

            if stack_length >= part_length:
                substring = "".join(stack[-part_length:])
                if substring == part:
                    stack = stack[:-part_length]
                    stack_length -= part_length

        return "".join(stack)


# revised - 02/21/2025