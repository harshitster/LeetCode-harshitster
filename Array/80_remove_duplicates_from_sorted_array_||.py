class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i, count = 1, 1
        n = len(nums)

        for j in range(1, n):
            if nums[j] == nums[j - 1]:
                count += 1
            else:
                count = 1

            if count <= 2:
                nums[i] = nums[j]
                i += 1

        return i