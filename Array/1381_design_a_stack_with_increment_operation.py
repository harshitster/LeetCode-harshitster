class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.length = 0
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        if self.length == self.maxSize:
            return

        self.stack.append(x)
        self.length += 1

    def pop(self) -> int:
        if self.length == 0:
            return -1

        val = self.stack.pop()
        self.length -= 1

        return val   

    def increment(self, k: int, val: int) -> None:
        for i in range(0, min(k, self.length)):
            self.stack[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)