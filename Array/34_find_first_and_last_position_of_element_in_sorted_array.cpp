class Solution {
private:
    int helper(vector<int>& nums, int target, int search, int left, int right) {
        int idx = -1;

        while(left <= right) {
            int pivot = left + (right - left) / 2;

            if(target < nums[pivot]) right = pivot - 1;
            else if(target > nums[pivot]) left = pivot + 1;
            else {
                idx = pivot;
                if(search == 0) right = pivot - 1;
                else left = pivot + 1;
            }
        }
        
        return idx;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int left = helper(nums, target, 0, 0, size - 1);
        if(left == -1) return {-1, -1};
        int right = helper(nums, target, 1, left, size - 1);
        return {left, right};
    }
};