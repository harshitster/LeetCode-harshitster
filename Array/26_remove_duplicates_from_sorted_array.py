class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i, j = 0, 1
        n = len(nums)

        for j in range(1, n):
            if nums[i] == nums[j]:
                continue
            nums[i + 1] = nums[j]
            i += 1

        return i + 1
