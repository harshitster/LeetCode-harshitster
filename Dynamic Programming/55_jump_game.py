class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dest = len(nums) - 1
        for i in range(dest - 1, -1, -1):
            if i + nums[i] >= dest:
                dest = i
        return dest == 0
    
# revised - 02/19/2025