class Solution:
    def partition(self, s: str) -> List[List[str]]:
        length = len(s)
        dp = [[False] * length for _ in range(length)]
        res = []

        def backtrack(s, dp, res, start, rl):
            if start >= length:
                res.append(list(rl))
                return

            for end in range(start, length):
                if s[start] == s[end] and (end - start <= 2 or dp[start + 1][end - 1]):
                    rl.append(s[start:end + 1])
                    dp[start][end] = True
                    backtrack(s, dp, res, end + 1, rl)
                    rl.pop()

        backtrack(s, dp, res, 0, [])
        return res