class Solution:
    def heapify(self, nums, n, i):
        largest = i

        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and nums[i] < nums[left]:
            largest = left
        if right < n and nums[largest] < nums[right]:
            largest = right

        if largest != i:
            nums[i], nums[largest] = nums[largest], nums[i]
            self.heapify(nums, n, largest)

    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        for i in range(n // 2, -1, -1):
            self.heapify(nums, n, i)

        for i in range(n - 1, 0, -1):
            nums[i], nums[0] = nums[0], nums[i]
            self.heapify(nums, i, 0)

        return nums