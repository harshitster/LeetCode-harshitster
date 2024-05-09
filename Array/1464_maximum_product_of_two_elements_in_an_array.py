class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        highest, second_highest = -1, -1
        for num in nums:
            if num > highest:
                second_highest = highest
                highest = num
            else:
                second_highest = max(second_highest, num)

        return (highest - 1) * (second_highest - 1)