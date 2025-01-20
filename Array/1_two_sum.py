class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}

        for i in range(len(nums)):
            r = target - nums[i]
            if r in hashmap:
                return [hashmap[r], i]
            hashmap[nums[i]] = i

        return hashmap