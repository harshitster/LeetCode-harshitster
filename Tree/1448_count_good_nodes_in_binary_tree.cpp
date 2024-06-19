class Solution {
private:
    void helper(TreeNode* root, int* count, int max_val) {
        if(root == nullptr) return;

        if(root -> val >= max_val) (*count) += 1;
        helper(root -> left, count, max(max_val, root -> val));
        helper(root -> right, count, max(max_val, root -> val));
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        helper(root, &count, INT_MIN);
        return count;
    }
};