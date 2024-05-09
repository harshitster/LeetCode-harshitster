class Solution:
    def jump(self, nums: List[int]) -> int:
        n, window, jumps, limit = len(nums), 0, 0, 0
        if n == 1:
            return 0

        for i in range(n):
            window = max(window, i + nums[i])
            if i == limit:
                limit = window
                jumps += 1

                if window >= n - 1:
                    return jumps

        return jumps