class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        x = minutes / 60
        y = hour % 12 * 5 + x * 5
        res = abs(y - minutes) * 6
        return min(360 - res, res)