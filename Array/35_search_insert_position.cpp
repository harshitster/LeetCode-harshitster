class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int pivot = left + (right - left) / 2;

            if(nums[pivot] == target) return pivot;
            else if(target < nums[pivot]) right = pivot - 1;
            else left = pivot + 1;
        }

        return left;
    }
};