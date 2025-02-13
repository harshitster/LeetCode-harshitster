class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        l = r = 0
        out = []

        while r < len(nums):
            if q and l > q[0]:
                q.popleft()

            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)

            if (r + 1) >= k:
                out.append(nums[q[0]])
                l += 1

            r += 1

        return out

# revised - 02/12/2025