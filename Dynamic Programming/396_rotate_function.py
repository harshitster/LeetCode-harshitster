class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        nums_sum = sum(nums)
        prev_sum = 0
        n = len(nums)

        for i in range(1, n):
            prev_sum += i * nums[i]

        max_sum = prev_sum
        for i in range(1, n):
            current_sum = nums_sum + prev_sum - n * nums[n - i]
            max_sum = max(max_sum, current_sum)
            prev_sum = current_sum

        return max_sum