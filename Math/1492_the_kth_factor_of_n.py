class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        if k == 1:
            return 1
        k -= 1

        for i in range(2, n // 2 + 1):
            if n % i == 0:
                k -= 1      
                if k == 0:
                    return i

        if k == 1:
            return n

        return -1
    
# revised - 02/19/2025