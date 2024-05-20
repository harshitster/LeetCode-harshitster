class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, peak, valley;
        int i = 0, n = prices.size();

        while(i < n - 1) {
            while(i < n - 1 && prices[i] >= prices[i + 1]) {
                i += 1;
            }
            valley = prices[i];

            while(i < n - 1 && prices[i] <= prices[i + 1]) {
                i += 1;
            }
            peak = prices[i];

            profit += peak - valley;
        }

        return profit;
    }
};