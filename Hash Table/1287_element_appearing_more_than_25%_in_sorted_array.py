class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        cutoff = n // 4

        hashmap = {}
        out = []
        for i in range(n):
            hashmap[arr[i]] = hashmap.get(arr[i], 0) + 1
            if hashmap[arr[i]] > cutoff:
                return arr[i]

        return -1