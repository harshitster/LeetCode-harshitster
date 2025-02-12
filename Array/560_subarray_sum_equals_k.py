class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum, count, hashmap = 0, 0, {}

        for num in nums:
            prefix_sum += num
            r = prefix_sum - k

            if r == 0:
                count += 1
            if r in hashmap:
                count += hashmap[r]

            hashmap[prefix_sum] = hashmap.get(prefix_sum, 0) + 1

        return count
        

# revised - 02/11/2025