class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX, sum = 0;
        for(int i = 0; i < n - 2; i += 1) {
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if(abs(target - s) < min_diff) {
                    min_diff = abs(target - s);
                    sum = s;
                }
                if(s < target) j += 1;
                else k -= 1;
            }
        }

        return sum;
    }
};
