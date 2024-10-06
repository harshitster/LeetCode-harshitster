class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1_len, s2_len, s3_len = len(s1), len(s2), len(s3)
        if s1_len + s2_len != s3_len:
            return False

        dp = [[False for _ in range(s2_len + 1)] for _ in range(s1_len + 1)]
        dp[s1_len][s2_len] = True

        for i in range(s1_len, -1, -1):
            for j in range(s2_len, -1, -1):
                if i < s1_len and s1[i] == s3[i + j] and dp[i + 1][j]:
                    dp[i][j] = True
                if j < s2_len and s2[j] == s3[i + j] and dp[i][j + 1]:
                    dp[i][j] = True

        return dp[0][0]