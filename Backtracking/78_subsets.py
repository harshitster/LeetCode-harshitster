class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        out = []

        def backtrack(start_index, e):
            out.append(e.copy())

            for i in range(start_index, len(nums)):
                e.append(nums[i])
                backtrack(i + 1, e)
                e.pop()

        backtrack(0, [])
        return out
    
# revised - 02/19/2025