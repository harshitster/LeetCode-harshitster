class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []
        for i in range(len(nums)):
            if stack and nums[stack[-1]] <= nums[i]:
                continue
            stack.append(i)

        max_width = 0
        for i in range(len(nums) - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[i]:
                max_width = max(max_width, i - stack[-1])
                stack.pop()

        return max_width
    
# revised - 02/21/2025