class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        hashmap = {}

        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1

        index = 0
        for i in range(3):
            for j in range(hashmap.get(i, 0)):
                nums[index] = i
                index += 1

# revise - 02/19/2025