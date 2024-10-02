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
    int depth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = depth(root -> left);
        int right = depth(root -> right);

        return left >= right ? left + 1 : right + 1;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};

        int height = depth(root);
        vector<vector<int>> res(height);

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i += 1) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            res[height - 1 - level] = temp;
            level += 1;
        }

        return res;
    }
};