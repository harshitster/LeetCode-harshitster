class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        hashmap = {}
        prefix_sum = 0
        max_len = 0

        for i in range(len(nums)):
            if nums[i] == k:
                max_len = max(max_len, 1)

            prefix_sum += nums[i]
            if prefix_sum == k:
                max_len = max(max_len, i + 1)

            rem = prefix_sum - k

            if rem in hashmap:
                max_len = max(max_len, i - hashmap[rem])
            else:
                if prefix_sum not in hashmap:
                    hashmap[prefix_sum] = i

        return max_len 