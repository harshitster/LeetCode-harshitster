class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        left, right = 0, n - 1
        res = -1

        while left < right:
            pivot = left + (right - left) // 2

            lw, rw = pivot - left, right - pivot
            if nums[pivot - 1] == nums[pivot]:
                lw += 1
            elif nums[pivot + 1] == nums[pivot]:
                rw += 1
            else:
                return nums[pivot]
       

            if lw % 2 == 0:
                left = pivot + 1
                if nums[left] == nums[pivot]:
                    left += 1
            else:
                right = pivot - 1
                if nums[right] == nums[pivot]:
                    right -= 1

        return nums[left]