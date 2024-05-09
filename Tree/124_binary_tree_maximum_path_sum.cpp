class Solution {
private:
    int helper(TreeNode* root, int* val) {
        if(root == nullptr) return 0;

        int left = helper(root -> left, val) + root -> val;
        int right = helper(root -> right, val) + root -> val;
        int temp = left + right - root -> val;

        if(*val < root -> val) *val = root -> val;
        if(*val < left) *val = left;
        if(*val < right) *val = right;
        if(*val < temp) *val = temp;

        return max(root -> val, max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        helper(root, &val);
        return val;
    }
};