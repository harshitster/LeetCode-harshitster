class Solution:
    def reorganizeString(self, s: str) -> str:
        hashmap = {}
        for c in s:
            hashmap[c] = hashmap.get(c, 0) + 1

        heap = [(-count, c) for c, count in hashmap.items()]
        heapq.heapify(heap)

        prev = None
        res = ""
        while heap or prev:
            if not heap and prev:
                return ""

            count, c = heapq.heappop(heap)
            res += c
            count += 1

            if prev:
                heapq.heappush(heap, prev)
                prev = None
            if count != 0:
                prev = (count, c)

        return res
    
# revised - 02/11/2025