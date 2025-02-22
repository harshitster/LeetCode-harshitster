class Solution:
    def frequencySort(self, s: str) -> str:
        hashmap = {}
        for c in s:
            hashmap[c] = hashmap.get(c, 0) + 1
        h = [(-count, c) for c, count in hashmap.items()]
        heapq.heapify(h)

        res = ""
        while h:
            count, c = heapq.heappop(h)
            count = -count

            res += (c * count)

        return res
    
# revised - 02/21/2025