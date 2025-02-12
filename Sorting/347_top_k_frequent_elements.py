class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1

        h = [(-count, num) for num, count in hashmap.items()]
        heapq.heapify(h)

        out = []
        while k > 0:
            out.append(heapq.heappop(h)[1])
            k -= 1

        return out
    
# revised - 02/11/2025