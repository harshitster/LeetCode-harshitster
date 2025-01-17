class Solution {
private:
    int helper(vector<int>& nums, int i, int j) {
        if(j - i == 0) return nums[i];

        int one = nums[i], two = max(nums[i], nums[i + 1]);
        for(int k = i + 2; k < j + 1; k += 1) {
            int temp = two;
            two = max(two, one + nums[k]);
            one = temp;
        }

        return two;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};