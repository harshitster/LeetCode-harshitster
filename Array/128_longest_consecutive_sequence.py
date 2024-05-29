class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        count = 0

        while nums:
            num = nums.pop()

            left = num - 1
            while left in nums:
                nums.remove(left)
                left -= 1

            right = num + 1
            while right in nums:
                nums.remove(right)
                right += 1

            count = max(count, right - left - 1)
        
        return count