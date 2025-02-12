class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int min_buy = INT_MAX, max_profit = INT_MIN;
    
            for(int i = 0; i < prices.size(); i += 1) {
                min_buy = min(min_buy, prices[i]);
                max_profit = max(max_profit, prices[i] - min_buy);
            }
    
            return max_profit;
        }
    };

// revised - 02/11/2025