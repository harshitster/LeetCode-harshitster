class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest = 0
        nums = set(nums)

        while len(nums) > 0:
            count = 1
            num = nums.pop()

            temp = num + 1
            while temp in nums:
                count += 1
                nums.remove(temp)
                temp += 1

            temp = num - 1
            while temp in nums:
                count += 1
                nums.remove(temp)
                temp -= 1

            longest = max(longest, count)

        return longest
    
# revised - 02/25/2025