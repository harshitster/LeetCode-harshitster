class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}

        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1
        
        el = sorted([(k, v) for k, v in hashmap.items()], key=lambda x: x[1], reverse=True)
        el = el[:k]

        return [k for k, v in el]
    
# Better Approach = Heap - Must with CPP