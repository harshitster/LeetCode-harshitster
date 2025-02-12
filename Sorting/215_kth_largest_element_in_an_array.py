class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        h = [-num for num in nums]
        heapq.heapify(h)

        while k != 1:
            heapq.heappop(h)
            k -= 1

        return -heapq.heappop(h)