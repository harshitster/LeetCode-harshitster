class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int length = 0, max_length = 0, left = 0;
        int k = 1;

        for(int right = 0; right < nums.size(); right += 1) {
            if(nums[right] == 0) {
                while(k == 0) {
                    length -= 1;
                    if(nums[left++] == 0) k += 1;
                }
                k -= 1;
            }
            length += 1;
            max_length = max(max_length, length);
        }

        return max_length;
    }
};