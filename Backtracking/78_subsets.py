class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        n = len(nums)

        def backtrack(start_index, elements, size, e_size): 
            if size == e_size:
                res.append(list(elements))
                return

            for i in range(start_index, n):
                elements.append(nums[i])
                backtrack(i + 1, elements, size, e_size + 1)
                elements.pop()

        for i in range(1, n + 1):
            backtrack(0, [], i, 0)

        return res