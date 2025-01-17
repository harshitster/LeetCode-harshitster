class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i = 0; i < n1 + 1; i += 1) {
            for(int j = 0; j < n2 + 1; j += 1) {
                if(i == 0 && j == 0) continue;
                else if(i == 0) dp[i][j] = dp[i][j - 1] + 1;
                else if(j == 0) dp[i][j] = dp[i - 1][j] + 1;
                else {
                    if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                }
            }
        }

        return dp[n1][n2];
    }
};