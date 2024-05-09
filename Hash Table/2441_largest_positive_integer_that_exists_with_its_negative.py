class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        hashmap = {}
        max_ele = -1

        for num in nums:
            if -num in hashmap and abs(num) > max_ele:
                max_ele = abs(num)
            hashmap[num] = 1
            
        return max_ele