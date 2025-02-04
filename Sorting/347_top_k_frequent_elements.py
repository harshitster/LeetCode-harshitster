class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        h = [[-count, num] for num, count in counter.items()]
        heapq.heapify(h)

        res = []
        for i in range(k):  
            res.append(heapq.heappop(h)[1])

        return res
    
# revised - 02/03/2025