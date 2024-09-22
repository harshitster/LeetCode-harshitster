class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)

        for i in range(n):
            num = abs(nums[i]) - 1
            if nums[num] > 0:
                nums[num] *= -1

        res = []
        for i in range(n):
            if nums[i] > 0:
                res.append(i + 1)
        return res
