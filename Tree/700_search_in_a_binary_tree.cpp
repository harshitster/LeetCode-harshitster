class Solution {
private:
    void helper(TreeNode* root, TreeNode** res, int val) {
        if(*res == nullptr) {
            if(root == nullptr) return;
            if(root -> val == val) {
                *res = root;
                return;
            }

            helper(root -> left, res, val);
            helper(root -> right, res, val);
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = nullptr;
        helper(root, &res, val);
        return res;
    }
};