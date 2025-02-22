class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)
        if total_sum % 2 == 1:
            return False

        subset_sum = total_sum // 2

        dp = {}
        def dfs(i, subset_sum):
            if subset_sum == 0:
                return True
            elif subset_sum < 0 or i == len(nums):
                return False

            if (i, subset_sum) in dp:
                return dp[(i, subset_sum)]

            dp[(i, subset_sum)] = dfs(i + 1, subset_sum - nums[i]) or dfs(i + 1, subset_sum)

            return dp[(i, subset_sum)]

        return dfs(0, subset_sum)