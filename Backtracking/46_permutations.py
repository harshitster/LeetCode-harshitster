class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        output = list()

        def backtrack(start_index):
            if start_index == n:
                output.append(nums[:])
                return

            for i in range(start_index, n):
                nums[start_index], nums[i] = nums[i], nums[start_index]
                backtrack(start_index + 1)
                nums[start_index], nums[i] = nums[i], nums[start_index]

        backtrack(0)
        return output