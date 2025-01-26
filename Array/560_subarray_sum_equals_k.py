class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_counts = {0: 1} 
        curr_sum = count = 0
        
        for num in nums:
            curr_sum += num
            count += prefix_counts.get(curr_sum - k, 0)
            prefix_counts[curr_sum] = prefix_counts.get(curr_sum, 0) + 1
            
        return count