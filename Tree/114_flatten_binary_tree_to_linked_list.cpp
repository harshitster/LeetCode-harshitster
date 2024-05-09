class Solution {
private:
    TreeNode* helper(TreeNode* root) {
        if(root == nullptr) return nullptr;

        helper(root -> left);
        helper(root -> right);

        if(root -> right == nullptr) {
            root -> right = root -> left;
            root -> left = nullptr;
        }
        else {
            if(root -> left) {
                TreeNode* temp = root -> left;
                while(temp -> right) temp = temp -> right;

                temp -> right = root -> right;
                root -> right = root -> left;
                root -> left = nullptr;
            }
        }

        return root;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};