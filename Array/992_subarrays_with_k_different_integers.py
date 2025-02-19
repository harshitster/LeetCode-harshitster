class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        hashmap = {}
        l_far, l_near = 0, 0
        count = 0

        for right in range(len(nums)):
            hashmap[nums[right]] = hashmap.get(nums[right], 0) + 1

            while len(hashmap) > k:
                hashmap[nums[l_near]] -= 1
                if hashmap[nums[l_near]] == 0:
                    del hashmap[nums[l_near]]
                l_near += 1
                l_far = l_near

            while hashmap[nums[l_near]] > 1:
                hashmap[nums[l_near]] -= 1
                l_near += 1

            if len(hashmap) == k:
                count += (l_near - l_far + 1)

        return count