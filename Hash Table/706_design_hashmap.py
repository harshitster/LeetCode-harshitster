class MyHashMap:

    def __init__(self):
        self.keys = [-1] * 1000000
        self.values = [-1] * 1000000
        self.hash = 1000000 

    def put(self, key: int, value: int) -> None:
        idx = key % self.hash
        if self.keys[idx] == -1:
            self.keys[idx] = key
        self.values[idx] = value

    def get(self, key: int) -> int:
        idx = key % self.hash
        return self.values[idx]

    def remove(self, key: int) -> None:
        idx = key % self.hash        
        self.keys[idx] = -1
        self.values[idx] = -1

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)