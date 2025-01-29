class Solution:
    def calculate(self, s: str) -> int:
        i = 0

        def cal():
            nonlocal i
            num, stack, sign = 0, [], '+'

            def update(op, val):
                if sign == '+': stack.append(val)
                if sign == '-': stack.append(-val)
                if sign == '*': stack.append(stack.pop() * val)
                if sign == '/': stack.append(stack.pop() // val)

            while i < len(s):
                if s[i].isdigit():
                    num = num * 10 + int(s[i])
                elif s[i] in '+-*/':
                    update(s[i], num)
                    num, sign = 0, s[i]
                elif s[i] == '(':
                    i += 1
                    num = cal()
                elif s[i] == ')':
                    update(sign, num)
                    return sum(stack)
                i += 1

            update(sign, num)
            return sum(stack)

        return cal()