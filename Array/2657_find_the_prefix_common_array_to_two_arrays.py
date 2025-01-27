class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        map1, map2 = {}, {}
        res = [0] * len(A)

        for i in range(len(A)):
            map1[A[i]] = map1.get(A[i], 0) + 1
            map2[B[i]] = map2.get(B[i], 0) + 1

            if A[i] in map2 and map1[A[i]] == map2[A[i]]:
                res[i] += 1

            if A[i] != B[i] and B[i] in map1 and map1[B[i]] == map2[B[i]]:
                res[i] += 1

            if i > 0:
                res[i] += res[i - 1]

        return res