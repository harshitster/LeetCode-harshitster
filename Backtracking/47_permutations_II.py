class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        out, perm = [], []
        hashmap = {}
        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1

        def backtrack():
            if len(perm) == len(nums):
                out.append(perm.copy())
                return

            for num in hashmap:
                if hashmap[num] > 0:
                    perm.append(num)
                    hashmap[num] -= 1
                    backtrack()
                    hashmap[num] += 1
                    perm.pop()

        backtrack()
        return out