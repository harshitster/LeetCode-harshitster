class Solution:
    def reorganizeString(self, s: str) -> str:
        hashmap = {}
        for i in range(len(s)):
            if s[i] not in hashmap:
                hashmap[s[i]] = 1
            else:
                hashmap[s[i]] += 1

        h = [[-count, char] for char, count in hashmap.items()]
        heapq.heapify(h)

        prev = None
        res = ""
        while h or prev:
            if prev and not h:
                return ""

            count, char = heapq.heappop(h)
            res += char
            count += 1

            if prev:
                heapq.heappush(h, prev)
                prev = None
            if count != 0:
                prev = [count, char]

        return res