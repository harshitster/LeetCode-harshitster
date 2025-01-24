class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;

        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        for(int i = 0; i < 4; i += 1) {
            int j = n - 4 + i;
            min_diff = min(min_diff, nums[j] - nums[i]);
        }

        return min_diff;
    }
};