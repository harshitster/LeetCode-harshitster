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
    int helper(TreeNode* root, vector<vector<int>>& res, int* size) {
        if(root == nullptr) return 0;
        if(root -> left == nullptr && root -> right == nullptr) {
            if(*size == 0) {
                res.push_back(vector<int>());
                (*size) += 1;
            }
            res[0].push_back(root -> val);
            return 1;
        }

        int left = helper(root -> left, res, size);
        int right = helper(root -> right, res, size);

        int index = max(left, right);
        if(index >= *size) {
            res.push_back(vector<int>());
            (*size) += 1;
        }
        res[index].push_back(root -> val);

        return index + 1;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        int size = 0;
        helper(root, res, &size);
        return res;
    }
};