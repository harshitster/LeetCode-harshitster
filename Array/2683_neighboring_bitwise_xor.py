class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        first, num = 0, 0
        n = len(derived)
        for i in range(n - 1):
            if num ^ 0 == derived[i]:
                num = 0
            elif num ^ 1 == derived[i]:
                num = 1
            else:
                return False

        if first ^ num != derived[n - 1]:
            return False

        return True