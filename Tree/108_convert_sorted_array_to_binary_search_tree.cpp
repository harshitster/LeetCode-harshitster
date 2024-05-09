class Solution {
private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;

        int pivot = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[pivot]);
        root -> left = helper(nums, left, pivot - 1);
        root -> right = helper(nums, pivot + 1, right);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};