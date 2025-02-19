class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        out = []

        def backtrack(e, s, index):
            if s >= target:
                if s == target:
                    out.append(e.copy())
                return

            for i in range(index, len(candidates)):
                e.append(candidates[i])
                backtrack(e, s + candidates[i], i)
                e.pop()

        backtrack([], 0, 0)
        return out
    
# revised - 02/18/2025