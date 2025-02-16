class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        hashmap = {nums[0]: 0}
        max_sum = float('-inf')
        prefix_sum = nums[0]

        for i in range(1, len(nums)):
            if nums[i] - k in hashmap:
                max_sum = max(max_sum, (prefix_sum + nums[i]) - hashmap[nums[i] - k])
            if nums[i] + k in hashmap:
                max_sum = max(max_sum, (prefix_sum + nums[i]) - hashmap[nums[i] + k])

            if nums[i] in hashmap:
                hashmap[nums[i]] = min(hashmap[nums[i]], prefix_sum)
            else:
                hashmap[nums[i]] = prefix_sum
            prefix_sum += nums[i]

        return max_sum if max_sum != float('-inf') else 0