class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        def binary_search(seq, num):
            left, right = 0, len(seq) - 1
            while left <= right:
                pivot = left + (right - left) // 2

                if seq[pivot] < num:
                    left = pivot + 1
                else:
                    right = pivot - 1

            return left

        seq = [nums[0]]
        for num in nums[1:]:
            if num > seq[-1]:
                seq.append(num)
            else:
                i = binary_search(seq, num)
                seq[i] = num

        return len(seq)