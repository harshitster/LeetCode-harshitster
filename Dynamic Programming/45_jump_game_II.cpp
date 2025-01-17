class Solution {
public:
    int jump(vector<int>& nums) {
        int window = 0, limit = 0, jumps = 0, n = nums.size();
        if(n == 1) return 0;

        for(int i = 0; i < n ; i += 1) {
            window = max(window, i + nums[i]);
            if(i == limit) {
                limit = window;
                jumps += 1;

                if(limit >= n - 1) return jumps;
            }
        }

        return jumps;
    }
};