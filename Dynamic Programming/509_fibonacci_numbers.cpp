class Solution {
private:
    int helper(vector<int>& dp, int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];
        else dp[n] = helper(dp, n - 1) + helper(dp, n - 2);

        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return helper(dp, n);
    }
};