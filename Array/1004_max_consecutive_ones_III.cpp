class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, count = 0, max_count = 0;

        for(int right = 0; right < nums.size(); right += 1) {
            if(nums[right] == 0) {
                k -= 1;

                while(k < 0) {
                    if(nums[left] == 0) k += 1;
                    left += 1;
                    count -= 1;
                }
            }
            count += 1;
            max_count = max(max_count, count);
        }

        return max_count;
    }
};