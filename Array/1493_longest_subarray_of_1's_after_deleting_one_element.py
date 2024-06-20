class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0 
        k = 1
        l = 0
        
        for right in range(len(nums)):
            if(nums[right] == 0):
                while k == 0:
                    if nums[left] == 0:
                        k += 1
                    left += 1
                k -= 1
            
            l = max(l, right - left + 1)
                
        return l - 1