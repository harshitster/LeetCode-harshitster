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

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        int leftToRight = 1;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);

            for(int i = 0; i < size; i += 1) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                temp[index] = node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            res.push_back(temp);
            leftToRight = !leftToRight;
        }

        return res;
    }
};