class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        for string in strs:
            word = "".join(sorted(string))
            if word not in hashmap:
                hashmap[word] = [string]
            else:
                hashmap[word].append(string)

        out = []
        for k, val in hashmap.items():
            out.append(val)
        
        return out
    
# revised - 02/19/2025