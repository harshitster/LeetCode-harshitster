class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = {}

        for i in range(1, len(nums)):
            for j in range(i):
                dp[(i, nums[i] - nums[j])] = dp.get((j, nums[i] - nums[j]), 1) + 1

        return max(dp.values())