class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        count = 0

        while nums[0] < k:
            num1 = heapq.heappop(nums)
            num2 = heapq.heappop(nums)
            inum = min(num1, num2) * 2 + max(num1, num2)
            heapq.heappush(nums, inum)
            count += 1

        return count