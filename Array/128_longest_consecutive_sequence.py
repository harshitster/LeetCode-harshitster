class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        ls = 0

        while nums:
            num = nums.pop()
            count, temp = 1, num + 1
            
            while temp in nums:
                nums.remove(temp)
                count += 1 
                temp += 1

            temp = num - 1
            while temp in nums:
                nums.remove(temp)
                count += 1
                temp -= 1

            ls = max(ls, count)

        return ls

# revised - 02/12/2025