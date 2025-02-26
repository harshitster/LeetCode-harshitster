class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        hashmap = {}
        for word in words:
            hashmap[word] = hashmap.get(word, 0) + 1
        h = [(-count, word) for word, count in hashmap.items()]
        heapq.heapify(h)

        out = []
        while k != 0:
            out.append(heapq.heappop(h)[1])
            k -= 1

        return out