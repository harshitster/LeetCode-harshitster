class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        return left >= right ? left + 1 : right + 1;
    }
};

// Revised - 01/08/2025