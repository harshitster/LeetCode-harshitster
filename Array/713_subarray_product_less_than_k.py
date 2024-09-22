class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        result, left, prod = 0, 0, 1

        for right in range(len(nums)):
            prod *= nums[right]
            while prod >= k:
                prod = prod // nums[left]
                left += 1

            result += right - left + 1

        return result