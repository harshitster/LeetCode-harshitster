class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        hashmap = {}
        prefix_sum = 0
        max_len = 0

        for i in range(len(nums)):
            prefix_sum += 1 if nums[i] == 0 else -1

            if prefix_sum == 0:
                max_len = max(max_len, i + 1)
            else:
                if prefix_sum in hashmap:
                    max_len = max(max_len, i - hashmap[prefix_sum])
                else:
                    hashmap[prefix_sum] = i

        return max_len