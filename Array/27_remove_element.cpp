class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int replace_index = 0;
        for(int i = 0; i < nums.size(); i += 1) {
            if(val != nums[i]) nums[replace_index++] = nums[i];
        }

        return replace_index;
    }
};