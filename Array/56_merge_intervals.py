class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        left, length = 0, len(intervals)

        for right in range(1, length):
            while right < length and intervals[left][1] >= intervals[right][0]:
                intervals[left][1] = max(intervals[left][1], intervals[right][1])
                intervals.pop(right)
                length -= 1
            left += 1

        return intervals

# 02/11/2025