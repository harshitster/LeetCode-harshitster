class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp1 = [-1] * n
        dp2 = [-1] * n

        def helper(nums, i, n, dp):
            if i >= n:
                return 0
            elif dp[i] != -1:
                return dp[i]

            dp[i] = max(nums[i] + helper(nums, i + 2, n, dp), helper(nums, i + 1, n, dp))
            return dp[i]

        return max(helper(nums, 0, n - 1, dp1), helper(nums, 1, n, dp2))