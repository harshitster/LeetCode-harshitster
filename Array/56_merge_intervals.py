class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        out = [intervals[0]]

        for right in range(1, len(intervals)):
            if out[-1][1] >= intervals[right][0]:
                out[-1][1] = max(out[-1][1], intervals[right][1])
            else:
                out.append(intervals[right])

        return out

# 02/19/2025