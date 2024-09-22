class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        elif n == 2:
            return k * k
            
        two, one = k, k * k

        for i in range(n - 2):
            temp = one
            one = (k - 1) * (one + two)
            two = temp

        return one
