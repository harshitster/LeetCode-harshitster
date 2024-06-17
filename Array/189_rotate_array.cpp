class Solution {
private:
    void helper(vector<int>& nums, int left, int right) {
        while(left < right) {
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;

            right -= 1;
            left += 1;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        helper(nums, 0, n - 1);
        helper(nums, 0, k - 1);
        helper(nums, k, n - 1);
    }
};