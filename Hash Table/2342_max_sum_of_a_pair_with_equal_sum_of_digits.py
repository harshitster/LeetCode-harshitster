class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        hashmap = {}

        def helper(num):
            out = 0
            while num != 0:
                out += (num % 10)
                num = num // 10
            return out

        max_sum = float('-inf')
        for i in range(len(nums)):
            s = helper(nums[i])
            if s in hashmap:
                max_sum = max(max_sum, nums[i] + hashmap[s])
                hashmap[s] = max(hashmap[s], nums[i])
            else:
                hashmap[s] = nums[i]

        return max(max_sum, -1)