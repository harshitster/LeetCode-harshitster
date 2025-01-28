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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            TreeNode* node = nullptr;
            for(int i = 0; i < size; i += 1) {
                node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            res.push_back(node -> val);
        }

        return res;
    }
};

// revised - 01/27/2025