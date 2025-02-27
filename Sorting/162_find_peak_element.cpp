class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int left = 0, right = nums.size() - 1;
    
            while(left < right) {
                int pivot = left + (right - left) / 2;
    
                if(nums[pivot] <= nums[pivot + 1]) left = pivot + 1;
                else right = pivot;
            }
    
            return left;
        }
    };