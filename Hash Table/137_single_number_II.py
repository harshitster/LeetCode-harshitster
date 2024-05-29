class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hashmap = {}

        for num in nums:
            if num not in hashmap:
                hashmap[num] = 1
            else:
                hashmap[num] += 1
                if hashmap[num] == 3:
                    del hashmap[num]

        return list(hashmap.keys())[0]