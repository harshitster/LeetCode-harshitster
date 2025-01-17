class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        map1, map2 = set(), set()
        
        for i in range(len(s) - 9):
            temp = s[i:i + 10]
            if temp in map2:
                map1.add(temp)
            map2.add(temp)

        return list(map1)
