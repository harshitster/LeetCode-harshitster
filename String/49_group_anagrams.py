class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        for s in strs:
            k = "".join(sorted(s))
            if k in hashmap:
                hashmap[k].append(s)
            else:
                hashmap[k] = [s]

        return [val for k, val in hashmap.items()]
    
# revised - 02/26/2025