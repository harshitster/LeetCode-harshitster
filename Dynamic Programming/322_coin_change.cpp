class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i < amount + 1; i += 1) {
            for(int coin: coins) {
                if(i - coin < 0) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};

// revised - 02/13/2025