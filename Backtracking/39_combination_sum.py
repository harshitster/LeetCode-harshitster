class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        size = len(candidates)

        def backtrack(start_index=0, curr_sum=0, elements=[]):
            if curr_sum >= target:
                if curr_sum == target:
                    res.append(list(elements))
                return

            for i in range(start_index, size):
                elements.append(candidates[i])
                backtrack(i, curr_sum + candidates[i], elements)
                elements.pop()

        backtrack()
        return res