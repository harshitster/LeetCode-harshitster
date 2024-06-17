class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        c, n = 1, len(digits)
        i = n - 1
        
        while i >= 0 and c == 1:
            digits[i] += c
            if digits[i] > 9:
                digits[i] = 0
                c = 1
            else:
                c = 0
            i -= 1

        if c == 1:
            digits.insert(0, 1)

        return digits