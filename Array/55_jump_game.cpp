class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;

        for(int i = target - 1; i >= 0; i -= 1) {
            if(i + nums[i] >= target) target = i;
        }

        return target == 0;
    }
};