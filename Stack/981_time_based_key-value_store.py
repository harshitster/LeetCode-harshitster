class TimeMap:

    def __init__(self):
        self.hashmap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.hashmap:
            self.hashmap[key] = []

        self.hashmap[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        res = ""
        if key not in self.hashmap:
            return res

        for i in range(len(self.hashmap[key]) - 1, -1, -1):
            if self.hashmap[key][i][0] <= timestamp:
                res = self.hashmap[key][i][1]
                return res

        return res



# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)