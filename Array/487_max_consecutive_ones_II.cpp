class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int last_idx = -1, count = 0;
        int max_count = INT_MIN;

        for(int i = 0; i < nums.size(); i += 1) {
            if(nums[i] == 0) {
                if(last_idx != -1) count = i - last_idx - 1;
                last_idx = i;
            }
            count += 1;

            max_count = max(max_count, count);
        }

        return max_count;
    }
};