class Solution {
private:
    int helper(TreeNode* root, int* diameter) {
        if(root == nullptr) return 0;

        int left = helper(root -> left, diameter);
        int right = helper(root -> right, diameter);
        int s = left + right;
        if(s > *diameter) *diameter = s;

        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, &diameter);
        return diameter;
    }
};