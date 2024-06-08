class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        def helper(array1, array2):
            n1, n2 = len(array1), len(array2)
            i, j = 0, 0
            res = []

            while i < n1 and j < n2:
                if array1[i] == array2[j]:
                    res.append(array1[i])
                    i += 1
                    j += 1
                elif array1[i] < array2[j]:
                    i += 1
                else:
                    j += 1

            return res

        res = None
        for i in range(len(arrays) - 1):
            res = helper(res if res is not None else arrays[i], arrays[i + 1])
            if len(res) == 0:
                return []

        return res