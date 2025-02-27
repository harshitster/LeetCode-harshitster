class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hashmap = {}
        prefix_sum = 0
        count = 0

        for num in nums:
            prefix_sum += num

            if prefix_sum == k:
                count += 1
            if prefix_sum - k in hashmap:
                count += hashmap[prefix_sum - k]

            hashmap[prefix_sum] = hashmap.get(prefix_sum, 0) + 1

        return count
        

# revised - 02/26/2025