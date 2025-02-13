class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        hashmap = {}
        total = 0
        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1
            total += num

        out = float('-inf')
        for num in nums:
            pc = total - 2 * num

            if pc in hashmap:
                if pc != num or hashmap[pc] > 1:
                    out = max(out, pc)

        return out
