class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr) - 1
        
        while l < r:
            pivot = (l + r) // 2

            if arr[pivot] < arr[pivot + 1]:
                l = pivot + 1
            else:
                r = pivot

        return l