class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        hashmap = {}
        total_sum = 0
        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1
            total_sum += num

        outlier = float('-inf')
        for num in nums:
            po = total_sum - 2 * num

            if po in hashmap:
                if po != num or hashmap[po] > 1:
                    outlier = max(outlier, po)

        return outlier
    
# revised - 02/26/2025