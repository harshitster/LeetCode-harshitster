class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n1, n2 = len(nums1), len(nums2)
        if n1 <= n2:
            ac = nums1
            ref = nums2
        else:
            ac = nums2
            ref = nums1

        hashmap = {}
        for num in ac:
            if num not in hashmap:
                hashmap[num] = 1
            else:
                hashmap[num] += 1

        res = []
        for num in ref:
            if num in hashmap:
                res.append(num)
                hashmap[num] -= 1

                if hashmap[num] == 0:
                    del hashmap[num]

        return res