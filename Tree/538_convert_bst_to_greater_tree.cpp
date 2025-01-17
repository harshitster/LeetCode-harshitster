/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, TreeNode** prev) {
        if(root == nullptr) return;

        helper(root -> right, prev);
        root -> val += (*prev) -> val;
        *prev = root;
        helper(root -> left, prev);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* prev = new TreeNode(0);
        helper(root, &prev);

        return root;
    }
};

// Revised - 01/16/2025