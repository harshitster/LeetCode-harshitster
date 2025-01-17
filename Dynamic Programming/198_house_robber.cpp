class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int one = nums[0], two = max(nums[0], nums[1]);
        for(int i = 2; i < n; i += 1) {
            int temp = two;
            two = max(two, one + nums[i]);
            one = temp;
        }

        return two;
    }
};