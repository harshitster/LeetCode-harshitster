class Solution {
public:
    int rob(vector<int>& nums) {
        int one = 0, two = nums[0];

        for(int i = 1; i < nums.size(); i += 1) {
            int temp = two;
            two = max(two, nums[i] + one);
            one = temp;
        }

        return two;
    }
};

// revised - 02/03/2025