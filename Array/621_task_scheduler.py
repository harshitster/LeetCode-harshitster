class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        hashmap = {}
        for task in tasks:
            hashmap[task] = hashmap.get(task, 0) + 1    
        heap = [(-count, task) for task, count in hashmap.items()]
        heapq.heapify(heap)

        queue = []
        time = 0

        while heap or queue:
            if heap:
                count, task = heapq.heappop(heap)
                count += 1

                if count != 0:
                    queue.append((count, task, time + n))

            if queue and queue[0][2] <= time:
                count, task, _ = queue.pop(0)
                heapq.heappush(heap, (count, task))

            time += 1

        return time
    
# revised - 02/19/2025