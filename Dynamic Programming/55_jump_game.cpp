class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dest = n - 1;

        for(int i = dest - 1; i >= 0; i -= 1) {
            if(i + nums[i] >= dest) dest = i;
        }

        return dest == 0;
    }
};

// Revised - 01/06/2025