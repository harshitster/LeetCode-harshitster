class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []
        for i in range(len(points)):
            dist = pow(pow(points[i][0], 2) + pow(points[i][1], 2), 0.5)
            h.append((dist, i))
        heapq.heapify(h)

        out = []
        while k != 0:
            out.append(points[heapq.heappop(h)[1]])
            k -= 1
        return out
    
# revised - 02/21/2025