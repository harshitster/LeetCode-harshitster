class Solution {
    public:
        int jump(vector<int>& nums) {
            int jumps = 0, limit = 0, window = 0;
    
            for(int i = 0; i < nums.size() - 1; i += 1) {
                if(i + nums[i] > window) {
                    window = i + nums[i];
                }
    
                if(i == limit) {
                    limit = window;
                    jumps += 1;
                }
            }
    
            return jumps;
        }
    };

// revised - 02/26/2025