class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int i = 0, n = prices.size();
            int v, p;
            int profit = 0;
    
            while(i < n - 1) {
                while(i < n - 1 && prices[i] >= prices[i + 1]) i += 1;
                v = prices[i];
    
                while(i < n - 1 && prices[i] <= prices[i + 1]) i += 1;
                p = prices[i];
    
                profit += (p - v);
            }
    
            return profit;
        }
    };

// Revised - 02/11/2025