class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        prefix_sum, count = 0, 0
        hashmap = {}

        for num in nums:
            prefix_sum += num
            if prefix_sum == goal:
                count += 1

            if prefix_sum - goal in hashmap:
                count += hashmap[prefix_sum - goal]
            
            hashmap[prefix_sum] = hashmap.get(prefix_sum, 0) + 1
        
        return count