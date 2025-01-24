class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int right_sum = 0, n = nums.size();
        for(int i = 0; i < n; i += 1) right_sum += nums[i];

        long long int left_sum = 0, i = 0;
        int count = 0;
        while(i < n - 1) {
            left_sum += nums[i];
            right_sum -= nums[i];

            if(left_sum >= right_sum) count += 1;
            i += 1;
        }

        return count;
    }
};
