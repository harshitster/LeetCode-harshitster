class Solution {
private:
    int helper(vector<int>& nums, int left, int right) {
        int one = 0, two = nums[left];
        for(int i = left + 1; i < right; i += 1) {
            int temp = two;
            two = max(one + nums[i], two);
            one = temp;
        }

        return two;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
};

// revised - 01/28/2025