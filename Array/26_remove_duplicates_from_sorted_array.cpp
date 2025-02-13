class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int left = 1;
    
            for(int right = 1; right < nums.size(); right += 1) {
                if(nums[right] != nums[right - 1]) {
                    nums[left++] = nums[right];
                }
            }
    
            return left;
        }
    };

// revised - 02/12/2025