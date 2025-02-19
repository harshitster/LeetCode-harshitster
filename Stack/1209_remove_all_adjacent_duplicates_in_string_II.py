class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        n = len(s)
        stack = [(None,None)] * n
        index = 0

        for i in range(n):
            count = 1
            if index > 0 and stack[index - 1][0] == s[i]:
                count = stack[index - 1][1] + 1
            stack[index] = (s[i], count)
            index += 1

            if stack[index - 1][1] == k:
                index -= k

        res = ""
        for i in range(index):
            res += stack[i][0]
        
        return res