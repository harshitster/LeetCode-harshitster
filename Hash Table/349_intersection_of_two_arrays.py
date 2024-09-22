class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n1, n2 = len(nums1), len(nums2)
        if n1 <= n2:
            ac = nums1
            ref = nums2
        else:
            ac = nums2
            ref = nums1

        hashmap = {}
        for num in ac:
            hashmap[num] = 1

        res = []
        for num in ref:
            if num in hashmap:
                res.append(num)
                del hashmap[num]

        return res