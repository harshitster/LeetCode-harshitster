class Solution {
private:
    void helper(TreeNode* root, int prev, int* max_path, int path) {
        if(root == nullptr) return;

        if(root -> val == prev + 1) path += 1;
        else path = 1;
        if(path > *max_path) *max_path = path;

        helper(root -> left, root -> val, max_path, path);
        helper(root -> right, root -> val, max_path, path);
    }
public:
    int longestConsecutive(TreeNode* root) {
        int prev = root -> val - 1;
        int max_path = 0;
        helper(root, prev, &max_path, 0);

        return max_path;
    }
};