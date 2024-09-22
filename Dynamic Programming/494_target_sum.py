class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}

        def backtrack(index, running_sum):
            if index == len(nums):
                return 1 if running_sum == target else 0
            if (index, running_sum) in dp:
                return dp[(index, running_sum)]

            dp[(index, running_sum)] = backtrack(index + 1, running_sum + nums[index]) + backtrack(index + 1, running_sum - nums[index])
            return dp[(index, running_sum)]

        return backtrack(0, 0)