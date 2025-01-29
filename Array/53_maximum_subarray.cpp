class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0, max_sum = INT_MIN;

        for(int num: nums) {
            curr_sum = max(curr_sum, 0) + num;
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};

// revised - 01/28/2025