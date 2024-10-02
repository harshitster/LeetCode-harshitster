class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        hashmap = {i: [] for i in range(len(s))}
        dp = [False] * (len(s) + 1)
        dp[len(s)] = True

        for i in range(len(s) - 1, -1, -1):
            for word in wordDict:
                match = False
                if i + len(word) <= len(s) and s[i: i + len(word)] == word:
                    match = True
                    dp[i] = dp[i] or dp[i + len(word)]
                if match:
                    hashmap[i].append(i + len(word))

        if not dp[0]:
            return []

        res = []

        def dfs(index, string):
            if index == len(s):
                res.append(" ".join(string))
                return

            for next_index in hashmap[index]:
                if dp[next_index]:
                    string.append(s[index: next_index])
                    dfs(next_index, string)
                    string.pop()

        dfs(0, [])

        return res