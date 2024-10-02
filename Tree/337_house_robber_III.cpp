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
    vector<int> helper(TreeNode* node) {
        if(node == nullptr) return {0, 0};

        vector<int> left = helper(node -> left);
        vector<int> right = helper(node -> right);

        int rob = node -> val + left[1] + right[1];
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);

        return {rob, not_rob};
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
};