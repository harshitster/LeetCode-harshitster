class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i += 1) nums[i] += nums[i - 1];
        return nums;
    }
};