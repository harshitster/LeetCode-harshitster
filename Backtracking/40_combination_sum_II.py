class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        size = len(candidates)
        candidates = sorted(candidates)

        def backtrack(start_index, curr_sum, elements): 
            if curr_sum >= target:
                if curr_sum == target:
                    res.append(list(elements))
                return

            for i in range(start_index, size):
                if i > start_index and candidates[i] == candidates[i - 1]:
                    continue

                elements.append(candidates[i])
                backtrack(i + 1, curr_sum + candidates[i], elements)
                elements.pop()

        backtrack(0, 0, [])
        return list(res)