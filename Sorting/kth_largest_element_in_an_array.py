class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums = [-num for num in nums]
        heapq.heapify(nums)

        for i in range(k):
            val = heapq.heappop(nums)
            if i == k - 1:
                return -val

