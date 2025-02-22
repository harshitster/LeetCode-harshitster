class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_deque = deque()
        min_deque = deque()
        left = 0
        longest = 0

        for right in range(len(nums)):
            if max_deque and left > max_deque[0]:
                max_deque.popleft()
            if min_deque and left > min_deque[0]:
                min_deque.popleft()

            while max_deque and nums[max_deque[-1]] <= nums[right]:
                max_deque.pop()
            max_deque.append(right)

            while min_deque and nums[min_deque[-1]] >= nums[right]:
                min_deque.pop()
            min_deque.append(right)

            if nums[max_deque[0]] - nums[min_deque[0]] > limit:
                left += 1
            else:
                longest = max(longest, right - left + 1)

        return longest