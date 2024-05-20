class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = INT_MAX, max_diff = INT_MIN;

        for(int i = 0; i < prices.size(); i += 1) {
            if(min_buy > prices[i]) {
                min_buy = prices[i];
            } 

            max_diff = max(max_diff, prices[i] - min_buy);
            
        }

        return max_diff == INT_MIN ? 0 : max_diff;
    }
};