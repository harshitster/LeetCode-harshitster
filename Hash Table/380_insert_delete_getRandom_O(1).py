class RandomizedSet:

    def __init__(self):
        self.hashmap = {}
        self.list = []

    def insert(self, val: int) -> bool:
        res = val not in self.hashmap
        if res:
            self.hashmap[val] = len(self.list)
            self.list.append(val)

        return res

    def remove(self, val: int) -> bool:
        res = val in self.hashmap
        if res:
            idx = self.hashmap[val]
            lastVal = self.list[-1]
            self.list[idx] = lastVal
            self.list.pop()
            self.hashmap[lastVal] = idx
            del self.hashmap[val]

        return res

    def getRandom(self) -> int:
        return random.choice(self.list)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()