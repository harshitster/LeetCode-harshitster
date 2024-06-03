class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for(int i = 0; i < size; i += 1) {
            if(nums[i] < 0) nums[i] = 0;
        }

        for(int i = 0; i < size; i += 1) {
            int val = abs(nums[i]);
            if(val >= 1 && val <= size) {
                if(nums[val - 1] > 0) nums[val - 1] *= -1;
                else if(nums[val - 1] == 0) nums[val - 1] = (-1) * (size + 1);
            }
        }

        for(int num = 1; num < size + 1; num += 1) {
            if(nums[num - 1] >= 0) return num;
        }

        return size + 1;
    }
};