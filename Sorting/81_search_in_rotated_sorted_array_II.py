class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1

        while left <= right:
            pivot = left + (right - left) // 2

            if nums[pivot] == target:
                return True

            if nums[left] < nums[pivot]:
                if nums[left] <= target < nums[pivot]:
                    right = pivot - 1
                else:
                    left = pivot + 1
            elif nums[left] > nums[pivot]:
                if nums[pivot] < target <= nums[right]:
                    left = pivot + 1
                else:
                    right = pivot - 1
            else:
                left += 1

        return False