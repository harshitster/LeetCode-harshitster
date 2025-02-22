class Solution {
    public:
        int triangularSum(vector<int>& nums) {
            int length = nums.size();
    
            while(length != 1) {
                for(int i = 0; i < length - 1; i += 1) {
                    nums[i] = (nums[i] + nums[i + 1]) % 10;
                }
                length -= 1;
            }
    
            return nums[0];
        }
    };