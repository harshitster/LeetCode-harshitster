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
    void helper(TreeNode* root, map<pair<int, int>, vector<int>>& m, int row, int col) {
        if(root == nullptr) return;

        if(m.find({row, col}) == m.end()) m[{row, col}] = vector<int>();
        m[{row, col}].push_back(root -> val);

        helper(root -> left, m, row + 1, col - 1);
        helper(root -> right, m, row + 1, col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> m;
        helper(root, m, 0, 0);

        int min_col = INT_MAX, max_col = INT_MIN;
        for(auto& pair: m) {
            if(pair.second.size() > 1) sort(pair.second.begin(), pair.second.end());
            min_col = min(min_col, pair.first.second);
            max_col = max(max_col, pair.first.second);
        }

        int n = max_col - min_col + 1;
        vector<vector<int>> res(n, vector<int>());

        for(auto& pair: m) {
            for(int num: pair.second) {
                res[pair.first.second - min_col].push_back(num);
            }
        }

        return res;
    }
};