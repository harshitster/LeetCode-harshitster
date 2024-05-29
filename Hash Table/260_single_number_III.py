class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        hashmap = {}

        for num in nums:
            if num not in hashmap:
                hashmap[num] = 1
            else:
                del hashmap[num]

        return list(hashmap.keys())
    
# Can be optimized. Check LeetCode