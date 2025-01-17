class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, curr_sum = 0;

        for(int i = 0; i < nums.size(); i += 1) {
            curr_sum = max(0, curr_sum) + nums[i];
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;
    }
};

// Revised - 01/14/2025