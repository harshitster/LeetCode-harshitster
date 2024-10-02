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
    TreeNode* helper(TreeNode* root, int val, int depth, int level) {
        if(root == nullptr) return nullptr;

        root -> left = helper(root -> left, val, depth, level + 1);
        root -> right = helper(root -> right, val, depth, level + 1);

        if(level + 1 == depth) {
            TreeNode* node1 = new TreeNode(val, root -> left, nullptr);
            TreeNode* node2 = new TreeNode(val, nullptr, root -> right);
            root -> left = node1;
            root -> right = node2;
        }

        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) return nullptr;
        if(depth == 1) {
            return new TreeNode(val, root, nullptr);
        }

        return helper(root, val, depth, 1);
    }
};