class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        dp = [-1] * n

        def helper(start, bricks, ladders):         
            if start == n - 1:
                return start

            if dp[start] != -1:
                return dp[start]

            if heights[start] >= heights[start + 1]:
                dp[start] = helper(start + 1, bricks, ladders)
            else:
                if bricks == 0 and ladders == 0:
                    dp[start] = start
                elif bricks == 0:
                    dp[start] = helper(start + 1, bricks, ladders - 1)
                elif ladders == 0:
                    if heights[start + 1] - heights[start] > bricks:
                        dp[start] = start
                    else:
                        dp[start] = helper(start + 1, heights[start + 1] - heights[start], ladders)
                else:
                    if heights[start + 1] - heights[start] > bricks:
                        dp[start] = helper(start, bricks, ladders - 1)
                    else:
                        dp[start] = max(helper(start + 1, bricks, ladders - 1), helper(start + 1, heights[start + 1] - heights[start], ladders))

            return dp[start]

        return helper(0, bricks, ladders)