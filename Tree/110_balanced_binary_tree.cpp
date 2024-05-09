class Solution {
private:
    int helper(TreeNode* root, int* res) {
        if(*res == 1) {
            if(root == nullptr) return 0;

            int left = helper(root -> left, res);
            int right = helper(root -> right, res);
            
            if(abs(left - right) > 1) *res = 0;

            return max(left, right) + 1;
        }
        return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        int res = 1;
        helper(root, &res);
        return res == 1 ? true: false;
    }
};