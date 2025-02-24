class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return n

        pos = 1
        neg = 1
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                pos = neg + 1
            elif nums[i] < nums[i - 1]:
                neg = pos + 1
        
        return max(pos, neg)