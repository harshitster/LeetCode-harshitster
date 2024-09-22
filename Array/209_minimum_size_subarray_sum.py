class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = -1
        n = len(nums)
        min_len = n + 1
        prefix_sum = 0

        for right in range(n):
            if nums[right] >= target:
                return 1
            prefix_sum += nums[right]
            if prefix_sum >= target:
                while left < right and prefix_sum >= target:
                    min_len = min(min_len, right - left)
                    left += 1
                    prefix_sum -= nums[left]

        return min_len if min_len != n + 1 else 0