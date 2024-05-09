class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness = sorted(happiness, reverse=True)
        res = 0

        for i in range(min(len(happiness), k)):
            if happiness[i] - i <= 0:
                break
            res += (happiness[i] - i)

        return res