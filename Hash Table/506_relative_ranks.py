class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        hashmap = {}
        n = len(score)
        for i in range(n):
            hashmap[score[i]] = i

        score = sorted(score, reverse=True)
        res = ['' for _ in range(n)]

        for i in range(n):
            if i >= 3:
                res[hashmap[score[i]]] = str(i + 1)
            if i == 0:
                res[hashmap[score[i]]] = "Gold Medal"
            if i == 1:
                res[hashmap[score[i]]] = "Silver Medal"
            if i == 2:
                res[hashmap[score[i]]] = "Bronze Medal"

        return res