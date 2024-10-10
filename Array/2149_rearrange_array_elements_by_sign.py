class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n

        pi, ni = 0, 1

        for num in nums:
            if num > 0:
                res[pi] = num
                pi += 2
            else:
                res[ni] = num
                ni += 2

        return res