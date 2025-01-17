class Solution {
private:
    void helper(TreeNode* root, int targetSum, int run_sum, int* res) {
        if(*res == 0) {
            if(root == nullptr) return;
        
            if(root -> left == nullptr && root -> right == nullptr) {
                if(run_sum + root -> val == targetSum) *res = 1;
                return;
            }
            helper(root -> left, targetSum, run_sum + root -> val, res);
            helper(root -> right, targetSum, run_sum + root -> val, res);
        } 
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int res = 0;
        helper(root, targetSum, 0, &res);
        return res == 1 ? true : false;
    }
};

// Revised - 01/08/2025