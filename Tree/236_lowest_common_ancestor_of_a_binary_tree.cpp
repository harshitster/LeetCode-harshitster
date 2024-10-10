/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** res) {
        if(root == nullptr) return false;

        bool left = helper(root -> left, p, q, res);
        bool right = helper(root -> right, p, q, res);

        if((left && right) || ((root == p || root == q) && (left || right))) *res = root;

        return root == p || root == q || left || right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        helper(root, p, q, &res);
        return res;
    }
};