class Solution {
private:
    void helper(TreeNode* root, int* val) {
        if(root == nullptr) return;

        helper(root -> right, val);
        root -> val += *val;
        *val = root -> val;
        helper(root -> left, val);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        helper(root, &val);

        return root;
    }
};