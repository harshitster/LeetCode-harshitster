class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []
        for point in points:
            distance = math.sqrt((math.pow(point[0], 2) + math.pow(point[1], 2)))
            h.append((distance, point))

        heapq.heapify(h)
        res = []
        for i in range(k):
            d, point = heapq.heappop(h)
            res.append(point)

        return res
    
# revised - 02/03/2025