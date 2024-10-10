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
    int helper(TreeNode* root, int* count, int val) {
        if(root == nullptr) return 1;

        int left = helper(root -> left, count, root -> val);
        int right = helper(root -> right, count, root -> val);

        if(left && right) (*count) += 1;

        return root -> val == val && left && right;
    }   
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(root == nullptr) return 0;

        int count = 0;
        helper(root, &count, root -> val);
        return count;
    }
};