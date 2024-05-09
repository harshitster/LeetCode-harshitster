class Solution {
private:
    TreeNode* helper(TreeNode* root) {
        if(root == nullptr) return nullptr;
        if(root -> left == nullptr && root -> right == nullptr) return root;

        TreeNode* left = helper(root -> left);
        TreeNode* right = helper(root -> right);
        root -> left = nullptr;
        root -> right = nullptr;

        left -> left = right;
        left -> right = root;
        return root;
    }
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        TreeNode* placeholder = root;
        while(placeholder -> left) placeholder = placeholder -> left;

        helper(root);
        return placeholder;
    }
};