class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        hashmap = {}

        for i in range(len(nums) - 1):
            s = nums[i] + nums[i + 1]
            if s in hashmap:
                return True
            hashmap[s] = 1

        return False