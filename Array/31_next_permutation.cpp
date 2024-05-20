class Solution {
private:
    void swap(vector<int>&nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void reverse(vector<int>& nums, int left, int right) {
        int i = left, j = right;

        while(i < j) {
            swap(nums, i, j);
            i += 1;
            j -= 1;
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;

        int break_point = -1;
        for(int i = n - 2; i >= 0; i -= 1) {
            if(nums[i] < nums[i + 1]) {
                break_point = i;
                break;
            }
        }

        if(break_point == -1) reverse(nums, 0, n - 1);
        else {
            int swap_idx;
            for(swap_idx = n - 1; swap_idx > break_point; swap_idx -= 1) {
                if(nums[swap_idx] > nums[break_point]) {
                    swap(nums, break_point, swap_idx);
                    break;
                }
            }
            reverse(nums, break_point + 1, n - 1);
        }
    }
};