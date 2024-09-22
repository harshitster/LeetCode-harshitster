class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        nums.insert(0, 0)

        for i in range(1, len(nums)):
            num = abs(nums[i])
            if nums[num] < 0:
                res.append(num)
            else:
                nums[num] *= -1

        return res