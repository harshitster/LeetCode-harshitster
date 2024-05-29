class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        ni, nj = float("inf"), float("inf")
        for n in nums:
            if n <= ni:
                ni = n
            elif n <= nj:
                nj = n
            else:
                return True
        return False