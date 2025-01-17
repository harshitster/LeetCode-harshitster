class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = m - 1; i >= 0; i -= 1) {
            for(int j = n - 1; j >= 0; j -= 1) {
                if(i == m - 1 || j == n - 1) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};

// Revised - 01/14/2025