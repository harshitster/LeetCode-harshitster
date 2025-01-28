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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;

        q.push(root);
        int left = 1;
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp(n);

            for(int i = 0; i < n; i += 1) {
                TreeNode* node = q.front();
                q.pop();

                int index = left ? i : n - i - 1;
                temp[index] = node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            res.push_back(temp);
            left = 1 - left;
        }

        return res;
    }
};

// revised - 01/27/2025