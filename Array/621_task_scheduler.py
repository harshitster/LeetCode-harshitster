class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        hashmap = {}
        for task in tasks:
            hashmap[task] = hashmap.get(task, 0) + 1
        
        h = [(-cnt, task) for task, cnt in hashmap.items()]
        heapq.heapify(h)
        queue = []
        time = 0
        
        while h or queue:
            time += 1
            
            if h:
                cnt, task = heapq.heappop(h)
                cnt += 1 
                if cnt != 0:
                    queue.append((cnt, task, time + n))
            
            if queue and queue[0][2] <= time:
                cnt, task, _ = queue.pop(0)
                heapq.heappush(h, (cnt, task))
        
        return time