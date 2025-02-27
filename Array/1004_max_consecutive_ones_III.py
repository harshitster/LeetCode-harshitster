class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        longest, left = 0, 0

        for right in range(len(nums)):
            if nums[right] == 0:
                k -= 1

            while k < 0:
                if nums[left] == 0:
                    k += 1
                left += 1

            longest = max(longest, right - left + 1)

        return longest
    
# revised - 02/26/2025