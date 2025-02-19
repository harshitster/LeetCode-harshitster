class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        window = nums.count(1)
        window_ones = max_window_ones = 0
        left = 0

        for right in range(2 * n):
            if nums[right % n] == 1:
                window_ones += 1
            if (right - left + 1) > window:
                window_ones -= nums[left % n]
                left += 1

            max_window_ones = max(max_window_ones, window_ones)

        return window - max_window_ones