class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        hashmap = {}
        for c in words[0]:
            if c not in hashmap:
                hashmap[c] = 1
            else:
                hashmap[c] += 1

        for word in words[1:]:
            temp = {}
            for c in word:
                if c not in temp:
                    temp[c] = 1
                else:
                    temp[c] += 1

            for key in hashmap.keys():
                if key not in temp:
                    hashmap[key] = 0
                else:
                    hashmap[key] = min(hashmap[key], temp[key])

        res = []
        for key in hashmap.keys():
            if hashmap[key] > 0:
                res.extend([key] * hashmap[key])

        return res