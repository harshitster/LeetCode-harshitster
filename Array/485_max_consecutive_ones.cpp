class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_count = 0;

        for(int i = 0; i < nums.size(); i += 1) {
            if(nums[i] == 1){
                count += 1;
                max_count = max(max_count, count);
            } else {
                count = 0;
            }
        }

        return max_count;
    }
};