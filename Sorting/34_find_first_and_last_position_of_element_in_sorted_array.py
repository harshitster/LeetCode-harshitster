class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def search(left, right, first):
            index = -1
            while left <= right:
                pivot = left + (right - left) // 2
                
                if nums[pivot] == target:
                    index = pivot
                    if first:
                        right = pivot - 1
                    else:
                        left = pivot + 1
                elif nums[pivot] > target:
                    right = pivot - 1
                else:
                    left = pivot + 1

            return index

        n = len(nums)
        return [search(0, n - 1, True), search(0, n - 1, False)]