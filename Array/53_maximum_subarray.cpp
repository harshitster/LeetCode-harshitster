class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int max_sum = INT_MIN, curr_sum = 0;
    
            for(int i = 0; i < nums.size(); i += 1) {
                curr_sum = max(curr_sum, 0) + nums[i];
                max_sum = max(max_sum, curr_sum);
            }
    
            return max_sum;
        }
    };

// revised - 02/19/2025