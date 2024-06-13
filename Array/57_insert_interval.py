class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        def binary_search(left=0, right=n-1):
            while left <= right:
                pivot = left + (right - left) // 2

                if intervals[pivot][0] > newInterval[0]:
                    right = pivot - 1
                elif intervals[pivot][0] < newInterval[0]:
                    left = pivot + 1
                else:
                    return pivot

            return left

        output = []
        intervals.insert(binary_search(), newInterval)
        for i in range(n + 1):
            if not output or output[-1][1] < intervals[i][0]:
                output.append(intervals[i])
            else:
                output[-1][1] = max(output[-1][1], intervals[i][1])

        return output