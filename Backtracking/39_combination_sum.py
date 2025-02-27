class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        out = []

        def backtrack(i, part, s):
            if s >= target:
                if s == target:
                    out.append(part.copy())
                return

            for j in range(i, len(candidates)):
                part.append(candidates[j])
                backtrack(j, part, s + candidates[j])
                part.pop()

        backtrack(0, [], 0)
        return out
    
# revised - 02/26/2025