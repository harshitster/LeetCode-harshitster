class FileSystem:

    def __init__(self):
        self.fileSystem = {}
        self.values = {}

    def createPath(self, path: str, value: int) -> bool:
        files = path.split('/')
        curr = self.fileSystem

        for f in files[:-1]:
            if f == "":
                continue
            if f not in curr:
                return False
            curr = curr[f]

        if files[-1] in curr:
            return False
        curr[files[-1]] = {}
        self.values[path] = value
        return True

    def get(self, path: str) -> int:
        if path not in self.values:
            return -1
        return self.values[path]
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)