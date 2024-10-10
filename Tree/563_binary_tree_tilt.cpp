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
    int helper(TreeNode* root, int* sum) {
        if(root == nullptr) return 0;

        int left = helper(root -> left, sum);
        int right = helper(root -> right, sum);

        int val = root -> val;
        root -> val = abs(left - right);
        (*sum) += root -> val;
        return val + left + right;
    }
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, &sum);
        return sum;
    }
};