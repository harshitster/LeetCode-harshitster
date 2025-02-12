class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dest = len(nums) - 1
        for i in range(dest - 1, -1, -1):
            if nums[i] + i >= dest:
                dest = i
        return dest == 0
    
# revised - 02/11/2025