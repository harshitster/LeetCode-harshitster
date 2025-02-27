class Solution:
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        h = []
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                h.append((-grid[i][j], i))

        heapq.heapify(h)
        res = 0

        while k and h:
            val, i = heapq.heappop(h)
            if limits[i] == 0:
                continue

            res += (-val)
            limits[i] -= 1
            k -= 1

        return res