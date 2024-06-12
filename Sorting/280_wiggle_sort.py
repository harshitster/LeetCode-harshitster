class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)

        for i in range(0, n, 2):
            j, k = i + 1, i + 2

            if j < n and nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
            if k < n and nums[j] < nums[k]:
                nums[j], nums[k] = nums[k], nums[j]