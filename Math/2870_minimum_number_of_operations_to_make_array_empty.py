class Solution:
    def minOperations(self, nums: List[int]) -> int:
        counts = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        
        ops = 0
        for num, count in counts.items():
            if count == 1:
                return -1

            ops += (count + 2) // 3

        return ops