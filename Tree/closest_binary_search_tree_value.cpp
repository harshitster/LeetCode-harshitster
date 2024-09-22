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
    void helper(TreeNode* root, long double* diff, int* val, double target) {
        if(root == nullptr) return;

        if(abs(root -> val - target) < *diff) {
            *diff = abs(root -> val - target);
            *val = root -> val;
        } else if(abs(root -> val - target) == *diff && *val > root -> val) {
            *val = root -> val;
        }
        helper(root -> left, diff, val, target);
        helper(root -> right, diff, val, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        long double diff = LONG_MAX;
        int val = INT_MAX;
        helper(root, &diff, &val, target);

        return val;
    }
};