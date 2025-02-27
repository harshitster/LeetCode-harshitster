class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        hashmap = {}
        prefix_sum = 0
        longest = 0

        for i in range(len(nums)):
            prefix_sum += 1 if nums[i] == 1 else -1

            if prefix_sum == 0:
                longest = i + 1
            else:
                if prefix_sum in hashmap:
                    longest = max(longest, i - hashmap[prefix_sum])
                else:
                    hashmap[prefix_sum] = i

        return longest
    
# revised - 02/26/2025