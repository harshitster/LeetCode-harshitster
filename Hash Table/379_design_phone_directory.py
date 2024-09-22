class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        self.numbers = set([i for i in range(maxNumbers)])

    def get(self) -> int:
        if self.numbers:
            return self.numbers.pop()
        return -1 

    def check(self, number: int) -> bool:
        if number in self.numbers:
            return True
        return False

    def release(self, number: int) -> None:
        self.numbers.add(number)

# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)