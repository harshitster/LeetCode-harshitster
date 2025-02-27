class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            pivot = left + (right - left) // 2
            left_part = pivot - left
            right_part = right - pivot

            if nums[pivot] == nums[pivot - 1]:
                left_part += 1
            elif nums[pivot] == nums[pivot + 1]:
                right_part += 1
            else:
                return nums[pivot]

            if left_part % 2 == 0:
                left = pivot + 1
                if nums[pivot] == nums[left]:
                    left += 1
            elif right_part % 2 == 0:
                right = pivot - 1
                if nums[pivot] == nums[right]:
                    right -= 1
            
        return nums[left]