class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = [0]
        for i in range(1, n + 1):
            mask = 1 << (i - 1)
            length = len(res)
            for j in range(length - 1, -1, -1):
                res.append(res[j] | mask)

        return res