class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int prefix_sum = 0, left = 0, min_length = INT_MAX;

        for(int right = 0; right < nums.size(); right += 1) {
            if(nums[right] >= target) return 1;

            prefix_sum += nums[right];
            while(prefix_sum >= target) {
                min_length = min(min_length, right - left + 1);
                prefix_sum -= nums[left++];
            }
        }

        return min_length != INT_MAX ? min_length : 0;
    }
};

